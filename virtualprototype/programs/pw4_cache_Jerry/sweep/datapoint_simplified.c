/** @note defined in `defs.h`. */
#define __packed __attribute__((packed))

/** @brief Item struct. Relates an `id` to a piece of `data`. */
typedef struct __packed /* or nothing, depending on the configuration */ {
    uint32_t id;
    char data[PARAM_DATALEN];
} item_t;

/** @brief An array of items. */
static __global item_t items[PARAM_COUNT];

/**
 * @brief Searches for an item matching the `id`.
 * 
 * @param id 
 * @return item_t* Pointer to the found item.
 */
item_t* items_find(uint32_t id) {
    for (size_t i = 0; i < PARAM_COUNT; ++i) {
        if (items[i].id == id)
            return &items[i];
    }
    return NULL;
}