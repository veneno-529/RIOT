#ifndef CLK_H7_APB1_H
#define CLK_H7_APB1_H

#include "ahb.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CONFIG_CLOCK_APB1_DIV
#define CONFIG_CLOCK_APB1_DIV 1
#endif

#define CLOCK_APB1             (CLOCK_AHB / CONFIG_CLOCK_APB1_DIV)

#ifdef __cplusplus
}
#endif

#endif /* CLK_H7_APB1_H */
