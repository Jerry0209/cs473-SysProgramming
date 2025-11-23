#include <stdio.h>
#include <stddef.h>
#include <cache.h>
#include <perf.h>
#include <vga.h>
#include <swap.h>
#include <defs.h>
#include <dma.h>
#include <string.h>
#include "fractal_fxpt.h"

// #define __REALLY_FAST__

// Define DMA Burst Size (Change this to 255, 63, or 15 for experiments)
#define BURST_SIZE 255

rgb565 frameBuffer[SCREEN_WIDTH*SCREEN_HEIGHT]; //! frame buffer for the VGA controller, stored each pixel as rgb565



int main() {
   volatile unsigned int *vga = (unsigned int *) 0X50000020; // vga controller base address
   volatile unsigned int reg, hi;

   /* DMA CONFIGURATION (STATIC PART) */
   volatile uint32_t *dma = (uint32_t *) DMA_BASE_ADDRESS;
   printf("Current Burst Size: %#x\n", BURST_SIZE);

   // 1. Set Source Address (SPM Address: 0xC0000000)
   // volatile uint32_t *spm_buffer = (uint32_t *) swap_u32(dma[SPM_ADDRESS_ID]); // dma[SPM_ADDRESS_ID] = 0xC0, big endian
   volatile uint32_t *spm_buffer = (uint32_t *) 0xC0000000;
   dma[SPM_ADDRESS_ID] = swap_u32((uint32_t) spm_buffer); 
   printf("Start address in the SPM-space: %#x\n", swap_u32(dma[SPM_ADDRESS_ID]));
   printf("Start address in the MEM-space: %#x\n", swap_u32(dma[MEMORY_ADDRESS_ID]));


   // 2. Set Buffer Size (Transfer size)
   uint32_t spm_buffer_size = SCREEN_WIDTH * 2 / 4; // in words (4 bytes), 512 * 2 / 4 = 256 words
   dma[TRANSFER_SIZE_ID] = swap_u32(spm_buffer_size - 1);
   printf("Transfer size: %#x\n", swap_u32(dma[TRANSFER_SIZE_ID]));
   // printf("Status: %#x\n", swap_u32(dma[START_STATUS_ID]));



   uint32_t *pixel;

   perf_init();
   perf_set_mask(PERF_COUNTER_0, PERF_ICACHE_NOP_INSERTION_MASK | PERF_STALL_CYCLES_MASK);
   perf_set_mask(PERF_COUNTER_1, PERF_BUS_IDLE_MASK);
   perf_set_mask(PERF_COUNTER_2, PERF_ICACHE_MISS_MASK);
   perf_set_mask(PERF_COUNTER_3, PERF_DCACHE_MISS_MASK);

   vga_clear();
   printf("Starting drawing a fractal\n");
   fxpt_4_28 delta = FRAC_WIDTH / SCREEN_WIDTH;

   /* enable the caches */
   icache_write_cfg( CACHE_FOUR_WAY | CACHE_SIZE_8K | CACHE_REPLACE_LRU );
   dcache_write_cfg( CACHE_DIRECT_MAPPED | CACHE_SIZE_8K | CACHE_WRITE_BACK);
   icache_enable(1);
   dcache_enable(1);

   /* Enable the vga-controller's graphic mode */
   vga[0] = swap_u32(SCREEN_WIDTH);
   vga[1] = swap_u32(SCREEN_HEIGHT);
   vga[3] = swap_u32( (unsigned int) &frameBuffer[0] ); // set frame buffer address, VGA gets data from memory
   

   /* Clear screen */
   for (int i = 0 ; i < SCREEN_WIDTH*SCREEN_HEIGHT ; i++) frameBuffer[i]=0;

   


   perf_start();
#ifdef __REALLY_FAST__
   int color = (2<<16) | N_MAX;
   asm volatile ("l.nios_crc r0,%[in1],%[in2],0x21"::[in1]"r"(color),[in2]"r"(delta)); // custom hardware instruction to set up the hardware accelerator
   // pixel = (uint32_t *)frameBuffer;


   fxpt_4_28 cy = CY_0;
   for (int k = 0 ; k < SCREEN_HEIGHT ; k++) {
     fxpt_4_28 cx = CX_0;
     for (int i = 0 ; i < SCREEN_WIDTH ; i+=2) { // process two pixels at a time
       asm volatile ("l.nios_rrr %[out1],%[in1],%[in2],0x20":[out1]"=r"(color):[in1]"r"(cx),[in2]"r"(cy));
      //  *(pixel++) = color;

       // Write 32-bit word (2 pixels) to SPM
       spm_buffer[i >> 1] = color; 
       cx += delta << 1;
     }

      /* DMA TRANSFER START */

      // 3. Set Destination Address (Main Memory Address for the current line)
      dma[MEMORY_ADDRESS_ID] = swap_u32((uint32_t) &frameBuffer[k * SCREEN_WIDTH]);
      // printf("Updated Start address in the MEM-space: %#x\n", swap_u32(dma[MEMORY_ADDRESS_ID]));

      // 4. Start Transfer
      // Bit 8 = 1 (Start SPM -> Mem)
      // Bits 7..0 = Burst Size
      dma[START_STATUS_ID] = swap_u32((1 << 8) | BURST_SIZE);
      // printf("Current Status: %#x\n", swap_u32(dma[START_STATUS_ID]));

      // 5. Poll until finished (Bit 0 is '1' if busy)
      while (swap_u32(dma[START_STATUS_ID]) & 1) {
         // Wait for DMA...
      }

     

     cy += delta;
   }
#else
   draw_fractal(frameBuffer,SCREEN_WIDTH,SCREEN_HEIGHT,&calc_mandelbrot_point_soft, &iter_to_colour,CX_0,CY_0,delta,N_MAX);
#endif
   dcache_flush(); // flush the data cache to make sure VGA controller get the latest data
   asm volatile ("l.lwz %[out1],0(%[in1])":[out1]"=r"(pixel):[in1]"r"(frameBuffer)); // dummy instruction to wait for the flush to be finished
   perf_stop();

   printf("Done\n");
   perf_print_cycles( PERF_COUNTER_2 , "I$ misses" );
   perf_print_cycles( PERF_COUNTER_3 , "D$ misses" );
   perf_print_cycles( PERF_COUNTER_0 , "Stall cycles" );
   perf_print_cycles( PERF_COUNTER_1 , "Bus idle cycles" );
   perf_print_cycles( PERF_COUNTER_RUNTIME , "Runtime cycles" );
}
