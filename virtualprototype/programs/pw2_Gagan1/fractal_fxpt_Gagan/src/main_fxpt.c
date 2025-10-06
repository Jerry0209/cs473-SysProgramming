#include "fractal_fxpt.h"
#include <stddef.h>
#include <stdio.h>

#ifdef __OR1300__
#include "vga.h"
#include "cache.h"
#endif

//! screen width
const int SCREEN_WIDTH = 512;
//! screen height
const int SCREEN_HEIGHT = 512;
//! maximum number of iterations
const uint16_t N_MAX = 64;

int main() {
    volatile unsigned int *vga = (unsigned int *)0x50000020;
    volatile unsigned int reg, hi;
    rgb565 frameBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];
    
    int i;
    
#ifdef __OR1300__
    vga_clear();
#endif
    
    printf("Starting drawing a fractal (fixed-point version)\n");
    
#ifdef __OR1300__
    icache_write_cfg(CACHE_DIRECT_MAPPED | CACHE_SIZE_8K | CACHE_REPLACE_FIFO);
    dcache_write_cfg(CACHE_FOUR_WAY | CACHE_SIZE_8K | CACHE_REPLACE_LRU | CACHE_WRITE_BACK);
    icache_enable(1);
    dcache_enable(1);
    
    vga[0] = swap_u32(SCREEN_WIDTH);
    vga[1] = swap_u32(SCREEN_HEIGHT);
    vga[2] = swap_u32(1);
    vga[3] = swap_u32((unsigned int)&frameBuffer[0]);
#endif
    
    for (i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        frameBuffer[i] = 0;
    }
    
    draw_fractal(frameBuffer, SCREEN_WIDTH, SCREEN_HEIGHT, 
                 &calc_mandelbrot_point_soft, &iter_to_colour, 
                 CX_0_FP, CY_0_FP, DELTA_FP, N_MAX);
    
#ifdef __OR1300__
    dcache_flush();
#endif
    
    printf("Done\n");
    
    return 0;
}