//MatrixCExt class definition
#ifndef MATRIXEXT_H
#define MATRIXEXT_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

class CMatrixExt{

public:
  //constructers
  //default constructer, that sets deafult if no parmaiter is given
  //to 2
  CMatrixExt(int n = 2);

  //copy constructer
  CMatrixExt(const CMatrixExt &M);

  //destructor
  virtual ~CMatrixExt();

  //managing memory
  //alocating memory to matrix array
  int **AllocateMatrixMemory(unsigned int n);

  //dealocating
  void DeallocateMatrixMemory(int **M, unsigned int n);

  //performing modifcation on class members
  //replacing elment at pos (i,j) with newint
  int ReplaceElementAt(int i, int j, int newint);
  //set element at pos (i,j) to be 1
  int SetElementAt(int i, int j);
  //deleting element at pos(i,j)
  int ClearElementAt(int i, int j);
  //swaping elment at pos(i1,j1) with elemnt at pos(i2,j2)
  void SwapElementsAt(int i1, int j1, int i2, int j2);
  //resizes matrix
  void ResizeMatrix(int newsize);
  //copys a matrix form a matirxClass to another
  void CopyMatrix(const CMatrixExt &M);
  //change all elements on diagoanl to 1, with rest being set to 0
  void MakeIdentity();

  //performing math on matrix
  //doing math with other matrixs
  //returns the CMatrixExe object resulting from the sum of two
  //matrix objs
  CMatrixExt AddMatrix(const CMatrixExt &M);
  //returns the CMatrixExe object that is the differnce between
  // two matrixs
  CMatrixExt SubtractMatrix(const CMatrixExt &M);
  //perfoming multiplication of two matrixs
  CMatrixExt MultiplyMatrix(const CMatrixExt &M);

  //doing math with constant
  //adding x to each element of the matrix
  CMatrixExt AddMatrix(int x);
  //subtracting x from each element
  CMatrixExt SubtractMatrix(int x);
  //multiply each element by x
  CMatrixExt MultiplyMatrix(int x);

  //output/input
  //outputs MatrixCExt obj
  void PrintMatrix();
  //reads in input fo rcorisponding pos in
  //MatrixCExt class
  void ReadMatrix();

  //other
  //gets matrix dimensions
  int GetDimension();
  //gets element at i, j in matrix
  int GetElementAt(int i, int j);

  //checks to see if all elements not on the diagonal are 0
  bool IsDiagonal();
  //checks to see if all element along the diagonal are ones
  //and all other elements are 0
  bool IsIdentity();
  //checks if given matrix is bigger
  bool IsBigger(const CMatrixExt &M);
  //checks if given matrix is smaller
  bool IsSmaller(const CMatrixExt &M);
  //checks if given matrix is equal
  bool IsEqual(const CMatrixExt &M);

private:
  //varibles
  //deimensions of the matrix
  int dimension;
  //the array of the MatrixCExt class
  int **matrix;

};
#endif
