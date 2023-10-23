#ifndef STRUCTURED_MATRIX
#define STRUCTURED_MATRIX
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StructuredMatrix{
public:
  //constructors
  /*conditions
  //acts as default constructor if no argument is supplied
  //precondition: none
  //postCondition: a sturcturedMatrix Object is created with the paramiters of size and elements
  */
  StructuredMatrix(int size = 0, double element = 0.0);

  //indexs
  /*conditions
  //precondition: none
  //postCondition: returns constant elements in matrix object from the given
  //row and coloums
  */
  virtual const double& operator()(int rows, int coloums) const = 0;
  /*conditions
  //precondition: none
  //postCondition: returns non constant elements in matrix object from the given
  //row and coloums
  */
  virtual double& operator()(int rows, int coloums) = 0;

  //caculations
  virtual double sum() = 0; //finds the sum of a matrixs contents

  //output
  virtual void print() = 0;

protected:
  virtual void FormMatrix(double element) = 0; //forms matrixs
  virtual void SetSize(int size);//sets the size of the matrix, based on paramiter int size
  //varibles
  int thisRow;
  int thisColoum;
  int matrixSize;
  double *matrix;
};

#endif
