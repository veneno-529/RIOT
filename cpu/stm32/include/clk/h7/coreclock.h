#ifndef CLK_H7_CORECLOCK_H
#define CLK_H7_CORECLOCK_H

#include "sysclk.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CLOCK_CORE_SRC          CLOCK_SYSCLK

#if defined(CONFIG_CLOCK_CORECLOCK_DIV)
#define CLOCK_CORECLOCK         (CLOCK_CORE_SRC / CONFIG_CLOCK_CORECLOCK_DIV)
#else
#define CLOCK_CORECLOCK         CLOCK_CORE_SRC
#endif

#ifdef __cplusplus
}
#endif

#endif /* CLK_H7_CORECLOCK_H */
