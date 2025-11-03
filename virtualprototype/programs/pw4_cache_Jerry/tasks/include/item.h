#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <defs.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ITEM_DATALEN 32

typedef struct item_t item_t;

/**
 * @brief An item connects an `id` to `data`.
 *
 */
struct item_t {
    /** @brief Item ID. */
    unsigned id;

    /** @brief Item data. */
    char data[ITEM_DATALEN];
};

/**
 * @brief Initializes items with random data.
 *
 * @param nodes
 * @param log2n
 */
void items_init(item_t* nodes, size_t log2n);

/**
 * @brief Finds an item with the given ID.
 *
 * @param node
 * @param log2n
 * @param id
 * @return item_t*
 */
item_t* items_find(item_t* node, size_t log2n, unsigned id);

/**
 * @brief Initializes an item with given parameters.
 *
 * @param item
 * @param id
 * @param data
 */
void item_init(item_t* item, uint32_t id, const char* data);

#ifdef __cplusplus
}
#endif

#endif /* ITEM_H_INCLUDED */
