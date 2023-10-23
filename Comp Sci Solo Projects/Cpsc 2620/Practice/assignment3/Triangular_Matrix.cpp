#include "Triangular_Matrix.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//implementation of class Triangular Matrix
//constructors
TriangularMatrix::TriangularMatrix(int size, double element)
  :StructuredMatrix(size , element) {
}

TriangularMatrix::~TriangularMatrix() {delete [] matrix;}
