//program

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//function prototypes
map<char,int> MakeCharMap();
bool CompareValue(pair<string,int> pair1, pair<string,int> pair2);
bool CompareValue2(pair<char,int> pair1, pair<char,int> pair2);
char UpperToLower(unsigned char letter);
void FreqSort( map<string,int> wordList, map<char,int> charList,vector<pair<string,int>> &freqWordList, vector<pair<char,int>> &freqCharList);
void SepearteInput(string input, unsigned int inputPos, map<string,int> &wordList, map<char,int> &charList);

int main(){
  //varibles
  map<string, int> wordList;
  map<char, int> charList;
  //lists orginized on value this would be frequancy rather then key letter or word
  vector<pair<string,int>> freqWordList;
  vector<pair<char,int>> freqCharList;

  //input varibles
  string inputString;
  charList = MakeCharMap();

  //main program loop
  //getting input
  cout << "> please input a list of words \n>>> ";
  while (  getline(cin,inputString)) {
    cout<<">>> ";
  //make input string to lower case from upper
  //transform(inputString.begin(), inputString.end(), inputString.begin(),this->UpperToLower);
  transform(inputString.begin(), inputString.end(), inputString.begin(),UpperToLower);

  SepearteInput(inputString, 0, wordList, charList);
  //sorting based on Frequency
  FreqSort(wordList, charList,freqWordList, freqCharList);
  cout << endl;

  //output
  cout <<setw(10)<<left<< "Words" << "Freqency" << endl;
  //print out in wordlist alphabetical
  for (auto word = wordList.begin(); word != wordList.end(); word++) {
    cout << setw(14) << left << word->first << word->second <<  endl;
  }

//printing out chararacter
  cout<< endl << setw(10)<<  left<< "Letter" << "Freqency" << endl;
  //printing out charList in alphabetical
  for (auto letter = charList.begin(); letter != charList.end(); letter++) {
    if (letter->second > 0 ) {
        cout << setw(14) << left << letter->first << letter->second << endl;
    }
  }

  //printing things out based on freqeuency
  //print out word list in order of Frequency
  cout<<endl<<"> word and char list order based on freqeuency"<<endl;
  cout << setw(10)<<left<<"Words" << "Frequency" << endl;
  for (auto word = freqWordList.begin(); word != freqWordList.end(); word++) {
    cout << setw(14) << left << word->first << word->second << endl;
  }

  //letters in order of Freqency
  cout<< endl << setw(10) << left << "Letter" << "Frequency" << endl;
  for (auto letter = freqCharList.begin(); letter != freqCharList.end(); letter++) {
    if (letter->second > 0 ) {
        cout << setw(14) << left << letter->first << letter->second << endl;
    }
  }

  cout <<endl<< "> done reading output." <<endl;
  cout << "> please input either new list or command to terminate: "<<endl;
}
  return 0;
}

//function defs
//make a map of letetrs
map<char,int> MakeCharMap(){
  map<char,int> charList;
  for (int letter = 'a'; letter < 'z'; letter++) {
    //running through alphabet and adding it to the char list
    //setting keys to 0
    charList.insert({letter,0});
  }
  return charList;
}

//comparing the value of a pair<string,int> inorder to orginize the
//list based on valiue rather then key
bool CompareValue(pair<string,int> pair1, pair<string,int> pair2){
  return pair1.second > pair2.second;
}

//comparing the value of a pair<char,int> inorder to orginize the
//list based on valiue rather then key
bool CompareValue2(pair<char,int> pair1, pair<char,int> pair2){
  return pair1.second > pair2.second;
}
//checks if the parmiter is lower using isLower(), and if not then
//it will convert it to lowercase, by adding 32
char UpperToLower(unsigned char letter){
  if (!islower(letter) && letter != 32) { //
    unsigned char lower = letter +32 ;
    return lower;
  }
  return letter;
}

//sorts map into a vector of pairs inorder to be orginzied based on frequancy
void FreqSort(map<string,int> wordList, map<char,int> charList, vector<pair<string,int>> &freqWordList, vector<pair<char,int>> &freqCharList){
  // setting  wordList to be vector to be sorted based on freqeuency
  for (auto word = wordList.begin(); word != wordList.end(); word++) {
    freqWordList.push_back(make_pair( word->first,word->second));
  }

  sort(freqWordList.begin(),freqWordList.end(), CompareValue); //need  aget this working
  //sort(freqWordList.begin(),freqWordList.end());

  // setting charList to be vector to be sorted based on freqeuency
  for (auto letter = charList.begin(); letter != charList.end(); letter++) {
    freqCharList.push_back(make_pair(letter->first,letter->second ));
  }
  sort(freqCharList.begin(), freqCharList.end(), CompareValue2);
}

void SepearteInput(string input, unsigned int inputPos,map<string,int> &wordList, map<char,int> &charList){
  string wordToAdd = "";
  bool addWord = true;

  //making sure string doesn't start at a white space;
  while (input[inputPos] == ' ' && !isalnum(input[inputPos])) {
    inputPos++;
  }
  //setting wordToAdd to first letter of the current word

  wordToAdd = input[inputPos];

  //adding letter to char list check
  for (auto letter = charList.begin(); letter != charList.end(); letter++) {
    if (input[inputPos] == letter->first)  {
      letter->second++;
      break;
    }
  }
inputPos++;
  //running through rest of the word
  for (; inputPos != input.size(); inputPos++) {
    //end of the current word, an wanna add it to them
    //word list
    if (input[inputPos] == ' ' ) {
      break;
    }
    if (isalnum(input[inputPos])) {
      wordToAdd += input[inputPos];
    }

    //add char to char list
    for (auto letter = charList.begin(); letter != charList.end(); letter++) {
      if (input[inputPos] == letter->first)  {
        letter->second++;
        break;
      }
    }

  }

  //runing through word list to see if word needs to be added
  for (auto word = wordList.begin(); word != wordList.end(); word++) {
    if (wordToAdd == word->first) {
      word->second++;
      addWord = false;
      break;
    }
  }
  if (addWord) {
    wordList.insert({wordToAdd, 1});
  }

  //check if input is done being seperated or if this function needs to run again
  if (inputPos == input.size()) {
    //nothing sense function doesn't need a run

  }
  else{
    //run function again
    SepearteInput(input, inputPos, wordList,charList);
  }
}
