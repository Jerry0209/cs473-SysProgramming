#include <stdint.h>
#include <stdio.h>

#include <taskman/semaphore.h>
#include <taskman/taskman.h>
#include <taskman/tick.h>
#include <taskman/uart.h>

#include <coro/coro.h>

__global struct taskman_semaphore s;

/**
 * @brief Periodically prints the internal time.
 *
 */
static void periodic_task() {
    uint32_t arg = (uint32_t)coro_arg();
    uint32_t t0 = taskman_tick_now();

    while (1) {
        printf("[ t = %10u ms ] %s: period = %u\n", taskman_tick_now(), __func__, arg);
        taskman_tick_wait_for(arg);
    }

    taskman_return(NULL);
}

/**
 * @brief Increments the semaphore after a certain amount of time.
 *
 */
static void up_task() {
    uint32_t wait_ms = (uint32_t)coro_arg();

    taskman_tick_wait_for(wait_ms);
    taskman_semaphore_up(&s);
    printf("[ t = %10u ms ] %s: complete\n", taskman_tick_now(), __func__);
    taskman_return(NULL);
}

/**
 * @brief Receives data from UART and echoes it back.
 *
 */
static void uart_task() {
    uint8_t buf[4096 /* vary this, maybe. */];
    int total_len = 0;

    while (1) {
        int len = taskman_uart_getline(buf, sizeof(buf));
        total_len += len;
        printf(
            "[ t = %10u ms ] %s: received line with length = %d (total = %d): %s\n",
            taskman_tick_now(), __func__,
            len, total_len, buf
        );
    }

    taskman_return(NULL);
}

static void entry_task() {
    printf("hello from the entry_task\n");

    // to comment a section, use `#if 0`
    // to uncomment a section, use `#if 1`
    // comment all sections first, and uncomment them as you
    // implement the functionality.

    // SECTION: basic test
    #if 1
    taskman_spawn(&periodic_task, (void*)1000, 4ull << 10);
    taskman_spawn(&periodic_task, (void*)3000, 4ull << 10);
    taskman_spawn(&periodic_task, (void*)9000, 4ull << 10);
    #endif

    // SECTION: uart test
    #if 1
    taskman_spawn(&uart_task, NULL, 8ull << 10);
    #endif

    // SECTION: semaphore test
    #if 1
    taskman_semaphore_init(&s, 0, 3);

    taskman_spawn(&up_task, (void*)2000, 8ull << 10);
    taskman_spawn(&up_task, (void*)3000, 8ull << 10);
    taskman_spawn(&up_task, (void*)4000, 8ull << 10);
    printf("[ t = %10u ms ] %s: waiting for all up_task's to finish\n", taskman_tick_now(), __func__);

    taskman_semaphore_down(&s);
    printf("[ t = %10u ms ] %s: done 1\n", taskman_tick_now(), __func__);

    taskman_semaphore_down(&s);
    printf("[ t = %10u ms ] %s: done 2\n", taskman_tick_now(), __func__);

    taskman_semaphore_down(&s);
    printf("[ t = %10u ms ] %s: done 3\n", taskman_tick_now(), __func__);

    printf("[ t = %10u ms ] %s: all up_task's are complete\n", taskman_tick_now(), __func__);

    /* Now, let's block `up_task`s. */
    taskman_semaphore_up(&s);
    taskman_semaphore_up(&s);
    taskman_semaphore_up(&s);

    taskman_spawn(&up_task, (void*)0, 1ull << 10);
    taskman_spawn(&up_task, (void*)0, 1ull << 10);
    taskman_spawn(&up_task, (void*)0, 1ull << 10);
    printf("[ t = %10u ms ] %s: blocking all up_task's for 2 seconds\n", taskman_tick_now(), __func__);

    taskman_tick_wait_for(2000);

    taskman_semaphore_down(&s);
    taskman_semaphore_down(&s);
    taskman_semaphore_down(&s);

    #endif

    taskman_tick_wait_for(1000);

    printf("[ t = %10u ms ] %s: stopping the task manager loop\n", taskman_tick_now(), __func__);
    taskman_stop();

    taskman_return(NULL);
}

void part2_1() {
    printf("Part 2.1: Single-core Task Manager Implementation\n");
    printf("now executing: %s\n", __func__);

    coro_glinit();
    taskman_glinit();

    taskman_semaphore_glinit();
    taskman_uart_glinit();
    taskman_tick_glinit();

    taskman_spawn(&entry_task, NULL, 4ull << 10);

    taskman_loop();
}
