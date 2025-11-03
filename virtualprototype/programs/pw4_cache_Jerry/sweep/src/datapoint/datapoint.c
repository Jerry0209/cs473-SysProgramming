#include <defs.h>
#include <perf.h>
#include <cache.h>
#include <stdio.h>
#include <string.h>

#include "params.h"

/**
 * @brief Item struct.
 *
 */
typedef struct PACKED {
    uint32_t id;
    char data[PARAM_DATALEN];
} item_t;

static item_t items[PARAM_COUNT];

/**
 * @brief Initializes the global variable items.
 * 
 */
static
void items_init() {
    for (size_t i = 0; i < PARAM_COUNT; ++i) {
        items[i].id = i;
        memset(items[i].data, 0, PARAM_DATALEN);
    }

    // this item has a special ID
    items[PARAM_MAGIC].id = 0xDEAD;
}

/**
 * @brief Searches for an item matching the `id`.
 * 
 * @param id 
 * @return item_t* 
 */
static __no_optimize
item_t* items_find(uint32_t id) {
    for (size_t i = 0; i < PARAM_COUNT; ++i) {
        if (items[i].id == id)
            return &items[i];
    }

    return NULL;
}

/**
 * @brief Entry function of the test.
 * 
 */
void PARAM_ENTRY() {
    dcache_flush();

    perf_start();
    items_find(PARAM_MAGIC);
    perf_stop();

    printf(
        "Config: %-32s, sizeof(item_t): %2d, dcache misses: %10lld\n",
        PARAM_DESC,
        sizeof(item_t),
        perf_read_counter(PERF_COUNTER_0)
    );
}
