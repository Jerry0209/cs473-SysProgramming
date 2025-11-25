#ifndef CORO_CORO_H_INCLUDED
#define CORO_CORO_H_INCLUDED

#include <stddef.h>

typedef void (*coro_fn_t)();

/**
 * @brief Initializes the coroutine-related context.
 *
 */
void coro_glinit();

/**
 * @brief Initializes a stack for a new coroutine to be executed.
 *
 * @return void* Pointer to the stack to be allocated.
 */
void coro_init(void* stack, size_t stack_sz, coro_fn_t coro_fn, void* arg);

/**
 * @brief Resumes a coro.
 *
 * @param coro
 * @return void* Pointer to the coroutine stack.
 */
void coro_resume(void* stack);

/**
 * @brief Yields control to the caller of `coro_resume`.
 *
 */
void coro_yield();

/**
 * @brief Returns from the executed coroutine.
 *
 * @param result
 */
void coro_return(void* result);

/**
 * @brief Returns the argument passed to the coroutine.
 *
 * @return Coroutine argument.
 */
void* coro_arg();

/**
 * @brief Returns the data associated with the coroutine.
 * @note If `stack` is NULL, returns data associated with the executed coroutine.
 *
 * @param stack Stack to the coroutine stack.
 * @return void* Coroutine data.
 */
void* coro_data(void* stack);

/**
 * @brief Checks if the coroutine has completed or not.
 *
 * @param coro Pointer to the coroutine stack.
 * @param result Pointer to store the result of the coroutine.
 * Not modified if the coro has not finished.
 */
int coro_completed(void* coro, void** result);

/**
 * @brief Returns a pointer to the currently executed coroutine stack.
 *
 * @return void*
 */
void* coro_stack();

#endif /* CORO_CORO_H_INCLUDED */
