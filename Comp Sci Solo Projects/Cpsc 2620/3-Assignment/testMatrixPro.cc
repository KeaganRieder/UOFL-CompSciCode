//test program for CMatrixPro class
#include "MatrixPro.h"

using namespace std;

const int MATRIX_SIZE = 3; //size for matrix 1
const int MATRIX2_SIZE = MATRIX_SIZE; //size for matrix 2

//main loop
int main(){

  //creating base matrix objects
  CMatrixPro matrixA(MATRIX_SIZE);
  CMatrixPro matrixB(MATRIX2_SIZE);

  cout <<"> CMatrixPro class Test "<< endl;
  cout << setw(40)<< setfill('#')<<' '<< endl <<endl;
  //testing reading in values
  cout << "> reading input for matrix 1"<<endl;
  cin >> matrixA;
  cout << "> reading input for matrix 2"<<endl;
  cin >> matrixB;

  cout << setw(40)<< setfill('#')<<' '<< endl <<endl;
  //testing output
  cout << matrixA;
  cout << matrixB;

  //tetsing math
  cout << setw(40)<< setfill('#')<<' '<< endl <<endl;
  cout << "> testing Math Functions"<<endl;
  CMatrixPro matrixACopy = matrixA;
  CMatrixPro matrixBCopy = matrixB;

  //math with constants and a matrix
  cout << "> Math with constants"<<endl;
  cout << "> adding constant to matrixA "<<endl;

  CMatrixPro sumMatrix = matrixA + 5 + 1;
  matrixA = matrixACopy;
  cout << sumMatrix;

  cout << "> subtracting constant from matrixB "<<endl;
  CMatrixPro difMatrix = matrixB - 6;
  matrixB = matrixBCopy;
  cout << difMatrix;

  cout << "> multipling matrixB by constant"<<endl;
  CMatrixPro prodMatirx = matrixB * 6;
  matrixB = matrixBCopy;
  cout << prodMatirx;

  cout << "> perfoming all operation using "<< endl
  <<"> constants on matrixA "<< endl;
  CMatrixPro allOpMatrix = matrixA + 10 * 6 -2;
  matrixA = matrixACopy;
  cout << allOpMatrix;

  //testing math between matrixs
  cout << setw(40)<< setfill('#')<<' '<< endl <<endl;;
  cout << "> Math between matrixs"<<endl;

  cout << "> Adding matrixB to matrixA "<<endl;
  sumMatrix = matrixA + matrixB;
  matrixA = matrixACopy;
  cout << sumMatrix;

  cout << "> subtracting matrixA from matrixB "<<endl;
  difMatrix = matrixB - matrixA;
  matrixB = matrixBCopy;
  cout << difMatrix;

  cout << "> Multiply matrixA to matrixB "<<endl;
  prodMatirx = matrixB * matrixA;
  cout<< prodMatirx;
  matrixB = matrixBCopy;

  //tetsing bool functions
  cout<< setw(40)<< setfill('#')<<' '<< endl <<endl;
  cout<< "> testing bool functions"<<endl;
  //comparing
  if (matrixA == matrixB) {
    cout<< "> matrixA is equal to matrixB" << endl;
  }
  else{
    cout<< "> matrixA is not equal to  matrixB" << endl;
  }

  if (matrixA < matrixB) {
    cout<< "> matrixA is less than  matrixB" << endl;
  }
  else{
    cout<< "> matrixA is not less than  matrixB" << endl;
  }

  if (matrixA > matrixB) {
    cout<< "> matrixA is more than  matrixB" << endl;
  }
  else{
    cout<< "> matrixA is not more than  matrixB" << endl;
  }

  //for matrix b
  if (matrixB < matrixA) {
    cout<< "> matrixB is less than  matrixA" << endl;
  }
  else{
    cout<< "> matrixB is not less than  matrixA" << endl;
  }

  if (matrixB > matrixA) {
    cout<< "> matrixB is more than  matrixA" << endl;
  }
  else{
    cout<< "> matrixB is not more than  matrixA" << endl;
  }


  cout<< endl;
//identy matrixs
  if (matrixB.IsIdentity()) {
    cout<<"> identity matrix is "<<endl;
    cout<<matrixB;
  }
  else{
    cout<<"> making matrixB's identity matrix"<<endl;
    matrixBCopy.MakeIdentity();
    cout<<matrixBCopy;
  }

  if (matrixA.IsIdentity()) {
    cout<<"> identity matrix is "<<endl;
    cout<<matrixACopy;
  }
  else{
    cout<<"> making matrixA's identity matrix"<<endl;
    matrixACopy.MakeIdentity();
    cout<<matrixACopy;
  }

  return 0;
}
