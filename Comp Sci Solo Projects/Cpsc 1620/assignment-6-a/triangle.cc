//name: Keagan

/*program purpose:
promts user to enter the lengths of three sides
check if they form a triangle, and outputs if it is a
isosceles, equilateral, scalene,or right triangle
*/

#include <iostream>
#include <cmath>

using namespace std;

//function prototypes
int isTriangle (double,double,double);
int isIsosceles(double,double,double);
int isEquilateral(double,double,double);
int isRightTriangle(double,double,double);


int main() {
  double side1, side2, side3;
  string runAgain;

  runAgain = true;
  do {
    //get user to input side lengths
    cout << "Enter the lengths of the three sides of a triangle --";
    cin >> side1 >> side2 >> side3;

    //checking if it's a triangle
    if (isTriangle(side1, side2, side3)) {
      //check if equilateral
      if (isEquilateral(side1, side2, side3)) {
        cout << "\ntriangle is an equilateral triangle\n";
      }
      //check if Isosceles
      else if (isIsosceles(side1, side2, side3)) {
       //check if Isosceles and right
          if (isRightTriangle(side1, side2, side3)) {
            cout << "triangle is an isosceles and right triangle\n";
          }
          //otherwise it's an Isosceles
          else {
            cout << "triangle is an isosceles triangle\n";
          }
      }

      //otherwise it's scalene
      else  {
          //check if it's scalene and right
          if (isRightTriangle(side1, side2, side3)) {
            cout<< "triangle is an scalene triangle and right triangle\n";
          }
          //otherwise it's scalene
          else {
            cout<< "triangle is an scalene triangle\n";
          }
      }
    }

    // otherwise it's not
    else {
      cout << "\nThis is not a triangle.";
    }

    //checking if the user wants to run again
    cout <<"\nWould you like to star again? (y/n): ";
    cin >> runAgain;

  }while(runAgain == "y" || runAgain== "Y");

  return 0;
}

//function definitions
/*purpose: checks if sides make triangle
paramiters: inputs --side1,side2,side3 -- all  doubles
ruturns: ture if it's a triangle, otherwise false
*/
int isTriangle (double side1, double side2, double side3) {
  if (((side1 + side2) > side3 && (side1 + side3) > side2 && (side3 + side2) > side1)) {
    return true;
  }
  else
  {
    return false;
  }
}

/*purpose: checks if sides make and isosceles triangle
paramiters: inputs --side1,side2,side3 -- all  doubles
ruturns: ture if it's a isosceles triangle, otherwise false
*/
int isIsosceles(double side1, double side2, double side3) {
  if (side1 == side2 || side3 == side2 || side1 == side3) {
    return true;
  }
  else {
    return false;
  }
}

/*purpose: checks if sides make and equilateral triangle
paramiters: inputs --side1,side2,side3 -- all  doubles
ruturns: ture if it's a isosceles triangle, otherwise false
*/
int isEquilateral(double side1, double side2, double side3) {
  if (side1 == side2 && side3 == side2 && side3 == side1) {
    return true;
  }
  else {
    return false;
  }
}

/*purpose: checks if sides make and right triangle
paramiters: inputs --side1,side2,side3 -- all  doubles
ruturns: ture if it's a right triangle, otherwise false
*/
int isRightTriangle(double side1, double side2, double side3) {
  //caculate right triangle to check if triangle is right triangle later
  double side1And2Sum,side1And3Sum,side3And2Sum;

  side1 = static_cast <int> (pow(side1 * .5, 2));
  side2 = static_cast <int> (pow(side2 * .5, 2));
  side3 = static_cast <int> (pow(side3 * .5, 2));
  side1And2Sum = side1 + side2;
  side3And2Sum = side2 + side3;
  side1And3Sum = side1 + side3;

  if (side1And2Sum == side3 || side3And2Sum == side1 || side1And3Sum == side2) {
    return true;
  }
  else {
    return false;
  }
}
