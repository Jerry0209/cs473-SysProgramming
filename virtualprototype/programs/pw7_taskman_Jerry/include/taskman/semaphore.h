#ifndef TASKMAN_SEMAPHORE_H_INCLUDED
#define TASKMAN_SEMAPHORE_H_INCLUDED

#include <stdint.h>

#include "taskman.h"

struct taskman_semaphore {
    uint32_t count;
    uint32_t max;
};

/**
 * @brief Initializes the semaphore module for taskman.
 *
 */
void taskman_semaphore_glinit();

/**
 * @brief Initializes an individual semaphore instance.
 *
 * @param semaphore
 * @param initial The initial value of the semaphore.
 * @param max The maximum value of the semaphore.
 */
void taskman_semaphore_init(
    struct taskman_semaphore* semaphore,
    uint32_t initial,
    uint32_t max
);

/**
 * @brief Decrements the semaphore, waits if the semaphore is zero.
 *
 * @param semaphore
 */
void taskman_semaphore_down(struct taskman_semaphore* semaphore);

/**
 * @brief Increments the semaphore, waits if the semaphore reached its
 * maximum value.
 *
 * @param semaphore
 */
void taskman_semaphore_up(struct taskman_semaphore* semaphore);

#endif /* TASKMAN_SEMAPHORE_H_INCLUDED */
