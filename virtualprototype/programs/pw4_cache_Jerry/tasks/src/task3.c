#include <cache.h>
#include <defs.h>
#include <perf.h>
#include <stdio.h>
#include <task3.h>

#define MATRIX_N 256

typedef int32_t elem_t;

// identity matrix
static elem_t (*matrix)[MATRIX_N];

// input vector
static elem_t in_vector[MATRIX_N];

// output vector
static elem_t out_vector[MATRIX_N];

static void init() {
    // YOU ARE NOT SUPPOSED TO MODIFY THIS.

    // matrix is huge, it bloats the executable size.
    // for that reason, place it dynamically.
    matrix = (elem_t(*)[MATRIX_N])0x01000000;

    // the matrix is the identity matrix
    for (size_t i = 0; i < MATRIX_N; ++i) {
        for (size_t j = 0; j < MATRIX_N; ++j) {
            matrix[i][j] = (i == j);
        }
    }

    // the input vector is linearly increasing
    for (size_t i = 0; i < MATRIX_N; ++i) {
        in_vector[i] = i;
    }

    // the output vector is all zeros (for now)
    for (size_t i = 0; i < MATRIX_N; ++i) {
        out_vector[i] = 0;
    }
}

/**
 * @brief Multiplies the matrix with the input vector.
 * Writes to the output vector.
 */
static void multiply() {
    // YOU CAN MODIFY THIS.

    for (int j = 0; j < MATRIX_N; ++j) {
        for (int i = 0; i < MATRIX_N; ++i) {
            out_vector[i] += matrix[i][j] * in_vector[j];
        }
    }
}

static void verify() {
    // YOU ARE NOT SUPPOSED TO MODIFY THIS.

    for (int i = 0; i < MATRIX_N; ++i) {
        if (in_vector[i] != out_vector[i]) {
            printf(
                "out_vector verification failed at i = %d, %ld != %ld!\n",
                i, in_vector[i], out_vector[i]
            );
            return;
        }
    }

    printf("out_vector verification successful!\n");
}

void task3_main() {
    puts(__func__);

    init();

    dcache_flush();

    perf_start();
    multiply();
    perf_stop();

    printf(
        "Task 3: dcache misses: %10lld\n",
        perf_read_counter(PERF_COUNTER_0)
    );

    verify();
}
