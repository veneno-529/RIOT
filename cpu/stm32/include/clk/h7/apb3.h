#ifndef CLK_H7_APB3_H
#define CLK_H7_APB3_H

#include "ahb.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CONFIG_CLOCK_APB3_DIV
#define CONFIG_CLOCK_APB3_DIV 2
#endif

#define CLOCK_APB3             (CLOCK_AHB / CONFIG_CLOCK_APB3_DIV)

#ifdef __cplusplus
}
#endif

#endif /* CLK_H7_APB3_H */
