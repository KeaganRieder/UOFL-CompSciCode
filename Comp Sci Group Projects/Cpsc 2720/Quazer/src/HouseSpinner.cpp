#include <iostream>
#include "HouseSpinner.h"

HouseSpinner::HouseSpinner(int range) {
  if (range == 1) {
    min = 6;
    max = 8;
  } else if (range == 2) {
    min = 6;
    max = 7;
  }
}
HouseSpinner::~HouseSpinner() {
}
