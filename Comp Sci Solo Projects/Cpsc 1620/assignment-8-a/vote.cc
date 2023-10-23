//name:keagan

//program purpose: reads the last name and number of votes of candidates in an election.
//outputs the candiates name,number of vote and the percentage of votes, in decsending order.
//it then outputs the winner.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cctype>

using namespace std;



//function prototypes

string getInput();
void display(double, string[], int[], double[]);
void displayWinner(string);
void openFile(ifstream&,double&, string[], int[]);
void computePercent(double, int[], double[]);
void sortVote(string[], int[], double []);

//const dec
const int ARRAY_SIZE = 30;
const int LINESPACING = 15;

int main(){
  ifstream inData;
  string candiates[ARRAY_SIZE] = {};
  int votes[ARRAY_SIZE] ={};
  double percents[ARRAY_SIZE] ={};
  double totalVotes = 0;
  string winner;

  openFile(inData, totalVotes, candiates, votes);
  computePercent(totalVotes, votes, percents);
  sortVote(candiates, votes, percents);

  display(totalVotes, candiates, votes, percents);


  inData.close();
  return 0;
}

//function defintions
/*
purpose: opens file based on input from getInput();
paraimters:   inputs--inData as ifstream,candiates as a string array,votes as a int array
              outputs--

retrun:
*/
void openFile(ifstream& inData,double& totalVotes,string candiates[], int votes[]){
  int pos = 0;
  //telling program to pull from file, user inputed in getInput();
  string input = getInput();
  inData.open(input);

  inData >> candiates[pos];

  while(!inData.eof()){
    inData >> votes[pos];
    totalVotes += votes[pos];
    pos++;
    inData >> candiates[pos];
  }

}

/*
purpose:promts user to enter file name
paraimters:   I/O -- input -- string

retrun:
*/
string getInput(){
  string fileName;

  cout <<"please input the name of a file to open, as follow fileName.in\n>";
  getline(cin,fileName);

  return fileName;
}

/*
purpose: caculate the percentage of votes
paraimters:   inputs-- votes as an array of ints,votePercentage as a double array
              outputs--

retrun: array of vote percentage
*/
void computePercent(double totalVotes, int votes[], double votepercents[]){
  int pos = 0;

  while (votes[pos] != 0) {
    double percentVal = votes[pos]/totalVotes * 100;
    votepercents[pos] = percentVal;
    pos++;
  }
}

/*
purpose: sort arrays
paraimters:   inputs-- candiates as a string array, votes as a int array, votePercentage as a double array
              outputs-- sorted arrays

retrun:
*/
void sortVote(string candiates[], int votes[], double votePercentage[]){
  for (int top = 0; top < ARRAY_SIZE-1; top++) {
    //find smallest
    int smallestIndex = top;
    for (int pos = top+1; pos < ARRAY_SIZE; pos++) {
      if(votes[pos] < votes[smallestIndex]){
        smallestIndex = pos;
      }
    }
    //swap vote
    int temp = votes[top];
    votes[top] = votes[smallestIndex];
    votes[smallestIndex] = temp;

    //swap candidates
    string tempCand = candiates[top];
    candiates[top] = candiates[smallestIndex];
    candiates[smallestIndex] = tempCand;

    //swap percentage
    double tempPercent = votePercentage[top];
    votePercentage[top] = votePercentage[smallestIndex];
    votePercentage[smallestIndex] = tempPercent;
  }
  //only use sorting algorithim he showed in class
}

/*
purpose: display the candiate names,numer of votes, vote perctange, and toatl votes
paraimters:   inputs--candiates as stirng array, vote as int array, votePercentage as double array
              outputs--displays text to user

retrun:
*/
void display(double totalVotes,string candiates[], int votes[], double votePercentage[]){
  cout << "\nCandiate ------ Votes Recived ------ % of Total Votes" << endl;
//output arrays
  for (int pos = ARRAY_SIZE-1; pos >= 0; pos--) {
     //end of file
    if (candiates[pos].length() == 0) {
      break;
    }
    cout << setw(LINESPACING)<< left << candiates[pos]
     << setw(LINESPACING-5)<< right << votes[pos] <<
     setw(LINESPACING+8)<< right <<setprecision(2)<< fixed<< votePercentage[pos]<<endl;
  }


  cout << "\nTotal Votes:"<<setw(LINESPACING-2)<< right<< setprecision(0)<< totalVotes <<endl<<endl;
  displayWinner(candiates[ARRAY_SIZE-1]);
}

/*
purpose: displasy the winner of the election
paraimters:   inputs--winner as string
              outputs-- displays text to user

retrun:
*/
void displayWinner(string winner){
  cout << "The winner is " << winner<<endl;
}
