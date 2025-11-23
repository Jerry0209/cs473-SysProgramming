#include <stdio.h>
#include <stdint.h>
#include <cache.h>
#include <vga.h>
#include <switches.h>
#include <swap.h>
#include <defs.h>
#include <perf.h>
#include <spr.h>
#include <exception.h>


// Constants describing the output device
#define SCREEN_WIDTH 512   //!< screen width
#define SCREEN_HEIGHT 512  //!< screen height

// SPR definitions
#define SPR_SR              ((0 << 11) | 17)  // Supervision Register
#define SPR_PICMR           ((9 << 11) | 0)   // PIC Mask Register
#define SPR_PICSR           ((9 << 11) | 2)   // PIC Status Register

// Bit definitions for buttons and dip-switches
// #define BIT_SW2             (1 << 6)  // GECKO5: SW1=5, so SW2=6
#define BIT_SW2             0x40000000
#define BIT_DIP1            (1 << 7)  // GECKO5: Dip8=0 (Right), so Dip1=7 (Left)

#define IRQ_DIP        (1 << 2)  // Dip Enable IRQ bit 2
#define IRQ_BTN        (1 << 3)  // Buttons and Joystick Enable IRQ bit 3
#define SR_IEE              (1 << 2)  // Interrupt Exception Enable bit inside SR!! I wrongly set this to 1<<3 before, then it did not work!!

/** switches.h content
 *  #define SWITCHES_BASE_ADDRESS 0x50000080
 *  #define DIP_SWITCH_STATE_ID 0
 *  #define DIP_SWITCH_PRESSED_IRQ_ID 1
 *  #define DIP_SWITCH_RELEASE_IRQ_ID 2
 *  #define BUTTONS_STATE_ID 3
 *  #define BUTTONS_PRESSED_IRQ_ID 4
 *  #define BUTTONS_RELEASE_IRQ_ID 5
 *  #define IRQ_LATENCY_ID 6
 *  #define CLEAR_ALL_IRQ_ID 7
 **/


// Constants describing the initial view port on the fractal function
const uint32_t FRAC_WIDTH = 0x30000000; 
const uint32_t CX_0 = 0xe0000000;       
const uint32_t CY_0 = 0xe8000000;       
const uint16_t N_MAX = 64;              

// global variables indicating the zoom factor and x- and y- offset for the fractal
// uint32_t delta, cxOff, cyOff, redraw;
uint32_t delta, cxOff, cyOff;
volatile uint32_t redraw;
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

