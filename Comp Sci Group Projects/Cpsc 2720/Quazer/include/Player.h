//#pragma once
#include <iostream>

#ifndef PLAYER_H
#define PLAYER_H

class Player {
 public:
  Player();  // default constructor
  ~Player();  // default destrucctor

  int GetCredits();  // function to get the player's credits
  void SetCredits(int value);  // fucntion to set a player's credits.
  int GetBuyIn();  // function to get the player's BuyIn amount
  void SetBuyIn(int value);  // fucntion to set a player's BuyIn amount.
  void UpdateCredits(int value);  // fucntion to update a player's credits
  bool HighStakesOpen();  // check if a plaayer can play high stakes
  bool MediumStakesOpen();  // check if a player can play medium stakes
 private:
  int credits;
  int buyIn;
};
#endif
