//matrix class implemntation

#include "assert.h"
#include <string>

#include "Matrix.h"

using namespace std;


//# constructors #
//default constructer
CMatrix::CMatrix(){
  dimension = 0;
}

//override constructer that sets length of array to n
//and all elemnts to 0
CMatrix::CMatrix(int n){
  dimension = n;
  //creating a new matrix, that is n x n
  AllocateMatrixMemory();
  //setting the elements in matrix to 0
  for (int i = 0; i < dimension; i++) {
    for (int j = 0; j < dimension; j++) {
      matrix[i][j] = 0;
    }
  }
}

//# modifing elements of matrix #
int CMatrix::ReplaceElementAt(int i, int j, int newInt){
  //checking to see if i or j are out of index
  assert(i >= 0);
  assert(i <= dimension);
  assert(j >= 0);
  assert(j <= dimension);

  int oldValue = GetElementAt(i,j);
  matrix[i][j] = newInt;
  return oldValue;
}

//set element at pos (i,j) to be 1
int CMatrix::SetElementAt(int i, int j){
return ReplaceElementAt( i,  j, 1);
}
//deleting element at pos(i,j), which just means to set the value to 0
int CMatrix::ClearElementAt(int i, int j){
  return ReplaceElementAt(i, j, 0);
}
//swaping elment at pos(i1,j1) with elemnt at pos(i2,j2)
void CMatrix::SwapElementsAt(int i1, int j1, int i2, int j2){
  //checking to see if i1 or j1 are out of index
  assert(i1 >= 0);
  assert(i1 <= dimension);
  assert(j1 >= 0);
  assert(j1 <= dimension);
  //checking to see if i2 or j2 are out of index
  assert(i2 >= 0);
  assert(i2 <= dimension);
  assert(j2 >= 0);
  assert(j2 <= dimension);
  //repalces value at i1,j1 and then sets value at i2,j2
  // to i1,j1 old value
  matrix[i2][j2] = ReplaceElementAt(i1, j1, matrix[i2][j2]);
}
//adds constant to each element
//check
void CMatrix::AddConstant(int constant){ //adds constant
    for (int i = 0; i < GetDimension(); i++) {
    for (int j = 0; j < GetDimension(); j++) {
      matrix[i][j] = matrix[i][j] + constant;
    }
  }
}

//reads n x n elements
void CMatrix::ReadMatrix(){
  int inputNum = 0;
  for (int i = 0; i < GetDimension(); i++) {
    for (int j = 0; j < GetDimension(); j++) {
      cout << "> Input matrix element at (" << i
      << ", " << j <<"): ";
      cin >> inputNum;
      matrix[i][j] = inputNum;
    }
  }
  cout<< "> done reading input for matrix elements." << endl<<endl;
  //cin.ignore() is used to clear the input line for
  //get line to run correctly and not atuomatically filled with
  //garbage following a cin
  cin.ignore();
}

//# modfing size of array #
void CMatrix::ResizeMatrix(unsigned int newSize){
  //checking for miss input, to see if newSize = dimension
  //cheacking to make sure that newSize != the matrixs current size.
  //doing this to avoid running unesccery process if there was a mis input
  if (newSize != (unsigned)GetDimension()) {
    //create a temp 2 dimensional array
    int **tempArray = new int*[newSize]; //rows
    for (size_t i = 0; i < newSize; i++) {
      tempArray[i] = new int[newSize];//coloums
    }

    //setting temps elments to be equal to that of matrix elemnts
    //but first checking to see if temp is smaller or bigger to
    //know how long for needs to run.
    //new array is bigger then then old
    if (newSize > (unsigned)GetDimension()) {
      //intaizling all elements to 0 and then setting them to elements
      //in old matrix
      for (size_t i = 0; i < newSize; i++) {
        for (size_t j = 0; j < newSize; j++) {
          tempArray[i][j] = 0 ;
        }
      }
      for (int i = 0; i < GetDimension(); i++) {//running rows
        for (int j = 0; j < GetDimension(); j++) {//running coloums
          tempArray[i][j] = GetElementAt(i,j);
        }
      }
      cout << "> the matrix's size has grown from " <<  GetDimension() << endl
      << "> to " << newSize << endl;
    }

    //new array is smaller then old array
    else{
      //intaizling all elements to 0 and then setting them to elements
      //in old matrix
      for (size_t i = 0; i < newSize; i++) {
        for (size_t j = 0; j < newSize; j++) {
          tempArray[i][j] = 0 ;
        }
      }
      for (size_t i = 0; i < newSize; i++) {//running rows
        for (size_t j = 0; j < newSize; j++) {//running coloums
          tempArray[i][j] = GetElementAt(i,j);
        }
      }
      cout << "> the matrix's size has Shrunk from " <<  GetDimension() << endl
      << "> to " << newSize << endl;
    }
    //setting matrix to new tempArray
    //and dimension to newSize
    //first dealcoating memory used by old matrix array
    DeallocateMatrixMemory();
    matrix = tempArray;
    dimension = newSize;
  }
  else{
    cout<<"> matrix is already size"<<newSize<<endl;
  }
}

//# geting information about matrixC #
int CMatrix::GetDimension(){
  return dimension;
}

int CMatrix::GetElementAt(int i, int j){
//checking to see if i or j are out of index
  assert(i >= 0);
  assert(i <= dimension);
  assert(j >= 0);
  assert(j <= dimension);

  //checking if i, j are in matrix range
  //running through matrix to get element at row i
  //coloum j
  return matrix[i][j];

}

//# output #
void CMatrix::PrintMatrix(){

  cout <<"> here is a " << GetDimension() << " x " << GetDimension() << " matrix." << endl;
  for (int i = 0; i < GetDimension(); i++) {
    cout <<"> ";
    for (int j = 0; j < GetDimension(); j++) {
      cout<< GetElementAt(i,j) << " ";
    }
    cout<<endl;//make new row after coloum has finished for current row
  }
  cout<<endl;
}

//# handling memory #
void CMatrix::AllocateMatrixMemory(){

  matrix = new int*[dimension]; //setting rows
  for (int i = 0; i < dimension; i++) {
    matrix[i] = new int[dimension];//setting coloums
  }
}
void CMatrix::DeallocateMatrixMemory(){
//running delete command for a length of dimension + 1
  for (int i = 0; i < dimension; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
}
