#include "TimerSoftware.h"

void changeGreenFill (const int fill) {
  changePwmState(3, FULL_FILL, fill/2, FULL_FILL -(percent/2));
}

void changeRedFill (const int fill) {
  changePwmState(4, FULL_FILL, fill/2, FULL_FILL -(percent/2));
}

void changeBlueFill (const int fill) {
  changePwmState(5, FULL_FILL, fill/2, FULL_FILL -(percent/2));

}