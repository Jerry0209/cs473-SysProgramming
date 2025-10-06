#ifndef FRACTAL_MYFLPT_H
#define FRACTAL_MYFLPT_H

#include <stdint.h>
#include <stdbool.h>

typedef uint32_t mfp;

#define MFP_ZERO    ((mfp)0u)
#define MFP_ONE     ((1u<<22)<<8 | (uint8_t)(251))
#define MFP_TWO     ((1u<<22)<<8 | (uint8_t)(252))
#define MFP_FOUR    ((1u<<22)<<8 | (uint8_t)(253))
#define MFP_HALF    ((1u<<22)<<8 | (uint8_t)(250))
#define MFP_QUARTER ((1u<<22)<<8 | (uint8_t)(249))

enum { MFP_EXP_BIAS = 250, MFP_MAG_BITS = 23, MFP_MAG_TOP = 22 };
#define MFP_SIGN_MASK  (0x80000000u)
#define MFP_EXP_MASK   (0x000000FFu)
#define MFP_MAG_MASK   (0x7FFFFF00u)

bool mfp_sign(mfp v);
int16_t mfp_exp(mfp v);
uint32_t mfp_mag(mfp v);


mfp mfp_add(mfp a, mfp b);
mfp mfp_sub(mfp a, mfp b);
mfp mfp_mul(mfp a, mfp b);
mfp mfp_from_float(float f);
float mfp_to_float(mfp v);
int mfp_cmp(mfp a, mfp b);

//! Colour type (5-bit red, 6-bit green, 5-bit blue)
typedef uint16_t rgb565;

//! Pointer to fractal point calculation function
typedef uint16_t (*calc_frac_point_p)(mfp cx, mfp cy, uint16_t n_max);

uint16_t calc_mandelbrot_point_soft(mfp cx, mfp cy, uint16_t n_max);

//! Pointer to function mapping iteration to colour value
typedef rgb565 (*iter_to_colour_p)(uint16_t iter, uint16_t n_max);

rgb565 iter_to_bw(uint16_t iter, uint16_t n_max);
rgb565 iter_to_grayscale(uint16_t iter, uint16_t n_max);
rgb565 iter_to_colour(uint16_t iter, uint16_t n_max);
rgb565 iter_to_colour1(uint16_t iter, uint16_t n_max);

void draw_fractal(rgb565 *fbuf, int width, int height,
                  calc_frac_point_p cfp_p, iter_to_colour_p i2c_p,
                  mfp cx_0, mfp cy_0, mfp delta, uint16_t n_max);

int ilog2(unsigned x);

#endif