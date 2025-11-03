#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <defs.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NODE_DATALEN 52

typedef struct node_t node_t;

/**
 * @brief Defines a node.
 * @note **Do not remove** any fields from this structure.
 */
struct node_t {
    /** @brief Node ID. */
    unsigned id;

    /** @brief Node data. */
    char data[NODE_DATALEN];

    /** @brief The next node. */
    node_t* next;

    /** @brief The previous node. */
    node_t* prev;
};

/**
 * @brief Initializes the nodes randomly.
 *
 * @param nodes
 * @param log2n
 */
void nodes_init(node_t* nodes, size_t log2n);

/**
 * @brief Initializes a single node.
 *
 * @param node
 * @param id
 * @param data
 */
void node_init(node_t* node, uint32_t id, const char* data);

/**
 * @brief Connects two nodes together.
 *
 * @param first
 * @param second
 */
void node_connect(node_t* first, node_t* second);

/**
 * @brief Counts the nodes, starting from `node`.
 *
 * @param node
 * @return uint32_t
 */
uint32_t node_count(node_t* node);

#ifdef __cplusplus
}
#endif

#endif /* NODE_H_INCLUDED */
