//name:keagan

//program purpose: reads the last name and number of votes of candidates in an election.
//outputs the candiates name,number of vote and the percentage of votes, in decsending order.
//it then outputs the winner.
//if(in.fail())

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cctype>

using namespace std;

//struct def
struct electionStats{
  string name = "";
  int votes = 0;
  double votePercent = 0;
};

//function prototypes
string getInput();
void display(electionStats[], double);
void displayWinner(string);
void openFile(ifstream&,double&, electionStats[]);
void computePercent(double, electionStats[]);
void sortVote(electionStats[]);

//const dec
const int ARRAY_SIZE = 30;
const int LINESPACING = 15;

int main(){
  ifstream inData;
  electionStats candiate[ARRAY_SIZE];
  double totalVotes =0;


  openFile(inData, totalVotes, candiate);
  computePercent(totalVotes, candiate);
  sortVote(candiate);
  display(candiate, totalVotes);


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
void openFile(ifstream& inData,double& totalVotes, electionStats candiate[]){
  int pos = 0;
  //telling program to pull from file, user inputed in getInput();
  string input = getInput();
  inData.open(input);

  inData >> candiate[pos].name;

  while(!inData.eof()){
    inData >> candiate[pos].votes;
    totalVotes += candiate[pos].votes;
    pos++;
    inData >> candiate[pos].name;

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
void computePercent(double totalVotes, electionStats candiate[]){
  int pos = 0;

  while (candiate[pos].votes != 0) {
    candiate[pos].votePercent = candiate[pos].votes/totalVotes * 100;
    pos++;
  }
}

/*
purpose: sort arrays
paraimters:   inputs-- candiates as a string array, votes as a int array, votePercentage as a double array
              outputs-- sorted arrays

retrun:
*/
void sortVote(electionStats candiate[]){
  for (int top = 0; top < ARRAY_SIZE-1; top++){
    int smallestIndex = top;
    for(int pos = top+1; pos< ARRAY_SIZE; pos++){
      if (candiate[pos].votes < candiate[smallestIndex].votes) {
        smallestIndex = pos;
      }
    }
    //swap vote
    electionStats temp = candiate[top];
    candiate[top] = candiate[smallestIndex];
    candiate[smallestIndex] = temp;
  }
}

/*
purpose: display the candiate names,numer of votes, vote perctange, and toatl votes
paraimters:   inputs--candiates as stirng array, vote as int array, votePercentage as double array
              outputs--displays text to user

retrun:
*/
void display(electionStats candiate[], double totalVotes){
  cout << "\nCandiate ------ Votes Recived ------ % of Total Votes" << endl;
//output arrays
  for(int pos = ARRAY_SIZE-1; pos >= 0; pos--){
    cout<<candiate[0].name<<endl;
    if (candiate[pos].name.length() == 0) {
      break;
    }

  cout << setw(LINESPACING)<< left << candiate[pos].name
   << setw(LINESPACING-5)<< right << candiate[pos].votes <<
   setw(LINESPACING+8)<< right <<setprecision(2)<< fixed<<
   candiate[pos].votePercent;

  }

  cout << "\nTotal Votes:"<<setw(LINESPACING-2)<< right<< setprecision(0) << right << fixed << totalVotes <<endl<<endl;
  displayWinner(candiate[ARRAY_SIZE-1].name);
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
