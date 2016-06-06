
#include "diods/diods_hl_api.h"
#include "uart/uart_soft.h"
#include "timer/timer_ll_api.h"

int main() {
  
  diodsInitSoft();
  diodsInitHardware();
  uartInitHardware();
  
  timer_ll_api_init();

  irc_ll_api_init();
  irc_hl_api_init();

  send("conf ok\r\n", 9);
  return 0;
}


