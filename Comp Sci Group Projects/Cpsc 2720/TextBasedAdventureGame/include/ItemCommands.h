/**
 * @author Keagan Rieder <k.rieder@uleth.ca>
 * @author Maxenne Jubane <maxenne.jubane@uleth.ca>
 * @date 2023-03-28
 */

#ifndef ITEM_COMMANDS_H_INCLUDED
#define ITEM_COMMANDS_H_INCLUDED
#include "Command.h"
#include <iostream>
#include <string>
/**
 * @class PickUp ItemCommands.h  "ItemCommands.h"
 * @brief class to define a command to move up
 */
class PickUp : public Command {
 public:
  /**
   * @brief default constructor
   * @parm [in] map as pointer to game map
   * @parm [in] player as pointer to PlayerData
   */
  PickUp(GameMap *map, PlayerData *player);
  /**
   * @brief default destructor
   */
  virtual ~PickUp();

  /**
   * @brief runs comamnd
   * parm[in] itemName as string
   */
  void Run(std::string itemName);
};

/**
 * @class Drop ItemCommands.h  "ItemCommands.h"
 * @brief class to define a command to move up
 */
class Drop : public Command {
 public:
  /**
   * @brief default constructor
   * @parm [in] map as pointer to game map
   * @parm [in] player as pointer to PlayerData
   */
  Drop(GameMap *map, PlayerData *player);
  /**
   * @brief default destructor
   */
  virtual ~Drop();

  /**
   * @brief runs comamnd
   * parm[in] itemName as string
   */
  void Run(std::string itemName);
};

/**
 * @class FinishQuest ItemCommands.h  "ItemCommands.h"
 * @brief class to define a command to move up
 */
class FillAir : public Command {
 public:
  /**
   * @brief default constructor
   * @parm [in] player as pointer to PlayerData
   */
  FillAir(PlayerData *player);
  /**
   * @brief default destructor
   */
  virtual ~FillAir();

  /**
   * @brief runs comamnd
   * parm[in] itemName as string
   */
  void Run();
};
#endif // ITEM_COMMANDS_H_INCLUDED
