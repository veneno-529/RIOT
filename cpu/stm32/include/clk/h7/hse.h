#ifndef CLK_H7_HSE_H
#define CLK_H7_HSE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cpu_conf.h"
#include "kernel_defines.h"

#if IS_ACTIVE(CONFIG_USE_HSE_PLL) || IS_ACTIVE(CONFIG_USE_HSE_DIRECT)

#if !defined(CONFIG_CLOCK_HSE)
    #error "CONFIG_CLOCK_HSE must be defined when using HSE PLL"
#endif

#define CLOCK_HSE               CONFIG_CLOCK_HSE

#endif /* USE_CLOCK_HSE_PLL */

#ifdef __cplusplus
}
#endif

#endif /* CLK_H7_HSE_H */
