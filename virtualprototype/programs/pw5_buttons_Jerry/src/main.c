#include <stdio.h>
#include <stdint.h>
#include <cache.h>
#include <vga.h>
#include <switches.h>
#include <swap.h>
#include <defs.h>
#include <perf.h>

// Constants describing the output device
#define SCREEN_WIDTH 512   //!< screen width
#define SCREEN_HEIGHT 512  //!< screen height

// Constants describing the initial view port on the fractal function
const uint32_t FRAC_WIDTH = 0x30000000; 
const uint32_t CX_0 = 0xe0000000;       
const uint32_t CY_0 = 0xe8000000;       
const uint16_t N_MAX = 64;              

// global variables indicating the zoom factor and x- and y- offset for the fractal
uint32_t delta, cxOff, cyOff, redraw;
uint32_t frameBuffer[(SCREEN_WIDTH * SCREEN_HEIGHT)/2];


void drawFractal(uint32_t *frameBuffer) {
  printf("Starting drawing a fractal\n");
  uint32_t color = (2<<16) | N_MAX;
  uint32_t * pixels = frameBuffer;
  asm volatile ("l.nios_crc r0,%[in1],%[in2],0x21"::[in1]"r"(color),[in2]"r"(delta));
  uint32_t cy = CY_0 + cyOff;
  for (int k = 0 ; k < SCREEN_HEIGHT ; k++) {
    uint32_t cx = CX_0 + cxOff;
    for (int i = 0 ; i < SCREEN_WIDTH ; i+=2) {
      asm volatile ("l.nios_rrr %[out1],%[in1],%[in2],0x20":[out1]"=r"(color):[in1]"r"(cx),[in2]"r"(cy));
      *(pixels++) = color;
      cx += delta << 1;
    }
    cy += delta;
  }
  dcache_flush();
  printf("Done\n");
}

int main() {
  icache_write_cfg( CACHE_DIRECT_MAPPED | CACHE_SIZE_8K );
  dcache_write_cfg( CACHE_DIRECT_MAPPED | CACHE_SIZE_8K | CACHE_WRITE_BACK );
  icache_enable(1);
  dcache_enable(1);
  perf_init();

  volatile unsigned int *vga = (unsigned int *) 0X50000020;

  vga_clear();

  /* Enable the vga-controller's graphic mode */
  vga[0] = swap_u32(SCREEN_WIDTH);
  vga[1] = swap_u32(SCREEN_HEIGHT);
  vga[3] = swap_u32((unsigned int)&frameBuffer[0]); // disable the vga controller by commenting this line

  delta = FRAC_WIDTH / SCREEN_WIDTH;
  cxOff = 0;
  cyOff = 0;
  redraw = 1;

  do {
    if (redraw == 1) {
      redraw = 0;
      drawFractal(frameBuffer);
    }
  } while(1);
}
