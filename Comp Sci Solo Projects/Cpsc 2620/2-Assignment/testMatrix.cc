//test file for matrix class
#include "Matrix.h"
#include <sstream>

using namespace std;

//test file functions decleration
//input and output
//gets input form user
string GetUserInput();
//processs user command and sets it to corisponding varibles
void ProcessUserInputString(string, size_t&, string&);
void ProcessUserInput(string, size_t&, int&);
//checks for if current pos in input is white space or
//a character menaing a word or number
void CheckInputPos(string, size_t&);
//outputs the list of comamnds for matrix
void PrintCommands();

int main(){
  //varible and object dec
  bool running = false;
  string userInput = " ";
  size_t inputPos = 0;
  int matrixDimensions = 0;
  //varibles for switchoard
  string command = "";
  int newInt;
  int constant;
  int newSize;
  int row;
  int col;
  int row2;
  int col2;

  //main program loop
  cout<<"> Welcome to Matrix Maker.\n";
  cout<<"> Please input the dimensions of your matirx: \n>>> ";
  cin >> matrixDimensions;
  //cin.ignore() is used to clear the input line for
  //get line to run correctly and not atuomatically filled with
  //garbage following a cin
  cin.ignore();
  PrintCommands();

  //creating a matrix object of size matrixDimensions x matrixDimensions;
  CMatrix matrixObj(matrixDimensions);

  //starting main program loop
  running = true;
  while (running) {
    //getting user input to run matrix commands
    userInput = GetUserInput();
    inputPos = 0;
    //setting value to default so theres a value if nothing is
    //inputed
    command = "";
    newInt = 0;
    constant = 0;
    newSize = 1;
    row = 0;
    col = 0;
    row2 = 0;
    col2 = 0;

    //command swicthboard
    ProcessUserInputString(userInput, inputPos, command);

    if (command == "getDimension") {
      cout<< "> the matrix dimensions are "
      << matrixObj.GetDimension() << " x " << matrixObj.GetDimension() << endl;
    }
    else if (command == "getElement") {

      ProcessUserInput(userInput,inputPos, row);
      ProcessUserInput(userInput,inputPos, col);
      //running command
      cout<<"> the element at row " << row <<", col "<< col
      <<"\n> is " << matrixObj.GetElementAt(row,col) << endl;
    }
    else if (command == "replaceElement") {

      ProcessUserInput(userInput,inputPos, row);
      ProcessUserInput(userInput,inputPos, col);
      ProcessUserInput(userInput,inputPos, newInt);
      //running command
      matrixObj.ReplaceElementAt(row,col,newInt);

      cout<< "> " << newInt << " has been replace.\n";

    }
    else if (command == "setElement") {
      ProcessUserInput(userInput,inputPos, row);
      ProcessUserInput(userInput,inputPos, col);
      //running command
      matrixObj.SetElementAt(row,col);

      cout<< "> element set to 1 \n";
    }
    else if (command == "clearElement") {
      ProcessUserInput(userInput,inputPos, row);
      ProcessUserInput(userInput,inputPos, col);
      //running command
      matrixObj.ClearElementAt(row,col);
      cout<< "> element set to 0 \n";
    }
    else if (command == "swapElements") {
      ProcessUserInput(userInput,inputPos, row);
      ProcessUserInput(userInput,inputPos, col);
      ProcessUserInput(userInput,inputPos, row2);
      ProcessUserInput(userInput,inputPos, col2);
      //running command
      matrixObj.SwapElementsAt(row, col, row2, col2);

      cout<< "> element at pos " << row <<", " << col
      << " has been swaped with elemnt at " << row2 <<", " << col2
      << endl;
    }
    else if (command == "resizeMatrix") {
      ProcessUserInput(userInput, inputPos, newSize);
      matrixObj.ResizeMatrix(newSize);
    }
    else if (command == "addConstant") {
      ProcessUserInput(userInput, inputPos, constant);
      //running command
      matrixObj.AddConstant(constant);
      cout<< "> every element has been set to constant " << constant << endl;
    }
    else if (command == "readMatrix") {
      matrixObj.ReadMatrix();
    }
    else if (command == "printMatrix") {
      matrixObj.PrintMatrix();
    }
    else if (command == "help") {
      PrintCommands();
    }
    else if (command == "exit") {
      cout<< "> bye bye. \n";
      running = false;
      matrixObj.DeallocateMatrixMemory();
    }
    else{
      cout<< "\n> invalid command. \n";
      PrintCommands();
    }
  }
  //end of program
  return 0;
}

//testFile function implemenation
//gets input form user
string GetUserInput(){
  string userInput = "";
  cout<<"> please input matrix command "
  << endl << ">>> ";
  getline(cin, userInput);
  return userInput;
}
//processs user command and sets it to corisponding varibles
void ProcessUserInputString(string userInput, size_t& inputPos, string& command){
  //check if current input pos is white space
  CheckInputPos(userInput,inputPos);
  //setting command to first char afetr a whitespace
  command = userInput[inputPos];
  inputPos++;
  //setting rest of command
  for (; inputPos < userInput.size(); inputPos++) {
    //checking to see if white space, menaing end of command
    if (userInput[inputPos] == ' ') {
      break;
    }
    command += userInput[inputPos];
  }
}
void ProcessUserInput(string userInput, size_t& inputPos, int& command){
  //checking to see if there is anything left to add, or if input was missing paramiter
  if (inputPos != userInput.size()) {
    string tempStr = "0";
    //check if current input pos is white space
    CheckInputPos(userInput,inputPos);
    //setting command to first char afetr a whitespace

    tempStr = userInput[inputPos];
    inputPos++;
    //setting rest of command
    if (userInput[inputPos] != ' ') {
      for (; inputPos < userInput.size(); inputPos++) {
        //checking to see if white space, menaing end of command
        if (userInput[inputPos] == ' ') {
          break;
        }
        tempStr += userInput[inputPos];
      }
    }
    //stoi is to convert string to int
    command = stoi(tempStr);
  }
  else{
    command = 0;
  }
}
//checks for if current pos in input is white space or
//a character menaing a word or number
void CheckInputPos(string userInput, size_t& inputPos){
  while (userInput[inputPos] == ' ') {
    inputPos++;
  }
}
//outputs commands to user
void PrintCommands(){
  cout << "\n> The comamnds are as followed:\n"
  << "> getDimension, getElement row col, replaceElement row col newInt \n"
  << "> setElement row col, clearElement row col \n"
  << "> swapElements row1 col1 row2 col2, resizeMatrix newSize, \n"
  << "> addConstant constant, readMatrix,\n"
  <<"> printMatrix, help and exit. \n"
  <<"> Any value left blank will be set to the default value of 0.\n\n";
}
