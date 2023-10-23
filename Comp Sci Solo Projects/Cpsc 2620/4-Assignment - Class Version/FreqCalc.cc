//########## freqCalc implemenation ##########
#include "FreqCalc.h"
using namespace std;

//######### constructers ########
//constructer
FreqCalc::FreqCalc(){
  //freqWordList
  //freqCharList
  for (int letter = 'a'; letter < 'z'; letter++) {
    //running through alphabet and adding it to the char list
    //setting keys to 0
    charList.insert({letter,0});
  }
}

//destructor
FreqCalc::~FreqCalc(){

  //making iterators to specfi where to delete form and to
  for (auto i = wordList.begin(); i != wordList.end(); i++) {
      wordList.erase(i);
  }
  for (auto i = charList.begin(); i != charList.end(); i++) {
      charList.erase(i);
  }
  for (auto i = freqWordList.begin(); i != freqWordList.end(); i++) {
      freqWordList.erase(i);
  }
  for (auto i = freqCharList.begin(); i != freqCharList.end(); i++) {
      freqCharList.erase(i);
  }

}

//######### functions ########
//recursive function scans and seperates the input it will
//call it self if input string isn't done being sepearted
void FreqCalc::SepearteInput(string input, unsigned int inputPos){
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
    if (input[inputPos] == ' ') {
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
    //sorting based on Frequency
    FreqSort();
  }
  else{
    //run function again
    SepearteInput(input, inputPos);
  }
}

//need to work on
//comparing the value of a pair<string,int>, inorder to orginize the
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

//sorts the char and word lists, into a new lists where they are order
//based on freqeuency ratehr then alphabetical
void FreqCalc::FreqSort(){
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



//######### input/output ########
//getting input from user
istream& operator>>(istream& inputSource,  FreqCalc &freqCalc){
  string inputString;

  cout << "> please input a list of words \n>>> ";
  getline(inputSource,inputString);

  //make input string to lower case from upper
  //transform(inputString.begin(), inputString.end(), inputString.begin(),this->UpperToLower);
  transform(inputString.begin(), inputString.end(), inputString.begin(),UpperToLower);

  freqCalc.SepearteInput(inputString, 0);
  cout << endl;
  return inputSource;
}

//outputting to user
ostream& operator<<(ostream& outputSource, const FreqCalc &freqCalc){

  outputSource <<setw(10)<<left<< "Words" << "Freqency" << endl;
  //print out in wordlist alphabetical
  for (auto word = freqCalc.wordList.begin(); word != freqCalc.wordList.end(); word++) {
    outputSource << setw(14) << left << word->first << word->second <<  endl;
  }

//printing out chararacter
  outputSource<< endl << setw(10)<<  left<< "Letter" << "Freqency" << endl;
  //printing out charList in alphabetical
  for (auto letter = freqCalc.charList.begin(); letter != freqCalc.charList.end(); letter++) {
    if (letter->second > 0 ) {
        outputSource << setw(14) << left << letter->first << letter->second << endl;
    }
  }

  //printing things out based on freqeuency
  //print out word list in order of Frequency
  outputSource<<endl<<"> word and char list order based on freqeuency"<<endl;
  outputSource << setw(10)<<left<<"Words" << "Frequency" << endl;
  for (auto word = freqCalc.freqWordList.begin(); word != freqCalc.freqWordList.end(); word++) {
    outputSource << setw(14) << left << word->first << word->second << endl;
  }

  //letters in order of Freqency
  outputSource<< endl << setw(10) << left << "Letter" << "Frequency" << endl;
  for (auto letter = freqCalc.freqCharList.begin(); letter != freqCalc.freqCharList.end(); letter++) {
    if (letter->second > 0 ) {
        outputSource << setw(14) << left << letter->first << letter->second << endl;
    }
  }

  outputSource <<endl<< "> done reading output." <<endl;
  return outputSource;
}
