
#include <iostream>
#include <string>
#include <cctype>

using namespace std;



int main (){
    string input, month, day, year,cleanString;
    int strLength,commaPos;
    int lastExctractPos;

    // cout<< "test >";
    // getline(cin, input);

    input = "December          24th, 2021";
    strLength =  input.length();
    //for fucntion called clean
    for (int i = 0; i < strLength; i++) {
      if (input[i] != ' ') {
        cleanString += input[i];
      }
    }


//finding month
    //strLength =cleanString  ;

    for (unsigned int i = 0; i < cleanString.length(); i++) {
      if (!isdigit(cleanString[i])) {
        month += tolower(cleanString[i]);
      }
      else{
        lastExctractPos = i;
        break;
      }

    }
    cout <<endl<< month ;

//finding day
    for (unsigned int i = lastExctractPos; i < cleanString.length(); i++) {
      if (isdigit(cleanString[i])) {
        day += cleanString[i];

      }
      else{
        lastExctractPos = i;
        break;

      }

    }
    cout <<endl<< day ;

    for (unsigned int i = lastExctractPos; i < cleanString.length(); i++) {
      if (cleanString[i] == ',') {
        commaPos = i+1;
        break;
      }
    }
    year = cleanString.erase(0,commaPos);
    //cleanString.substr(commaPos,4);

cout <<endl << year ;

//convert digits function
int temp, convertedNum=0;
for (unsigned int i = 0; i < year.length(); i++) {
  convertedNum = convertedNum*10 + (static_cast<int>(year[i]) - static_cast<int>('0'));
}

cout<<endl << convertedNum;

//convert month test
int monthNumber;
{JANUARY = 1, FEBURAY = 2, MARCH = 3,APRIL = 4, MAY = 5,JUNE = 6,
  JULY = 7,AUGUST = 8,SEPEMBER = 9,OCTOBER = 10,NOVEMEBR = 11,DECEMEBR = 12};

/*
switch (month) {
  case  january:
    monthNumber = 1;
  case february:
      monthNumber = 2;
  case march:
      monthNumber = 3;
  case april:
      monthNumber = 4;
  case may:
      monthNumber = 5;
  case june:
      monthNumber = 6;
  case july:
      monthNumber = 7;
  case august:
      monthNumber = 8;
  case september:
      monthNumber = 9;
  case october:
      monthNumber = 10;
  case november:
      monthNumber = 11;
  case december:
      monthNumber = 12;
  }
*/
cout <<endl<< monthNumber;


}
