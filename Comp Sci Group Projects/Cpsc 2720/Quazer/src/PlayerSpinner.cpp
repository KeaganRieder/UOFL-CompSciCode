#include <iostream>
#include "PlayerSpinner.h"

PlayerSpinner::PlayerSpinner(int range) {
  if (range == 1) {
    min = 1;
    max = 5;
  } else if (range == 2) {
    min = 4;
    max = 5;
  }
}
PlayerSpinner::~PlayerSpinner() {
}

