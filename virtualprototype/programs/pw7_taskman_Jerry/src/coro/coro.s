.global coro_glinit # Export global label
.global coro__switch # Export global label

coro_glinit:
    l.jr r9 # Return to caller
    l.or r10, r0, r0 # Initialize r10 to zero

# Note: in the switch routine, we do not need to save
# all the registers, because stackful coroutines are
# not preemptive. Preemptive context switching requires
# all registers to be properly saved.

coro__switch:
    # r1: SP (Stack Pointer)
    # r9: LR (Link Register)
    # r3: void *sp, r4: void **old_sp

    # step 1: save the current coroutine context
    l.addi r1, r1, -0x2C # Allocate 44 bytes on stack, r1 is the Stack Pointer (of main) of current stack (when this function being called)

    l.sw 0x00(r4), r1 # sw, store single word, Store current SP to old_sp pointer, content of r1 --> (EA) = (content of r4, old_sp + 0), put caller_sp, i.e. current stack pointer
    l.sw 0x00(r1), r9 # Save LR (return address), the next line after the coro__switch function

    Here are a few ways to translate the comment, focusing on clarity and technical accuracy:

    # Callee-saved registers are the callee's responsibility to save/restore. Save them to the coroutine context allocated in step [number/name].
    # note that we do not need to save:
    # r1 (SP), r10 (TLS)
    l.sw 0x04(r1), r2 # Save r2
    l.sw 0x08(r1), r14 # Save r14
    l.sw 0x0C(r1), r16 # Save r16
    l.sw 0x10(r1), r18 # Save r18
    l.sw 0x14(r1), r20 # Save r20
    l.sw 0x18(r1), r22 # Save r22
    l.sw 0x1C(r1), r24 # Save r24
    l.sw 0x20(r1), r26 # Save r26
    l.sw 0x24(r1), r28 # Save r28
    
    # r30
    l.sw 0x28(r1), r30 # Save r30

    # the supervisor register (overflow flags, etc.)
    l.mfspr r30, r0, 17 # Read supervisor status register
    l.sw 0x2C(r1), r30 # Save supervisor register

    # other registers shall be saved by the caller

    # now, restore the other context (for each coroutine, those data are stored above (after) coro_data struct)
    l.or r1, r3, r3 # Load new SP from r3, load new stack pointer to r1
    l.lwz r9, 0x00(r1) # Restore LR, func_coro

    # callee-saved registers, read values from new stack of new coroutine
    l.lwz r2, 0x04(r1) # Restore r2
    l.lwz r14, 0x08(r1) # Restore r14
    l.lwz r16, 0x0C(r1) # Restore r16
    l.lwz r18, 0x10(r1) # Restore r18
    l.lwz r20, 0x14(r1) # Restore r20
    l.lwz r22, 0x18(r1) # Restore r22
    l.lwz r24, 0x1C(r1) # Restore r24
    l.lwz r26, 0x20(r1) # Restore r26
    l.lwz r28, 0x24(r1) # Restore r28

    # the supervisor register
    l.lwz r30, 0x2C(r1) # Restore supervisor register
    l.ori r30, r30, 0x04 # Enable interrupts (set bit)

    # r30
    l.mtspr r0, r30, 17 # Write supervisor status register

    l.lwz r30, 0x28(r1) # Restore r30

    # jump to the routine
    l.jr r9 # Jump to restored return address
    l.addi r1, r1, 0x2C # Deallocate stack (delay slot), destroy the stack of current routine, whose register values have been restored

    # This involves a low-level hardware concept: the **Delay Slot**.
    # The pipeline design of OpenRISC (and architectures like MIPS) dictates that: the instruction immediately following a jump instruction will be executed **before** (or concurrently with) the jump actually taking effect.
    # Therefore, the physical execution order is as follows:
    # 1. The CPU encounters the **jump** instruction and begins preparation for the jump.
    # 2. In the gap before the jump completes, the CPU executes the following **l.addi** instruction.
    # 3. The CPU lands, arriving at the new address pointed to by **r9**.
    # 3. What exactly is this **addi** instruction doing?
