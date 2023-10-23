/**
 * @author Keagan Rieder <k.rieder@uleth.ca>
 * @author Maxenne Jubane <maxenne.jubane@uleth.ca>
 * @date 2023-03-28
 */

#ifndef COMMND_MANGER_H_INCLUDED
#define COMMND_MANGER_H_INCLUDED

#include "Command.h"
#include "ItemCommands.h"
#include "NpcCommands.h"
#include "RoomCommands.h"
#include <iostream>
#include <string>
#include <algorithm>
/**
 * @class CommandManger CommandManger.h  "CommandManger.h"
 * @brief abstract class to define a commands
 */
class CommandManger {
 public:
  /**
   * @brief default constructor
   * @parm [in] player as a pointer to PlayerData
   * @parm [in] map as a pointer to GameMap
   */
  CommandManger(PlayerData *player, GameMap *map);
  /**
   * @brief default destructor
   */
  virtual ~CommandManger();
  /**
   * @brief runs command based on input
   * @parm [in] input as string
   */
  bool RunCommand(std::string input);
  /**
   * @brief sets up command array
   */
  void SetCommandArray();
  /**
   * @brief clears command array
   */
  void ClearCommandArray();
  /**
   * @brief runs command based on input
   * @parm [in] inv as Inventory pointer
   * @return name of item as string
   */
  std::string GetItemName(Inventory *inv);

 protected:
  GameMap *gameMap;
  PlayerData *playerData;
  Up *up;
  Down *down;
  Left *left;
  Right *right;
  Look *look;
  FixRoom *fixRoom;
  Talk *talk;
  FinishQuest *finishQuest;
  PickUp *pickUp;
  Drop *drop;
  FillAir *fillAir;
  Heal *heal;
};

#endif // COMMND_MANGER_H_INCLUDED
