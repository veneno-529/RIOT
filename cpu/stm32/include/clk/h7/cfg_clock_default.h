/*
 * Copyright (c) 2024 Prime Controls, Inc.(R)
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup         cpu_stm32
 * @{
 *
 * @file
 * @brief           Main header for STM32H7 clock configuration (STM32H753ZI)
 *
 * @note
 * This configuration supports:
 *  - HSE (8 MHz or 25 MHz) + PLL1 → 480 MHz
 *  - HSI (64 MHz) + PLL1 → 480 MHz
 *  - HSI direct (no PLL) with optional divider (/1, /2, /4, /8)
 */

#ifndef CFG_CLOCK_DEFAULT_H
#define CFG_CLOCK_DEFAULT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cpu_conf.h"
#include "kernel_defines.h"
#include "modules.h"
#include "macros/units.h"
#include "lse.h"
#include "lsi.h"


/* ==========================
 *  DEFAULT CONFIGURATION - HSI PLL
 * ========================== */

/**
 * Select system clock source:
 * 1 = Use HSI direct (no PLL)
 */
#ifndef CONFIG_USE_HSI_DIRECT
#define CONFIG_USE_HSI_DIRECT      0
#endif

/*
 * Default to HSI with PLL1 as 
 * system clock source
 */
#ifndef CONFIG_USE_HSI_PLL
#if IS_ACTIVE(CONFIG_USE_HSI_DIRECT) || IS_ACTIVE(CONFIG_USE_HSE_DIRECT) || \
    IS_ACTIVE(CONFIG_USE_CSI_DIRECT) || IS_ACTIVE(CONFIG_USE_CSI_PLL) || \
    IS_ACTIVE(CONFIG_USE_HSE_PLL)
    #define CONFIG_USE_HSI_PLL         0
#else
    #define CONFIG_USE_HSI_PLL         1
#endif
#endif

/**
 * HSI divider when using HSI direct (no PLL)
 * Valid values: 1, 2, 4, 8
 */
#ifndef CONFIG_CLOCK_HSI_DIV
#define CONFIG_CLOCK_HSI_DIV       1
#endif

/**
 * Disable HSE usage by default
 */
#ifndef CONFIG_USE_HSE_PLL
#define CONFIG_USE_HSE_PLL         0
#endif

#ifndef CONFIG_USE_HSE_DIRECT
#define CONFIG_USE_HSE_DIRECT      0
#endif

/**
 * Disable CSI usage by default
 */
#ifndef CONFIG_USE_CSI_PLL
#define CONFIG_USE_CSI_PLL         0
#endif  
#ifndef CONFIG_USE_CSI_DIRECT
#define CONFIG_USE_CSI_DIRECT      0
#endif

/* ==========================
 *  Base oscillator defaults
 * ========================== */
#if IS_ACTIVE(CONFIG_USE_HSI_DIRECT) || IS_ACTIVE(CONFIG_USE_HSI_PLL)
#ifndef CONFIG_CLOCK_HSI
#define CONFIG_CLOCK_HSI           64
#endif
#endif

#if IS_ACTIVE(CONFIG_USE_HSE_PLL) || IS_ACTIVE(CONFIG_USE_HSE_DIRECT)
#ifndef CONFIG_CLOCK_HSE
#define CONFIG_CLOCK_HSE           8
#endif
#endif

#if IS_ACTIVE(CONFIG_USE_CSI_DIRECT) || IS_ACTIVE(CONFIG_USE_CSI_PLL)
#ifndef CONFIG_CLOCK_CSI
#define CONFIG_CLOCK_CSI           4
#endif
#endif

#ifndef CONFIG_CLOCK_LSE
#define CONFIG_CLOCK_LSE           32768UL
#endif

#if IS_ACTIVE(CONFIG_USE_LSI)
#ifndef CONFIG_CLOCK_LSI
#define CONFIG_CLOCK_LSI           32000UL
#endif
#endif

/* ==========================
 *  Clock path configuration
 * ========================== */
#ifndef CONFIG_CLOCK_CORECLOCK_DIV
    #define CONFIG_CLOCK_CORECLOCK_DIV     1
#endif

#if CONFIG_USE_HSI_DIRECT

/* --------------------------------------------------------------------------
 * MODE: HSI Direct (no PLL)
 * --------------------------------------------------------------------------
 * SYSCLK source = HSI / HSI_DIV
 * Example: HSI=64 MHz, HSI_DIV=4 → SYSCLK=16 MHz
 * -------------------------------------------------------------------------- */

//#define CONFIG_CLOCK_SYSCLK_SOURCE     "HSI"
//#define CONFIG_CLOCK_PLL1_ENABLE       0
#ifndef CONFIG_CLOCK_AHB_DIV
    #define CONFIG_CLOCK_AHB_DIV           1
