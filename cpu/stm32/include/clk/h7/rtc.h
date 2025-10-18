/*
 * STM32H7 RTC clock selection - Kconfig compliant
 */

#ifndef CLK_H7_RTC_H
#define CLK_H7_RTC_H

#include "lse.h"
#include "lsi.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CONFIG_RTC_USE_LSE
#define CONFIG_RTC_USE_LSE 1
#endif

#if CONFIG_RTC_USE_LSE
#define CLOCK_RTC CLOCK_LSE
#else
#define CLOCK_RTC CLOCK_LSI
#endif

#ifdef __cplusplus
}
#endif

#endif /* CLK_H7_RTC_H */
