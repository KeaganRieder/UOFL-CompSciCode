#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(){
  int n = 5;
  int[5] test ={1,2,3,4,5};

  for (int i = 0; i < n; ++i) {
    cout<< test<<endl;
    test[i+1] = test[i];
  }
  cout<< test<<endl;

  return 0;
}
