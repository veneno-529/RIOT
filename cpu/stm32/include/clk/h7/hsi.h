#ifndef CLK_H7_HSI_H
#define CLK_H7_HSI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cpu_conf.h"
#include "kernel_defines.h"

#if IS_ACTIVE(CONFIG_USE_HSI_DIRECT) || IS_ACTIVE(CONFIG_USE_HSI_PLL)

#if !defined(CONFIG_CLOCK_HSI)
    #error "CONFIG_CLOCK_HSI must be defined"
#endif

#ifndef CONFIG_CLOCK_HSI_DIV
#define CONFIG_CLOCK_HSI_DIV 1
#endif

#define CLOCK_HSI               (CONFIG_CLOCK_HSI / CONFIG_CLOCK_HSI_DIV)

#endif /* HSI usage */

#ifdef __cplusplus
}
#endif

#endif /* CLK_H7_HSI_H */
