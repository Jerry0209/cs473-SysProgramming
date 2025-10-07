#include "fractal_fxpt.h"
#include "swap.h"
#include "vga.h"
#include <stddef.h>
#include <stdio.h>
#ifdef __OR1300__
#include "perf.h"
#include "cache.h"
#endif

// Constants describing the output device
#define SCREEN_WIDTH 512  //!< screen width
#define SCREEN_HEIGHT 512  //!< screen height

// Constants describing the initial view port on the fractal function
const fxpt_4_28 FRAC_WIDTH = 0x30000000; //!< default fractal width (3.0 in Q4.28)
const fxpt_4_28 CX_0 = 0xe0000000;       //!< default start x-coordinate (-2.0 in Q4.28)
const fxpt_4_28 CY_0 = 0xe8000000;       //!< default start y-coordinate (-1.5 in Q4.28)
const rgb565 N_MAX = 64;                 //!< maximum number of iterations

volatile rgb565 frameBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

int main() {
   volatile unsigned int *vga = (unsigned int *) 0X50000020;
   volatile unsigned int reg, hi;
   fxpt_4_28 delta = FRAC_WIDTH / SCREEN_WIDTH;
   int i;
   vga_clear();
   printf("Starting drawing a fractal\n");
#ifdef __OR1300__   
   /* enable the caches */
   icache_write_cfg( CACHE_DIRECT_MAPPED | CACHE_SIZE_8K | CACHE_REPLACE_FIFO );
   dcache_write_cfg( CACHE_FOUR_WAY | CACHE_SIZE_8K | CACHE_REPLACE_LRU | CACHE_WRITE_BACK );
   icache_enable(1);
   dcache_enable(1);
   /* initialize the performance counters */
   perf_init();
   perf_set_mask(PERF_COUNTER_0, PERF_STALL_CYCLES_MASK | PERF_ICACHE_NOP_INSERTION_MASK);
   perf_set_mask(PERF_COUNTER_1, PERF_BUS_IDLE_MASK);
   perf_memdist_set(0);
#endif
   /* Enable the vga-controller's graphic mode */
   vga[0] = swap_u32(SCREEN_WIDTH);
   vga[1] = swap_u32(SCREEN_HEIGHT);
   vga[2] = swap_u32(1);
   vga[3] = swap_u32((unsigned int)&frameBuffer[0]);
   /* Clear screen */
   for (i = 0 ; i < SCREEN_WIDTH*SCREEN_HEIGHT ; i++) frameBuffer[i]=0;
#ifdef __OR1300__   
   perf_start();
#endif
   draw_fractal(frameBuffer,SCREEN_WIDTH,SCREEN_HEIGHT,&calc_mandelbrot_point_soft, &iter_to_colour,CX_0,CY_0,delta,N_MAX);
#ifdef __OR1300__
   perf_stop();   
   printf("Done\n");
   perf_print_cycles(PERF_COUNTER_0, "Stall cycles    ");
   perf_print_cycles(PERF_COUNTER_1, "Bus idle cycles ");
   perf_print_cycles(PERF_COUNTER_RUNTIME, "Runtime cycles  ");
   perf_print_time(PERF_COUNTER_0, "Stall time    ");
   perf_print_time(PERF_COUNTER_1, "Bus idle time ");
   perf_print_time(PERF_COUNTER_RUNTIME, "Runtime      ");
   dcache_flush();
#endif
}
