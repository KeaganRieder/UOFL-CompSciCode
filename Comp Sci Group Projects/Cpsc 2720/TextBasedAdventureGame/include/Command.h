/**
 * @author Keagan Rieder <k.rieder@uleth.ca>
 * @date 2023-03-28
 */

#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include "GameMap.h"
#include "PlayerData.h"
#include <iostream>
#include <string>
/**
 * @class Command Command.h  "Command.h"
 * @brief abstract class to define a commands
 */
class Command {
 public:
  /**
   * @brief default constructor
   */
  Command() {
  }

  /**
   * @brief default destructor
   */
  virtual ~Command() {
  }

  /**
   * @brief runs comamnd
   */
  virtual void Run() {
  }
  /**
   * @brief runs comamnd
   * parm[in] string name of item
   */
  virtual void Run(std::string itemName) {
  }

 protected:
  GameMap *gameMap;
  PlayerData *playerData;
  Coordinate *Coordinates;
};

#endif // COMMAND_H_INCLUDED
