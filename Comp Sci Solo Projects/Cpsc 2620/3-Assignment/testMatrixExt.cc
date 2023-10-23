//test file for MatrixExt
#include "MatrixExt.h" //figure out how to make .h work an not .cc
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

//const varibles to changes
//for testing
const  int MATRIX_SIZE = 3;
const  int MATRIX_SIZE2 = MATRIX_SIZE;
const  int ADD_CONST = 5;
const  int SUB_CONST = 5;
const  int MULTI_CONST = 5;

//main program loop
int main() {
  //making MatrixExt objects
  //making two x by x matrix
  CMatrixExt matrixA(MATRIX_SIZE);
  CMatrixExt matrixB(MATRIX_SIZE2);

  //main program loop
  cout<<"> CMatrixExt class Test "<< endl << endl;

  //getting input and print out the intial matrix
  cout<<"> matrixA input "<< endl;
  matrixA.ReadMatrix();

  cout<<"> matrixB input "<< endl;
  matrixB.ReadMatrix();

  cout<<"> Before testing of math"<< endl;
  cout<<"> matrixA: "<< endl;
  matrixA.PrintMatrix();

  cout<<"> matrixB: "<< endl;
  matrixB.PrintMatrix();

  //testing math
  cout<< " ###################################################################### " <<endl <<endl;
  cout<< endl<< "> CMatrixExt math function test "<< endl;
  cout << "> constant test " << endl;
  //tetsing math with constants
  cout<< "> adding constant " << ADD_CONST <<" to matrixA test "<< endl;
  matrixA.AddMatrix(ADD_CONST).PrintMatrix();

  cout<< "> subtracting constant "<< SUB_CONST << " to matrixA test " << endl;
  matrixA.SubtractMatrix(SUB_CONST).PrintMatrix();

  cout<< "> Multiply constant " << MULTI_CONST << " to matrixA test " << endl;
  matrixA.MultiplyMatrix(MULTI_CONST).PrintMatrix();

  cout<< endl;
  cout<< "> adding constant " << ADD_CONST <<" to matrixB test "<< endl;
  matrixB.AddMatrix(ADD_CONST).PrintMatrix();

  cout<< "> subtracting constant "<< SUB_CONST << " to matrixB test " << endl;
  matrixB.SubtractMatrix(SUB_CONST).PrintMatrix();

  cout<< "> Multiply constant " << MULTI_CONST << " to matrixB test " << endl;
  matrixB.MultiplyMatrix(MULTI_CONST).PrintMatrix();

  //testing matix math with otehr matrixs
  cout<< "> with other matries test "<< endl;
  cout<< "> adding matrixA to matrixB test "<< endl;
  matrixB.AddMatrix(matrixA).PrintMatrix();

  cout<< "> subtracting matrixA from matrixB test "<< endl;
  matrixB.SubtractMatrix(matrixA).PrintMatrix();

  cout<< "> Multiplying matrixA to matrixB test "<< endl;
  matrixB.MultiplyMatrix(matrixA).PrintMatrix();

  //making sure matrixs are left unchnaged
  cout<<endl << " ###################################################################### " << endl <<endl;
  cout<<"> following math on matrixs"<< endl;
  cout<<"> matrixA: "<< endl;
  matrixA.PrintMatrix();

  cout<<"> matrixB: "<< endl;
  matrixB.PrintMatrix();

  //testing bool functions
  cout<<endl << " ###################################################################### " << endl <<endl;
  cout<<"> is matrixA equal to matrixB"<<endl;
  if (matrixA.IsEqual(matrixB)) {
    cout<<"> yes it is equal"<<endl;
  }
  else{
    cout<<"> no it is not equal"<<endl;
  }

  cout <<endl <<"> is matrixA smaller then matrixB"<<endl;
  if (matrixA.IsSmaller(matrixB)) {
    cout<<"> yes it is smaller"<<endl;
  }
  else{
    cout<<"> no it is not smaller"<<endl;
  }
  cout <<endl <<"> is matrixA bigger then matrixB"<<endl;
  if (matrixA.IsBigger(matrixB)) {
    cout<<"> yes it is bigger"<<endl;
  }
  else{
    cout<<"> no it is not bigger"<<endl;
  }

  //testing identy matrix stuff
  //for matrixB
  cout<<endl << " ###################################################################### " <<endl <<endl;
  cout<<"> identity test for matrixB"<<endl;
  if (matrixB.IsIdentity()) {
    cout<<"> identity matrix is "<<endl;
    matrixB.PrintMatrix();
  }
  else
  {
    cout<<"> making matrixB into identity matrix"<<endl;
    matrixB.MakeIdentity();
    matrixB.PrintMatrix();
  }

  //for matrixA
  cout<<endl << " ###################################################################### " <<endl <<endl;
  cout<< "> for matrixA"<<endl;
  cout<<"> identity test for matrixA"<<endl;
  if (matrixA.IsIdentity()) {
    cout<<"> identity matrix is "<<endl;
      matrixA.PrintMatrix();
  }
  else
  {
    cout<<"> making matrixA into identity matrix"<<endl;
    matrixA.MakeIdentity();
    matrixA.PrintMatrix();
  }

  cout<<endl << " ###################################################################### " <<endl <<endl;

  cout<< "> end of tests for CMatrixExt program"<<endl;
  return 0;
}
