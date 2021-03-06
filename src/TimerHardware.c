#include "TimerHardware.h"

/*void timer_ll_api_change_pwm_tim3(int percent) {
  TIM3->CR1 |= TIM_CR1_UDIS;
  TIM3->ARR = FULL_FILL ;
  TIM3->CCR1 = percent/2;
	TIM3->CCR2 = FULL_FILL -(percent/2);
  TIM3->CR1 &= ~TIM_CR1_UDIS;
};

void timer_ll_api_change_pwm_tim4(int percent) {
  TIM4->CR1 |= TIM_CR1_UDIS;
  TIM4->ARR = FULL_FILL ;
  TIM4->CCR1 = percent/2;
	TIM4->CCR2 = FULL_FILL -(percent/2);
  TIM4->CR1 &= ~TIM_CR1_UDIS;
};

void timer_ll_api_change_pwm_tim5(int percent) {
  TIM5->CR1 |= TIM_CR1_UDIS;
  TIM5->ARR = FULL_FILL ;
  TIM5->CCR1 = percent/2;
	TIM5->CCR2 = FULL_FILL -(percent/2);
  TIM5->CR1 &= ~TIM_CR1_UDIS;
};*/

static int actTime = 0;
int getTime() {
  return actTime;
}

void incTime() {
  actTime++;
}

void TIM2_IRQHandler(void) {
  uint32_t it_status = TIM3->SR & TIM3->DIER;
  if (it_status & TIM_SR_UIF) {
    TIM3->SR = ~TIM_SR_UIF;
    incTime();
  }
  if (it_status & TIM_SR_CC1IF) {
    TIM3->SR = ~TIM_SR_CC1IF;
    incTime();
  }
}

void changeTim2Pwm(const int arr, const int ccr1, const int ccr2) {
  TIM2->CR1 |= TIM_CR1_UDIS;
  TIM2->ARR = arr;
  TIM2->CCR1 = ccr1;
	TIM2->CCR2 = ccr2;
  TIM2->CR1 &= ~TIM_CR1_UDIS;
}

void changeTim3Pwm(const int arr, const int ccr1, const int ccr2) {
  TIM3->CR1 |= TIM_CR1_UDIS;
  TIM3->ARR = arr;
  TIM3->CCR1 = ccr1;
	TIM3->CCR2 = ccr2;
  TIM3->CR1 &= ~TIM_CR1_UDIS;
}

void changeTim4Pwm(const int arr, const int ccr1, const int ccr2) {
  TIM4->CR1 |= TIM_CR1_UDIS;
  TIM4->ARR = arr;
  TIM4->CCR1 = ccr1;
	TIM4->CCR2 = ccr2;
  TIM4->CR1 &= ~TIM_CR1_UDIS;
}

void changeTim5Pwm(const int arr, const int ccr1, const int ccr2) {
  TIM5->CR1 |= TIM_CR1_UDIS;
  TIM5->ARR = arr;
  TIM5->CCR1 = ccr1;
	TIM5->CCR2 = ccr2;
  TIM5->CR1 &= ~TIM_CR1_UDIS;
}

void changeTimPwm(const int number, const int arr, const int ccr1, const int ccr2) {
  if (number == 2) 
    changeTim2Pwm(arr, ccr1, ccr2);
  else if (number == 3)
    changeTim3Pwm(arr, ccr1, ccr2);
  else if (number == 4)
    changeTim4Pwm(arr, ccr1, ccr2);
  else if (number == 5)
    changeTim5Pwm(arr, ccr1, ccr2);
}

