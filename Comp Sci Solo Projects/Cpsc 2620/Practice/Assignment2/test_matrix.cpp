//Matrix_H code test
#include "Matrix.cpp"
#include <iostream>
using namespace std;

int  main() {
  int row = 0;
  int col = 0;
  vector<double> doubleVect(0,0);

  //constructors
  ReadFile(doubleVect, row, col, "data1");
  Matrix matrix1(row,col, doubleVect);
  ReadFile(doubleVect, row, col, "data2");
  Matrix matrix2(row,col, doubleVect);
  ReadFile(doubleVect, row, col, "data3");
  Matrix matrix3(row,col, doubleVect);
  ReadFile(doubleVect, row, col, "data4");
  Matrix matrix4(row,col, doubleVect);
  ReadFile(doubleVect, row, col, "data3");
  Matrix matrix5(row,col, doubleVect);
  ReadFile(doubleVect, row, col, "data4");
  Matrix matrix6(row,col, doubleVect);
  ReadFile(doubleVect, row, col, "data3");
  Matrix matrix7(row,col, doubleVect);
  ReadFile(doubleVect, row, col, "data4");
  Matrix matrix8(row,col, doubleVect);

  Matrix temp =(matrix3 + matrix4);
  writeToFile(temp.outputVector(), temp.findLen(), temp.nrows(), temp.ncols(), "additionData.txt");

  Matrix temp2 =(matrix7 - matrix8);
  writeToFile(temp2.outputVector(), temp2.findLen(), temp2.nrows(), temp2.ncols(), "subTest.txt");

  Matrix temp3 = (matrix1 * matrix2);
  writeToFile(temp3.outputVector(), temp3.findLen(), temp3.nrows(), temp3.ncols(), "MultiTest.txt");

  matrix5*= 5;
  matrix6*=2;
  Matrix temp4 = (matrix5 + matrix6);
  writeToFile(temp4.outputVector(), temp4.findLen(), temp4.nrows(), temp4.ncols(), "addPowTest.txt");

  return 0;
}

//file stuff
template <class T>
void writeToFile(const vector<T> & a, int len, int nrow, int ncol, const string data){
  int dataPos = 0;
  ofstream outData;

  outData.open(data);
  outData << nrow <<" " << ncol << " " << len <<endl;
  for (int i = 0; i < len; i++) {
    if (dataPos == 10) {
      outData<< endl;
      dataPos = 0;
    }

    outData<< a[i] <<" ";
    dataPos++;
  }
  outData<< endl;

  outData.close();
}

template <class T>
void ReadFile(vector<T> & a, int &nrow, int &ncol, const string data){
  int len =0;
  ifstream inData;

  inData.open(data);

  inData >> nrow >> ncol >> len;
  double dataLine[len];
  vector<double> tempVect (len,0);
  for (int i = 0; i < len; i++) {
    inData >> dataLine[i];
  }
  for (int i = 0; i < len; i++) {
    tempVect[i] = dataLine[i];
  }
  a = tempVect;
  inData.close();
}