#endif
#ifndef CONFIG_CLOCK_APB1_DIV
    #define CONFIG_CLOCK_APB1_DIV          2
#endif
#ifndef CONFIG_CLOCK_APB2_DIV
    #define CONFIG_CLOCK_APB2_DIV          2
#endif
#ifndef CONFIG_CLOCK_APB3_DIV
    #define CONFIG_CLOCK_APB3_DIV          2
#endif
#ifndef CONFIG_CLOCK_APB4_DIV
    #define CONFIG_CLOCK_APB4_DIV          2
#endif

#else /* ------------------------------------------------------------------- */
/* --------------------------------------------------------------------------
 * MODE: PLL-based (default)
 * --------------------------------------------------------------------------
 * SYSCLK source = PLL1_P output
 * Target SYSCLK = 480 MHz
 * -------------------------------------------------------------------------- */

/* Default PLL1 configuration based on input clock */

#if (CONFIG_CLOCK_HSE == 8)
    /* HSE with PLL1 → 480 MHz (VCO=960 MHz) */
#ifndef CONFIG_CLOCK_PLL1_M
    #define CONFIG_CLOCK_PLL1_M        4
    #define CONFIG_CLOCK_PLL1_N        480
    #define CONFIG_CLOCK_PLL1_P        2
    #define CONFIG_CLOCK_PLL1_Q        20
    #define CONFIG_CLOCK_PLL1_R        2
#endif

#elif (CONFIG_CLOCK_HSE == 25)
#ifndef CONFIG_CLOCK_PLL1_M
    #define CONFIG_CLOCK_PLL1_M        5
    #define CONFIG_CLOCK_PLL1_N        192
    #define CONFIG_CLOCK_PLL1_P        2
    #define CONFIG_CLOCK_PLL1_Q        20
    #define CONFIG_CLOCK_PLL1_R        2
#endif

#elif (CONFIG_CLOCK_CSI == 4)
    /* CSI with PLL1 → 480 MHz (VCO=960 MHz) */
#ifndef CONFIG_CLOCK_PLL1_M
    #define CONFIG_CLOCK_PLL1_M        1
    #define CONFIG_CLOCK_PLL1_N        240
    #define CONFIG_CLOCK_PLL1_P        2
    #define CONFIG_CLOCK_PLL1_Q        20
    #define CONFIG_CLOCK_PLL1_R        2
#endif

#elif (CONFIG_CLOCK_HSI == 64)
    /* HSI with PLL1 → 480 MHz (VCO=960 MHz) */
#ifndef CONFIG_CLOCK_PLL1_M
    #define CONFIG_CLOCK_PLL1_M        8
    #define CONFIG_CLOCK_PLL1_N        120
    #define CONFIG_CLOCK_PLL1_P        2
    #define CONFIG_CLOCK_PLL1_Q        20
    #define CONFIG_CLOCK_PLL1_R        2
#endif

#else
    #error "Unsupported clock input for PLL configuration."
#endif
#endif /* CONFIG_USE_HSI_DIRECT */

#include "clk/h7/lse.h"
#include "clk/h7/lsi.h"
#include "clk/h7/hse.h"
#include "clk/h7/hsi.h"
#include "clk/h7/csi.h"
#include "clk/h7/pll1.h"
#include "clk/h7/pll2.h"
#include "clk/h7/pll3.h"

#ifndef CONFIG_CORECLOCK_DIV
    #define CONFIG_CORECLOCK_DIV       1
#endif

#include "clk/h7/coreclock.h"

/* AHB divider required (HCLK max 240 MHz) */
#ifndef CONFIG_CLOCK_AHB_DIV
    #define CONFIG_CLOCK_AHB_DIV       2
#endif

#include "clk/h7/ahb.h"

/* Default APB settings (keep within 120 MHz max) */
#ifndef CONFIG_CLOCK_APB1_DIV
    #define CONFIG_CLOCK_APB1_DIV      2
#endif
#ifndef CONFIG_CLOCK_APB2_DIV
    #define CONFIG_CLOCK_APB2_DIV      2
#endif
#ifndef CONFIG_CLOCK_APB3_DIV
    #define CONFIG_CLOCK_APB3_DIV      2
#endif
#ifndef CONFIG_CLOCK_APB4_DIV
    #define CONFIG_CLOCK_APB4_DIV      2
#endif

#include "clk/h7/apb1.h"
#include "clk/h7/apb2.h"
#include "clk/h7/apb3.h"
#include "clk/h7/apb4.h"


#ifdef __cplusplus
}
#endif

#endif /* CFG_CLOCK_DEFAULT_H */
/** @} */
