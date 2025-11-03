#include <cache.h>
#include <defs.h>
#include <node.h>
#include <perf.h>
#include <stdio.h>
#include <task1.h>

#define LOG2NUM_NODES 4 // 16 nodes in total
static node_t nodes[1 << LOG2NUM_NODES]
    // what does __aligned(X) do? (defined in defs.h)
    __aligned(sizeof(node_t));

static void print_layout() {
    node_t node;

    uint32_t addr0 = (uint32_t)&node;
    uint32_t addr1 = (uint32_t)&node.id;
    uint32_t addr2 = (uint32_t)node.data;
    uint32_t addr3 = (uint32_t)&node.next;
    uint32_t addr4 = (uint32_t)&node.prev;

    printf("sizeof(node_t) = %d:\n", sizeof(node_t));
    printf("struct layout for node_t:\n");
    printf("member        -> offset\n");
    printf("node.id       -> 0x%03x\n", addr1 - addr0);
    printf("node.data     -> 0x%03x\n", addr2 - addr0);
    printf("node.next     -> 0x%03x\n", addr3 - addr0);
    printf("node.prev     -> 0x%03x\n", addr4 - addr0);
}

void task1_main() {
    puts(__func__);
    print_layout();

    nodes_init(nodes, LOG2NUM_NODES);

    dcache_flush();

    perf_start();
    node_count(&nodes[0]);
    perf_stop();

    printf(
        "Task 1: dcache misses: %10lld\n",
        perf_read_counter(PERF_COUNTER_0)
    );
}
