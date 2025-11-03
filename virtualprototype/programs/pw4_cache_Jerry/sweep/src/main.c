#include "datapoint/entry.h"
#include <cache.h>
#include <perf.h>
#include <platform.h>
#include <stdio.h>
#include <string.h>

int main() {
    // initializes the UART, performance counters, peripherals etc.
    platform_init();
    perf_init();

    dcache_write_cfg(CACHE_FOUR_WAY | CACHE_SIZE_4K | CACHE_REPLACE_LRU | CACHE_WRITE_BACK);
    dcache_enable(1);

    perf_set_mask(PERF_COUNTER_0, PERF_DCACHE_MISS_MASK);

    entry();

    printf("done.\n");
    return 0;
}
