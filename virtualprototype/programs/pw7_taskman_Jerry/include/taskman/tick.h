#ifndef TASKMAN_TICK_H_INCLUDED
#define TASKMAN_TICK_H_INCLUDED

#include "taskman.h"

/**
 * @brief Initializes tick timer module for taskman.
 *
 */
void taskman_tick_glinit();

/**
 * @brief Waits asyncronously for a given number of milliseconds.
 *
 */
void taskman_tick_wait_for(uint32_t duration_ms);

/**
 * @brief Waits asynchronously until `tick_ms` variable is at least the given value.
 *
 * @param timepoint_ms
 */
void taskman_tick_wait_until(uint32_t timepoint_ms);

/**
 * @brief Returns the current time, in ms.
 *
 * @return uint32_t
 */
uint32_t taskman_tick_now();

#endif /* TASKMAN_TICK_H_INCLUDED */
