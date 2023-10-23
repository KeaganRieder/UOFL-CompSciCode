//Name: keagan rieder

/*program purpose: ask the user to input two fractions and an opperator,
that is either +,-,/ or * and then prefrom the correct opperation based on the given
operation symbole.
*/
#include <iostream>
#include <cmath>

using namespace std;

//function prototypes
int gcd(int, int);
int min(int, int);
int absoluteValue(int);
void flip(int&, int&);
void reduce(int&, int&);
void add(int, int, int, int, int&, int&);
void subtract(int, int, int, int, int&, int&);
void multiply(int, int, int, int, int&, int&);
void divison(int, int, int, int, int&, int&);

int main(){

  int numerator1, denominator1, numerator2, denominator2, numeratorOutcome, denominatorOutcome;
  string opperator, runAgain, skip;

  do{
  cout << "Please enter the expression of two fractions a/b, c/d in the form a / b opperator c / d\n";
  cout <<"Replace opperator by any one of +, -, *, / \n> ";

  cin >> numerator1 >> skip >> denominator1 >> opperator >> numerator2 >> skip >> denominator2;
  cout <<"> ";
  //checking if they are attempting to dvided by zero
  while (denominator2 == 0 || denominator2 == 0) {
    //check if both divsiors are invalid/= 0
    if (denominator1 == 0 && denominator2 == 0) {
      cout << "invalid input, denominator cannot be zero, please enter a valid expression of two fractionsa a/b, c/d in the form a b opperator c d: ";
      cin >> numerator1 >> skip >> denominator1 >> opperator >> numerator2 >> skip >> denominator2;
    }
    //check if divsior 1 is invalid
    else if (denominator1 == 0) {
      cout << "invalid input, fraction 1 denominator cannot be zero, please re-enter fraction a/b in form of a / b: ";
      cin >>numerator1 >> skip >> denominator1;
    }
    //checking if divisor two is equal to zero
    else if (denominator2 == 0){
      cout << "invalid input, fraction 2 denominator cannot be zero, please re-enter fraction c/d in form of c / d:";
      cin >> numerator2 >> skip >> denominator2;
    }
  }

  //if denominator is negitive and not numerator then make numerator negtive
  reduce(numerator1, denominator1);
  reduce(numerator2, denominator2);
  flip(numerator1, denominator1);
  flip(numerator2, denominator2);



  //preforming opperations
  if (opperator == "+") {
    add(numerator1, denominator1, numerator2, denominator2, numeratorOutcome, denominatorOutcome);
  }
  //check if subtraction
  else if (opperator == "-") {
    subtract(numerator1, denominator1, numerator2, denominator2, numeratorOutcome, denominatorOutcome);
  }
  //check if multiplying
  else if (opperator == "*") {
    multiply(numerator1, denominator1, numerator2, denominator2, numeratorOutcome, denominatorOutcome);
  }
  //check if dividing
  else if (opperator == "/") {
    divison(numerator1, denominator1, numerator2, denominator2, numeratorOutcome, denominatorOutcome);
  }

  if (denominatorOutcome < 0 && numeratorOutcome > 0) {
    numeratorOutcome = -numeratorOutcome;
  }

  cout << numerator1 << "/" << denominator1 << " "<< opperator << " "
  << numerator2 << "/" << denominator2 << " = " << numeratorOutcome << "/" << absoluteValue(denominatorOutcome)<< endl;

  //checking if user wants to run again
  cout <<"\nrun Agin? (y/n): ";
  cin >> runAgain;
  cout <<"\n";
  }while(runAgain == "y" || runAgain == "Y");

  return 0;

}
//function def
/*purpose: finds the smallest of two postive numbers
paramiters: inputs -- number1, number2 as int
ruturns: an int
*/
int min(int number1, int number2){
  int smallest;
  //check if smallest is number2
  if (number1 > number2) {
    smallest = number2;
  }
  //check if smallest is number1
  if (number1 < number2) {
    smallest = number1;
  }

  return smallest;
}
/*purpose: finds absolute value of given integer
paramiters: inputs -- number as int

ruturns: an int
*/
int absoluteValue(int number){
  if (number < 0) {
    number = -number;
  }
  return number;
}
/*purpose: finds the greatest common divsior
paramiters: inputs -- number1, number2 as int
ruturns: an int;
*/
int gcd(int number1, int number2){
  int tempNumber, largestNumber, smallestNumber;

  smallestNumber = min(number1, number2);
  //making sure largest number will be moded by smallest number
  if (number1 == smallestNumber) {
    largestNumber = number2;
  }
  else{
    largestNumber = number1;
  }
  //finding gcd
  while (tempNumber != 0)
  {
    tempNumber = largestNumber % smallestNumber;
    largestNumber = smallestNumber;
    smallestNumber = tempNumber;

  }
  //once tempnum = zero, then gcd equals laregst number
  return largestNumber;
}
/*purpose: flips a function
paramiters: inputs/outputs  Numerator, denominator as int
ruturns:
*/
void flip(int& numerator, int& denominator){

  if (denominator < 0 && numerator > 0) {
    numerator = -numerator;
    denominator = absoluteValue(denominator);
  }
}
/*purpose: reduces a function
paramiters: inputs/outputs  reducedNumerator, reducedDenominator as int
ruturns:
*/
void reduce(int& numerator, int& denomiter){
  int commonFactor, tempNumerator, tempDenomiter;
  commonFactor = gcd(numerator, denomiter);

  tempNumerator = numerator;
  tempDenomiter = denomiter;
  numerator = numerator/commonFactor;
  denomiter = denomiter/commonFactor;


  //check if reduceable, if equals 0 then set back before reduce
  if (numerator == 0 || denomiter == 0) {
    numerator = tempNumerator;
    denomiter = tempDenomiter;
  }
}
/*purpose: adds fractions
paramiters: inputs -- numerator1, denominator1, numerator2, denominator2 as int
            outputs -- numeratorOutcome, denomiterOutcome as ints
ruturns:
*/
void add(int numerator1, int denominator1, int numerator2, int denominator2, int& numeratorOutcome, int& denomiterOutcome){
  int tempDenominator, smallestNumber, largestNumber, commonFactor;
  tempDenominator = denominator1;

  smallestNumber = min(denominator1, denominator2);
  //making sure largest number will be moded by smallest number
  if (denominator1 == smallestNumber) {
    largestNumber = denominator2;
  }
  else{
    largestNumber = denominator1;
  }

  //checking if denominators are the same
   if (absoluteValue(denominator1) != absoluteValue(denominator2)) {
      if (largestNumber == denominator2 && largestNumber % smallestNumber == 0) {
        commonFactor =  largestNumber / smallestNumber;
        numerator1 = numerator1 * commonFactor;
        denominator1 = denominator1 * commonFactor;
      }
      else if(largestNumber == denominator1 && largestNumber % smallestNumber == 0){
        commonFactor =  largestNumber / smallestNumber;
        numerator2 = numerator2 * commonFactor;
        denominator2 = denominator2 * commonFactor;
      }
      else{
      numerator1 = numerator1 * absoluteValue(denominator2);
      denominator1 = denominator1 * absoluteValue(denominator2);
      numerator2 = numerator2 * absoluteValue(tempDenominator);
      denominator2 = denominator2 * absoluteValue(tempDenominator);
      }
  }

  numeratorOutcome = numerator1 + numerator2;
  denomiterOutcome = denominator2;

  reduce(numeratorOutcome, denomiterOutcome);
}
/*purpose: subtracts fractions
paramiters: inputs -- numerator1, denominator1, numerator2, denominator2 as int
            outputs -- outcome form subtracting fractions
ruturns:
*/
void subtract(int numerator1, int denominator1, int numerator2, int denominator2, int& numeratorOutcome, int& denomiterOutcome){

  numerator2 = -numerator2;

  add(numerator1, denominator1, numerator2, denominator2, numeratorOutcome, denomiterOutcome);

}
/*purpose: multiplies fractions
paramiters: inputs -- numerator1, denominator1, numerator2, denominator2 as int
            outputs -- outcome form multiplying fractions
ruturns:
*/
void multiply(int numerator1, int denominator1, int numerator2, int denominator2, int& numeratorOutcome, int& denomiterOutcome){
  numeratorOutcome = numerator1 * numerator2;
  denomiterOutcome = denominator1 * denominator2;

  reduce(numeratorOutcome, denomiterOutcome);
}
/*purpose: divides fractions
paramiters: inputs -- numerator1, denominator1, numerator2, denominator2 as int
            outputs -- outcome form dividing fractions
ruturns:
*/
void divison(int numerator1, int denominator1, int numerator2, int denominator2, int& numeratorOutcome, int& denomiterOutcome){

  flip(numerator2, denominator2);

  numeratorOutcome = numerator1 * denominator2;
  denomiterOutcome = denominator1 * numerator2;

  reduce(numeratorOutcome, denomiterOutcome);
}
