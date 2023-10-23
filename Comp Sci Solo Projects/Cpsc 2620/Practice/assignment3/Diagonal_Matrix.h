#ifndef DIAGONAL_MATRIX
#define DIAGONAL_MATRIX
#include "Symmetric_Matrix.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DiagonalMatrix : public SymmetricMatrix{
public:
  //constructors
  /*conditions
  //acts as default constructor if no argument is supplied
  //precondition: none
  //postCondition: a Diagonal Matrix Object is created with the paramiters of size and elements
  */
  DiagonalMatrix(int size = 0, double element = 0.0);

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
  void FormMatrix(double element);

};
#endif
