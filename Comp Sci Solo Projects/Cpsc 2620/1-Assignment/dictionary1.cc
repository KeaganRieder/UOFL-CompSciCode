#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

//function prototypes
string* MyAdd(string *dictionary, int &wordCount, string aWord);
string* MyDelete(string *dictionary, int &wordCount, string aWord);
string ProcessInput(string input, int &inputPos);
void MySearch(string dictionary[], int wordCount, string aWord);
bool LinerSearch(const string dictionary[], int wordCount, string aWord, int &count);
void MyUpdate(string dictionary[], int wordCount, string oldWord, string newWord);
void MyList(string dictionary[], int wordCount);
void MyRList(string dictionary[], int wordCount);
void MyExit();

//Main function
int main(){
  string* dictionary = new string[0]; //make initaly be null
  string command;
  string aWord;
  string wordReplacer;
  string input; //input text to be broken into coorect varibles
  int inputPos = 0; //used to run through the users input and seperate to it's parts
  int wordCount = 0;
  bool running;

  cout <<"Welcome to dictionary."<< endl
  <<"> The commands are as followed: " << endl
  <<"> ADD givenword, RLIST, LIST, EXIT " << endl
  <<"> DELETE givenword, SEARCH givenword," << endl " add"
  <<"> UPDATE oldWord newWord" << endl;
  running = true;

  while (running) {
    //geting user input/checking what the command is and resetting varibles things
    inputPos = 0;
    cout << endl <<">>> ";

    getline(cin, input);
    //processing input and set varibles to check for command prompt
    command = ProcessInput(input, inputPos);

    //switch board to decide which command to run based on user input
    if (command == "ADD"){
      //processing input and set varibles to corrisponding postion in input
      aWord = ProcessInput(input, inputPos);

      //runing fiunction to corisponding command
      dictionary = MyAdd(dictionary, wordCount, aWord);
    }

    else if (command == "DELETE"){
      //processing input and set varibles to corrisponding postion in input
      aWord = ProcessInput(input, inputPos);

      //runing fiunction to corisponding command
      dictionary = MyDelete(dictionary, wordCount, aWord);
    }

    else if (command == "UPDATE"){ // needs work
      //processing input and set varibles to corrisponding postion in input
      aWord = ProcessInput(input, inputPos);
      wordReplacer = ProcessInput(input, inputPos);
      //runing fiunction to corisponding command
      MyUpdate(dictionary, wordCount, aWord, wordReplacer);
    }

    else if (command == "SEARCH"){
      aWord = ProcessInput(input, inputPos);
      MySearch(dictionary, wordCount, aWord);
    }

    else if (command == "LIST"){
      MyList(dictionary,  wordCount);
    }

    else if (command == "RLIST"){
      MyRList(dictionary,  wordCount);
    }

    else if (command == "EXIT"){
      MyExit();
      running = false;
    }

    else{
      cout << "> invalid entry, ensure"<<endl
      << "> commands are in all caps."<<endl;
    }
  }

  delete[] dictionary;
  return 0;
}

//function definitions
//checks user input for the words to eiethr add to dictionary
//or update a word in dictionary with
string ProcessInput(string input, int &inputPos){
  string aWord;

  //ensure that current postion in input isn't a white space
  while (input[inputPos] == ' ') {
    inputPos += 1;
  }
  //set the string to intaily first letter of word
  aWord = input[inputPos];
  inputPos += 1;

  //after checking for word set word to corisponding varible
  for (size_t i = inputPos; i < input.size(); i++) {
    if (input[i] == ' ') { //stops at space between command and if there is a word
      inputPos = i;
      break;
    }
    aWord += input[i];
  }

  return aWord;
}

