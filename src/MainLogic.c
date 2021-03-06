#include "MainLogic.h"


void processCmd(DEVICE_CMD cmd) {
  
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
			*fill = MAX_FILL;
			break;
		case TURN_OFF:
			*fill = MIN_FILL;
			break;
		case INC_SOUND:
			if (*fill <= MAX_FILL - CHANGE_SPEED)
				*fill += CHANGE_SPEED;
			break;
		case DEC_SOUND:
			if (*fill >= CHANGE_SPEED)
				*fill -= CHANGE_SPEED;
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
