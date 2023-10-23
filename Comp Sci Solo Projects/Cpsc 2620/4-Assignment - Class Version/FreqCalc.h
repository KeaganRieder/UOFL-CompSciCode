//########## freqCalc definition ##########

#ifndef FREQCALC_H
#define FREQCALC_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class FreqCalc{
public:
  //######### constructers ########
  //default constructer sets up char map, to have all keys set to
  //each letter of the alphabet in lower case, with the values for
  //each key being set to 0
  FreqCalc();

  //destructor
  virtual ~FreqCalc();

  //######### functions ########
  //sorting the lists into list based on Frequency rather then alphabetical
  void FreqSort();

  //######### input/output ########
  //getting input from user
  friend istream& operator>>(istream& inputSource, const FreqCalc &freqCalc);
  //outputting to user
  friend ostream& operator<<(ostream& outputSource, const FreqCalc &freqCalc);//make an overlaod that sawps

  //######### handling input ########
  //recursive function scans and seperates the input it will
  //call it self if input stsring isn't done being sepearted
  void SepearteInput(string input, unsigned int inputPos);

private:
  string inputString;
  //######### varibles ########
  map<string, int> wordList;
  map<char, int> charList;
  //lists orginized on value this would be frequancy rather then key letter or word
  vector<pair<string,int>> freqWordList;
  vector<pair<char,int>> freqCharList;

};
#endif
