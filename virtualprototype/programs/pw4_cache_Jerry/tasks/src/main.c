#include <cache.h>
#include <node.h>
#include <perf.h>
#include <platform.h>
#include <stdio.h>
#include <string.h>

#include <task1.h>
#include <task2.h>
#include <task3.h>
#include <task4.h>

int main() {
    // initializes the UART, performance counters, peripherals etc.
    platform_init();
    perf_init();

    dcache_write_cfg(CACHE_FOUR_WAY | CACHE_SIZE_4K | CACHE_REPLACE_LRU | CACHE_WRITE_BACK);
    dcache_enable(1);

    perf_set_mask(PERF_COUNTER_0, PERF_DCACHE_MISS_MASK);

    task1_main();
    task2_main();
    task3_main();
    task4_main();

    return 0;
}
