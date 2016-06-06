#include "NecIrcProtocol.h"

int getByte(int* bits) {
  int ret = 0;
  int i;
  for(i=0;i<8;i++)
    if(bits[i]==1) {
			ret |= (1U << i);
		}
  return ret;
}

void process(int time) {
  int t = time-irc_protocol_data.lastFrameTs;
  irc_protocol_data.lastFrameTs = time;
  if(t > START_FRAME_TIME) {
    if(irc_protocol_data.lastFrame == START_FRAME)
			irc_hl_api_process_remote_cmd(irc_protocol_data.lastCmd);
		irc_protocol_data.lastFrame = START_FRAME;
		int i;
		for(i=0;i<CMD_FRAME_COUNT;i++)
			irc_protocol_data.cmd[i]=0;
		irc_protocol_data.cmdPointer = 0;
	} else
  if(t > ZERO_FRAME_TIME) {
		irc_protocol_data.cmd[irc_protocol_data.cmdPointer++] = 1;
    irc_protocol_data.lastFrame = ZERO_FRAME;
  } else
	if(t > ONE_FRAME_TIME) {
		irc_protocol_data.cmd[irc_protocol_data.cmdPointer++] = 0;
		irc_protocol_data.lastFrame = ONE_FRAME;
  } 
  if(irc_protocol_data.cmdPointer==CMD_FRAME_COUNT) {
    irc_protocol_data.lastCmd = getByte(irc_protocol_data.cmd+16);
		irc_hl_api_process_remote_cmd(irc_protocol_data.lastCmd);
    //sendInt(getByte(irc_protocol_data.cmd));
		//sendInt(getByte(irc_protocol_data.cmd+8));
		//sendInt(getByte(irc_protocol_data.cmd+16));
		//sendInt(getByte(irc_protocol_data.cmd+24));
	}
}

void EXTI1_IRQHandler(void) {
  EXTI->PR = EXTI_PR_PR1;
  process(getTime());
}

void runIrc() {
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN;
  RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
  GPIOinConfigure(GPIOB, 0x1, GPIO_OType_OD, EXTI_Mode_Interrupt, EXTI_Trigger_Rising);
  EXTI->PR = EXTI_PR_PR1;
  NVIC_EnableIRQ(EXTI1_IRQn);
  irc_protocol_data.cmdPointer = 0;
  irc_protocol_data.lastFrameTs = 0;
  irc_protocol_data.lastFrame = UNKNOWN_FRAME;
}


