#include <assert.h>
#include <item.h>
#include <lfsr.h>
#include <stdio.h>
#include <string.h>

#define MEM_SIZE 1024

static struct {
    char data[MEM_SIZE];
    size_t next;
} mem = { .next = 0 };

/**
 * @brief Allocates memory from global storage.
 * Hint: How is this useful?
 *
 * @param sz Size of memory to allocate.
 * @return void*
 */
void* alloc(size_t sz) {
    // YOU ARE NOT SUPPOSED TO MODIFY THIS.

    if ((mem.next + sz) > MEM_SIZE) {
        printf("Out-of-memory! Dead.");
        while (1)
            ;
    }

    void* res = mem.data + mem.next;
    mem.next += sz;
    return res;
}

void items_init(item_t* items, size_t log2n) {
    // YOU ARE NOT SUPPOSED TO MODIFY THIS.
    char buffer[ITEM_DATALEN];

    assert(log2n >= 3);

    /* create a random number generator */
    struct lfsr_fibonacci lfsr;
    lfsr_fibonacci_init(&lfsr, log2n, 5, 0);

    for (size_t i = 0; i < (1 << log2n); ++i) {
        item_t* item = &items[i];
        unsigned num = lfsr_fibonacci_next(&lfsr);
        sprintf(buffer, "random data: %u", num);
        item_init(item, i, buffer);
    }
}

item_t* items_find(item_t* items, size_t log2n, unsigned id) {
    // YOU ARE NOT SUPPOSED TO MODIFY THIS.
    for (size_t i = 0; i < (1 << log2n); ++i) {
        if (items[i].id == id)
            return &items[i];
    }
    return NULL;
}

void item_init(item_t* item, uint32_t id, const char* data) {
    // YOU CAN MODIFY THIS.
    item->id = id;

    if (data != NULL)
        memcpy(item->data, data, ITEM_DATALEN);
    else
        memset(item->data, 0, ITEM_DATALEN);
}
