#ifndef FRACTAL_FXPT_H
#define FRACTAL_FXPT_H

#include <stdint.h>

typedef int32_t fxpt_4_28;  //!< Q4.28 fixed-point type
typedef int32_t fxpt_8_24;  //!< Q8.24 fixed-point type
typedef int64_t fxpt_8_56;  //!< Q8.56 fixed-point type

//! Colour type (4 bit unused, 4-bit red, 4-bit green, 4-bit blue)
typedef uint16_t rgb565;

//! \brief Pointer to fractal point calculation function
typedef uint16_t (*calc_frac_point_p)(fxpt_4_28 cx, fxpt_4_28 cy, uint16_t n_max);

uint16_t calc_mandelbrot_point_soft(fxpt_4_28 cx, fxpt_4_28 cy, uint16_t n_max);

//! Pointer to function mapping iteration to colour value
typedef rgb565 (*iter_to_colour_p)(uint16_t iter, uint16_t n_max);

rgb565 iter_to_bw(uint16_t iter, uint16_t n_max);
rgb565 iter_to_grayscale(uint16_t iter, uint16_t n_max);
rgb565 iter_to_colour(uint16_t iter, uint16_t n_max);
rgb565 iter_to_colour1(uint16_t iter, uint16_t n_max);

void draw_fractal(rgb565 *fbuf, int width, int height,
                  calc_frac_point_p cfp_p, iter_to_colour_p i2c_p,
                  fxpt_4_28 cx_0, fxpt_4_28 cy_0, fxpt_4_28 delta, uint16_t n_max);

#endif // FRACTAL_FXPT_H
