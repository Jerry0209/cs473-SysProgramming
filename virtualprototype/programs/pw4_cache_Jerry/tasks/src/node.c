#include <assert.h>
#include <lfsr.h>
#include <node.h>
#include <stdio.h>
#include <string.h>

void nodes_init(node_t* nodes, size_t log2n) {
    // YOU ARE NOT SUPPOSED TO MODIFY THIS.

    assert(log2n >= 3);

    /* create a random number generator */
    struct lfsr_fibonacci lfsr;
    lfsr_fibonacci_init(&lfsr, log2n, 5, 0);

    for (size_t i = 0; i < (1 << log2n); ++i) {
        node_t* node = &nodes[i];
        node_init(node, i, NULL);
    }

    node_t* last = &nodes[0];
    for (size_t i = 0; i < (1 << log2n) - 1; ++i) {
        unsigned num = lfsr_fibonacci_next(&lfsr);
        node_t* next = &nodes[num];

        sprintf(last->data, "connects to node #%u", num);
        node_connect(last, next);

        last = next;
    }
}

void node_init(node_t* node, uint32_t id, const char* data) {
    // YOU ARE NOT SUPPOSED TO MODIFY THIS.

    node->next = NULL;
    node->prev = NULL;
    node->id = id;

    if (data != NULL)
        memcpy(node->data, data, NODE_DATALEN);
    else
        memset(node->data, 0, NODE_DATALEN);
}

void node_connect(node_t* first, node_t* second) {
    // YOU ARE NOT SUPPOSED TO MODIFY THIS.

    first->next = second;
    second->prev = first;
}

uint32_t node_count(node_t* node) {
    // YOU ARE NOT SUPPOSED TO MODIFY THIS.

    uint32_t result = 0;

    while (node) {
        printf("#%u -> ", node->id);
        result++;
        node = node->next;
    }

    printf("Done.\n");

    return result;
}
