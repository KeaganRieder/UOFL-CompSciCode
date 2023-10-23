#include "Symmetric_Matrix.h"
#include <string>
#include <vector>
using namespace std;

//implementation of class Symmetric Matrix
//constructors
SymmetricMatrix::SymmetricMatrix(int size, double element)
  :StructuredMatrix(size, element){

  }

  SymmetricMatrix::~SymmetricMatrix() {delete [] matrix;}