/* Interrupt Handlers Declarations */
void buttons_handler(void);
void dipswitch_handler(void);
void joystick_handler(void);

  
int main() {
  icache_write_cfg( CACHE_DIRECT_MAPPED | CACHE_SIZE_8K );
  dcache_write_cfg( CACHE_DIRECT_MAPPED | CACHE_SIZE_8K | CACHE_WRITE_BACK );
  icache_enable(1);
  dcache_enable(1);
  perf_init();

  volatile unsigned int *vga = (unsigned int *) 0X50000020;
  volatile uint32_t *switches = (uint32_t *) SWITCHES_BASE_ADDRESS;

  vga_clear();

  /* Enable the vga-controller's graphic mode */
  vga[0] = swap_u32(SCREEN_WIDTH);
  vga[1] = swap_u32(SCREEN_HEIGHT);
  // vga[3] = swap_u32((unsigned int)&frameBuffer[0]); // disable the vga controller by commenting this line


  /* IMPORTANT: First enable interrupt generation on the switch peripheral itself */
  // The switch peripheral needs to be told to generate interrupts for buttons and dip-switches
  // According to switches.pdf, word index 1 is "Write dip-switch pressed IRQ enable mask" and word index 4 is "Write joystick and buttons pressed IRQ enable mask

  // Enable all dip-switch interrupts
  // switches[DIP_SWITCH_PRESSED_IRQ_ID] = swap_u32(0xFF); // on the GECKO5 board, only the lower 8 bits are available for dip-switches, all others read as 0, but require change from little to big endian

  // Enable all buttons/joystick interrupts
  // switches[BUTTONS_PRESSED_IRQ_ID] = swap_u32(0xFF); // on the GECKO5 board, only the lower 8 bits are available for buttons/joystick, all others read as 0, but require change from little to big endian

  switches[DIP_SWITCH_PRESSED_IRQ_ID] = swap_u32(0x01); // Enable only DIP-switch 1 interrupt
  switches[BUTTONS_PRESSED_IRQ_ID] = swap_u32(0x40); // Enable only Button SW2 interrupt (bit 6)


  
  /* Configure SR and PICMR */
  // 1. Enable External Interrupts in SR (Supervision Register)
  uint32_t sr = SPR_READ(SPR_SR);  // SPR group 0, reg 17
  printf("Current SR: %#x\n", sr); // Read current SR
  sr |= SR_IEE;  // Set IEE bit (3 - IEE: Interrupt Exception Enable)
  SPR_WRITE(SPR_SR, sr); // Write back updated SR
  printf("Updated SR: %#x\n", SPR_READ(SPR_SR));
  
  // 2. Configure PIC mask register (SPR group 0x09, index 0x0)
  uint32_t picmr = SPR_READ(SPR_PICMR);  // SPR group 9, reg 0
  printf("Current PICMR: %#x\n", picmr); // Read current PICMR
  uint32_t pic_mask = IRQ_BTN | IRQ_DIP;  // Enable IRQ 2 (dip-switch) and IRQ 3 (buttons)
  SPR_WRITE(SPR_PICMR, pic_mask); // Write back updated PICMR
  printf("Updated PICMR: %#x\n", SPR_READ(SPR_PICMR)); // It seems that reading back PICMR always returns 0?? But it works anyway

  // now ready to receive external interrupts from buttons and dip-switches
  

  delta = FRAC_WIDTH / SCREEN_WIDTH;
  cxOff = 0;
  cyOff = 0;
  // redraw = 1;

  uint32_t dip_switch_old = 0;
  uint32_t joystick_button_old = 0;
  uint32_t dip_switch_new = 0;
  uint32_t joystick_button_new = 0;
  uint32_t read_clear_dip_switch = 0;

  do {

    /* Polling */

    // dip_switch_new = switches[DIP_SWITCH_STATE_ID];
    // joystick_button_new = switches[BUTTONS_STATE_ID];

    // if (dip_switch_new != dip_switch_old)
    // {
    //   dip_switch_old = dip_switch_new;
    //   printf("%#x\n", swap_u32(dip_switch_new));
    // }

    // if (joystick_button_new != joystick_button_old)
    // {
    //   joystick_button_old = joystick_button_new;
    //   printf("%#x\n", swap_u32(joystick_button_new)); // values from 0x0 to 0x200 (buttons from bit 5 to bit 9, joystick from bit 0 to bit 4, bit 4 is Joystick center = 0x10, bit 5 is SW1 = 0x20)
    // }

    /* Print values directly */
    // printf("%u", dip_switch_new);
    // printf("%#x", dip_switch_new);
    // printf("%#x", joystick_button_new);

    
    /* Orignal redraw */
    // if (redraw == 1) {
    //   redraw = 0;
    // drawFractal(frameBuffer);
    // }

    // --- TASK 2.4 MODIFICATION ---
    if (redraw == 1) {
      // Reset the flag
      redraw = 0; // [cite: 115]
      
      // Measure and print the CPU cycles used for this operation
      // PERF_COUNTER_RUNTIME is a constant from perf.h
      perf_print_cycles(PERF_COUNTER_RUNTIME, "irq runtime"); 
      
      // Execute the fractal drawing
      drawFractal(frameBuffer); 
    }
    // --- TASK 2.4 MODIFICATION END ---


  } while(1);
}


/* External interrupt handler - overrides the weak default from exception.c */
void external_interrupt_handler(void) {
  volatile uint32_t *switches = (uint32_t *) SWITCHES_BASE_ADDRESS;
  
  // Read PIC status to determine which interrupt fired
  uint32_t picsr = SPR_READ(SPR_PICSR); // Read by SPR_READ macro from defs.h, so it's inherent little endian
  printf("PICSR: %#x\n", picsr);
  
  // Check dip-switch interrupt (IRQ 2)
  if (picsr & IRQ_DIP) { // If picsr is 0x4, then IRQ 2 fired
    dipswitch_handler();
    return;
  }
  
  // Check buttons/joystick interrupt (IRQ 3)
  if (picsr & IRQ_BTN) { // If picsr is 0x8, then IRQ 3 fired
    buttons_handler();
    return;
  }
}

void buttons_handler(void) {
  volatile uint32_t *switches = (uint32_t *) SWITCHES_BASE_ADDRESS;

  // Reading the BUTTONS_PRESSED_IRQ_ID clears the interrupt
  uint32_t button_value = switches[BUTTONS_PRESSED_IRQ_ID];
  printf("Button pressed: %#x\n", swap_u32(button_value));
  puts("button handler"); // Output without format and auto new line: button handler\n

  // --- TASK 2.4 START ---
  
  // Read the hardware latency counter
  // This value represents system clock cycles between IRQ generation and clearance [cite: 92]
  uint32_t latency = switches[IRQ_LATENCY_ID];
  
  // Print the latency value in decimal as requested [cite: 94]
  printf("IRQ Latency: %d cycles\n", latency);

  // Trigger the redraw in the main loop to measure CPU runtime 
  redraw = 1;
  
  // --- TASK 2.4 END ---


}

void dipswitch_handler(void) {
  volatile uint32_t *switches = (uint32_t *) SWITCHES_BASE_ADDRESS;

  // Reading the DIP_SWITCH_PRESSED_IRQ_ID clears the interrupt
  uint32_t dip_value = switches[DIP_SWITCH_PRESSED_IRQ_ID];
  printf("DIP-switch pressed: %#x\n", swap_u32(dip_value));
  puts("dipswitch handler");
}

void joystick_handler(void) {
  puts("joystick handler");
}
