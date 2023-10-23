#ifndef HOUSESPINNER_H
#define HOUSESPINNER_H
#include "Spinners.h"
#include <iostream>

class HouseSpinner : public Spinners {
 public:
  HouseSpinner(int range);
  virtual ~HouseSpinner();
};

#endif
