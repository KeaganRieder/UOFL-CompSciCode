/**
 * @author Keagan Rieder <k.rieder@uleth.ca>
 * @date 2023-03-13
 */

#ifndef REACTOR_H_INCLUDED
#define REACTOR_H_INCLUDED

#include "Environment.h"
#include <iostream>
#include <string>
/**
 * @class Reactor Reactor.h  "Reactor.h"
 * @brief concrete class to define a reactor room
 */
class Reactor : public Environment {
 public:
  /**
   * @brief default constructor
   */
  Reactor();
  /**
   * @brief default destructor
   */
  virtual ~Reactor();
  /**
   * @brief outputs the rooms info
   * @return a string  with room info
   */
  void GetInfo();
  /**
   * @brief makes room not have any loot able things
   * @return nullptr
   */
  Inventory* GetInventory();
  /**
   * @brief hets the rooms inventory containg required items
   * @return pointer to invnetory
   */
  Inventory* GetReqInventory();
  /**
   * @brief checks what items are need to repair
   * @return return false if room not fixed, true if it is
   */
  void CheckRepairItems(Inventory *PlayerInv);
  /**
   * @brief fixes a room if required items are met
   * @parm [in] inventory used to check req items for fixing
   */
  void FixRoom(Inventory *inventory);
  /**
   * @brief returns if a room is fixed or not
   * @return return false if room not fixed, true if it is
   */
  //bool RoomFixed();
  /**
   * @brief makes Up movement not possible and injure player
   * @parm [in] cords Player cords
   */
  void UpWall(PlayerData *player);
  /**
   * @brief makes Down movement not possible and injure player
   * @parm [in] playerData
   */
  void DownWall(PlayerData *player);
  /**
   * @brief makes Right movement not possible and injure player
   * @parm [in] playerData
   */
  void RightWall(PlayerData *player);
  /**
   * @brief makes left movement not possible and injure player
   * @parm [in] playerData
   */
  void LeftWall(PlayerData *player);

 private:
  /**
   * @brief sets contents of locations inventory
   */
  void SetContents();
};

/**
 * @class AirLock FixableRooms.h  "FixableRooms.h"
 * @brief concrete class to define a reactor room
 */
class AirLock : public Environment {
 public:
  /**
   * @brief default constructor
   */
  AirLock();
  /**
   * @brief default destructor
   */
  virtual ~AirLock();
  /**
   * @brief outputs the rooms info
   * @return a string  with room info
   */
  void GetInfo();
  /**
   * @brief makes room not have any loot able things
   * @return pointer to invnetory
   */
  Inventory* GetInventory();
  /**
   * @brief hets the rooms inventory containg required items
   * @return pointer to ReqInventory
   */
  Inventory* GetReqInventory();
  /**
   * @brief checks what items are need to repair
   * @return return false if room not fixed, true if it is
   */
  void CheckRepairItems(Inventory *PlayerInv);
  /**
   * @brief fixes a room if required items are met
   * @parm [in] inventory used to check req items for fixing
   */
  void FixRoom(Inventory *inventory);
  /**
   * @brief moves player up
   * @parm [in] player the player's data
   */
  void UpWall(PlayerData *player);
  /**
   * @brief Moves player into ocean if diving gear is fixed, otherwise kills them
   * @parm [in] player the player's data
   */
  void DownWall(PlayerData *player);
  /**
   * @brief  moves player right
   * @parm [in] player the player's data
   */
  void RightWall(PlayerData *player);
  /**
   * @brief moves player left
   * @parm [in] player the player's data
   */
  void LeftWall(PlayerData *player);

 private:
  /**
   * @brief sets contents of locations inventory
   */
  void SetContents();
};

#endif // REACTOR_H_INCLUDED
