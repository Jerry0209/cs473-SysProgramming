#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
typedef int32_t fxpt_4_28;  //!< Q4.28 fixed-point type
typedef int32_t fxpt_8_24;  //!< Q8.24 fixed-point type
typedef int64_t fxpt_8_56;  //!< Q8.56 fixed-point type

//! Colour type (5-bit red, 6-bit green, 5-bit blue)
typedef uint16_t rgb565;

// Constants describing the output device
#define SCREEN_WIDTH 512   //!< screen width
#define SCREEN_HEIGHT 512  //!< screen height

// Constants describing the initial view port on the fractal function
#define FRAC_WIDTH 0x30000000 //!< default fractal width (3.0 in Q4.28)
#define CX_0 0xe0000000       //!< default start x-coordinate (-2.0 in Q4.28)
#define CY_0 0xe8000000       //!< default start y-coordinate (-1.5 in Q4.28)
#define N_MAX 64              //!< maximum number of iterations

#endif // MAIN_H
