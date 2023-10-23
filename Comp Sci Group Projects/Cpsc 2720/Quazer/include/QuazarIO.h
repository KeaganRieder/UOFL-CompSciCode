//#####################
// QuazarIO definition
//#####################
#ifndef QUAZARIO_H
#define QUAZARIO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>
#include <random>

//player class
#include "Player.h"
//spinner class include
#include "Spinners.h"
#include "FairSpinner.h"
#include "HouseSpinner.h"
#include "PlayerSpinner.h"

class QuazarIO {
 public:
  //##########################
  // Constructors/Destructors
  //##########################

  //constructor
  QuazarIO();
  //Destructors
  virtual ~QuazarIO();

  //#######################
  // QuazarIO UI and logic
  //#######################

  //main main of quazar, function used to begin the game/get to help screen
  void MainMenu();

  //main Recursive function of QuazarIO, will run until
  // either the player has to low of credits or they
  //wish to quit
  void Run();

  //displays helpful information about how the game works
  void Help();

  // outputs UI for gameover/exit screen
  //Parameter exit is passed in to determine weather to display
  //game over(exit = false) /exit(exit=true) screen
  void GameOver(bool exit);

 private:
  //making input lowercase
  void MakeLowercase(std::string&);

  //game logic
  //checking output to see weatehr to keep thing blank or not
  //this is only ran inside of run
  int CheckPayOut();
  void Spin();

  //QuazarIO classes
  //player class
  Player player;
  //QuazarIO variables
  std::string stakes;
  int spinValue;

  //UI formatting code
  int BorderLength;
};

#endif
