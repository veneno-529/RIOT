#ifndef CLK_H7_SYSCLK_H
#define CLK_H7_SYSCLK_H

#include "hse.h"
#include "hsi.h"
#include "csi.h"
#include "pll1.h"

#ifdef __cplusplus
extern "C" {
#endif

#if IS_ACTIVE(CONFIG_USE_HSI_DIRECT)
#define CLOCK_SYSCLK            CLOCK_HSI
#elif IS_ACTIVE(CONFIG_USE_CLOCK_HSE)
#define CLOCK_SYSCLK            CLOCK_HSE
#elif IS_ACTIVE(CONFIG_USE_CSI_DIRECT)
#define CLOCK_SYSCLK            CLOCK_CSI
#elif IS_ACTIVE(CONFIG_USE_HSI_PLL) || IS_ACTIVE(CONFIG_USE_HSE_PLL) || \
      IS_ACTIVE(CONFIG_USE_CSI_PLL)
#define CLOCK_SYSCLK            CLOCK_PLL1_P_OUT
#else
#error "No valid clock source selected"
#endif

#ifdef __cplusplus
}
#endif

#endif /* CLK_H7_SYSCLK_H */
