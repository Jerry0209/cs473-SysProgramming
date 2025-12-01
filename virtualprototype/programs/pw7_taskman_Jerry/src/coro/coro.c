#include <assert.h>
#include <coro/coro.h>
#include <defs.h>

/**
 * @brief Switches to the coroutine designated by the stack.
 *
 * @param sp
 */
void coro__switch(void* sp, void** old_sp); // Defined in coro.s

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

 // It creates a new "result" variable to hold the value of the current coroutine data structure.
 // The current pointer to the coroutine data structure is stored in register r10
 // The address in r10 is stored by CORO_SET_SELF macro.
 // 将当前的 coro_data 结构体的指针存储在 r10 寄存器中。
#define CORO_SELF() ({                                           \
    struct coro_data* result;                                    \
    asm volatile("l.or %[out1],r0,r10" : [out1] "=r"(result) :); \
    result;                                                      \
})

#define CORO_SET_SELF(self) \
    asm volatile("l.or r10,r0,%[in1]" ::[in1] "r"(self))

void coro_init(void* stack, size_t stack_sz, coro_fn_t coro_fn, void* arg) {

    // 
    die_if_not_f(
        stack_sz >= sizeof(struct coro_data*) + 48, // Why 48?
        "stack size is too small minimum recommended: 64 bytes for a 32-bit processor."
    );

    struct coro_data* coro = (struct coro_data*)stack; // Turn stack pointer into coro data pointer

    /* layout: coro info + stack */
    // Task stack pointer is at the top of the allocated stack (High memory address)
    uint32_t* coro_sp = (uint32_t*)((uint8_t*)stack + stack_sz); // point to top of stack, current stack pointer is at high address, which is stack top
    coro_sp -= 12; // 假设保存了 12 个当前寄存器的值

    /* initialize coro data */
    coro->complete = 0; // Not complete yet
    coro->result = NULL; 

    coro->arg = arg;

    coro->coro_sp = coro_sp; // Set the coro stack pointer to the calculated stack pointer
    coro->caller_sp = NULL;

    *coro_sp = (uint32_t)coro_fn; /* LR */ 
    // 2. (uint32_t)coro_fn是什么意思？
    // coro_fn 是一个函数指针，类型是 coro_fn_t。
    // (uint32_t)coro_fn 把这个函数指针强制转换成一个 32 位整数地址，也就是函数在内存中的入口地址。
    // 然后这行代码：
    // C*coro_sp = (uint32_t)coro_fn; /* LR */Show more lines
    // 把这个地址写到 coro_sp 指向的位置，相当于把协程函数的地址放在栈上，模拟 ARM 架构中的 LR（Link Register），也就是返回地址寄存器。
    // 当协程开始运行时，CPU 会“返回”到这个地址，从而跳转到 coro_fn 执行。
    // Put this function on the top of the stack
    // When program starts this coroutine, jump to coro_fn as if it were the return address.
}

void __no_optimize coro_resume(void* p) { // Address of the coro stack

    die_if_not(p != NULL);
    struct coro_data* coro = (struct coro_data*)p; // Turn stack pointer into coro data pointer

    struct coro_data* self = CORO_SELF(); // Get the currently executed coro
    die_if_not_f(self == NULL, "coro_resume shall not be called from a coro!");
    // 这行代码的意思是：“只允许主程序（光杆司令）去启动协程，不允许协程自己去启动另一个协程。”
	// 如果 self 是 0 (NULL)，说明调用者是主程序 -> 检查通过 (Pass)。
    // 如果 self 不是 0，说明调用者是某个正在运行的协程 -> 报错 (Fail)。

    if (coro->complete)
        /* coro is complete, no need to continue */
        return;

    CORO_SET_SELF(coro); // Set the private coro pointer to the coro being resumed
    coro__switch(coro->coro_sp, &coro->caller_sp); // execute coro_sp = coro_func, Arg: coro->coro_sp in r3, &coro->caller_sp in r4
    // &coro->caller_sp 存储 caller_sp (这个地址)的地址
    CORO_SET_SELF(NULL);
}

void __no_optimize coro_yield() { // Gives control back to the caller of coro_resume
    struct coro_data* self = CORO_SELF(); // Get the currently executed coro
    die_if_not_f(self != NULL, "coro_yield() shall be called from a coro!");
    // die if (self != NULL) not satisfy -> self != NULL should be held!

    coro__switch(self->caller_sp, &self->coro_sp); // Continue running main, store the current state of current subroutine
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
        struct coro_data* self = CORO_SELF(); // Current coro_data, restored from r10
        die_if_not_f(self != NULL, "coro_data(NULL) shall be called from a coro!");

        stack = (void*)self; 
    }

    // If stack is not NULL, it points to the coro data area, not struct coro_data itself.
    return (void*)(1 + (struct coro_data*)stack);
}

int __no_optimize coro_completed(void* p, void** result) {
    die_if_not(p != NULL);
    struct coro_data* coro = (struct coro_data*)p;

    if (!coro->complete)
        return 0;

    if (result != NULL)
        *result = coro->result; // *result stores a pointer

    return 1;
}

void* __no_optimize coro_stack() {
    return CORO_SELF();
}
