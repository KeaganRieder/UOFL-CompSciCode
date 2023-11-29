/*
####################################################################
   keagan rieder cpsc 3620 AS 6
   Program that takes differnt denominations amounts of coins and 
   a target it then uses the dynamic programming strategy inorder to 
   find an amount of coins in the provided denominations need to reach
   the target
####################################################################
*/
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>     
using namespace std;

//global varibles
const int SIZE_LIMIT = 100000; //size limit of coins denominations and target

int targetAmount;
vector<int> denominations;
int  minNeeded = 0;



//function decleration
void GetTarget();
void GetDenotaions();
void OutputResult();
int FindRequiredAmount(int target);

//main program loop
int main(){
    //inital play the denomination of 1 sense it's always avalible
    denominations.push_back(1);
    //get input
    GetTarget();

    //find amount of coins to reach 
    minNeeded = FindRequiredAmount(targetAmount);

    //output result
    OutputResult();

    //temp to hold power shell
    cout<<endl;
    GetTarget();
    return 0;
}

//function implementation
void GetTarget(){
    bool valid = false;
    int input;

    //prompt for user to input coin target
    cout << "Please input the desired target amount. ensur it's positive and less then " << 
    SIZE_LIMIT << endl;

    //check if input for target is valid
    while (!valid)
    {
        cout << "> ";
        cin >> input;
        if(input > SIZE_LIMIT || input <= 1){
            cout <<"ERROR: Invalid target size ensure input is greater then one \n"
                << "and less then" << SIZE_LIMIT << endl;
        }
        else{
            valid = true;
            targetAmount = input;
        }
        
    }
    //getting denotations
    GetDenotaions();
}

void GetDenotaions(){
    bool valid = false;
    int input;
    int totalDenominations = 0;

    //prompt for user to input coin number denominations
    cout << endl << "Please Input the avalble amount ofcoin denominations to be provided "<< endl;
    cin >> totalDenominations;
   
    for (int i = 0; i < totalDenominations; i++)
    {
        cout << endl << "Please Input the coin denominations,ensure it's greater then 1 and less then " << SIZE_LIMIT << endl;
        while (!valid)
        {
            cout << "> ";
            cin >> input;
            //checking if input's valid
            if(input > SIZE_LIMIT || input <= 1 ){
                cout <<"ERROR: Invalid denominations size ensure input is greater then one \n"
                    << "and less then " << SIZE_LIMIT << endl;
            }  
            else{
                denominations.push_back(input);
            }         
        }
    }
    
    // sort vector so biggest element is last
    // then can just work backwards
    sort(denominations.begin(), denominations.end());
}

/*
    min
    1 ≤ i ≤n, D[i]≤S
    (min coins for S − D[i]) + 1
    where D[i] is the i-th denomination
*/
int FindRequiredAmount(int target){
    // make vector to store result of each sum
    vector<int> table(target + 1, SIZE_LIMIT); 
    //base case target = 0, meaning total needed = 0
    table[0] = 0;
    
    //iterate through all possible sums
    for (int i = 1; i < target; i++)
    {
        //run thorugh all possible denmoinations
        for (size_t j = 0; j < denominations.size(); j++)
        {
            //check if currnet denomination can contribute to current sum
            if(denominations[i] <= i){
                int difference = table[target - denominations[j]];

                //check if difference is valid an d if so
                //update the minimum number of coins
                if (difference != SIZE_LIMIT && difference + 1 < table[i])
                {
                    table[i] = difference + 1;
                } 
            }
        }
            
    }        
    
    return table[target];
}

void OutputResult(){
    // int totalCoins = 0;
    cout << "here is the coins from provided denominations required to reach \n"
        << "the target of " << targetAmount<< endl << endl;  

    cout << endl << "Total coins: "<< minNeeded;
}


