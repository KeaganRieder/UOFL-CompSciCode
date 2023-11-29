/*
####################################################################
   keagan rieder cpsc 3620 AS 4
   this is the main file for FlipsSide Program
   which conatins definitions to functions, to take in
   a state of a FlipSide Puzzle and then solve it
####################################################################
*/
#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

const string SOLUTION_STATE = "0123456789";

void GetInput();
void OutPutSolution();
bool IsSolved(const string&);
bool StateExsits(const string&);
void GenerateNeighbours(const string&);
string Flip(const string&, int, int);
bool SolveFlipSide();

map<string, int> stateDistance; 
map<string,pair<int,int>> stateMoves; //map to track moves of current state
map<string, string> stateParents; // map to store parents of a state
queue<string> stateQueue;


//main function loop
int main(){

   GetInput();

   bool solvable = SolveFlipSide();

   if(solvable){
      OutPutSolution();
   }
   else{
      cout<<"Error Solving: unsolvable";
   }

   return 0;
}

/*
#########################################################
   function's implementation
#####################################################################
*/

//BFs and functions to solve flipside
bool IsSolved(const string& state){
   return state == SOLUTION_STATE;
}

bool StateExsits(const string& state){
   if (stateDistance.find(state) == stateDistance.end())
   {
      return false;
   }
   else{
      return true;
   }
}

string Flip(const string& state, int botOffset, int topOffset){
   string newState = state;
   int center = state.length()/2;
   int bot = center + 2 + botOffset; //left side of string
   int top = center - 3 + topOffset; //right side of string
   
   //fliping pieces
   newState[bot-1] = state[top-1]; 
   newState[bot] = state[top];     
   newState[bot+1] = state[top+1];
   newState[top-1] = state[bot-1];
   newState[top] = state[bot];    
   newState[top+1] = state[bot+1];

   //cout<<newState<<endl<<endl;
   return newState;
}

void GenerateNeighbours(const string& currentState){
   int possibleMoves[3] = {-1,0,1}; // the posible moves for top and bottom
   int totalMoves = sizeof(possibleMoves) / sizeof(int);

   //generated new states for eevery possible move
   // 9 intotal moves will be generated
   for (int x = 0; x < totalMoves; x++)
   {
      for (int y = 0; y < totalMoves; y++)
      {
         
         string generatedNeighbour = Flip(currentState,possibleMoves[x],possibleMoves[y]);

         //checking if state hasn't been visted (not in the map "stateDistance")
         if (!StateExsits(generatedNeighbour))
         {
            //botom is first, top is second
            pair<int, int> moves(possibleMoves[x],possibleMoves[y]);
            stateQueue.push(generatedNeighbour);
            stateMoves[generatedNeighbour] = moves;
            stateParents[generatedNeighbour] = currentState;
            stateDistance[generatedNeighbour] = stateDistance[currentState] + 1;
         }
      }
   }
}

bool SolveFlipSide(){
   //running bfs
   cout<<"Solving input flipSide";
   while (!stateQueue.empty())
   {      
      string CurrentState = stateQueue.front();
      stateQueue.pop();

      //checking if current state is correct state
      if (IsSolved(CurrentState))
      {
         return true;      
      }
      //else running through the neibours
      GenerateNeighbours(CurrentState);
   }
   return false;
}

//input output functions
void GetInput(){
   string input = "";
   bool valid = false;

   cout << "please input the inital state of a 10 character flipside puzzle \n>>> ";
   cin >> input;
   cout << endl;

   while (!valid)
   {        
      if(input.size() > 10){
         cout << "Error: input greater then 10 character, reinput \n>>> ";
         cin >> input;
         cout << endl;
      }
      else{
         valid = true;
      }
   }

   //pushing the inital state onto queue
   //string initalState(input);
   stateQueue.push(input);
   stateDistance[input] = 0;
   stateParents[input] = input;
}

void OutPutSolution(){
   string state = SOLUTION_STATE;
   int steps = stateDistance[SOLUTION_STATE];

   cout << "Total moves to Solve provided FlipSide:" << stateDistance[SOLUTION_STATE] << endl;
   cout << "This can achived by doing the following steps" << endl;

   for (int i = 0; i < stateDistance[SOLUTION_STATE]; i++)
   {
      cout<<"> Step "<< steps-i <<endl;
      //botom is first, top is second
      cout <<"> State:"<< state <<" achived by the following:"<<endl<<endl;  
      cout <<"> shift bottom by:"<< stateMoves[state].first*-1 << endl <<endl;
      cout <<"> shift top by:"<< stateMoves[state].second*-1 << endl <<endl;    

      state = stateParents[state];
   }
}