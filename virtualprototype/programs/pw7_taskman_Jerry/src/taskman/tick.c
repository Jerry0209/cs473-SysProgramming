#include <assert.h>
#include <defs.h>
#include <taskman/taskman.h>
#include <taskman/tick.h>
#include <tick.h>

__global static struct {
    struct taskman_handler handler;

    /** @brief current time in milliseconds */
    uint32_t now_ms;

    /** @brief last tick value */
    uint32_t last_tick_value;
} tick_handler;

static int on_wait(struct taskman_handler* handler, void* stack, void* arg) {
    UNUSED(handler);
    UNUSED(stack);

    uint32_t wait_until = (uint32_t)arg;
    return taskman_tick_now() > wait_until;
}

static int can_resume(struct taskman_handler* handler, void* stack, void* arg) {
    UNUSED(handler);
    UNUSED(stack);

    uint32_t wait_until = (uint32_t)arg;
    return taskman_tick_now() > wait_until;
}

static void loop(struct taskman_handler* handler) {
    UNUSED(handler);

    uint64_t new_tick_value = tick_value();
    uint64_t diff = 0;

    /* sanity checks */
    die_if_not(new_tick_value <= TICK_TICKS_PERIOD);
    die_if_not(tick_handler.last_tick_value <= TICK_TICKS_PERIOD);

    if (new_tick_value < tick_handler.last_tick_value)
        diff = new_tick_value + TICK_TICKS_PERIOD - tick_handler.last_tick_value;
    else
        diff = new_tick_value - tick_handler.last_tick_value;

    tick_handler.now_ms += diff / TICK_TICKS_PER_MS;
    diff %= TICK_TICKS_PER_MS;

    if (new_tick_value < diff)
        tick_handler.last_tick_value = new_tick_value + TICK_TICKS_PERIOD - diff;
    else
        tick_handler.last_tick_value = new_tick_value - diff;
}

void taskman_tick_glinit() {
    tick_handler.handler.name = "tick";
    tick_handler.handler.on_wait = &on_wait;
    tick_handler.handler.can_resume = &can_resume;
    tick_handler.handler.loop = &loop;

    tick_handler.now_ms = 0;
    tick_handler.last_tick_value = tick_value();

    taskman_register(&tick_handler.handler);
}

void __no_optimize taskman_tick_wait_for(uint32_t duration_ms) {
    taskman_tick_wait_until(duration_ms + taskman_tick_now());
}

void __no_optimize taskman_tick_wait_until(uint32_t timepoint_ms) {
    taskman_wait(&tick_handler.handler, (void*)timepoint_ms);
}

uint32_t taskman_tick_now() {
    return tick_handler.now_ms;
}
