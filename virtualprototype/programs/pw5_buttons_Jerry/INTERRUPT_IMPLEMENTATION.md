# External Interrupt Implementation for Buttons and DIP-Switches

## Overview
This document explains the interrupt-driven implementation for handling SW2 button press and DIP-switch changes on the GECKO5Education board.

## Key Concepts

### 1. SR (Supervision Register) Configuration
The SR register is at SPR address **0x11000** in the OpenRISC architecture.

**Bit 3 - EIE (External Interrupt Enable):**
- Must be set to **1** to enable external interrupts
- When set, the CPU will respond to external interrupt signals

**Code:**
```c
uint32_t sr = SPR_READ(0x11000);  // Read current SR value
sr |= (1 << 3);                   // Set bit 3 (EIE)
SPR_WRITE(0x11000, sr);           // Write back to SR
```

### 2. PIC (Programmable Interrupt Controller) Mask Register
The PIC mask register is at SPR address **0x09000**.

**Interrupt Source Mapping:**
- **Bit 0**: DIP-Switch IRQ
- **Bit 1**: Buttons (SW1-SW5) IRQ
- **Bit 2**: Joystick IRQ

**Code:**
```c
uint32_t pic_mask = (1 << 1) | (1 << 0);  // Enable DIP-switch and Buttons
SPR_WRITE(0x09000, pic_mask);
```

This enables the physical interrupt lines on the PIC controller, allowing interrupts to propagate to the CPU.

### 3. External Interrupt Handler
The external interrupt handler is called when an external interrupt occurs. The handler must:

1. **Determine the interrupt source** by checking the IRQ registers
2. **Call the appropriate handler** based on the source
3. **Clear the interrupt** by reading the IRQ register

**Implementation:**
```c
void external_interrupt_handler(void) {
  volatile uint32_t *switches = (uint32_t *) SWITCHES_BASE_ADDRESS;
  
  // Check buttons first
  uint32_t buttons_irq = switches[BUTTONS_PRESSED_IRQ_ID];
  if (buttons_irq) {
    buttons_handler();
    return;
  }
  
  // Check dip-switches
  uint32_t dip_switch_irq = switches[DIP_SWITCH_PRESSED_IRQ_ID];
  if (dip_switch_irq) {
    dipswitch_handler();
    return;
  }
  
  // Check joystick
  joystick_handler();
}
```

### 4. Individual Interrupt Handlers

#### buttons_handler()
- Reads from `BUTTONS_PRESSED_IRQ_ID` register (index 4)
- Reading this register **automatically clears** the interrupt
- Outputs "button handler" text

```c
void buttons_handler(void) {
  volatile uint32_t *switches = (uint32_t *) SWITCHES_BASE_ADDRESS;
  uint32_t button_value = switches[BUTTONS_PRESSED_IRQ_ID];  // Read and clear
  puts("button handler");
}
```

#### dipswitch_handler()
- Reads from `DIP_SWITCH_PRESSED_IRQ_ID` register (index 1)
- Reading this register **automatically clears** the interrupt
- Outputs "dipswitch handler" text

```c
void dipswitch_handler(void) {
  volatile uint32_t *switches = (uint32_t *) SWITCHES_BASE_ADDRESS;
  uint32_t dip_value = switches[DIP_SWITCH_PRESSED_IRQ_ID];  // Read and clear
  puts("dipswitch handler");
}
```

#### joystick_handler()
- Can be extended to handle joystick interrupts
- Currently just outputs "joystick handler" text

```c
void joystick_handler(void) {
  puts("joystick handler");
}
```

## Register Definitions (from switches.h)

```c
#define SWITCHES_BASE_ADDRESS 0x50000080
#define DIP_SWITCH_STATE_ID 0              // Read current DIP-switch state
#define DIP_SWITCH_PRESSED_IRQ_ID 1        // DIP-switch press IRQ (read to clear)
#define DIP_SWITCH_RELEASE_IRQ_ID 2        // DIP-switch release IRQ
#define BUTTONS_STATE_ID 3                 // Read current button state
#define BUTTONS_PRESSED_IRQ_ID 4           // Button press IRQ (read to clear)
#define BUTTONS_RELEASE_IRQ_ID 5           // Button release IRQ
#define IRQ_LATENCY_ID 6
#define CLEAR_ALL_IRQ_ID 7
```

## SPR (Special Purpose Register) Macros (from spr.h)

The SPR macros from `spr.h` are used to read/write special purpose registers:

```c
// Read a 16-bit SPR address
#define SPR_READ(id) ({
    uint32_t r;
    asm volatile("l.mfspr %[out1],r0," STRINGIZE(id) : [out1] "=r"(r) :);
    r;
})

// Write to a 16-bit SPR address
#define SPR_WRITE(id, r)
    asm volatile("l.mtspr r0,%[in1]," STRINGIZE(id)::[in1] "r"(r))
```

## Execution Flow

1. **Initialization:**
   - Enable SR.EIE bit (external interrupts enabled)
   - Configure PIC mask to enable buttons and DIP-switch IRQ lines

2. **At Runtime:**
   - When user presses SW2 or sets DIP-switch 1, an interrupt occurs
   - CPU suspends current work and calls `external_interrupt_handler()`
   - Handler determines interrupt source and calls appropriate handler
   - Reading the IRQ register clears the interrupt
   - Program outputs "button handler" or "dipswitch handler"
   - CPU resumes normal execution

3. **Result:**
   - No more infinite "ping" messages (the weak default handler is overridden)
   - Efficient interrupt-driven behavior instead of inefficient polling

## Expected Output

When pressing SW2:
```
button handler
```

When setting DIP-switch 1:
```
dipswitch handler
```

## Key Advantages Over Polling

1. **CPU Efficiency**: CPU is not wasting cycles checking for changes
2. **Responsiveness**: Immediate reaction to input changes
3. **Lower Latency**: No delay waiting for next polling cycle
4. **Lower Power**: CPU can enter idle/sleep states between interrupts
