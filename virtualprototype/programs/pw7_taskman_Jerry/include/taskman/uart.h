#ifndef TASKMAN_UART_H_INCLUDED
#define TASKMAN_UART_H_INCLUDED

#include "taskman.h"
#include <defs.h>

/**
 * @brief Initializes uart module for taskman.
 *
 */
void taskman_uart_glinit();

/**
 * @brief Waits asynchronously until a line is read from UART.
 *
 * @note If the buffer is full, returns immediately.
 * @note This function results in weird bugs without `__no_optimize`, investigate.
 *
 * @param buffer Output buffer.
 * @param capacity Buffer size.
 * @return size_t Read data size.
 *
 */
size_t taskman_uart_getline(uint8_t* buffer, size_t capacity) __no_optimize;

#endif /* TASKMAN_UART_H_INCLUDED */
