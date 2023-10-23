#include "Structured_Matrix.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//implementation of class Structured Matrix
//constructors
StructuredMatrix::StructuredMatrix(int size, double element){
  SetSize(size);
}

void StructuredMatrix::SetSize(int size){
  thisRow = size;
  thisColoum = size;
  matrixSize = thisRow * thisColoum;
}
