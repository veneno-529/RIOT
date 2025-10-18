#ifndef CLK_H7_LSI_H
#define CLK_H7_LSI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cpu_conf.h"

#ifndef CONFIG_CLOCK_LSI
    #define CONFIG_CLOCK_LSI        32000U /* Default LSE frequency is 32.768kHz */
#endif

#if IS_ACTIVE(CONFIG_USE_LSI)
#define CLOCK_LSI               CONFIG_CLOCK_LSI
#endif

#ifdef __cplusplus
}
#endif

#endif /* CLK_H7_LSI_H */
