//useStack Test File

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


//function defintions
bool IsBalanced(const string& str);
bool EvalRPN(const string& str, int& result);

int main(){
  //varibles
  ifstream inputFile;
  string input;
  int rpnResult = 0;
  int filePos = 0;//to check if checking brackets or RPN
  bool fileFound = false;

  cout<<setw(20)<<setfill('#')<<'\n';
  cout<< " UseStack testCode" << endl;
  cout<<setw(20)<<setfill('#')<<'\n'<<endl;

  //asks user for file location, and if unable to locate
  //will ask again until eitehr able to find file or program is terminated
  while (!fileFound) {
    //Informing CurrentFIle BeingOpend
    cout<< "Input name of file and location if not in current dirctory" << endl
        << ">>> ";
    cin >> input;

    inputFile.open(input);
    if (inputFile) {
      cout<< "> given file has been located. Opening"<<endl
          << ">>> " << input << endl;
      fileFound = true;
    }
    else{
      cout <<"> Invalid location could not locate file"<<endl;
    }
  }

  //main program loop will run if file is found
  //opening files

  //main program loop
  cout<<setw(50)<<setfill('-')<<'\n'<<endl;
  while (getline(inputFile, input)) {
    //reading Bracket lines
    if (filePos < 5) {
      cout<<"> Chekcing if parentheses in stamenet are balanced: " << endl
          << "> " << input <<endl<<endl;
      if (IsBalanced(input)) {
        cout<<">>> given stamenet is balanced"<<endl;
      }
      else{
        cout<<">>> given stamenet is not balanced"<<endl;
      }
    }

    //reading RPN lines
    else if (filePos < 10 ) {
      cout<< "> Chekcing if given RPN Equation is valid: " << endl
          << "> " << input << endl <<endl;
      if (EvalRPN(input,rpnResult)) {
        cout<<">>> given equation is Valid the result is "<<endl
            << ">>> " << rpnResult <<endl;
      }
      else{
        cout<<">>> given equation is not Valid "<<endl;
      }
    }
    //adding a space between sections
    cout<<endl<<setw(50)<<setfill('-')<<'\n'<<endl;
    filePos++;
  }

  cout<<"> file reading is complete."<<endl;
  inputFile.close();

  return 0;
}
//function implemnetation

//cheks if paramietr str has balanced paranthases
bool IsBalanced(const string& str){
  //bool balanced = false;
  stack<char> checkingStack; //stack used to check if balanced
  string noBracket =" ";

  for (size_t i = 0; i < str.size(); i++) {

    //checking if open bracket, then adding it with push
    if (str[i] == '(' ) {
      checkingStack.push(str[i]);
    }
    //chekcing if close bracket, an then doing pop back
    else if (str[i] == ')') {
      //seeing if stack is empty, and then retruning false
      //cause if stack is empty and conatisn this ) it's not valid
      //do to this not being )( for paranthases
      if (checkingStack.empty()) {
        return false;
      }
      checkingStack.pop();

    }

  }
  //setting str to equation without brackets

  //checking if stack is empty, meaning their is eqal paranthases
  //and teh string is balanced otehr wise
  if (checkingStack.empty()) {
    return true;
  }
  //the stack contains a paranthases
  return false;
}

//process the opertaion given by the paramiter string,
//runs after is balanced an thus ensuring that the operation
//has ballanced paranthases
bool EvalRPN(const string& str, int& result){
  stack<int> operationStack;
  int operad1;
  int operad2;

  //runing through equation
  for (size_t i = 0; i < str.size(); i++) {
    if (str[i] == ' ') {
      //do nothing sense it space betwen char
    }
    //pop out 2 and push 1 in when opeartor is seen
    //have to convert between ints and strings
    //validRPN(operationStack, true)
    else if (str[i] =='+') {
      if (operationStack.size() >= 2) {

        operad1 = operationStack.top();
        operationStack.pop();
        operad2 = operationStack.top();
        operationStack.pop();
        operad2 += operad1;
        //pushing operation result back onto stack
        operationStack.push(operad2);
      }
      //not valid RPN
      else{
        return false;
      }

    }
    else if (str[i] =='-') {
      if (operationStack.size() >= 2) {
        operad1 = operationStack.top();
        operationStack.pop();
        operad2 = operationStack.top();
        operationStack.pop();
        operad2 -= operad1;
        //pushing operation result back onto stack
        operationStack.push(operad2);
      }
      //not valid RPN
      else{
        return false;
      }
    }

    else if (str[i] =='*') {
      if (operationStack.size() >= 2) {
        operad1 = operationStack.top();
        operationStack.pop();
        operad2 = operationStack.top();
        operationStack.pop();
        operad2 *= operad1;
        //pushing operation result back onto stack
        operationStack.push(operad2);
      }
      //not valid RPN
      else{
        return false;
      }
    }
    //adding current numebr to opeartion useStack
    else{
      string input;
      input = str[i];
      i++;
      for (; str[i] != ' '; i++) {
        input += str[i];
      }

      operationStack.push(stoi(input));
    }
  }

  //set operad to teh operations result
  //validRPN(operationStack,false)
  if (operationStack.size() == 1) {
    result = operationStack.top();
    operationStack.pop();
    return true;
  }
  else{
    return false;
  }
}
