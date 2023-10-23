//test code for assignment 3 code
#include "Structured_Matrix.cpp"
#include "Triangular_Matrix.cpp"
#include "Symmetric_Matrix.cpp"
#include "Lower_Triangular_Matrix.cpp"
#include "Upper_Triangular_Matrix.cpp"
#include "Symmetric_Tridiagonal_Matrix.cpp"
#include "Diagonal_Matrix.cpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//function defs
void process_str_matrix(StructuredMatrix *mtxprt[]);
string reverse_string(string toReverse, int length);
int seq_search(int array[], int key, int length);
void CheckIndex(int index, int key);
int dt_rt(int numToCompress);

//main program loop
int main(){

//constructors
LowerTriangularMatrix lowerTestOne(4,1);
UpperTriangularMatrix upperTestOne(4,2);
DiagonalMatrix diagonalTestOne(4,1);
SymmetricTridiagonalMatrix tridiagonalTestOne(4,1);



//caculations
//sume done in print function so here is a test for index opperator

cout<<"########################################"<<endl
    <<"index test"<<endl
    <<"########################################"<<endl<<endl;

cout<<"The index at 1,5 in the lower Triangular Matrix is:"<<endl
    <<lowerTestOne(4,4)
    <<endl<<endl;

//output
//lowerTestOne.print();
//upperTestOne.print();
//diagonalTestOne.print();
//tridiagonalTestOne.print();

//testing process_str_matrix

cout<<"########################################"<<endl
    <<"process_str_matrix test"<<endl
    <<"########################################"<<endl<<endl;
//adding to matrix array, NULL put at end of array, to ensure it ends
StructuredMatrix *matrixArray[5] = {&lowerTestOne,&upperTestOne,&diagonalTestOne,&tridiagonalTestOne, NULL};
process_str_matrix(matrixArray);
cout<<endl;

//testintg of revsersing a string
cout<<"########################################"<<endl
    <<"reverse_string Test"<<endl
    <<"########################################"<<endl<<endl;

string stringToReverse = "test code";
cout<< "Before:"<< stringToReverse<<endl;
stringToReverse = reverse_string(stringToReverse, stringToReverse.length());
cout<<"After:"<< stringToReverse <<endl<<endl;

//testintg of seq_search
cout<<"########################################"<<endl
    <<"seq_search Test"<<endl
    <<"########################################"<<endl<<endl;

int numArrayLength = 5;
int numArrayKey = 11;
int numArray[] = {1, 10, 4, 8, 9};

int index = seq_search(numArray, numArrayKey, numArrayLength);
 CheckIndex(index, numArrayKey);

numArrayKey = 10;
index = seq_search(numArray, numArrayKey, numArrayLength);
CheckIndex(index, numArrayKey);

//testintg of dt_rt for a key
cout<<"########################################"<<endl
    <<"dt_rt"<<endl
    <<"########################################"<<endl<<endl;

int numToCompress = 9832763;
int compressedNum = dt_rt(numToCompress);
cout<<"the signle Digit sum of " << numToCompress << " is "<< compressedNum
    << endl;

return 0;
}

//function decleration
/*conditions
//precondition: none
//postCondition:porcess an array of StructuredMatrix, and prints them out,
//as well as check and printing out which one has the largest sum
*/
void process_str_matrix(StructuredMatrix *mtxprt[]){
  double biggestSum = 0;
  for (int i = 0; mtxprt[i] != NULL; i++) {
    mtxprt[i] -> print();
    double sumToCheck = mtxprt[i] -> sum();

    if (sumToCheck > biggestSum) {
      biggestSum = sumToCheck;
    }
  }
  cout<<"the biggest Sum was:" << biggestSum << endl;
}

/*conditions
//precondition: none
//postCondition: reverses a string
*/
string reverse_string(string toReverse, int length){
  if (length == 0) {
    return toReverse;
  }
  else
    return reverse_string(toReverse.substr(1, length), length -1) + toReverse[0];
}

/*conditions
//precondition: none
//postCondition: goes through an array of ints, looking for a key, which it
will return, otherwise it will return -1;
*/
int seq_search(int array[], int key, int length){ //only finds postion of one index
    if (length == 0) { //to stop recursive function
      if (array[length - 1] == key) {
      return length;//index of where key was found
    }
    else{
      return -1;
    }
  }
  if (array[length - 1] == key) {
    return length;//index of where key was found
  }
  else{//contunie if key isn't found
    return seq_search(array, key, length - 1);
  }
}
void CheckIndex(int index, int key){
  if (index == -1) {
    cout<< "the key "<< key << " could not be found in given array "
        <<endl<<endl;
  }
  else{
    cout<< "the key "<< key << " was found at index:" << index
        <<endl<<endl;
  }
}//checks to see if the key had an index in the array

/*conditions
//precondition: none
//postCondition: adds sums of digits until the result is a single didgit
*/

int dt_rt(int numToCompress){
  string tempNumString;
  if (numToCompress <= 9 && numToCompress >= -9) {
    return numToCompress;
  }
  else{
    tempNumString = to_string(numToCompress);
    numToCompress = stoi(tempNumString.substr(0,tempNumString.length()-1));
    numToCompress += (int)(tempNumString[tempNumString.length() -1]- '0');

    return dt_rt(numToCompress);
  }
}
