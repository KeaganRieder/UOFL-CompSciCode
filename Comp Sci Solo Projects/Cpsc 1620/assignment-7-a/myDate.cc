//name:keagan rieder

//program purpose: gets the user to input the dae, in the format of month,day year. and then outputs it in the format of
// day month year.

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

enum Month {ERROR = 0,JANUARY = 1, FEBURAY = 2, MARCH = 3,APRIL = 4, MAY = 5,JUNE = 6,JULY = 7,AUGUST = 8,SEPTEMBER = 9,OCTOBER = 10,NOVEMEBR = 11, DECEMEBR = 12};

//function prototypes
Month convertMonth(string);
void extract(string,int&,int&,int&);
int convertDigits(string);
string getDate();
string clean(string);
string getInput();

int main(){
  string input, runAgain;
  int monthInt, dayInt, yearInt;

  do{

    input = getDate();

    extract(input, monthInt, dayInt, yearInt);

    //output
    cout << "the date is > " << dayInt << "/"<< monthInt << "/"<< yearInt << endl;

    cout <<"\nRun again?(y/n)\n> ";
    runAgain = getInput();

  }while(runAgain == "y");

  return 0;
}

//function definitions

/*purpose promts the user to enter the date as a string and return it
  paramiters:   input--
                output--
  return string

*/
 string getDate(){
   cout << "enter the date, as followed month day, year \n>";
   return getInput();
}
/*purpose promts the user to enter the date as a string and return it
  paramiters:   I/O -- input -- string
  return
*/
string getInput(){
  string input;

  getline(cin, input);

  input = clean(input);

  return input;
}

/*purpose:takes in the date as string and returns the day, month, year as int
  paramiters:   input-- date as string
                output--
  returtn 3 ints

*/
void extract(string cleanString, int& monthInt,int& dayInt,int& yearInt){
  int lastExctractPos,commaPos;
  string day,month,year;

  //finding month
  for (unsigned int i = 0; i < cleanString.length(); i++) {
    if (!isdigit(cleanString[i])) {
      month += cleanString[i];
    }
    else{
      lastExctractPos = i;
      break;
      //call function to convert month to int
    }
  }
  monthInt = convertMonth(month);

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
  dayInt = convertDigits(day);//here

//finding year
  for (unsigned int i = lastExctractPos; i < cleanString.length(); i++) {
    if (cleanString[i] == ',') {
      commaPos = i+1;
      break;
    }
  }
  year = cleanString.erase(0,commaPos);
  yearInt = convertDigits(year);
}

/*purpose: converts a string of digits to an int
  paramiters:   input-- string
                output--
  returtn convertedNum as int

*/
int convertDigits(string needingConvert){
  int  convertedNum=0;
  for (unsigned int i = 0; i < needingConvert.length(); i++) {
    convertedNum = convertedNum*10 + (static_cast<int>(needingConvert[i]) - static_cast<int>('0'));

  }
  return convertedNum;
}

/*purpose converts months form a string into it's corisponing number
  paramiters:   input-- month as string
                output--
  returtn an int
*/
Month convertMonth(string month){
    //swicting month to number
    if (month == "january") {
        return JANUARY;
    }
    else if (month =="february") {
      return FEBURAY;
    }
    else if (month == "march") {
      return MARCH;
    }
    else if (month == "april"){
      return APRIL;
    }
    else if (month == "may") {
      return MAY;
    }
    else if(month == "june"){
      return JUNE;
    }
    else if (month == "july") {
      return JULY;
    }
    else if (month == "august") {
      return AUGUST;
    }
    else if (month == "september"){
      return SEPTEMBER;
    }
    else if (month == "october") {
      return OCTOBER;
    }
    else if (month == "november") {
      return NOVEMEBR;
    }
    else if (month == "december") {
      return DECEMEBR;
    }
    else
    return ERROR;

}

/*purpose removes spaces in string
  paramiters:   input-- input as string
                output--
  returtn cleanString as string

*/
string clean(string input){
  string cleanString;

  //for fucntion called clean
  for (unsigned int i = 0; i < input.length(); i++) {
    if (input[i] != ' ') {
      cleanString += tolower(input[i]);
    }
  }

  return cleanString;
}
