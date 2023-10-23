#include <iostream>
#include <random>
#include <ctime>
#include "Spinners.h"

Spinners::Spinners() {
}  //constructor
Spinners::~Spinners() {
}  //destructor

int Spinners::Run() {
//  std::cout<<"min:"<<min<<" max:"<<max<<std::endl;// debugging
  std::default_random_engine doSpinning(std::time(0));
  std::uniform_int_distribution<int> range(min, max);
  int spin = 0;
  for (int i = 0; i < 5; i++) {
    spin = range(doSpinning);
//    std::cout<<spin<<std::endl; //debuging
  }

  return spin;
}
