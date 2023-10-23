#ifndef SPINNERS_H
#define SPINNERS_H

class Spinners {
 public:
  Spinners();  //constructor
  virtual ~Spinners();  //destructor

  //methods
  int Run();
  //called by objects of the sub class
  //by taking into account the particular values of min and max,
  //it generates/returns a random number that is in the desired range
  //(i.e. it does the spinning)
  //variables
  int min;
  int max;
};

#endif
