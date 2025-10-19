#ifndef CLK_H7_AHB_H
#define CLK_H7_AHB_H

#include "coreclock.h"
#include "sysclk.h"

#ifdef __cplusplus
extern "C" {
#endif

/* AHB clock definition */
#define CLOCK_AHB (CLOCK_CORECLOCK / CONFIG_CLOCK_AHB_DIV)

#ifdef __cplusplus
}
#endif

#endif /* CLK_H7_AHB_H */
