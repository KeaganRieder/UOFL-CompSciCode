#ifndef FAIRSPINNER_H
#define FAIRSPINNER_H
#include "Spinners.h"
#include <iostream>

class FairSpinner : public Spinners {
 public:
  FairSpinner(int range);
  virtual ~FairSpinner();
};

#endif
