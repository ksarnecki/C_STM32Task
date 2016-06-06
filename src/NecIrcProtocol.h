#ifndef IRC_PROTOCOL
#define IRC_PROTOCOL

#include "../uart/uart_soft.h"
#include "../diods/diods_hl_api.h"
#include "../timer/timer_ll_api.h"
#include "irc_hl_api.h"

#define PB1_IDR 1U << 1
// ilosc bitow w komendzie
#define CMD_FRAME_COUNT 32

// poczatek ramki ~130 cykli wysokiego stanu
#define START_FRAME_TIME	130

// logiczna 1 ~55 cykli wysokiego stanu
#define ZERO_FRAME_TIME		55

// logiczne 0 ~25 cykli wysokiego stanu
#define ONE_FRAME_TIME		25

typedef enum  {
  UNKNOWN_FRAME = 0x00,
  START_FRAME = 0x01,
  ZERO_FRAME = 0x2,
  ONE_FRAME = 0x3
} FRAME_TYPE;

struct Irc_control_data {
  int cmd[CMD_FRAME_COUNT];
  int cmdPointer;
  int lastFrameTs;
  int lastCmd;
  FRAME_TYPE lastFrame;
  int repeat;
} irc_protocol_data;

void irc_ll_api_init();

#endif
