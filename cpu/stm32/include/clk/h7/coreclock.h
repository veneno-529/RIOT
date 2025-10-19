#ifndef CLK_H7_CORECLOCK_H
#define CLK_H7_CORECLOCK_H

#include "clk/h7/ahb.h"
#include "clk/h7/sysclk.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CLOCK_CORE_SRC          MHZ(CLOCK_SYSCLK)

#if defined(CONFIG_CLOCK_CORECLOCK_DIV)
#define CLOCK_CORECLOCK         (CLOCK_CORE_SRC / CONFIG_CLOCK_CORECLOCK_DIV)
#else
#define CLOCK_CORECLOCK         CLOCK_CORE_SRC
#endif

#ifdef __cplusplus
}
#endif

#endif /* CLK_H7_CORECLOCK_H */
