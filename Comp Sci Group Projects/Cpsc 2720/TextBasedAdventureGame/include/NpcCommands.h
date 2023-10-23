/**
 * @author Keagan Rieder <k.rieder@uleth.ca>
 * @author Maxenne Jubane <maxenne.jubane@uleth.ca>
 * @date 2023-03-28
 */

#ifndef NPC_COMMANDS_H_INCLUDED
#define NPC_COMMANDS_H_INCLUDED
#include "Command.h"
#include <iostream>
#include <string>

/**
 * @class FinishQuest NPCCommands.h  "NPCCommands.h"
 * @brief class to define a command to move up
 */
class FinishQuest : public Command {
 public:
  /**
   * @brief default constructor
   * @parm [in] map as pointer to game map
   * @parm [in] player as pointer to PlayerData
   */
  FinishQuest(GameMap *map, PlayerData *player);
  /**
   * @brief default destructor
   */
  virtual ~FinishQuest();

  /**
   * @brief runs command
   */
  void Run();
};

/**
 * @class Talk NPCCommands.h  "NPCCommands.h"
 * @brief class to define a command to move up
 */
class Talk : public Command {
 public:
  /**
   * @brief default constructor
   * @parm [in] map as pointer to game map
   * @parm [in] player as pointer to PlayerData
   */
  Talk(GameMap *map, Coordinate *cords);
  /**
   * @brief default destructor
   */
  virtual ~Talk();

  /**
   * @brief runs command
   */
  void Run();
};

/**
 * @class Heal NPCCommands.h  "NPCCommands.h"
 * @brief class to define a command to move up
 */
class Heal : public Command {
 public:
  /**
   * @brief default constructor
   * @parm [in] map as pointer to game map
   * @parm [in] player as pointer to PlayerData
   */
  Heal(GameMap *map, PlayerData *player);
  /**
   * @brief default destructor
   */
  virtual ~Heal();

  /**
   * @brief runs command
   */
  void Run();
};

#endif // NPC_COMMANDS_H_INCLUDED
