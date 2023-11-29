/*
####################################################################
   keagan rieder cpsc 3620 AS 6
   Program that takes differnt denominations amounts of coins and 
   a target it then uses the greedy method inorder to find an
   amount of coins in the provided denominations need to reach
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
map<int, int> coinAmount; // key = coin, val = amount used
vector<int> denominations;


//function decleration
void GetTarget();
void GetDenotaions();
void OutputResult();
void FindRequiredAmount(int currentCoin, int target);

//main program loop
int main(){
    //inital play the denomination of 1 sense it's always avalible
    coinAmount[1] = 0;
    denominations.push_back(1);
    //get input
    GetTarget();

    //find amount of coins to reach 
    FindRequiredAmount(denominations.size(),targetAmount);

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
            else if (coinAmount.find(input ) != coinAmount.end())
            {
            cout <<"ERROR: denomination is already provided" << SIZE_LIMIT<<endl;
            }    
            else{
            coinAmount[input] = 0; 
            denominations.push_back(input);
            }         
        }
    }
    
    // sort vector so biggest element is last
    // then can just work backwards
    sort(denominations.begin(), denominations.end());
}

void FindRequiredAmount(int currentCoin, int target){
    int coin;
    //check if target amount is zero
    if(target == 0){
        //do nothing sense no return type
        //just used to stop recurrsion
    }
    //otherwise subtract from current coin amount
    else{
        coin = denominations[currentCoin];
        //subtract from target amount using cuurent denomination
        while (target >= coin)
        {
            target -= coin;
            coinAmount[coin] = coinAmount[coin] + 1;
        }
        //move to next coin
        FindRequiredAmount(currentCoin - 1, target);
    }
}

void OutputResult(){
    int totalCoins = 0;
    cout << "here is the coins from provided denominations required to reach \n"
        << "the target of " << targetAmount<< endl << endl;
    
    //ruuning through denomination amounts
    for (size_t i = 0; i < coinAmount.size(); i++)
    {
        totalCoins += coinAmount[denominations[i]];
        cout<< " coin: " << denominations[i] << " amount: " << coinAmount[denominations[i]] << endl;
    }    

    
    cout << endl << "Total coins: "<< totalCoins;
}

