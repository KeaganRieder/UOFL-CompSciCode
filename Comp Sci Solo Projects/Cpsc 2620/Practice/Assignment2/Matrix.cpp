#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

//constructors
Matrix::Matrix(int r, int c, double d){
  rows = r;
  cols = c;
  formArray(d);
}
Matrix::Matrix(int r, int c, vector<double> v){
  rows = r;
  cols = c;
  formArray(v);
}

void Matrix::formArray(double d){
  element = new double[rows *cols];
  for (int i = 0; i < rows * cols; i++) {
    element[i] = d;
  }
}
void Matrix::formArray(vector<double> v){
  element = new double[rows * cols];
  for (int i = 0; i < (rows * cols); i++) {
    element[i] = v[i];
  }
} //need to check

int Matrix::nrows() const{return rows;}
int Matrix::ncols() const{return cols;}
int Matrix::findLen() const{return (rows * cols);}
vector<double> Matrix::outputVector() const{
  vector<double> tempVect(rows*cols,0);
  for (int i = 0; i < rows*cols; i++) {
    tempVect[i] = element[i];
  }
  return tempVect;
}

//Copy constructor.
Matrix::Matrix(const Matrix& m){
  rows = m.rows;
  cols = m.cols;
  element = m.element;
}

//destructor
Matrix::~Matrix() {delete [] element;}

//indexs
double& Matrix::operator()(int i, int j){
  return element[i* j];
}
const double& Matrix::operator()(int i, int j) const{
  return element[i* j];
}

//Copy assignment operator
Matrix& Matrix::operator=(const Matrix& m){
  //checking to see if valid
  for (int i = 0; i < rows*cols; i++) {
    element[i] = m.element[i];
  }
  return *this;
}
matrix1 +
//Compound arithmetic operators
Matrix& Matrix::operator+=(const Matrix& x){
  //checking to see if valid
  if (nrows() == x.nrows() && ncols() == x.ncols()) {
    for (int i = 0; i < rows *cols; i++) {
       element[i] += x.element[i];
    }
  }
  else{
      cout<<"invalid operation sizes don't match"<<endl;
  }
  return *this;
}

Matrix& Matrix::operator-=(const Matrix& x){
  //checking to see if valid
  if (nrows() == x.nrows() && ncols() == x.ncols()) {
    for (int i = 0; i < rows*cols; i++) {
         element[i] -= x.element[i];
    }
  }
  else{
    cout<<"invalid operation sizes don't match"<<endl;
  }

  return *this;
}

Matrix& Matrix::operator*=(const Matrix& m){
  vector<double> results(rows*m.ncols(), 0);
  if (cols == m.nrows()) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < m.ncols(); j++) {
        int sum = 0;
        for (int k = 0; k < cols; k++) {
          sum = sum + element[i * cols + k] * m.element[k * m.ncols() + j];
        }
        results[i * m.ncols() + j] = sum;
      }
    }
    rows = rows;
    cols = m.ncols();
    formArray(results);
  }
  else{
    cout<<"invlaid size, matrix 1 coloums do't match matrix 2 rows"<<endl;
  }
  return *this;
}

Matrix& Matrix::operator*=(double d){//need work
  for (int i = 0; i < rows*cols; i++) {
      element[i] *= d;
      cout<<"ran";
  }
  return *this;
}//scaler multiplication

//non memeber arithmetic operators todo
Matrix operator+(const Matrix& l, const Matrix&r){
  Matrix temp(l);
  temp += r;
  return temp;
}
Matrix operator-(const Matrix& l, const Matrix&r){
  Matrix temp(l);
  temp -= r;
  return temp;
}
Matrix operator*(const Matrix& l, const Matrix&r){
  Matrix temp(l);
  temp *= r;
  return temp;
}
Matrix operator*(double d, const Matrix& r){ //d*l
  Matrix temp(r);
  temp *= d;
  return temp;
}
Matrix operator*(const Matrix& m, double d){ //l*d
  Matrix temp(m);
  temp *= d;
  return temp;
}

//output
void Matrix::print(ostream& sout) const{
  double test = 0;
  sout<< rows <<" "<< cols <<" "<< findLen() <<endl<<"";
  for (int i = 0; i < rows * cols; i++) {
      test = i%cols;
      if (test == 0) {
        sout<< "| ";
      }
      sout <<element[i]<< " ";
      if (test+1 == cols) {
        sout<<"| \n";
      }

    }
  sout<< endl;
}

//non memeber output
ostream& operator<<(ostream& out, const Matrix& x){
  x.print(out);
  return out;//check
}
