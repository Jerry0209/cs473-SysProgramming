#include "fractal_fxpt.h"

const fp FP_TWO = 0x20000000;
const fp FP_FOUR = 0x40000000;

fp add(fp val1, fp val2) {
    fp sum = val1 + val2;

    bool neg1 = ((val1 & (1 << (fp_size - 1))) != 0);
    bool neg2 = ((val2 & (1 << (fp_size - 1))) != 0);
    bool negSum = ((sum  & (1 << (fp_size - 1))) != 0);

    if (neg1 && neg2) {
        if ((sum & 0xf0000000)&0x7 < 4) return fp_MIN;
        else return sum;
    }
    
    if (!neg1 && !neg2 && sum > fp_MAX) {
        return fp_MAX;
    }

    return sum;
}

fp sub(fp val1, fp val2) {
    return add(val1, add(~val2, 1));
}

fp mul(fp val1, fp val2) {
    if (val1 == 0 || val2 == 0) {
        return 0;
    }

    bool val1_neg = (val1 & 0x80000000) != 0;
    bool val2_neg = (val2 & 0x80000000) != 0;
    
    if (!val1_neg && !val2_neg) {
        uint32_t a = (uint32_t)val1;
        uint32_t b = (uint32_t)val2;
        
        uint64_t result64 = (uint64_t)a * (uint64_t)b;
        result64 >>= fp_frac;  
        
        if (result64 > fp_MAX) return fp_MAX; 
        
        return (fp)(uint32_t)result64;
    }
    
    if (val1_neg && val2_neg) {
        uint32_t a = (uint32_t)add(~val1, 1);
        uint32_t b = (uint32_t)add(~val2, 1);
        
        uint64_t result64 = (uint64_t)a * (uint64_t)b;
        result64 >>= fp_frac;
        
        if (result64 > fp_MAX) return fp_MAX;
        
        return (fp)(uint32_t)result64;
    }
    
    uint32_t a = val1_neg ? (uint32_t)add(~val1, 1) : (uint32_t)val1;
    uint32_t b = val2_neg ? (uint32_t)add(~val2, 1) : (uint32_t)val2;
    
    uint64_t result64 = (uint64_t)a * (uint64_t)b;
    result64 >>= fp_frac;
    
    if (result64 > fp_MAX) return fp_MIN;
    
    return add(~(fp)(uint32_t)result64, 1);
}

fp float_to_fp(float val) {
    float scaled = val * (1 << fp_frac);
    
    if (scaled > 1073741823.0f) {
        return fp_MAX;
    } else if (scaled < -1073741824.0f) {
        return fp_MIN;
    }
    
    int32_t result = (int32_t)(scaled >= 0 ? scaled + 0.5f : scaled - 0.5f);
    return (fp)result;
}

uint16_t swap_u16(uint16_t val) {
    return ((val & 0xFF) << 8) | ((val >> 8) & 0xFF);
}

uint32_t swap_u32(uint32_t val) {
    return ((val & 0xFF) << 24) | 
           ((val & 0xFF00) << 8) |
           ((val & 0xFF0000) >> 8) |
           ((val & 0xFF000000) >> 24);
}

//! \brief  Mandelbrot fractal point calculation function
//! \param  cx    x-coordinate
//! \param  cy    y-coordinate
//! \param  n_max maximum number of iterations
//! \return       number of performed iterations at coordinate (cx, cy)
uint16_t calc_mandelbrot_point_soft(fp cx, fp cy, uint16_t n_max) {
    fp x = cx;
    fp y = cy;
    uint16_t n = 0;
    fp xx, yy, two_xy;
    
    do {
        xx = mul(x, x);
        yy = mul(y, y);
        two_xy = mul(FP_TWO, mul(x, y));

        x = add(sub(xx, yy), cx);
        y = add(two_xy, cy);
        ++n;
    } while ((add(xx, yy) < FP_FOUR) && (n < n_max));
    
    return n;
}

//! \brief  Map number of performed iterations to black and white
//! \param  iter  performed number of iterations
//! \param  n_max maximum number of iterations
//! \return       colour
rgb565 iter_to_bw(uint16_t iter, uint16_t n_max) {
    if (iter == n_max) {
        return 0x0000;
    }
    return 0xffff;
}

//! \brief  Map number of performed iterations to grayscale
//! \param  iter  performed number of iterations
//! \param  n_max maximum number of iterations
//! \return       colour
rgb565 iter_to_grayscale(uint16_t iter, uint16_t n_max) {
    if (iter == n_max) {
        return 0x0000;
    }
    uint16_t brightness = iter & 0xf;
    return swap_u16(((brightness << 12) | ((brightness << 7) | brightness << 1)));
}

//! \brief Calculate binary logarithm for unsigned integer argument x
//! \note  For x equal 0, the function returns -1.
int ilog2(unsigned x) {
    if (x == 0) return -1;
    int n = 1;
    if ((x >> 16) == 0) { n += 16; x <<= 16; }
    if ((x >> 24) == 0) { n += 8; x <<= 8; }
    if ((x >> 28) == 0) { n += 4; x <<= 4; }
    if ((x >> 30) == 0) { n += 2; x <<= 2; }
    n -= x >> 31;
    return 31 - n;
}

//! \brief  Map number of performed iterations to a colour
//! \param  iter  performed number of iterations
//! \param  n_max maximum number of iterations
//! \return colour in rgb565 format little Endian (big Endian for openrisc)
rgb565 iter_to_colour(uint16_t iter, uint16_t n_max) {
    if (iter == n_max) {
        return 0x0000;
    }
    uint16_t brightness = (iter & 1) << 4 | 0xF;
    uint16_t r = (iter & (1 << 3)) ? brightness : 0x0;
    uint16_t g = (iter & (1 << 2)) ? brightness : 0x0;
    uint16_t b = (iter & (1 << 1)) ? brightness : 0x0;
    return swap_u16(((r & 0x1f) << 11) | ((g & 0x1f) << 6) | ((b & 0x1f)));
}

rgb565 iter_to_colour1(uint16_t iter, uint16_t n_max) {
    if (iter == n_max) {
        return 0x0000;
    }
    uint16_t brightness = ((iter & 0x78) >> 2) ^ 0x1F;
    uint16_t r = (iter & (1 << 2)) ? brightness : 0x0;
    uint16_t g = (iter & (1 << 1)) ? brightness : 0x0;
    uint16_t b = (iter & (1 << 0)) ? brightness : 0x0;
    return swap_u16(((r & 0xf) << 12) | ((g & 0xf) << 7) | ((b & 0xf) << 1));
}

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
                  fp cx_0, fp cy_0, fp delta, uint16_t n_max) {
    rgb565 *pixel = fbuf;
    fp cy = cy_0;
    
    for (int k = 0; k < height; ++k) {
        fp cx = cx_0;
        for (int i = 0; i < width; ++i) {
            uint16_t n_iter = (*cfp_p)(cx, cy, n_max);
            rgb565 colour = (*i2c_p)(n_iter, n_max);
            *(pixel++) = colour;
            cx = add(cx, delta);
        }
        cy = add(cy, delta);
    }
}