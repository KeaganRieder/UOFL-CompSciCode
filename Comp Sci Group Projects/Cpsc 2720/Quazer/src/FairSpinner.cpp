#include <iostream>
#include "FairSpinner.h"

FairSpinner::FairSpinner(int range) {
  if (range == 1) {
    min = 1;
    max = 8;
  } else if (range == 2) {
    min = 4;
    max = 7;
  }
}
FairSpinner::~FairSpinner() {
}
