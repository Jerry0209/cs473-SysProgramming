#include <locks.h>
#include <spr.h>
#include <stdint.h>
#include <stdio.h>

void init_locks() {
    uint8_t* locks = (uint8_t*)LOCKS_START_ADDRESS;

    for (int i = 0; i < NR_OF_LOCKS; i++)
        locks[i] = 0;
}

int get_lock(uint32_t lockId) { // Trying to assign given lock [lockId] to current CPU
    if (lockId >= NR_OF_LOCKS)
        return -1;
    uint8_t* locks = (uint8_t*)LOCKS_START_ADDRESS;
    uint8_t res;
    uint8_t cpuId = SPR_READ(9) & 0xF;
    do {
        asm volatile( // Prevent race condition of acquiring a lock
            "l.cas %[out1],%[in1],%[in2],0" :
            [out1] "=r"(res) :
            [in1] "r"(&locks[lockId]),
            [in2] "r"(cpuId)
        );
    } while (res != cpuId); // If the lock is not assigned to current CPU, res != cpuId -> Busy waiting
    return 0;
}

int release_lock(uint32_t lockId) {
    if (lockId >= NR_OF_LOCKS)
        return -1;
    uint8_t* locks = (uint8_t*)LOCKS_START_ADDRESS;
    uint8_t cpuId = SPR_READ(9) & 0xF;
    if (locks[lockId] != cpuId) // If current CPU has the lock which will be released
        return -1;
    locks[lockId] = 0;
    return 0;
}
