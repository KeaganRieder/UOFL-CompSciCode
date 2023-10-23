
#include <iostream>
#include <vector>
#include "dictionary2.h"

using namespace std;

//defining base constructor
Dictionary2::Dictionary2(){}

//modifing the dictionary's elements
void Dictionary2::MyAdd(vector<string> &dictionary, string aWord){
  int wordPos = 0;
  int count = 0;
  //see if dictionary hsa nothing in it
  if (dictionary.size() == 0) {
    dictionary.push_back(aWord);
    cout <<"> "<< aWord << " was added."<<endl;
  }
  //check if dictionary has word in list alrady
  else if (LinerSearch(dictionary, wordPos, aWord, count)) {

    cout << "> " << aWord << " is already in dictionary at pos " << wordPos << endl;
  }
  //dictionary is already made, and word to be added isn't already in it
  //so just adding to it
  else{
    dictionary.push_back(aWord);
    cout << "> "<< aWord<<" has been added."<<endl;
  }

}

void Dictionary2::MyDelete(vector<string> &dictionary, string aWord){//work on
  int wordPos = 0;
  int count = 0;
  //check if dictionary has word in list  and remove if it does
  if (LinerSearch(dictionary, wordPos, aWord, count)) {
    //shifting elment designated to be removed to the back
    //to be deleted
    for (size_t i = wordPos; i < dictionary.size() -1; i++) {
      dictionary[i] = dictionary[i + 1];
    }
    //removes back most element

    dictionary.pop_back();
    cout << "> " << aWord <<" was removed from dictionary. " <<endl;
  }
  //otherwise inform user it isn't
  else{
    cout << "> "<< aWord<<" hasn't been found in list out"
    << endl <<" > of the "<< count << " elements" <<endl;
  }
}

void Dictionary2::MyUpdate(vector<string> &dictionary, string oldWord, string newWord){
  int wordPos = 0;
  int count = 0;
  //check if dictionary has word in list  and remove if it does
  if (LinerSearch(dictionary, wordPos, oldWord, count)) {
    dictionary[wordPos] = newWord;
    cout << "> " << oldWord << " was replaced by " << newWord << endl;
  }
  else{
    cout << "> "<< oldWord <<" hasn't been found in list out"
    << endl <<" > of the"<< count << " elements" <<endl;
  }
}

//listing the dictionary elements
void Dictionary2::MyList(const vector<string> &dictionary){
  if (dictionary.size() <= 0) {
    cout <<endl<<"> there is no word in dictionary "<<endl;
  }
  //there is only one word in list
  else if (dictionary.size() == 1) {
    cout <<"> "<<dictionary[0]<<endl
    <<endl<<"> there is a word in dictionary "<<endl;
  }
  else{
    for (size_t i = 0; i < dictionary.size(); i++) {
      cout<<"> "<<dictionary[i]<<endl;
    }
    cout <<endl <<"> there are " <<dictionary.size()
    << " words in dictionary "<<endl;
  }
}

void Dictionary2::MyRList(const vector<string> &dictionary){
  if (dictionary.size() <= 0) {
    cout <<endl<<"> there is no word in dictionary "<<endl;
  }
  //there is only one word in list
  else if (dictionary.size() == 1) {
    cout <<"> "<<dictionary[0]<<endl
    << endl<<"> there is a word in dictionary "<<endl;
  }
  else{
    for (int i = dictionary.size()-1; i >= 0; i--) {
      cout<<"> "<<dictionary[i]<<endl;
    }
    cout <<endl <<"> there are " <<dictionary.size()
    << " words in dictionary "<<endl;
  }
}

void Dictionary2::MySearch(const vector<string> dictionary, string aWord){
  size_t wordPos = 0;
  int count = 0;
  bool wordFound = false;

  for (; wordPos < dictionary.size(); wordPos++) {
    if (dictionary[wordPos] == aWord) {
      wordFound = true;
      break;
    }
    count++;
  }
  if (wordFound) {//work on
    cout << "> "<< aWord <<" was found at pos " << wordPos <<endl;
  }
  else{
    cout << "> "<< aWord <<" hasn't been found within the "<<count<<" elements"<<endl;
  }
}
//checking if an elemnt is in dictionary
//check pos
bool Dictionary2::LinerSearch(const vector<string> &dictionary, int& pos, string aWord, int& count){
  bool wordFound = false;
  for (size_t i = pos ; i < dictionary.size(); i++) {
    if (dictionary[i] == aWord) {
      wordFound = true;
      break;
    }
    count++;
  }
  pos = count;
  return wordFound;
}

//exiting
void Dictionary2::MyExit(bool& running){ //make it so it takes in a bool as a reference
  cout<< "> bye bye." << endl;
  running = false;
}
