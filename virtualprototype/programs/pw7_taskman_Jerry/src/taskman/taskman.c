#include <assert.h>
#include <cache.h>
#include <defs.h>
#include <locks.h>
#include <taskman/taskman.h>

// I included this to make the IMPLEMENT_ME error go away
// #define SOLUTION

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
    TASKMAN_LOCK();
    // Check the size of new stack
    die_if_not_f(
        taskman.stack_offset + stack_sz <= TASKMAN_STACK_SIZE, 
        "current task stack size is too large"
    );

    die_if_not_f(taskman.tasks_count < TASKMAN_NUM_TASKS, "Too many tasks");

    // Initialize coroutine with task stack
    
    uint8_t* task_sp = &taskman.stack[taskman.stack_offset];
    coro_init(task_sp, stack_sz, coro_fn, arg); // Not starting from here
    
    // Initialize struct task_data
    // struct task_data* task = (struct task_data*)task_sp;
    struct task_data* task_data = (struct task_data*)coro_data(task_sp); // In coro data
    task_data->wait.handler = NULL;
    task_data->wait.arg = NULL;
    task_data->running = 0;

    // Register task into array
    taskman.tasks[taskman.tasks_count] = task_sp;

    // Update task manager state
    taskman.stack_offset += stack_sz;
    taskman.tasks_count ++;


    TASKMAN_RELEASE();
    return task_sp;
}

void taskman_loop() {
    // (a) Call the `loop` functions of all the wait handlers.
    // (b) Iterate over all the tasks, and resume them if.
    //        * The task is not complete.
    //        * it yielded using `taskman_yield`.
    //        * the waiting handler says it can be resumed.

    

    while (!taskman.should_stop) {

        // IMPLEMENT_ME;

        TASKMAN_LOCK();
        // Start Polling of each handler
        for (int i = 0; i < taskman.handlers_count; i++) {
            struct taskman_handler* h = taskman.handlers[i];
            // 必须检查 h 不为空，且 h->loop 指针也不为空，防止崩
            if (h != NULL && h->loop != NULL) {
                h->loop(h); // 这一步就是去轮询硬件（比如问 UART 有没有数据）
            }
        }
        TASKMAN_RELEASE();

        for(int i = 0; i < taskman.tasks_count; i++){

            TASKMAN_LOCK();
            void* task_sp = taskman.tasks[i];

            // 1. If task has already completed
            if (coro_completed(task_sp, NULL)) {
                TASKMAN_RELEASE();
                continue;
            }

            struct task_data* task_data = (struct task_data*)coro_data(task_sp);

            // 2. If current stack is running
            if (task_data->running) {
                TASKMAN_RELEASE();
                continue;
            }

            // 3. Check handler
            int ready = 0;

            if (task_data->wait.handler == NULL) {
                // No handler
                ready = 1;
            } else {

                if (task_data->wait.handler->can_resume(task_data->wait.handler, task_sp, task_data->wait.arg)) {
                    ready = 1;
                }
            }

            if (ready) {
                task_data->running = 1;    
                
                TASKMAN_RELEASE();
                coro_resume(task_sp); // Run task!
                
                TASKMAN_LOCK();
                task_data->running = 0;
                TASKMAN_RELEASE();
                       
            } else {
                TASKMAN_RELEASE();
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
    if(handler == NULL || (!handler->on_wait(handler, stack, arg))){ // on_wait is 0 -> should wait

        // Store handler to current task if it has to wait, so next time it can be checked
        task_data->wait.handler = handler;
        task_data->wait.arg = arg;

        coro_yield();

        // If resume, previous handler is finished and should be removed
        task_data->wait.handler = NULL;
    }


    // struct task_data {
    // struct {
    //     /// @brief Handler
    //     /// @note NULL if waiting on `coro_yield`.
    //     struct taskman_handler* handler;

    //     /// @brief Argument to the wait handler
    //     void* arg;
    // } wait;

    // /// @brief 1 if running, 0 otherwise.
    // int running;
};

    

void taskman_yield() {
    taskman_wait(NULL, NULL);
}

void taskman_return(void* result) {
    coro_return(result);
}
