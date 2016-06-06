#ifndef TIMER_HARDWARE
#define TIMER_HARDWARE

#include <stm32.h>
#include <gpio.h>
#include <delay.h>

#define M 2
#define N 432
#define P 2
#define Q 2
#define DEFAULT_ARR 600
#define DEFAULT_CCR1 200
#define DEFAULT_CCR2 400
#define DEFAULT_PSC 1

static int actTime = 0;

inline int getTime();
void changeTim2Pwm(const int, const int, const int);
void changeTim3Pwm(const int, const int, const int);
void changeTim4Pwm(const int, const int, const int);
void changeTim5Pwm(const int, const int, const int);
void changeTimPwm(const int, const int, const int, const int);
void runTimers();

#endif
