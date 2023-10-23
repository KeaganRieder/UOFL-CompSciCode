#ifndef PLAYERSPINNER_H
#define PLAYERSPINNER_H
#include "Spinners.h"
#include <iostream>

class PlayerSpinner : public Spinners {
 public:
  PlayerSpinner(int range);
  virtual ~PlayerSpinner();
};

#endif
