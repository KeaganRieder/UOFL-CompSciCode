#include "Symmetric_Tridiagonal_Matrix.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//implementation of class Upper Tridiagonal Matrix //change to constructr stuff
//constructors
SymmetricTridiagonalMatrix::SymmetricTridiagonalMatrix(int size, double element)
  :SymmetricMatrix(size , element){
    FormMatrix(element);
}

void SymmetricTridiagonalMatrix::FormMatrix(double element){//todo
  int currentPos = 0;
  matrix = new double[matrixSize];

  for (int i = 0; i < thisRow; i++) {
    for (int j = 0; j < thisColoum; j++) {
      //check for diagonal
      if (i == j) {
        matrix[currentPos] = element;
      }
      //check upper diagonal
      else if (i < j && i == j-1) {
        matrix[currentPos] = element;
      }
      //check lower diagonal
      else if (i > j && j == i-1) {
        matrix[currentPos] = element;
      }
      //other wise it's just zero
      else{
        matrix[currentPos] = 0;
      }
      currentPos++;
    }
  }

}

//indexs
double& SymmetricTridiagonalMatrix::operator()(int row, int coloum){
  return matrix[row + coloum];
}
const double& SymmetricTridiagonalMatrix::operator()(int row, int coloum) const{
  return matrix[row + coloum];
}

//caculations
double SymmetricTridiagonalMatrix::sum(){
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
void SymmetricTridiagonalMatrix::print(){
  int currentPos = 0;
  cout<<"Here is a Symmetric Tridiagonal Matrix with"<<endl
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
