#include <defs.h>
#include <taskman/semaphore.h>
#define SOLUTION
#include <implement_me.h>

__global static struct taskman_handler semaphore_handler; // Define semaphore_handler

// I define a simple enum to know what operation we want to do
enum sem_operation {
    SEM_OP_DOWN = 0,
    SEM_OP_UP = 1
};

struct wait_data {
    // to be passed as an argument.
    // what kind of data do we need to put here
    // so that the semaphore works correctly?

    //
    struct taskman_semaphore* sem; // Pointer to the semaphore we are using
    enum sem_operation op;         // Are we doing UP or DOWN?

};

static int impl(struct wait_data* wait_data) {
    // implement the semaphore logic here
    // do not forget to check the header file


    // IMPLEMENT_ME;
    struct taskman_semaphore* s = wait_data->sem;

    if (wait_data->op == SEM_OP_DOWN) {
        // Trying to decrease (take a resource)
        if (s->count > 0) {
            s->count--; // Success! we took one
            return 1;   // Return 1 means we can resume/continue
        }
    } else {
        // Trying to increase (release a resource)
        // Check max semaphore
        if (s->count < s->max) {
            s->count++; // Success! we added one
            return 1;   // Return 1 means success
        }
    }

    // If we reach here, it means we couldn't do the operation yet
    return 0;
}

static int on_wait(struct taskman_handler* handler, void* stack, void* arg) {
    UNUSED(handler);
    UNUSED(stack);

    return impl((struct wait_data*)arg);
}

static int can_resume(struct taskman_handler* handler, void* stack, void* arg) {
    UNUSED(handler);
    UNUSED(stack);

    return impl((struct wait_data*)arg);
}

static void loop(struct taskman_handler* handler) {
    UNUSED(handler);
    // No polling required
}

/* END SOLUTION */

void taskman_semaphore_glinit() {
    semaphore_handler.name = "semaphore";
    semaphore_handler.on_wait = &on_wait;
    semaphore_handler.can_resume = &can_resume;
    semaphore_handler.loop = &loop;

    taskman_register(&semaphore_handler); // Register to taskman
}

void taskman_semaphore_init(
    struct taskman_semaphore* semaphore,
    uint32_t initial,
    uint32_t max
) {
    semaphore->count = initial;
    semaphore->max = max;
}

void __no_optimize taskman_semaphore_down(struct taskman_semaphore* semaphore) {

    // IMPLEMENT_ME;

    // Create the data package to pass to the handler
    struct wait_data data;
    data.sem = semaphore;
    data.op = SEM_OP_DOWN;

    // Call wait. If impl returns 1 immediately, wait will return immediately too.
    taskman_wait(&semaphore_handler, &data);
}

void __no_optimize taskman_semaphore_up(struct taskman_semaphore* semaphore) {

    // IMPLEMENT_ME;

    struct wait_data data;
    data.sem = semaphore;
    data.op = SEM_OP_UP;

    taskman_wait(&semaphore_handler, &data); // Handler 有用于判断的工具， taskman 根据 data 判断 yield 还是 resume
}
