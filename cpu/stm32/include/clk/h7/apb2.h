#ifndef CLK_H7_APB2_H
#define CLK_H7_APB2_H

#include "ahb.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CONFIG_CLOCK_APB2_DIV
#define CONFIG_CLOCK_APB2_DIV 2
#endif

#define CLOCK_APB2             (CLOCK_AHB / CONFIG_CLOCK_APB2_DIV)

#ifdef __cplusplus
}
#endif

#endif /* CLK_H7_APB2_H */
