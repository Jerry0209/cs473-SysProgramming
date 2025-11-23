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

   // DMA
   volatile uint32_t *dma = (uint32_t *) DMA_BASE_ADDRESS;
   volatile uint32_t *spm_buffer = (uint32_t *) dma[SPM_ADDRESS_ID];

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
   vga[3] = swap_u32( (unsigned int) &frameBuffer[0] ); // set frame buffer address
   // VGA gets data from memory
   
   /* Clear screen */
   for (int i = 0 ; i < SCREEN_WIDTH*SCREEN_HEIGHT ; i++) frameBuffer[i]=0;

   printf("Start address in the SPM-space: %#x\n", dma[SPM_ADDRESS_ID]);
   printf("Start address in the MEM-space: %#x\n", dma[MEMORY_ADDRESS_ID]);
   printf("Transfer size: %#x\n", dma[TRANSFER_SIZE_ID]);
   printf("Status: %#x\n", dma[START_STATUS_ID]);

   uint32_t spm_buffer_size = SCREEN_WIDTH * 2 / 4; // in words (4 bytes), 512 * 2 / 4 = 256 words, 
   dma[START_STATUS_ID] = spm_buffer_size - 1; // set transfer size
   printf("Current Status: %#x\n", dma[START_STATUS_ID]);


   perf_start();
#ifdef __REALLY_FAST__
   int color = (2<<16) | N_MAX;
   asm volatile ("l.nios_crc r0,%[in1],%[in2],0x21"::[in1]"r"(color),[in2]"r"(delta)); // custom hardware instruction to set up the hardware accelerator
   pixel = (uint32_t *)frameBuffer;
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

     // --- Start DMA Transfer for the completed line ---
     
     // 1. Set Source Address (SPM Address: 0xC0000000) [cite: 86, 108]
     // Word offset 1 corresponds to SPM-address register
     dma[1] = (uint32_t) spm_buffer; 

     // 2. Set Destination Address (Main Memory Address) [cite: 86]
     // Word offset 0 corresponds to Memory address register
     // Calculate address of the current line k in frameBuffer
     dma[0] = (uint32_t) &frameBuffer[k * SCREEN_WIDTH];

     // 3. Set Buffer Size [cite: 86]
     // Size is in 32-bit words. 512 pixels * 2 bytes / 4 bytes = 256 words.
     dma[2] = 256; 

     // 4. Start Transfer [cite: 88]
     // Word offset 3 is Control. 
     // Bit 8 = 1 (Start SPM->Mem). Bits 7..0 = Burst Size.
     dma[3] = (1 << 8) | BURST_SIZE;

     // 5. Poll until finished [cite: 96]
     // Bit 0 of status register (offset 3) is 1 if busy.
     while (dma[3] & 1) {
        // Wait for DMA to finish this line before overwriting SPM in next loop
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
