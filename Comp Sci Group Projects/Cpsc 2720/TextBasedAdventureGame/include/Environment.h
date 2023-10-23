/**
 * @author Keagan Rieder <k.rieder@uleth.ca>
 * @date 2023-03-13
 */

#ifndef ENVIRONMENT_H_INCLUDED
#define ENVIRONMENT_H_INCLUDED

#include <Coordinate.h>
#include <Inventory.h>
#include <Item.h>
#include <PlayerData.h>
#include <GlobalVaribles.h>
#include <NpcFact.h>
#include <iostream>
#include <string>

/**
 * @class Environment Environment.h  "Environment.h"
 * @the base class for rooms inside of the game
 */
class Environment {
 public:
  /**
   * @brief default constructor
   */
  Environment();
  /**
   * @brief Destructor
   */
  virtual ~Environment();
  /**
   * @brief outputs the rooms type
   * @return rooms type as string
   */
  std::string GetType();
  /**
   * @brief outputs the rooms info
   */
  virtual void GetInfo() = 0;
  /**
   * @brief gets the rooms inventory
   * @return pointer to invnetory
   */
  virtual Inventory* GetInventory();
  /**
   * @brief hets the rooms inventory containg required items
   * @return pointer to invnetory
   */
  virtual Inventory* GetReqInventory();
  /**
   * @brief sets the rooms inventory
   * @parm [in] inventory sets the rooms inventory
   */
  virtual Npc* GetNPC();
  /**
   * @brief fixes a room if required items are met
   * @parm [in] inventory used to check req items for fixing
   */
  virtual void FixRoom(Inventory *inventory);
  /**
   * @brief returns if a room is fixed or not
   * @return return false if room not fixed, true if it is
   */
  virtual bool RoomFixed();
  /**
   * @brief move player up if wall isn't blocking
   * @parm [in] playerData
   */
  virtual void UpWall(PlayerData *player) = 0;
  /**
   * @brief move player down if wall isn't blocking
   * @parm [in] playerData
   */
  virtual void DownWall(PlayerData *player) = 0;
  /**
   * @brief move player right if wall isn't blocking
   * @parm [in] playerData
   */
  virtual void RightWall(PlayerData *player) = 0;
  /**
   * @brief move player left if wall isn't blocking
   * @parm [in] playerData
   */
  virtual void LeftWall(PlayerData *player) = 0;

 protected:
  /**
   * @brief sets contents of locations inventory
   */
  virtual void SetContents() = 0;

  std::string name;
  bool fixed = false;
  Inventory *inventory = nullptr;
  Inventory *requiredItems;
  Npc *npc = nullptr;
};
#endif // ENVIRONMENT_H_INCLUDED
