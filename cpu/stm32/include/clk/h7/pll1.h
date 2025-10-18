#ifndef CLK_H7_PLL1_H
#define CLK_H7_PLL1_H

#include "cfg_clock_default.h"

#ifdef __cplusplus
extern "C" {
#endif

#if IS_ACTIVE(CONFIG_USE_CLOCK_HSI_PLL) || IS_ACTIVE(CONFIG_USE_CLOCK_HSE_PLL) || \
    IS_ACTIVE(CONFIG_USE_CSI_PLL)

#define CLOCK_PLL1_M            CONFIG_CLOCK_PLL1_M
#define CLOCK_PLL1_N            CONFIG_CLOCK_PLL1_N
#define CLOCK_PLL1_P            CONFIG_CLOCK_PLL1_P
#define CLOCK_PLL1_Q            CONFIG_CLOCK_PLL1_Q
#define CLOCK_PLL1_R            CONFIG_CLOCK_PLL1_R

#if IS_ACTIVE(CONFIG_USE_HSI_PLL)
#define CLOCK_PLL1_INPUT         CLOCK_HSI
#elif IS_ACTIVE(CONFIG_USE_HSE_PLL)
#define CLOCK_PLL1_INPUT         CLOCK_HSE
#if IS_ACTIVE(CONFIG_USE_CSI_PLL)
#define CLOCK_PLL1_INPUT         CLOCK_CSI
#endif

#define CLOCK_PLL1_VCO_TEMP           (CLOCK_PLL1_INPUT / CLOCK_PLL1_M)
#define CLOCK_PLL1_VCO               (CLOCK_PLL_VCO_TEMP * CLOCK_PLL1_N)
#define CLOCK_PLL1_P_OUT         (CLOCK_PLL_VCO / CLOCK_PLL1_P)
#define CLOCK_PLL1_Q_OUT         (CLOCK_PLL_VCO / CLOCK_PLL1_Q)
#define CLOCK_PLL1_R_OUT         (CLOCK_PLL_VCO / CLOCK_PLL1_R)

#endif /* PLL usage */

#ifdef __cplusplus
}
#endif

#endif /* CLK_H7_PLL1_H */
