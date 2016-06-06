#include "irc_ll_api.h"

int getByte(int* bits) {
  int ret = 0;
  int i;
  for(i=0;i<8;i++)
    if(bits[i]==1)
      ret |= (1U << i);
  return ret;
}

void clearBuf() {
  int i;
  for(i=0;i<CMD_FRAME_COUNT;i++)
    ircData.cmd[i]=0;
  ircData.cmdPointer = 0;
}

DEVICE_CMD getDeviceCmd(int value) {
  switch(value) {
    case
  }
}

void processBreak(int actTime) {
  int breakTime = actTime - ircData.lastFrameTs;
  ircData.lastFrameTs = actTime;
  if(breakTime > START_FRAME_TIME) {
    if(ircData.lastFrame == START_FRAME)
      processCmd(ircData.lastCmd);
    clearBuf();
	} else
  if(breakTime > ZERO_FRAME_TIME) {
		ircData.cmd[ircData.cmdPointer++] = 1;
    ircData.lastFrame = ZERO_FRAME;
  } else
	if(breakTime > ONE_FRAME_TIME) {
		ircData.cmd[ircData.cmdPointer++] = 0;
		ircData.lastFrame = ONE_FRAME;
  } 
  if(ircData.cmdPointer == CMD_FRAME_COUNT) {
    ircData.lastCmd = getDeviceCmd(getByte(ircData.cmd+16));
		processCmd(ircData.lastCmd);
	}
}

void EXTI1_IRQHandler(void) {
  EXTI->PR = EXTI_PR_PR1;
  processBreak(getTime());
}

void irc_ll_api_init() {
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN;
  RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
  GPIOinConfigure(IRC_GPIO_OUT_TYPE, IRC_GPIO_OUT_NUMBER, GPIO_OType_OD, EXTI_Mode_Interrupt, EXTI_Trigger_Rising);
  EXTI->PR = EXTI_PR_PR1;
  NVIC_EnableIRQ(EXTI1_IRQn);
  ircData.cmdPointer = 0;
  ircData.lastFrameTs = 0;
  ircData.lastFrame = UNKNOWN_FRAME;
}


