#include <assert.h>
#include <coro/coro.h>
#include <defs.h>

/**
 * @brief Switches to the coroutine designated by the stack.
 *
 * @param sp
 */
void coro__switch(void* sp, void** old_sp);

struct coro_data {
    /** @brief Task stack pointer. */
    void* coro_sp;

    /** @brief Caller stack pointer. */
    void* caller_sp;

    /** @brief Argument to the corutine. */
    void* arg;

    /** @brief 0 if coro is not complete, 1 otherwise. */
    int complete;

    /** @brief Task completion result. */
    void* result;
};

#include <stdio.h>

/**
 * @brief Returns a pointer to the currently executed coro.
 * @note R10 (Thread-local storage register) keeps a pointer to the current coro.
 *
 * @return struct coro_coro*
 */
#define CORO_SELF() ({                                           \
    struct coro_data* result;                                    \
    asm volatile("l.or %[out1],r0,r10" : [out1] "=r"(result) :); \
    result;                                                      \
})

#define CORO_SET_SELF(self) \
    asm volatile("l.or r10,r0,%[in1]" ::[in1] "r"(self))

void coro_init(void* stack, size_t stack_sz, coro_fn_t coro_fn, void* arg) {
    die_if_not_f(
        stack_sz >= sizeof(struct coro_data*) + 48,
        "stack size is too small minimum recommended: 64 bytes for a 32-bit processor."
    );

    struct coro_data* coro = (struct coro_data*)stack;

    /* layout: coro info + stack */
    uint32_t* coro_sp = (uint32_t*)((uint8_t*)stack + stack_sz);
    coro_sp -= 12;

    coro->complete = 0;
    coro->result = NULL;

    coro->arg = arg;

    coro->coro_sp = coro_sp;
    coro->caller_sp = NULL;

    *coro_sp = (uint32_t)coro_fn; /* LR */
}

void __no_optimize coro_resume(void* p) {
    die_if_not(p != NULL);
    struct coro_data* coro = (struct coro_data*)p;

    struct coro_data* self = CORO_SELF();
    die_if_not_f(self == NULL, "coro_resume shall not be called from a coro!");

    if (coro->complete)
        /* coro is complete, no need to continue */
        return;

    CORO_SET_SELF(coro);
    coro__switch(coro->coro_sp, &coro->caller_sp);
    CORO_SET_SELF(NULL);
}

void __no_optimize coro_yield() {
    struct coro_data* self = CORO_SELF();
    die_if_not_f(self != NULL, "coro_yield() shall be called from a coro!");

    coro__switch(self->caller_sp, &self->coro_sp);
}

void __no_optimize coro_return(void* result) {
    struct coro_data* self = CORO_SELF();
    die_if_not_f(self != NULL, "coro_return() shall be called from a coro!");

    self->complete = 1;
    self->result = result;

    coro_yield();
}

void* __no_optimize coro_arg() {
    struct coro_data* self = CORO_SELF();
    die_if_not_f(self != NULL, "coro_arg() shall be called from a coro!");

    return self->arg;
}

void* __no_optimize coro_data(void* stack) {
    if (stack == NULL) {
        struct coro_data* self = CORO_SELF();
        die_if_not_f(self != NULL, "coro_data(NULL) shall be called from a coro!");

        stack = (void*)self;
    }

    return (void*)(1 + (struct coro_data*)stack);
}

int __no_optimize coro_completed(void* p, void** result) {
    die_if_not(p != NULL);
    struct coro_data* coro = (struct coro_data*)p;

    if (!coro->complete)
        return 0;

    if (result != NULL)
        *result = coro->result;

    return 1;
}

void* __no_optimize coro_stack() {
    return CORO_SELF();
}
