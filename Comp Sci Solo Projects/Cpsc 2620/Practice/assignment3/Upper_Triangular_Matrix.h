#ifndef UPPER_TRIANGULAR_MATRIX
#define UPPER_TRIANGULAR_MATRIX
#include "Triangular_Matrix.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class UpperTriangularMatrix : public TriangularMatrix {
public:
  //constructors
  /*conditions
  //acts as default constructor if no argument is supplied
  //precondition: none
  //postCondition: a Upper Triangular Matrix Object is created with the paramiters of size and elements
  */
  UpperTriangularMatrix(int size = 0, double = 0.0);

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
  //forms a matrix
  void FormMatrix(double element);
  
};
#endif
