#ifndef MAIN_LOGIC
#define MAIN_LOGIC

#include "NecIrcProtocol.h"

typedef enum {
  BLUE_ID  = 0x00,
  GREEN_ID = 0x01,
  RED_ID   = 0x02
} DIOD_ID;

struct Data {
  int redFill;
  int blueFill;
  int greenFill;
  DIOD_ID focus;
} data;

#define DEFAULT_FILL  0x00
#define DEFAULT_FOCUS RED_ID
#define MIN_FILL      0x00
#define MAX_FILL      0x64
#define CHANGE_SPEED  0x04

void processCmd(DEVICE_CMD);

#endif
