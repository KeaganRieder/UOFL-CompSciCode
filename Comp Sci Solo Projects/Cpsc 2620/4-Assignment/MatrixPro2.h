//MatrixPro class definition
#ifndef MATRIXPRO_H
#define MATRIXPRO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

class CMatrixPro{
public:
  //constructers
  //default constructer, that sets deafult if no parmaiter is given
  //to 2
  CMatrixPro(int n = 2);

  //copy constructer
  CMatrixPro(const CMatrixPro &M);

  //destructor
  virtual ~CMatrixPro();

  //managing memory
  //alocating memory to matrix array
  int **AllocateMatrixMemory(unsigned int n);

  //dealocating
  void DeallocateMatrixMemory(int **M, unsigned int n);

  //modifing elements of matrix
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
  //change all elements on diagoanl to 1, with rest being set to 0
  void MakeIdentity();
  //copys a matrix form a matirxClass to another
  void CopyMatrix(const CMatrixPro &M);

  //get info about matrix functions
  //gets matrix dimensions
  int GetDimension();
  //gets element at i, j in matrix
  int GetElementAt(int i, int j);

  //check things about matrix
  //checks to see if all elements not on the diagonal are 0
  bool IsDiagonal();
  //checks to see if all element along the diagonal are ones
  //and all other elements are 0
  bool IsIdentity();

  //opperator stuff
  //Copy assignment operator
  CMatrixPro& operator=(const CMatrixPro& M); //should just call the copy constructer

  //Compound arithmetic operators
  CMatrixPro operator+(const CMatrixPro &M); //add matrix to martirx
  CMatrixPro operator+(int x); //add constant to matrix elements
  CMatrixPro operator-(const CMatrixPro &M); //subtarct matrix form matrix
  CMatrixPro operator-(int x); //subtract constant to matrix elements
  CMatrixPro operator*(const CMatrixPro &M); //multiply matrix by matrix
  CMatrixPro operator*(int x);//multiply matrix elements by constant

  //compound math operator overload
  CMatrixPro& operator+=(const CMatrixPro &M); //add matrix to martirx
  CMatrixPro& operator+=(int x); //add constant to matrix elements
  CMatrixPro& operator-=(const CMatrixPro &M); //subtarct matrix form matrix
  CMatrixPro& operator-=(int x); //subtract constant to matrix elements
  CMatrixPro& operator*=(const CMatrixPro &M); //multiply matrix by matrix
  CMatrixPro& operator*=(int x);//multiply matrix elements by constant

  //input/output opperators
  friend istream& operator>>(istream& inputSource, const CMatrixPro &M); //outputing matrix
  friend ostream& operator<<(ostream& outputSource, const CMatrixPro &M); //reading input and setting it to elemnts fo matrix

  //other opeprators
  bool operator>(const CMatrixPro &M); //check if matrix is bigger
  bool operator<(const CMatrixPro &M); //check if matrix is smaller
  bool operator==(const CMatrixPro &M); //check if matrix is equal

private:
  //varibles
  //deimensions of the matrix
  int dimension;
  //the array of the MatrixCExt class
  int **matrix;
};
#endif
