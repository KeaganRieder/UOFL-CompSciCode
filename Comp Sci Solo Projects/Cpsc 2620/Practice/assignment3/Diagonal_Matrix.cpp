#include "Diagonal_Matrix.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//implementation of class Upper Tridiagonal Matrix
//constructors
DiagonalMatrix::DiagonalMatrix(int size, double element)
  :SymmetricMatrix(size , element){
  FormMatrix(element);
}

void DiagonalMatrix::FormMatrix(double element){
  int currentPos = 0;
  matrix = new double[matrixSize];
  for (int i = 0; i < thisRow; i++) {
    for (int j = 0; j < thisColoum; j++) {
      //check to see if zero or non zero num
      //diagonal
      if (i == j) {
        matrix[currentPos] = element;
      }
      else{
        matrix[currentPos] = 0;
      }
      currentPos++;
    }
  }
}

//indexs
double& DiagonalMatrix::operator()(int row, int coloum){
  return matrix[row + coloum];
}
const double& DiagonalMatrix::operator()(int row, int coloum) const{
  return matrix[row + coloum];
}

//caculations
double DiagonalMatrix::sum(){
  double sumOfContents = 0;
  double tempDouble = 0;
  for (int i = 0; i < matrixSize; i++) {
    if (matrix[i] < 0) {
      tempDouble = matrix[i] * -1;
      sumOfContents = sumOfContents + tempDouble;
    }
    else {
    sumOfContents = sumOfContents + matrix[i];
  }
}
return sumOfContents;
}

//output
void DiagonalMatrix::print(){
  int currentPos = 0;
  cout<<"Here is a Diagonal Matrix with"<<endl
      <<"rows: "<< thisRow <<" coloums:"<< thisColoum <<" size: "<< matrixSize
      <<endl<<endl;

  for (int i = 0; i < thisRow; i++) {
    cout << "| ";
    for (int j = 0; j < thisColoum; j++) {
      cout<<matrix[currentPos]<<" ";
      currentPos++;
    }
    cout<<"|"<<endl;
  }
  cout<<endl<<"the sum of the matrix contents is: "<<sum()<<endl<<endl;
}
