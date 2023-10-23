#ifndef MATRIX_H
#define MATRIX_H
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Matrix{
public:

  //constructors
  /*conditions
  //acts a default constructor if no arguments are supplied
  //precondition: none
  //postCondition: a Matrix object is created with data memebers r, c and d
*/
  Matrix(int r = 0, int c = 0, double d = 0.0);

  /*conditions
  //precondition: none
  //postCondition: a Matrix object is created with data memebrs r, c and sets the
  //contents to values provided in v
*/
  Matrix(int r, int c, vector<double> v);

  /*conditions
  //precondition: a matrix Object must exist
  //postCondition: creates an identical copy of a matrix
*/
  Matrix(const Matrix& m);

  /*conditions
  //precondition:none
  //postCondition: removes an element form the matrix object, thus
  // freeing memory
*/
  ~Matrix();

  /*conditions
  //precondition: none
  //postCondition: returns amount of coloums
*/
  int ncols() const;
  /*conditions
  //precondition: none
  //postCondition: returns amount of Rows
*/
  int nrows() const;
  /*conditions
  //precondition: none
  //postCondition: returns amount of length of matrix objects array
*/
  int findLen() const;
  /*conditions
  //precondition: none
  //postCondition: returns amount of length of matrix object
  //array as vector<double> to be outputed
*/
  vector<double> outputVector() const;

  //indexs
  /*conditions
  //precondition: none
  //postCondition: retruns non constant elements in matrix object from row i
  // and coloums j
*/
  const double& operator()(int i, int j) const; //to work on const objects
  double& operator()(int i, int j);

  //operators
  //Copy assignment operator
  Matrix& operator=(const Matrix& m);

  //Compound arithmetic operators
  Matrix& operator+=(const Matrix& x);//adding matrixs
  Matrix& operator-=(const Matrix& x);//subtracting matrixs
  Matrix& operator*=(const Matrix& m);//multiplying matrixs
  Matrix& operator*=(double d); // scalar multiplication

  //output
  /*conditions
  //precondition: none
  //postCondition: displays matrix info onto output file
*/
  void print(ostream& sout) const;

private:
  /*conditions
  //precondition: none
  //postCondition: sets amount of rows of the matrix object to peramiter r
*/
  void setRowsAmount(int r);
  /* condition
  //precondition: none
  //postCondition: sets amount of coloums of the matrix object to peramiter c
*/
  void setColumnsAmount(int c);
  /* conditions
  //precondition: rows must be defiend in the matrix object
  //postCondition: creates array based on rows, and coloms
*/
  void formArray(double d);
  void formArray(vector<double> v);

  int rows; // number of rows
  int cols; // number of columns
  double* element; //dynamic array to hold data
};
//file stuff
/*conditions
//Precondition: vector a has len elements of type T
//Postcondition: The first line of the file contains three integers: nrow and ncol, len, in
//that order; len elements from vector a are written to the file named data starting from
//the second line, 10 elements per line.
*/
template <class T>
void writeToFile(const vector<T> & a, int len, int nrow, int ncol, const string data);
/* conditions
//Precondition The first line contains three integers. The remaining
//lines contain data; 10 elements per line, except possibly the last line which may contain
//fewer than 10 elements.
//Postcondition: The three integers in the first line are read into the parameters nrow, ncol,
//and len, in that order len elements are read from file data, into the vector parameter a
*/
template <class T>
void ReadFile(vector<T> & a, int &nrow, int &ncol, const string data);
//Nonmember arithmetic operators
Matrix operator+(const Matrix& l, const Matrix&r); // return l+r
Matrix operator-(const Matrix& l, const Matrix&r); // return l-r
Matrix operator*(const Matrix& l, const Matrix&r); // return l*r
Matrix operator*(double d, const Matrix& r); // return d*l
Matrix operator*(const Matrix& m, double d); // return l*d

// Overloaded stream insertion operator
ostream& operator<<(ostream& out, const Matrix& x);
#endif
