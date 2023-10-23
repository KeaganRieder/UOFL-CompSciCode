#include "Restaurant_g.h"
#include <iostream>
using namespace std;

RestaurantG::RestaurantG():resName("Unkown"),cusine("Unkown"){
  for(int i = 0; i < ARRAY_SIZE; i++)
    {
      veiwersRating[i] = 0;
      averageRating = 0;
    }
}
RestaurantG::RestaurantG(string name, string cusineName){
  setCuisine(cusineName);
  setName(name);
  for(int i = 0; i < ARRAY_SIZE; i++)
    {
      veiwersRating[i] = 0;
      averageRating = 0;
    }
}

string RestaurantG::getName(){return resName;}

string RestaurantG::getCuisine(){return cusine;}

void RestaurantG::setName(string name){
  if(name != "")
    resName = name;

  else
    resName = "Unkown";
}

void RestaurantG::setCuisine(string cusineName){
  if(cusineName != "")
    cusine = cusineName;

  else
    cusine = "Unkown";
}

void RestaurantG::addCustomerRating(int num){
  if (num >= 1 || num <= 5) {//checking if in range of 1 to 5
    veiwersRating[num-1] += 1;//adding total number of a specfic rating
  }
}

float RestaurantG::getAverage(){
  for(int i = 0; i < ARRAY_SIZE; i++){//runing through the array of ratings and adding them to a sum
    averageRating += (i+1) * veiwersRating[i];
  }
  return averageRating / ARRAY_SIZE;
}

void RestaurantG::printResInfo(){
  cout << "RestaurantInfo: " << endl;
  cout << "Name: " << getName() << endl;
  cout << "cusine: " << getCuisine() << endl;
  cout << "Rating Average:" << getAverage()<< endl<<endl;
}
