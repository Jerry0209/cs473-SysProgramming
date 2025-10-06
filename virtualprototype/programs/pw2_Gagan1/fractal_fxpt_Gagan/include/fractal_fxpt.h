#ifndef FRACTAL_FXPT_H
#define FRACTAL_FXPT_H

#include <stdint.h>
#include <stdbool.h>

// Fixed-point type definitions
typedef uint32_t fp;

#define fp_size (sizeof(fp) * 8)
#define fp_MAX  ((fp)0x40000000)
#define fp_MIN  ((fp)0xC0000000)
#define fp_bd   4
#define fp_frac (fp_size - fp_bd)

// Fixed-point constants for fractal viewport (Q4.28 format)
#define FRAC_WIDTH_FP  ((fp)0x30000000)  // 3.0 in Q4.28
#define CX_0_FP        ((fp)0xE0000000)  // -2.0 in Q4.28
#define CY_0_FP        ((fp)0xE8000000)  // -1.5 in Q4.28
#define DELTA_FP       ((fp)0x00180000)  // 3.0/512 in Q4.28

// Fixed-point arithmetic functions
fp add(fp val1, fp val2);
fp sub(fp val1, fp val2);
fp mul(fp val1, fp val2);
fp float_to_fp(float val);

//! Colour type (5-bit red, 6-bit green, 5-bit blue)
typedef uint16_t rgb565;

//! \brief Pointer to fractal point calculation function
typedef uint16_t (*calc_frac_point_p)(fp cx, fp cy, uint16_t n_max);

//! \brief  Mandelbrot fractal point calculation function
//! \param  cx    x-coordinate
//! \param  cy    y-coordinate
//! \param  n_max maximum number of iterations
//! \return       number of performed iterations at coordinate (cx, cy)
uint16_t calc_mandelbrot_point_soft(fp cx, fp cy, uint16_t n_max);

//! Pointer to function mapping iteration to colour value
typedef rgb565 (*iter_to_colour_p)(uint16_t iter, uint16_t n_max);

//! \brief  Map number of performed iterations to black and white
//! \param  iter  performed number of iterations
//! \param  n_max maximum number of iterations
//! \return       colour
rgb565 iter_to_bw(uint16_t iter, uint16_t n_max);

//! \brief  Map number of performed iterations to grayscale
//! \param  iter  performed number of iterations
//! \param  n_max maximum number of iterations
//! \return       colour
rgb565 iter_to_grayscale(uint16_t iter, uint16_t n_max);

//! \brief  Map number of performed iterations to a colour
//! \param  iter  performed number of iterations
//! \param  n_max maximum number of iterations
//! \return colour in rgb565 format little Endian (big Endian for openrisc)
rgb565 iter_to_colour(uint16_t iter, uint16_t n_max);
rgb565 iter_to_colour1(uint16_t iter, uint16_t n_max);

//! \brief  Draw fractal into frame buffer
//! \param  width  width of frame buffer
//! \param  height height of frame buffer
//! \param  cfp_p  pointer to fractal function
//! \param  i2c_p  pointer to function mapping number of iterations to colour
//! \param  cx_0   start x-coordinate (now fixed-point)
//! \param  cy_0   start y-coordinate (now fixed-point)
//! \param  delta  increment for x- and y-coordinate (now fixed-point)
//! \param  n_max  maximum number of iterations
void draw_fractal(rgb565 *fbuf, int width, int height,
                  calc_frac_point_p cfp_p, iter_to_colour_p i2c_p,
                  fp cx_0, fp cy_0, fp delta, uint16_t n_max);

//! \brief Calculate binary logarithm for unsigned integer argument x
//! \note  For x equal 0, the function returns -1.
int ilog2(unsigned x);

// Utility function for byte swapping
uint16_t swap_u16(uint16_t val);
uint32_t swap_u32(uint32_t val);

#endif // FRACTAL_FXPT_H