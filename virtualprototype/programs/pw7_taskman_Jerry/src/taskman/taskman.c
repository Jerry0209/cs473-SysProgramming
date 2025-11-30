#include <assert.h>
#include <cache.h>
#include <defs.h>
#include <locks.h>
#include <taskman/taskman.h>

// I included this to make the IMPLEMENT_ME error go away
#define SOLUTION

#include <implement_me.h>

/// @brief Maximum number of wait handlers.
#define TASKMAN_NUM_HANDLERS 32

/// @brief Maximum number of scheduled tasks.
#define TASKMAN_NUM_TASKS 128

/// @brief Maximum total stack size.
#define TASKMAN_STACK_SIZE (256 << 10)

#define TASKMAN_LOCK_ID 2

#define TASKMAN_LOCK()             \
    do {                           \
        get_lock(TASKMAN_LOCK_ID); \
    } while (0)

#define TASKMAN_RELEASE()              \
    do {                               \
        release_lock(TASKMAN_LOCK_ID); \
    } while (0)

__global static struct {
    /// @brief Wait handlers.
    struct taskman_handler* handlers[TASKMAN_NUM_HANDLERS];

    /// @brief Number of wait handlers;
    size_t handlers_count;

    /// @brief Stack area. Contains multiple independent stacks.
    uint8_t stack[TASKMAN_STACK_SIZE];

    /// @brief Stack offset (for the next allocation).
    size_t stack_offset;

    /// @brief Scheduled tasks.
    void* tasks[TASKMAN_NUM_TASKS];

    /// @brief Number of tasks scheduled.
    size_t tasks_count;

    /// @brief True if the task manager should stop.
    uint32_t should_stop;
} taskman;

/**
 * @brief Extra information attached to the coroutine used by the task manager.
 *
 */
struct task_data {
    struct {
        /// @brief Handler
        /// @note NULL if waiting on `coro_yield`.
        struct taskman_handler* handler;

        /// @brief Argument to the wait handler
        void* arg;
    } wait;

    /// @brief 1 if running, 0 otherwise.
    int running;
};

void taskman_glinit() {
    taskman.handlers_count = 0;
    taskman.stack_offset = 0;
    taskman.tasks_count = 0;
    taskman.should_stop = 0;
}

void* taskman_spawn(coro_fn_t coro_fn, void* arg, size_t stack_sz) {
    // (1) allocate stack space for the new task
    

    // (2) initialize the coroutine and struct task_data
    // (3) register the coroutine in the tasks array
    // use die_if_not() statements to handle error conditions (like no memory)


    // IMPLEMENT_ME;

    // (1) allocate stack space for the new task
    // First, we need to check if we have enough memory left in the big stack array.
    // We also check if we have reached the maximum number of tasks.
    TASKMAN_LOCK(); // Safety first! prevent issues later
    
    if (taskman.stack_offset + stack_sz > TASKMAN_STACK_SIZE) {
        die_if_not_f(0, "Error: Not enough stack memory available!");
    }
    
    if (taskman.tasks_count >= TASKMAN_NUM_TASKS) {
        die_if_not_f(0, "Error: Too many tasks!");
    }

    // Now calculate where the new stack starts
    // It starts at the current offset
    void* stack_ptr = &taskman.stack[taskman.stack_offset];
    
    // Update the offset for the next task
    taskman.stack_offset += stack_sz;

    // (2) initialize the coroutine and struct task_data
    // This sets up the stack for the coroutine function
    coro_init(stack_ptr, stack_sz, coro_fn, arg);

    // Get the task data pointer (it's stored in the coroutine stack)
    struct task_data* t_data = (struct task_data*)coro_data(stack_ptr);
    
    // Initialize the values
    t_data->wait.handler = NULL; // Not waiting for anything yet
    t_data->wait.arg = NULL;
    t_data->running = 0; // Not running yet

    // (3) register the coroutine in the tasks array
    taskman.tasks[taskman.tasks_count] = stack_ptr;
    taskman.tasks_count++; // Increase the task counter

    TASKMAN_RELEASE();
    return stack_ptr;
}

void taskman_loop() {
    // (a) Call the `loop` functions of all the wait handlers.
    // (b) Iterate over all the tasks, and resume them if.
    //        * The task is not complete.
    //        * it yielded using `taskman_yield`.
    //        * the waiting handler says it can be resumed.

    // while (!taskman.should_stop) {

    //     IMPLEMENT_ME;
    // }

    while (!taskman.should_stop) {
        // Step A: Let all handlers do their job (like checking hardware)
        for (int i = 0; i < taskman.handlers_count; i++) {
            struct taskman_handler* h = taskman.handlers[i];
            // Check if the loop function pointer is valid before calling it
            if (h != NULL && h->loop != NULL) {
                h->loop(h);
            }
        }

        // Step B: Check all tasks to see if anyone can work
        for (int i = 0; i < taskman.tasks_count; i++) {
            void* current_task_stack = taskman.tasks[i];
            
            // If the task is already finished, we just skip it
            if (coro_completed(current_task_stack, NULL)) {
                continue;
            }

            struct task_data* data = (struct task_data*)coro_data(current_task_stack);

            // If it's somehow marked as running (shouldn't happen in single core here), skip
            if (data->running) {
                continue;
            }

            int ready_to_run = 0;

            // Check why the task is waiting
            if (data->wait.handler == NULL) {
                // If handler is NULL, it means it just yielded voluntarily (taskman_yield)
                // So it is ready to run again immediately
                ready_to_run = 1;
            } else {
                // If it's waiting for a handler, ask the handler if it's okay to resume
                if (data->wait.handler->can_resume(data->wait.handler, current_task_stack, data->wait.arg)) {
                    ready_to_run = 1;
                }
            }

            // If it is ready, let's run it!
            if (ready_to_run) {
                data->running = 1; // Mark as running
                coro_resume(current_task_stack); // Switch context to the task
                data->running = 0; // It returned, so it's not running anymore
            }
        }
    }
}

void taskman_stop() {
    TASKMAN_LOCK();
    taskman.should_stop = 1;
    TASKMAN_RELEASE();
}

void taskman_register(struct taskman_handler* handler) {
    die_if_not(handler != NULL);
    die_if_not(taskman.handlers_count < TASKMAN_NUM_HANDLERS);

    taskman.handlers[taskman.handlers_count] = handler;
    taskman.handlers_count++;
}

void taskman_wait(struct taskman_handler* handler, void* arg) {
    void* stack = coro_stack();
    struct task_data* task_data = coro_data(stack);

    // I suggest that you read `struct taskman_handler` definition.
    // Call handler->on_wait, see if there is a need to yield.
    // Update the wait field of the task_data.
    // Yield if necessary.


    // IMPLEMENT_ME;

    int need_to_wait = 1; // Default is we need to wait

    // If we have a handler, maybe we don't actually need to wait?
    // For example, maybe the semaphore is already green.
    if (handler != NULL && handler->on_wait != NULL) {
        // on_wait returns 1 if we don't need to yield (success immediately)
        if (handler->on_wait(handler, stack, arg) == 1) {
            need_to_wait = 0;
        }
    }

    if (need_to_wait) {
        // Update the wait field of the task_data.
        task_data->wait.handler = handler;
        task_data->wait.arg = arg;

        // Yield if necessary.
        // This pauses the current task and goes back to taskman_loop
        coro_yield();
        
        // When we come back here, it means we were resumed.
        // So we are not waiting for anything anymore.
        task_data->wait.handler = NULL;
    }
}

void taskman_yield() {
    taskman_wait(NULL, NULL);
}

void taskman_return(void* result) {
    coro_return(result);
}
