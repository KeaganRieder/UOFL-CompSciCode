//test program for CMatrixPro class
#include "MatrixPro2.h"

using namespace std;

const int MATRIX_SIZE = 3; //size for matrix 1
const int MATRIX2_SIZE = MATRIX_SIZE; //size for matrix 2

//main loop
int main(){

  //creating base matrix objects
  CMatrixPro matrixA(MATRIX_SIZE);
  CMatrixPro matrixB(MATRIX2_SIZE);

  cout <<"> CMatrixPro2 class Test "<< endl;
  cout << setw(40)<< setfill('#')<<' '<< endl <<endl;
  //testing reading in values
  cout << "> reading input for matrix A"<<endl;
  cin >> matrixA;
  cout << "> reading input for matrix B"<<endl;
  cin >> matrixB;

  cout << setw(40)<< setfill('#')<<' '<< endl <<endl;
  //testing output
  cout << matrixA;
  cout << matrixB;

  //tetsing math
  cout << setw(40)<< setfill('#')<<' '<< endl <<endl;
  cout << "> testing Math Functions"<<endl;

  CMatrixPro MathMatrix(MATRIX_SIZE);
  //math with constants and a matrix
  cout << "> Math with constants"<<endl;
  cout << "> adding constant 5 to matrixA "<<endl;
  MathMatrix = matrixA + 5;
  cout << MathMatrix;

  cout << "> subtracting constant 6 from matrixB "<<endl;
  MathMatrix = matrixB - 6;
  cout << MathMatrix;

  cout << "> multipling matrixB 6 by constant"<<endl;
  MathMatrix = matrixB * 6;
  cout << MathMatrix;

  //testing math between matrixs
  cout << setw(40)<< setfill('#')<<' '<< endl <<endl;;
  cout << "> Math between matrixs"<<endl;

  cout<< "matrixA"<<endl;
  cout << matrixA;
  cout<< "matrixB"<<endl;
  cout << matrixB;

  cout << "> Adding matrixB to matrixA "<<endl;
  MathMatrix = (matrixA + matrixB);
  cout << MathMatrix;

  cout << "> subtracting matrixA from matrixB "<<endl;
  MathMatrix = (matrixB - matrixA);
  cout << MathMatrix;

  cout << "> Multiply matrixA to matrixB "<<endl;
  MathMatrix = (matrixB * matrixA);
  cout<< MathMatrix;

  //testing compund math operations
  CMatrixPro matrixACopy(matrixA);
  CMatrixPro matrixBCopy(matrixB);

  cout << setw(40)<< setfill('#')<<' '<< endl <<endl;
  cout << "> testing Compound Math Functions"<<endl;

  CMatrixPro matrixC(MATRIX_SIZE);
  CMatrixPro matrixD(MATRIX2_SIZE);
  cout<< "reading for matrixC"<<endl;
  cin >> matrixC;
  cout<< "reading for matrixD"<<endl;
  cin >> matrixD;



  cout<< "matrixC"<< endl;
  cout<< matrixC;
  cout<< "matrixD"<< endl;
  cout<< matrixD;
  //math with constants and a matrix

  cout << "> Math with constants"<<endl;
  cout << "> adding constant 4 to matrixC "<<endl;
  matrixC += 4;
  cout<< matrixC;

  cout << "> subtracting constant 4 from matrixC "<<endl;
  matrixC -= 4;
  cout<< matrixC;

  cout << "> multipling matrixD 3 by constant"<<endl;
  matrixD *= 3;
  cout<< matrixD;

  //testing math between matrixs
  cout << setw(40)<< setfill('#')<<' '<< endl <<endl;
  cout << "> Math between matrixs"<<endl;
  CMatrixPro matrixE(MATRIX_SIZE);
  CMatrixPro matrixF(MATRIX2_SIZE);
  cout << "> reading input for matrixE"<<endl;
  cin >> matrixE;
  cout << "> reading input for matrixF"<<endl;
  cin >> matrixF;
  cout << "> Adding matrixF to matrixE "<<endl;
  matrixE += matrixF;
  cout<< matrixE;
  cout << "> subtracting matrixF from matrixE "<<endl;
  matrixE -= matrixF;
  cout<< matrixE;

  cout << "> Multiply matrixE to matrixF "<<endl;
  matrixE *= matrixF;
  cout<< matrixE;

  //testing copying of differnt size

  cout << setw(40)<< setfill('#')<<' '<< endl <<endl;
  cout << "> testing copying matrix of differnt size"<<endl;
  CMatrixPro difSizeMatrix(4);
  cin >> difSizeMatrix;
  cout << difSizeMatrix;
  cout << matrixACopy;
  matrixACopy = difSizeMatrix;
  cout << matrixACopy;

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
    matrixB.MakeIdentity();
    cout<<matrixB;
  }

  if (matrixA.IsIdentity()) {
    cout<<"> identity matrix is "<<endl;
    cout<<matrixA;
  }
  else{
    cout<<"> making matrixA's identity matrix"<<endl;
    matrixA.MakeIdentity();
    cout<<matrixA;
  }

  return 0;
}
