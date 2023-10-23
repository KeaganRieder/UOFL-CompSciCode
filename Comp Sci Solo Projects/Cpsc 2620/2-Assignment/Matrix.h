//Definition of MatrixCExt
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

class CMatrix {
public:
  //constructors
  //default constructor
  CMatrix();

  //constructer that creates a matrix object of n length
  // with all elemnst set to 0
  CMatrix(int n);

  //functions
  //getting info about matrix
  int GetDimension();
  //get element at pos (i,j) in matrix
  int GetElementAt(int i, int j);

  //modifing elements of matrix
  //replacing elment at pos (i,j) with newint
  int ReplaceElementAt(int i, int j, int newint);
  //set element at pos (i,j) to be 1
  int SetElementAt(int i, int j);
  //deleting element at pos(i,j)
  int ClearElementAt(int i, int j);
  //swaping elment at pos(i1,j1) with elemnt at pos(i2,j2)
  void SwapElementsAt(int i1, int j1, int i2, int j2);
  //adds constant to each element
  void AddConstant(int constant); //adds a constant
  //reads n x n elements
  void ReadMatrix();

  //modfing size of array
  void ResizeMatrix(unsigned int newsize);

  // output
  //prints out the matrix to the user
  void PrintMatrix();

  //handling memory
  void AllocateMatrixMemory();
  void DeallocateMatrixMemory();
private:
  //varibles for matrix
  //the desingator for the matrix size
  //so if dimension = 4, then matrix is 4x4
  int dimension;
  int **matrix;

};
#endif
