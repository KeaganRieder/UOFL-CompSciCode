//definition of Dictionary2
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

class Dictionary2{
public:
  //costructers
  //default costructer sets everything relating to the
  //dictionary obejct to it's abse value
  Dictionary2();

  //modifing the dictionary's elements
  void MyAdd(vector<string> &dictionary, string aWord);
  void MyDelete(vector<string> &dictionary, string aWord);
  void MyUpdate(vector<string> &dictionary, string oldWord, string newWord);

  //listing the dictionary elements
  void MySearch(const vector<string> dictionary, string aWord);
  void MyList(const vector<string> &dictionary);
  void MyRList(const vector<string> &dictionary);

  //exiting
  void MyExit(bool &running);

  //checks dictonary to see if it has element aWord
  bool LinerSearch(const vector<string> &dictionary, int& pos, string aWord, int& count);

  //varibles
  vector<string> dictionary;

};

#endif
