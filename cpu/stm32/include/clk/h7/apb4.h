#ifndef CLK_H7_APB4_H
#define CLK_H7_APB4_H

#include "ahb.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CONFIG_CLOCK_APB4_DIV
#define CONFIG_CLOCK_APB4_DIV 1
#endif

#define CLOCK_APB4             (CLOCK_AHB / CONFIG_CLOCK_APB4_DIV)

#ifdef __cplusplus
}
#endif

#endif /* CLK_H7_APB4_H */
