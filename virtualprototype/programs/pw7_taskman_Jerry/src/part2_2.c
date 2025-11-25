#include <stdint.h>
#include <stdio.h>

#include <cache.h>
#include <cpu2.h>
#include <locks.h>
#include <swap.h>

#include <taskman/taskman.h>

#include <coro/coro.h>

#define STDOUT_LOCK_ID 0

// thread-safe printf macro
#define mt_printf(fmt, ...)                     \
    do {                                        \
        get_lock(STDOUT_LOCK_ID);               \
        printf(fmt __VA_OPT__(, ) __VA_ARGS__); \
        release_lock(STDOUT_LOCK_ID);           \
    } while (0)

static inline __always_inline uint8_t cpu_id() {
    return SPR_READ(9) & 0xF;
}

/**
 * @brief Blocking wait.
 * @note It does not yield control to the task manager's main loop.
 *
 * @param us Duration in microseconds.
 * @return __always_inline
 */
static inline __always_inline void wait_us(uint32_t us) {
    asm volatile("l.nios_rrr r0,%[in1],r0,0x6" ::[in1] "r"(us));
}

static void bouncing_ball_task() {
    int xdir, ydir, xpos, ypos, index;
    xpos = ypos = 5;
    xdir = ydir = 1;
    volatile unsigned int* leds = (unsigned int*)0x50000C00;
    volatile unsigned int* seven = (unsigned int*)0x50000060;

    mt_printf("bouncing_ball_task\n");

    while (1) {
        index = ypos * 12 + xpos;
        leds[index] = 0;

        if (ypos == 9)
            ydir = -1;
        if (ypos == 0)
            ydir = 1;
        if (xpos == 11)
            xdir = -1;
        if (xpos == 0)
            xdir = 1;

        ypos += ydir;
        xpos += xdir;
        index = ypos * 12 + xpos;

        leds[index] = swap_u32(cpu_id());
        index = (xpos & 0xFF) << 8 | (ypos & 0xFF);
        seven[4] = swap_u32(index);

        wait_us(100000 /* 0.1 s */);

        taskman_yield();
    }
}

static void print_task() {
    while (1) {
        mt_printf("print_task: arg = %s, cpu id = %d\n", coro_arg(), cpu_id());
        wait_us(100000 /* 0.1 s */);

        taskman_yield();
    }
}

int __no_optimize main2() {
    icache_enable(0);
    dcache_enable(0);

    coro_glinit();

    mt_printf("CPU with id %d is working!\n", cpu_id());

    taskman_loop();
}

int __no_optimize part2_2() {
    printf("Part 2.2: Dual-core Task Manager Implementation\n");

    init_locks();

    mt_printf("CPU with id %d is working!\n", cpu_id());

    coro_glinit();
    taskman_glinit();

    /* spawn tasks */
    taskman_spawn(&print_task, "task1", 1024);
    taskman_spawn(&print_task, "task2", 1024);
    taskman_spawn(&print_task, "task3", 1024);
    taskman_spawn(&print_task, "task4", 1024);
    taskman_spawn(&bouncing_ball_task, NULL, 4096);

    /* start the other CPU */
    SET_CPU2_MAIN(&init_cpu2);
    set_stack_cpu2(1ull << 20 /* 1 MB*/);
    START_CPU2();

    taskman_loop();

    return 0;
}
