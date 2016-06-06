#include "MainLogic.h"

void onStart() {
  data.redFill = DEFAULT_FILL;
	data.greenFill = DEFAULT_FILL;
  data.blueFill = DEFAULT_FILL;
  data.focus = DEFAULT_FOCUS;
  data.changed = true;
}

void processCmd(DEVICE_CMD cmd) {
  if(!data.changed)
    onStart();
  
  int* fill;
    
  switch(data.focus) {
    case GREEN_ID:
			fill = & data.greenFill;
			break;
		case RED_ID:
			fill = & data.redFill;
			break;
		case BLUE_ID:
			fill = & data.blueFill;
			break;
		return;
	}

  switch (cmd) {
		case TURN_ON:
			*fill = MAXFill;
			break;
		case TURN_OFF:
			*fill = MINFill;
			break;
		case INC_SOUND:
			if(*fill<=MAXFill-CHANGE_SPEED)
				*fill+=CHANGE_SPEED;
			break;
		case DEC_SOUND:
			if(*fill>=CHANGE_SPEED)
				*fill-=CHANGE_SPEED;
	}
  
  switch(data.focus) {
    case GREEN_ID:
			changeGreenFill(data.greenFill);
			break;
		case RED_ID:
			changeRedFill(data.redFill);
			break;
		case BLUE_ID:
			changeRedFill(data.blueFill);
			break;
		return;
	}
}