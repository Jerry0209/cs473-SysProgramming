#include <coro/coro.h>
#include <defs.h>
#include <stdio.h>

__global static char stack0[1024]; // Stack for the coroutine

static int f(int x) {
    printf("func = %s, x = %d\n", __func__, x); // Print function name and argument
    coro_yield();
    return 60 + x;
}

static void test_fn() {
    printf("func = %s, data = 0x%x\n", __func__, *(uint32_t*)coro_data(NULL)); // Print register data of current coroutine

    /* what happens if we use the return keyword in a coroutine? */ 
    for (int i = 0; i < 4; ++i) {
        printf("func = %s, i = %d, arg = 0x%x\n", __func__, i, coro_arg()); // Current argument of coroutine
        coro_yield(); // Running main
        printf("func = %s, f(15 + i) = %d\n", __func__, f(15 + i));
    }
    printf("%s\n", "done.");

    coro_return((void*)10);
}

void part1() {
    printf("Part 1: Coroutines\n");

    coro_glinit(); // Initialize global coroutine context, clear r10 and then execute next line

    // Pass the stack to be allocated to the coroutine, along with its size, the function to execute, and an argument
    coro_init(stack0, sizeof(stack0), &test_fn, (void*)0xDEADBEEF);

    // Set data in current coroutine area (private, not coro_data struct, but the area after it)
    *(uint32_t*)coro_data(stack0) = 0xAAAABEEF; // Configure register values in stack

    for (int i = 0; i < 9; ++i) {
        printf("func = %s\n", __func__);
        coro_resume(stack0); // Store current state and then execute test_fn
    }

    int result;
    if (coro_completed(stack0, (void**)&result)) { // the address of result become void **, which is the address of an address
        // *(&result) = int result, but this can hold a pointer (the return value from is a pointer
        // the value of this pointer represents the result)
        printf("result = %d\n", result);
    } else {
        puts("not completed");
    }
}


