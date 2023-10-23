/**
 * @author Keagan Rieder <k.rieder@uleth.ca>,
 * @author Maxenne Jubane <maxenne.jubane@uleth.ca>
 * @date 2023-03-30
 */

#ifndef UNDERUS_H_INCLUDED
#define UNDERUS_H_INCLUDED

#include <GameMap.h>
#include "PlayerData.h"
#include "CommandManger.h"
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

/**
 * @class UnderUS UnderUS.h  "UnderUS.h"
 * @Gets the concrete environment objects for the map
 */
class UnderUs {
 public:
  /**
   * @brief Default Constructor
   */
  UnderUs();
  /**
   * @brief Default Destructor
   */
  virtual ~UnderUs();
  /**
   * @brief Games Menu
   */
  void MainMenu();
  /**
   * @brief Displays commands
   */
  void GetCommands();
  /**
   * @brief Displays helpful info
   */
  void Gethelp();
  /**
   * @brief displays the back story for the game
   */
  void BackStory();
  /**
   * @brief Starts the game
   */
  void Play();
  /**
   * @brief Exits the game
   */
  void Exit();
  /**
   * @brief Asks for string input and returns it
   */
  void SendCommand();
  /**
   * @brief Displays game over msg
   */
  void GameOver();
  /**
   * @brief Displays Victory screen/credits
   */
  void GameWon();

 private:
  GameMap *gameMap;
  PlayerData *player;
  CommandManger *commandHandler;
  bool playing = false;
  std::string input;
};
#endif //UNDERUS_H_INCLUDED
