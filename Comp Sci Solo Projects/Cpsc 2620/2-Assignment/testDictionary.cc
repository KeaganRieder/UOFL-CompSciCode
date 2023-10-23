//dictonary2 test file

#include <iostream>
#include <string>

#include "dictionary2.h"

using namespace std;

//function defintions
void GetInput(string&, size_t&);
void ProcessInput(string, string&, string&, string&, size_t);
void CheckInputIsSpace(size_t&, string);

int main(){
  //creating Dictionary2 object
  Dictionary2 dict;

  //test file varibles
  bool running;
  size_t inputPos; //the current postion in the user's input
  string userInput; //users input
  string command = "";;
  string aWord = "";; //also old word for update function
  string newWord = "";

  //main program loop
  cout <<"Welcome to dictionary."<< endl
  <<"> The commands are as followed: " << endl
  <<"> ADD givenword, RLIST, LIST, EXIT " << endl
  <<"> DELETE givenword, SEARCH givenword," << endl
  <<"> UPDATE oldWord newWord" << endl;

  //starting main loop
  running = true;
  while (running) {
    //getting user input and processing it
    GetInput(userInput, inputPos);
    ProcessInput(userInput, command, aWord, newWord, inputPos);

    //switch board to decide which command to run based on user input
    if (command == "ADD"){
      dict.MyAdd(dict.dictionary, aWord);
    }

    else if (command == "DELETE"){
      dict.MyDelete(dict.dictionary, aWord);
    }

    else if (command == "UPDATE"){
      dict.MyUpdate(dict.dictionary, aWord, newWord);
    }

    else if (command == "SEARCH"){
      dict.MySearch(dict.dictionary, aWord);
    }

    else if (command == "LIST"){
      dict.MyList(dict.dictionary);
    }

    else if (command == "RLIST"){
      dict.MyRList(dict.dictionary);
    }

    else if (command == "EXIT"){
      dict.MyExit(running);
    }

    else{
      cout << "> invalid entry, ensure"<<endl
      << "> commands are in all caps."<<endl;
    }
  }
  return 0;
}

//test code function defintions
//which are handling input
  //getting input
  void GetInput(string& userInput,size_t& inputPos){
    cout << endl <<">>> ";
    getline(cin, userInput);
    inputPos = 0;
  }

  //processing user input
  void ProcessInput(string userInput, string& command, string& aWord, string& newWord, size_t inputPos){
    //setting command to it's corisponding thing in user input
    CheckInputIsSpace(inputPos, userInput);
    command = userInput[inputPos];//set commands first char
    inputPos++;
    //finish the word
    for (; inputPos < userInput.size(); inputPos++) {
      if (userInput[inputPos] == ' ') {//end of section
        break;
      }
      command += userInput[inputPos];
    }

    //checking to see if aWord and newWord need to be processed
    //or if fucntion is done
    if (command == "ADD" || command == "DELETE"|| command == "SEARCH") {
      CheckInputIsSpace(inputPos, userInput);
      aWord = userInput[inputPos];//set commands first char
      inputPos++;
      //finsih the word
      for (; inputPos < userInput.size(); inputPos++) {
        if (userInput[inputPos] == ' ') {//end of section
          break;
        }
        aWord += userInput[inputPos];
      }
    }

    else if (command == "UPDATE") {
      CheckInputIsSpace(inputPos, userInput);
      aWord = userInput[inputPos];//set commands first char
      inputPos++;
      //finish the word
      for (; inputPos < userInput.size(); inputPos++) {
        if (userInput[inputPos] == ' ') {//end of section
          break;
        }
        aWord += userInput[inputPos];
      }
      //setting newWord
      CheckInputIsSpace(inputPos, userInput);
      newWord = userInput[inputPos];//set commands first char
      inputPos++;
      //finish the word
      for (; inputPos < userInput.size(); inputPos++) {
        if (userInput[inputPos] == ' ') {//end of section
          break;
        }
        newWord += userInput[inputPos];
      }
    }

    //no else condtion sense it can't be specified and function
    //need to end anyways
  }
  //checks if input pos is space and then moves to next pos
  void CheckInputIsSpace(size_t& inputPos, string userInput){
    //making sure currnt pos in input is a char not whitespace
    while (userInput[inputPos] == ' ') {
      inputPos++;
    }
  }
