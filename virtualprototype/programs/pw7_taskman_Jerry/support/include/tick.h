#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <defs.h>
#include <spr.h>

#define TICK_SR_EXCEPTION (1 << 1)
#define TICK_SPR_TTMR (0x5000)
#define TICK_SPR_TCCR (0x5001)

#define TICK_TTMR_PERIOD_MASK (0xFFFFFFF)
#define TICK_TTMR_IP (1 << 28)
#define TICK_TTMR_IE (1 << 29)
#define TICK_TTMR_DISABLED (0 << 30)
#define TICK_TTMR_RESTART (1 << 30)
#define TICK_TTMR_ONESHOT (2 << 30)

/// @brief Number of ticks per ms (depends on frequency).
/// @todo Update if the frequency changes.
#define TICK_TICKS_PER_MS (42200)

/// @note Tick reset period.
#define TICK_TICKS_PERIOD (0xFFFFFFF)

/**
 * @brief Initializes the systick timer functionality.
 *
 */
void tick_glinit();

__static_inline uint32_t tick_value() {
    // NOTE: We end with the period mask to avoid spurious misreadings
    // TODO figure out why.
    return SPR_READ(TICK_SPR_TCCR) & TICK_TTMR_PERIOD_MASK;
}

#endif /* TIMER_H_INCLUDED */
