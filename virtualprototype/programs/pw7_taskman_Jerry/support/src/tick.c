#include <tick.h>

/** @note maynot work with TICK_TTMR_ONESHOT */
__static_inline void tick_setup_ttmr() {
    uint32_t ttmr = TICK_TICKS_PERIOD | TICK_TTMR_RESTART;
    SPR_WRITE(TICK_SPR_TTMR, ttmr);
}

__static_inline void tick_clear_tccr() {
    SPR_WRITE(TICK_SPR_TCCR, 0);
}

void tick_glinit() {
    tick_setup_ttmr();
    tick_clear_tccr();
}
