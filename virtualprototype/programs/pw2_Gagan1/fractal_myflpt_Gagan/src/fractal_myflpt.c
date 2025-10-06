#include "fractal_myflpt.h"
#include <swap.h>

bool mfp_sign(mfp v){ return (v & MFP_SIGN_MASK) != 0; }
int16_t mfp_exp(mfp v){return (uint8_t)(v & MFP_EXP_MASK)-250; }
uint32_t mfp_mag(mfp v){ return (uint32_t)((v & MFP_MAG_MASK) >> 8); }


mfp mfp_add(mfp a, mfp b) {
    if (a == MFP_ZERO) return b;
    if (b == MFP_ZERO) return a;

    bool sa = mfp_sign(a), sb = mfp_sign(b);
    int16_t ea = (int16_t)mfp_exp(a); 
    int16_t eb = (int16_t)mfp_exp(b); 
    uint32_t ma = mfp_mag(a);
    uint32_t mb = mfp_mag(b);

    int16_t ea_unbiased = ea;
    int16_t eb_unbiased = eb;

    int16_t diff = ea_unbiased - eb_unbiased;
    int16_t exp = 0;
    if (diff > 0) {
        if (diff >= 23) return a;
        mb >>= diff;
        exp = ea_unbiased;
    } else if (diff < 0) {
        if (-diff >= 23) return b;
        ma >>= -diff;
        exp = eb_unbiased;
    } else {
        exp = ea_unbiased;
    }

    int32_t val = (sa ? -(int32_t)ma : (int32_t)ma)
                + (sb ? -(int32_t)mb : (int32_t)mb);

    if (val == 0) return MFP_ZERO;

    bool sign = (val < 0);
    uint32_t mag = (val < 0) ? (uint32_t)(-(int32_t)val) : (uint32_t)val;

    int top_bit = 0;
    for (int i = 31; i >= 0; i--){
        if ((mag & (1u << i)) != 0) {
            top_bit = i;
            break;
        }
    }

    if (top_bit > MFP_MAG_TOP) {
        int shift = top_bit - MFP_MAG_TOP;
        mag >>= shift;
        exp += shift;
    } else if (top_bit < MFP_MAG_TOP) {
        int shift = MFP_MAG_TOP - top_bit;
        mag <<= shift;
        exp -= shift;
    }

    if (exp < -MFP_EXP_BIAS) return MFP_ZERO;
    if (exp > 5) {
        exp = 5;
        mag = 0x7FFFFF;
    }

    uint8_t exp_final = (uint8_t)(exp + MFP_EXP_BIAS);

    return (sign ? MFP_SIGN_MASK : 0) | ((mag & 0x7FFFFF) << 8) | exp_final;
}

mfp mfp_sub(mfp a, mfp b){ 
    if (b==MFP_ZERO) return a; 
    b ^= MFP_SIGN_MASK; 
    return mfp_add(a,b); 
}

mfp mfp_mul(mfp a, mfp b) {
    if (a == MFP_ZERO || b == MFP_ZERO) return MFP_ZERO;

    bool sa = mfp_sign(a);
    bool sb = mfp_sign(b);
    int16_t ea = mfp_exp(a);
    int16_t eb = mfp_exp(b);
    uint32_t ma = mfp_mag(a);
    uint32_t mb = mfp_mag(b);

    bool s = sa ^ sb;
    int16_t exp = ea + eb;

    uint64_t prod = (uint64_t)ma * (uint64_t)mb;

    uint32_t mag = (uint32_t)(prod >> 23);

    if (mag == 0) return MFP_ZERO;

    int highest = -1;
    for (int i = 31; i >= 0; i--) {
        if (mag & (1u << i)) {
            highest = i;
            break;
        }
    }

    if (highest > MFP_MAG_TOP) {
        int delta = highest - MFP_MAG_TOP;
        mag >>= delta;
        exp += delta;
    } else if (highest < MFP_MAG_TOP) {
        int delta = MFP_MAG_TOP - highest;
        mag <<= delta;
        exp -= delta;
    }

    if (exp < -250) {
        return MFP_ZERO;
    }
    if (exp > 5) {
        uint32_t mag_max = (MFP_MAG_MASK >> 8);
        return (s ? MFP_SIGN_MASK : 0) | (mag_max << 8) | 0xFF;
    }

    uint8_t biased = (uint8_t)(exp + MFP_EXP_BIAS);

    return (s ? MFP_SIGN_MASK : 0) | ((mag & 0x7FFFFF) << 8) | biased;
}


float mfp_to_float(mfp v){
    if (v == MFP_ZERO) return 0.0f;

    int sign = mfp_sign(v) ? -1 : 1;
    int exp_unbiased = mfp_exp(v);
    uint32_t mag = mfp_mag(v);

    float mant = (float)mag / (float)(1u << 23);

    if (exp_unbiased > 0) for(int i=0;i<exp_unbiased;i++) mant *= 2.0f;
    else if(exp_unbiased<0) for(int i=0;i<-exp_unbiased;i++) mant *= 0.5f;

    return sign < 0 ? -mant : mant;
}

