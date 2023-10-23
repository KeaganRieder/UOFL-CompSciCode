//restaurantG code test
#include "Restaurant_g.h"
#include <iostream>

using namespace std;

int main(){
  int numtoPass;
  //resteraunt names/object
  RestaurantG res0;// test of empty object
  RestaurantG res1("resName1", "cusineName1");
  RestaurantG res2("resName2", "cusineName2");
  RestaurantG res3("resName3", "cusineName3");
  RestaurantG res4("resName4", "cusineName4");
  RestaurantG res5("resName5", "cusineName5");
  RestaurantG res6("resName6", "cusineName6");
  RestaurantG res7("resName7", "cusineName7");
  RestaurantG res8("resName8", "cusineName8");
  RestaurantG res9("resName9", "cusineName9");
  RestaurantG res10("resName10", "cusineName10");

// adding test ratings to the resteraunt objects
for (int i = 0; i < 10; i++) {
  for (int x = 0; x < 5; x++) {
    if (i == 0) {
      numtoPass = (((i*x)+i)% 4)+1;
      res1.addCustomerRating(numtoPass);
    }
    if (i == 1) {
      numtoPass = (((x*x)+i)% 4)+1;
      res2.addCustomerRating(numtoPass);
    }
    if (i == 2) {
      numtoPass = (((i*i)+i)% 4)+1;
      res3.addCustomerRating(numtoPass);
    }
    if (i == 3) {
      numtoPass = ((i+x)% 4)+1;
      res4.addCustomerRating(numtoPass);
    }
    if (i == 4) {
      numtoPass = (((i*x)+i)% 4)+1;
      res5.addCustomerRating(numtoPass);
    }
    if (i == 5) {
    numtoPass = ((x+x)% 4)+1;
      res6.addCustomerRating(numtoPass);
    }
    if (i == 6) {
      numtoPass = (((i+x)*x)% 4)+1;
      res7.addCustomerRating(numtoPass);
    }
    if (i == 7) {
      numtoPass = (((i*8)+x)% 4)+1;
      res8.addCustomerRating(numtoPass);
    }
    if (i == 8) {
      numtoPass = (((i*4)+x)% 4)+1;
      res9.addCustomerRating(numtoPass);
    }
    if (i == 9) {
      numtoPass = (((i*7)+x)% 4)+1;
      res10.addCustomerRating(numtoPass);
    }
  }
}
  //displaying resteraunt info
  res0.printResInfo();
  res1.printResInfo();
  res2.printResInfo();
  res3.printResInfo();
  res4.printResInfo();
  res5.printResInfo();
  res6.printResInfo();
  res7.printResInfo();
  res8.printResInfo();
  res9.printResInfo();
  res10.printResInfo();

  return 0;
}
