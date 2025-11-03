#include <cache.h>
#include <defs.h>
#include <item.h>
#include <perf.h>
#include <stdio.h>
#include <task2.h>

#define LOG2NUM_ITEMS 4 // 16 items in total
static item_t items[1 << LOG2NUM_ITEMS];

void task2_main() {
    puts(__func__);
    
    items_init(items, LOG2NUM_ITEMS);

    dcache_flush();

    perf_start();
    item_t* item = items_find(items, LOG2NUM_ITEMS, 15);
    perf_stop();

    printf("Item ID = %u, data = %s\n", item->id, item->data);

    printf(
        "Task 2: dcache misses: %10lld\n",
        perf_read_counter(PERF_COUNTER_0)
    );
}
