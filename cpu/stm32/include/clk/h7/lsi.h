#ifndef CLK_H7_LSI_H
#define CLK_H7_LSI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "kernel_defines.h"

#ifndef CONFIG_CLOCK_LSI
    #define CONFIG_CLOCK_LSI        32000U /* Default LSE frequency is 32.768kHz */
#endif

#ifndef CONFIG_USE_LSI
    #define CONFIG_USE_LSI          1
#endif

#if IS_ACTIVE(CONFIG_USE_LSI)
#ifndef CLOCK_LSI
    #define CLOCK_LSI               CONFIG_CLOCK_LSI
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* CLK_H7_LSI_H */
