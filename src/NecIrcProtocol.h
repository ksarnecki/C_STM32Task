#ifndef IRC_PROTOCOL
#define IRC_PROTOCOL

/*#include "../uart/uart_soft.h"
#include "../diods/diods_hl_api.h"
#include "../timer/timer_ll_api.h"
#include "irc_hl_api.h"*/
#include "Config.h"


//protokol
#define START_FRAME_TIME	  0x82 // poczatek ramki ~130 cykli wysokiego stanu
#define ZERO_FRAME_TIME		  0x37 // logiczna 1 ~55 cykli wysokiego stanu
#define ONE_FRAME_TIME		  0x19 // logiczne 0 ~25 cykli wysokiego stanu
#define CMD_FRAME_COUNT		  0x29 // ilosc bitow w komendzie

//typy
typedef enum  {
  UNKNOWN_FRAME = 0x00,
  START_FRAME = 0x01,
  ZERO_FRAME = 0x2,
  ONE_FRAME = 0x3
} IRC_FRAME;

typedef enum {
  UNKNOWN = 0x0,
  INC_SOUND = 0x72,
  DEC_SOUND = 0x73, 
  TURN_OFF = 0x20,
  TURN_ON = 0x8,
  BUTTON_ONE = 0x99,
  BUTTON_TWO = 0x98,
  BUTTON_THREE = 0x97
} DEVICE_CMD;

struct IrcData {
  int cmd[CMD_FRAME_COUNT];
  int cmdPointer;
  int lastFrameTs;
  int lastCmd;
  IRC_FRAME lastFrame;
  int repeat;
} ircData;

//funkcje
void runIrc();

#endif