void runTim2() {
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->PSC = DEFAULT_PSC;
	TIM2->ARR = DEFAULT_ARR ;
	TIM2->EGR = TIM_EGR_UG;
	TIM2->CCR1 = DEFAULT_CCR1;
	TIM2->CCR2 = DEFAULT_CCR2;
	TIM2->CCMR1 = TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_0 | TIM_CCMR1_OC2PE;
	TIM2->CCER = TIM_CCER_CC1E | TIM_CCER_CC1P | TIM_CCER_CC2E | TIM_CCER_CC2P;
	TIM2->CR1 = TIM_CR1_ARPE | TIM_CR1_CEN;
  TIM2->SR = ~(TIM_SR_UIF | TIM_SR_CC1IF);
	TIM2->DIER = TIM_DIER_UIE | TIM_DIER_CC1IE;
	NVIC_EnableIRQ(TIM2_IRQn);
}

void runTim3() {
  RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	TIM3->PSC = DEFAULT_PSC;
	TIM3->ARR = DEFAULT_ARR ;
	TIM3->EGR = TIM_EGR_UG;
	TIM3->CCR1 = DEFAULT_CCR1;
	TIM3->CCR2 = DEFAULT_CCR2;
	GPIOafConfigure(RED_DIOD_GPIO_OUT_TYPE, RED_DIOD_GPIO_OUT_NUMBER, GPIO_OType_PP,GPIO_Low_Speed,GPIO_PuPd_NOPULL, GPIO_AF_TIM3);
	TIM3->CCMR1 = TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_0 | TIM_CCMR1_OC2PE;
	TIM3->CCER = TIM_CCER_CC1E | TIM_CCER_CC1P | TIM_CCER_CC2E | TIM_CCER_CC2P;
	TIM3->CR1 = TIM_CR1_ARPE | TIM_CR1_CEN;
  TIM3->SR = ~(TIM_SR_UIF | TIM_SR_CC1IF);
	TIM3->DIER = TIM_DIER_UIE | TIM_DIER_CC1IE;
}

void runTim4() {
  RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	TIM4->PSC = DEFAULT_PSC;
	TIM4->ARR = DEFAULT_ARR ;
	TIM4->EGR = TIM_EGR_UG;
	TIM4->CCR1 = DEFAULT_CCR1;
	TIM4->CCR2 = DEFAULT_CCR2;
	GPIOafConfigure(BLUE_DIOD_GPIO_OUT_TYPE, BLUE_DIOD_GPIO_OUT_NUMBER, GPIO_OType_PP,GPIO_Low_Speed,GPIO_PuPd_NOPULL, GPIO_AF_TIM4);
	TIM4->CCMR1 = TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_0 | TIM_CCMR1_OC2PE;
	TIM4->CCER = TIM_CCER_CC1E | TIM_CCER_CC1P | TIM_CCER_CC2E | TIM_CCER_CC2P;
	TIM4->CR1 = TIM_CR1_ARPE | TIM_CR1_CEN;
  TIM4->SR = ~(TIM_SR_UIF | TIM_SR_CC1IF);
	TIM4->DIER = TIM_DIER_UIE | TIM_DIER_CC1IE;
}

void runTim5() {
  RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
	TIM5->PSC = DEFAULT_PSC;
	TIM5->ARR = DEFAULT_ARR;
	TIM5->EGR = TIM_EGR_UG;
	TIM5->CCR1 = DEFAULT_CCR1;
	TIM5->CCR2 = DEFAULT_CCR2;
	GPIOafConfigure(GREEN_DIOD_GPIO_OUT_TYPE, GREEN_DIOD_GPIO_OUT_NUMBER, GPIO_OType_PP,GPIO_Low_Speed,GPIO_PuPd_NOPULL, GPIO_AF_TIM5);
	TIM5->CCMR1 = TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_0 | TIM_CCMR1_OC2PE;
	TIM5->CCER = TIM_CCER_CC1E | TIM_CCER_CC1P | TIM_CCER_CC2E | TIM_CCER_CC2P;
	TIM5->CR1 = TIM_CR1_ARPE | TIM_CR1_CEN;
  TIM5->SR = ~(TIM_SR_UIF | TIM_SR_CC1IF);
	TIM5->DIER = TIM_DIER_UIE | TIM_DIER_CC1IE;
}

void runTimers() {
  //RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  //runTim2();
  //runTim3();
	//runTim4();
  //runTim5();
}
