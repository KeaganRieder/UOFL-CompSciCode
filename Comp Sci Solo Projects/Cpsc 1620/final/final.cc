//keagan rieder
/*program purpose:
reads input from a file,a nd prints out the students ranks,
names, and grades form highest to lowest
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cctype>

using namespace std;

struct studentInfo{
  string firstName = "";
  string lastName = "";
  double grade = 0;
};

void openFile(ifstream&, int&, studentInfo[]);
void closeFile(ifstream&);
void sortData(studentInfo[], int);
void printData(studentInfo[], int);
string getInput();

const int ARRAY_SIZE = 200;
const int LINE_SPACING = 10;

int main(){
  ifstream inData;
  studentInfo students[ARRAY_SIZE];
  int listSize = 0;

  openFile(inData, listSize, students);
  sortData(students, listSize);
  printData(students, listSize);
  closeFile(inData);

  return 0;
}

//function def
/*purpose opens a file
  paramiters

  return
*/
void openFile(ifstream& inData, int& listSize, studentInfo students[]){

  string input = getInput();
  inData.open(input);

  while (inData.fail()) {
    cout<< "File failed to open.\n\n";
    string input = getInput();
    inData.open(input);
  }

  inData >> students[listSize].firstName;

  while(!inData.eof()){
    inData >> students[listSize].lastName;
    inData >> students[listSize].grade;
    listSize++;
    inData >> students[listSize].firstName;
  };
}

/*purpose closes file
  paraimiters input -- inData as fstream

  return:
*/
void closeFile(ifstream& inData){
  inData.close();
}

/*
purpose:promts user to enter file name
paraimters:   I/O -- input -- string

retrun:
*/
string getInput(){
  string fileName;
  cout << "Please input name of file you want opened\n> ";
  cin >> fileName;

  return fileName;
}

/*purpose sort data
  paraimiters inputs--listSize as int,students as struct
              outputs--

  return:
*/
void sortData(studentInfo students[], int listSize){
  for (int top = 0; top < listSize - 1; top++) {
      int smallestIndex = top;
      for (int pos = top+1; pos < listSize; pos++) {
        if (students[pos].grade < students[smallestIndex].grade) {
          smallestIndex = pos;
        }
      }
    studentInfo temp = students[top];
    students[top] = students[smallestIndex];
    students[smallestIndex] = temp;
  }

}

/*purpose gets users input
  paraimiters inputs-- students as a struct
              outputs-- displays text to user

  return:
*/
void printData(studentInfo students[], int listSize){
  int rank = 1;
  double tempGrade;

  cout << "\nRank ------ Student ------ Grade" << endl;

  for (int pos = listSize-1; pos >= 0; pos--) {
    //check if tie
    if (tempGrade != students[pos].grade) {
      cout << " "  << rank<< setw(LINE_SPACING+2)<< right<< students[pos].lastName
      << ", " <<setw(LINE_SPACING+1)<< left << students[pos].firstName
       <<setprecision(2)<< fixed << students[pos].grade
      <<endl;
    }

    if (tempGrade == students[pos].grade) {
      cout << setw(LINE_SPACING)<< right <<"  " << students[pos].lastName
      << ", " << setw(LINE_SPACING-4)<< left << students[pos].firstName
       << setprecision(2)<< fixed << students[pos].grade
      <<endl;
    }

    tempGrade = students[pos].grade;
    rank++;
  }

}