int mfp_cmp(mfp a, mfp b) {
    if (a == MFP_ZERO && b == MFP_ZERO) return 0;
    if (a == MFP_ZERO) {
        return mfp_sign(b) ? 1 : -1;
    }
    if (b == MFP_ZERO) {
        return mfp_sign(a) ? -1 : 1;
    }

    bool sa = mfp_sign(a);
    bool sb = mfp_sign(b);
    int16_t ea = mfp_exp(a);
    int16_t eb = mfp_exp(b);
    uint32_t ma = mfp_mag(a);
    uint32_t mb = mfp_mag(b);

    if (sa != sb) {
        return sa ? -1 : 1;
    }

    if (ea != eb) {
        if (!sa) {
            return (ea > eb) ? 1 : -1;
        } else {
            return (ea > eb) ? -1 : 1;
        }
    }

    if (ma != mb) {
        if (!sa) {
            return (ma > mb) ? 1 : -1;
        } else {
            return (ma > mb) ? -1 : 1;
        }
    }

    return 0;
}

mfp mfp_from_float(float f) {
    if (f == 0.0f) return MFP_ZERO;

    union { float f; uint32_t u; } v;
    v.f = f;

    bool sign = (v.u >> 31) & 1;
    int32_t exp_ieee = (v.u >> 23) & 0xFF;
    uint32_t frac = v.u & 0x7FFFFF;

    uint32_t mag;
    int32_t exp_unbiased;

    if (exp_ieee == 0) {
        if (frac == 0) return MFP_ZERO;
        exp_unbiased = -126;
        mag = frac;
        while ((mag & (1 << 23)) == 0) {
            mag <<= 1;
            exp_unbiased--;
        }
        mag &= 0x7FFFFF;
    } else {
        exp_unbiased = exp_ieee - 127;
        mag = (1u << 23) | frac;
    }

    int highest = -1;
    for (int i = 31; i >= 0; i--) {
        if (mag & (1u << i)) {
            highest = i;
            break;
        }
    }

    if (highest > MFP_MAG_TOP) {
        int delta = highest - MFP_MAG_TOP;
        mag >>= delta;
        exp_unbiased += delta;
    } else if (highest < MFP_MAG_TOP) {
        int delta = MFP_MAG_TOP - highest;
        mag <<= delta;
        exp_unbiased -= delta;
    }

    if (exp_unbiased < -250) return MFP_ZERO;
    if (exp_unbiased > 5) {
        uint32_t mag_max = (MFP_MAG_MASK >> 8);
        return (sign ? MFP_SIGN_MASK : 0) | (mag_max << 8) | 0xFF;
    }

    uint8_t biased = (uint8_t)(exp_unbiased + MFP_EXP_BIAS);

    return (sign ? MFP_SIGN_MASK : 0) | ((mag & 0x7FFFFF) << 8) | biased;
}

//! \brief  Mandelbrot fractal point calculation function
//! \param  cx    x-coordinate
//! \param  cy    y-coordinate
//! \param  n_max maximum number of iterations
//! \return       number of performed iterations at coordinate (cx, cy)
uint16_t calc_mandelbrot_point_soft(mfp cx, mfp cy, uint16_t n_max) {
    mfp x = cx;
    mfp y = cy;
    uint16_t n = 0;
    mfp xx, yy, two_xy;
    do {
        xx = mfp_mul(x,x);
        yy = mfp_mul(y,y);
        two_xy = mfp_mul(MFP_TWO, mfp_mul(x,y));

        x = mfp_add(mfp_sub(xx,yy),cx);
        y = mfp_add(two_xy,cy);
        ++n;
    } while ((mfp_cmp(mfp_add(xx, yy), MFP_FOUR) < 0) && (n < n_max));
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
    return swap_u16(((brightness << 12) | ((brightness << 7) | brightness<<1)));
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
    uint16_t brightness = (iter&1)<<4|0xF;
    uint16_t r = (iter & (1 << 3)) ? brightness : 0x0;
    uint16_t g = (iter & (1 << 2)) ? brightness : 0x0;
    uint16_t b = (iter & (1 << 1)) ? brightness : 0x0;
    return swap_u16(((r & 0x1f) << 11) | ((g & 0x1f) << 6) | ((b & 0x1f)));
}

rgb565 iter_to_colour1(uint16_t iter, uint16_t n_max) {
    if (iter == n_max) {
        return 0x0000;
    }
    uint16_t brightness = ((iter&0x78)>>2)^0x1F;
    uint16_t r = (iter & (1 << 2)) ? brightness : 0x0;
    uint16_t g = (iter & (1 << 1)) ? brightness : 0x0;
    uint16_t b = (iter & (1 << 0)) ? brightness : 0x0;
    return swap_u16(((r & 0xf) << 12) | ((g & 0xf) << 7) | ((b & 0xf)<<1));
}

//! \brief  Draw fractal into frame buffer
//! \param  width  width of frame buffer
//! \param  height height of frame buffer
//! \param  cfp_p  pointer to fractal function
//! \param  i2c_p  pointer to function mapping number of iterations to colour
//! \param  cx_0   start x-coordinate
//! \param  cy_0   start y-coordinate
//! \param  delta  increment for x- and y-coordinate
//! \param  n_max  maximum number of iterations
void draw_fractal(rgb565 *fbuf, int width, int height,
                  calc_frac_point_p cfp_p, iter_to_colour_p i2c_p,
                  mfp cx_0, mfp cy_0, mfp delta, uint16_t n_max) {
    rgb565 *pixel = fbuf;
    mfp cy = cy_0;
    for (int k = 0; k < height; ++k) {
        mfp cx = cx_0;
        for(int i = 0; i < width; ++i) {
            uint16_t n_iter = (*cfp_p)(cx, cy, n_max);
            rgb565 colour = (*i2c_p)(n_iter, n_max);
            *(pixel++) = colour;
            cx = mfp_add(cx, delta);
        }
        cy = mfp_add(cy, delta);
    }
}