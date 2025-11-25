#ifndef TASKMAN_TASKMAN_H_INCLUDED
#define TASKMAN_TASKMAN_H_INCLUDED

#include <coro/coro.h>

struct taskman_handler {
    /**
     * @brief Name of the handler. Useful for debugging.
     *
     */
    const char* name;

    /**
     * @brief Called when a task calls `taskman_wait`.
     * Returns 0 if should wait (i.e., yield), 1 otherwise.
     *
     */
    int (*on_wait)(struct taskman_handler* handler, void* stack, void* arg);

    /**
     * @brief Checks if the task should be resumed.
     *
     */
    int (*can_resume)(struct taskman_handler* handler, void* stack, void* arg);

    /**
     * @brief Called at each main loop iteration.
     *
     */
    void (*loop)(struct taskman_handler* handler);
};

/**
 * @brief Initializes the task manager at startup.
 *
 */
void taskman_glinit();

/**
 * @brief Spawns a new task.
 *
 * @param coro_fn Coroutine function corresponding to the task.
 * @param arg Argument to be passed to the coroutine.
 * @param stack_sz Stack size allocated to it.
 * @return void* Pointer to the stack of the scheduled task.
 */
void* taskman_spawn(coro_fn_t coro_fn, void* arg, size_t stack_sz);

/**
 * @brief Executes the main loop of the task manager.
 *
 */
void taskman_loop();

/**
 * @brief Sets the stop flag.
 *
 */
void taskman_stop();

/**
 * @brief Registers a wait handler.
 *
 * @param handler Handler struct.
 */
void taskman_register(struct taskman_handler* handler);

/**
 * @brief Wait using a handler.
 *
 * @note If a function calls `taskman_wait`, it should not be optimized.
 * Use `__no_optimize_` for the caller function.
 *
 * @param handler Can be NULL, in which case it simply yields.
 * @param arg
 */
void taskman_wait(struct taskman_handler* handler, void* arg);

/**
 * @brief Yields control.
 *
 */
void taskman_yield();

/**
 * @brief Returns from the task.
 *
 * @param result
 */
void taskman_return(void* result);

#endif /* TASKMAN_TASKMAN_H_INCLUDED */
