#ifndef CLK_H7_LSE_H
#define CLK_H7_LSE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "kernel_defines.h"

#ifndef CONFIG_CLOCK_LSE
    #define CONFIG_CLOCK_LSE        32768U /* Default LSE frequency is 32.768kHz */
#endif

#if IS_ACTIVE(CONFIG_USE_LSE)
#define CLOCK_LSE               CONFIG_CLOCK_LSE
#endif

#ifdef __cplusplus
}
#endif

#endif /* CLK_H7_LSE_H */
