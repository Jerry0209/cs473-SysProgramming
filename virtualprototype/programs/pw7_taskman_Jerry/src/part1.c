#include <coro/coro.h>
#include <defs.h>
#include <stdio.h>

__global static char stack0[1024];

static int f(int x) {
    printf("func = %s, x = %d\n", __func__, x);
    coro_yield();
    return 60 + x;
}

static void test_fn() {
    printf("func = %s, data = 0x%x\n", __func__, *(uint32_t*)coro_data(NULL));

    /* what happens if we use the return keyword in a coroutine? */
    for (int i = 0; i < 4; ++i) {
        printf("func = %s, i = %d, arg = 0x%x\n", __func__, i, coro_arg());
        coro_yield();
        printf("func = %s, f(15 + i) = %d\n", __func__, f(15 + i));
    }
    printf("%s\n", "done.");

    coro_return((void*)10);
}

void part1() {
    printf("Part 1: Coroutines\n");

    coro_glinit();

    coro_init(stack0, sizeof(stack0), &test_fn, (void*)0xDEADBEEF);
    *(uint32_t*)coro_data(stack0) = 0xAAAABEEF;

    for (int i = 0; i < 9; ++i) {
        printf("func = %s\n", __func__);
        coro_resume(stack0);
    }

    int result;
    if (coro_completed(stack0, (void**)&result)) {
        printf("result = %d\n", result);
    } else {
        puts("not completed");
    }
}
