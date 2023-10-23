#ifndef LOWER_TRIANGULAR_MATRIX
#define LOWER_TRIANGULAR_MATRIX
#include "Triangular_Matrix.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LowerTriangularMatrix : public TriangularMatrix{
public:
  //constructors
  /*conditions
  //acts as default constructor if no argument is supplied
  //precondition: none
  //postCondition: a Lower Triangular Matrix Object is created with the paramiters of size and elements
  */
  LowerTriangularMatrix(int size = 0, double element = 0.0);
  //indexs
  /*conditions
  //precondition: none
  //postCondition: returns constant elements in matrix object from the given
  //row and coloums
  */
   const double& operator()(int rows, int coloums) const;
  /*conditions
  //precondition: none
  //postCondition: returns non constant elements in matrix object from the given
  //row and coloums
  */
  double& operator()(int rows, int coloums);
  //caculations
  double sum();
  //output
  void print();

protected:
  //forms a Lower Triangular Matrix, setting 0 in the left
  //upper half to 0
  void FormMatrix(double element);
};
#endif
