#include <cache.h>
#include <platform.h>

void part1();
void part2_1();
void part2_2();

int main() {
    platform_glinit();

    // we do not care about caches in this assignment
    icache_enable(0);
    dcache_enable(0);

    part1();
    part2_1();
    part2_2();
}