//Modifing the dictionary,elemnts
string* MyAdd(string *dictionary, int &wordCount, string aWord){
  int wordPos = 0;
  string* tempArr;

  //see if dictionary is new array with nothing in
  if (wordCount <= 0) {
    wordCount += 1;
    dictionary = new string[wordCount];
    dictionary[wordCount - 1] = aWord;

    cout <<"> "<< aWord << " was added."<<endl;
  }

  //checks if words already in list
  else if (LinerSearch(dictionary, wordCount, aWord, wordPos)) {
    cout<<"> sorry but " << aWord << " is already in dictionary at position " <<
    wordPos << endl;
  }

  //dictionarys already created so just resizing it and aWord not already in it
  else{
    wordCount += 1;
    tempArr = new string[wordCount];
    for (int i = 0; i < wordCount-1; i++) {
      tempArr[i] = dictionary[i];
    }
    tempArr[wordCount - 1] = aWord;
    delete[] dictionary;
    dictionary = tempArr;

    cout <<"> "<< aWord << " was added."<<endl;

  }
  return dictionary;
}

string *MyDelete(string *dictionary, int &wordCount, string aWord){
  int wordPos = 0;
  string* tempArr;

  if (LinerSearch(dictionary, wordCount, aWord, wordPos)) {
    for (int i = wordPos; i < wordCount-1; i++) {
      dictionary[i] = dictionary[i + 1];
    }
    //updateing array size
    tempArr = new string[wordCount - 1];
    wordCount -= 1;

    //setting temp array to dictionary values so the array is smaller
    for (int i = 0; i < wordCount; i++) {
      tempArr[i] = dictionary[i];
    }
    delete[] dictionary;
    dictionary = tempArr;

    cout <<"> "<<aWord << " was removed."<<endl;
  }

  else{
    cout<<"> "<< aWord << " is not located inside dictionary."<<endl;
  }
  return dictionary;
}

void MyUpdate(string dictionary[], int wordCount, string oldWord, string newWord){
    int wordPos = 0;
    //checking if new word is already in list
    if (LinerSearch(dictionary, wordCount, newWord, wordPos)) {
      cout<<"> sorry but " << newWord << " is already in dictionary at position " <<
      wordPos << endl;
    }
    //otherwise see if word wanting to be repalced is in this
    else if (LinerSearch(dictionary, wordCount, oldWord, wordPos)){
        dictionary[wordPos] = newWord;
        cout << "> "<<oldWord << " has been replaced by " << newWord <<endl;
    }
    else{
        cout << "> Sorry but "<< oldWord << " isn't in dictionary."<<endl;
    }
}

//searching teh array for given elemnt
void MySearch(string dictionary[], int wordCount, string aWord){
    int wordPos =0;
    if (LinerSearch(dictionary, wordCount, aWord, wordPos)){
        cout << aWord << "> has been found at postion " << wordPos <<endl;
    }
    else{
        cout << "> Sorry but "<< aWord << " isn't in dictionary."<<endl;
    }
}

bool LinerSearch(const string dictionary[], int wordCount, string aWord, int &count){
  count = 0;
  bool wordFound = false;
  for (; count < wordCount; count++) {
    if (dictionary[count] == aWord) {
      wordFound = true;
      break;
    }
  }
  return wordFound;
}

//Listing the array's elemnts
void MyList(string dictionary[], int wordCount){
  if (wordCount <= 0) {
    cout <<endl<<"> there is no word in dictionary "<<endl;
  }
  else{
    for (int i = 0; i < wordCount; i++) {
      cout<<"> "<<dictionary[i]<<endl;
    }
    //there is only one word in list
    if (wordCount == 1) {
      cout <<endl<<"> there is a word in dictionary "<<endl;
    }
    //if there is more than 1 word
    else{
      cout <<endl<<"> there are " <<wordCount<<" words in dictionary "<<endl;
    }
  }
}

void MyRList(string dictionary[], int wordCount){
  //see if dictionary has actually anything in it
  if (wordCount <= 0) {
    cout <<endl<<"> there is no word in dictionary "<<endl;
  }
  else{
    for (int i = wordCount-1; i >= 0; i--) {
      cout<<"> "<<dictionary[i]<<endl;
    }
    //theres only one word in list
    if (wordCount > 1) {
      cout <<endl<<"> there is a word in dictionary "<<endl;
    }
    //if there is more than 1 word
    else{
      cout <<endl<<"> there are " <<wordCount<<" words in dictionary "<<endl;
    }
  }
}

//exit program
void MyExit(){
  cout <<"> bye bye." << endl;
}
