/**
 * @author Keagan Rieder <k.rieder@uleth.ca>
 * @date 2023-04-02
 */

#ifndef ROOMS_H_INCLUDED
#define ROOMS_H_INCLUDED

#include "Environment.h"
#include <iostream>
#include <string>

/**
 * @class Infirmary Rooms.h  "Rooms.h"
 * @brief concrete class to define a Infirmary room
 */
class Infirmary : public Environment {
 public:
  /**
   * @brief default constructor
   */
  Infirmary();
  /**
   * @brief default destructor
   */
  virtual ~Infirmary();
  /**
   * @brief outputs the rooms info
   * @return a string  with room info
   */
  void GetInfo();
  /**
   * @brief makes up movement not possible and injure player
   * @parm [in] playerData
   */
  void UpWall(PlayerData *player);
  /**
   * @brief makes down movement not possible and injure player
   * @parm [in] playerData
   */
  void DownWall(PlayerData *player);
  /**
   * @brief defines right direction
   * @parm [in] playerData
   */
  void RightWall(PlayerData *player);
  /**
   * @brief defines left direction
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
 * @class Barracks Rooms.h  "Rooms.h"
 * @brief concrete class to define a Barracks room
 */
class Barracks : public Environment {
 public:
  /**
   * @brief default constructor
   */
  Barracks();
  /**
   * @brief default destructor
   */
  virtual ~Barracks();
  /**
   * @brief outputs the rooms info
   * @return a string  with room info
   */
  void GetInfo();
  /**
   * @brief makes up movement not possible and injure player
   * @parm [in] playerData
   */
  void UpWall(PlayerData *player);
  /**
   * @brief makes down movement not possible and injure player
   * @parm [in] playerData
   */
  void DownWall(PlayerData *player);
  /**
   * @brief defines right direction
   * @parm [in] playerData
   */
  void RightWall(PlayerData *player);
  /**
   * @brief defines left direction
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
 * @class Bridge Rooms.h  "Rooms.h"
 * @brief concrete class to define a Bridge room
 */
class Bridge : public Environment {
 public:
  /**
   * @brief default constructor
   */
  Bridge();
  /**
   * @brief default destructor
   */
  virtual ~Bridge();
  /**
   * @brief outputs the rooms info
   * @return a string  with room info
   */
  void GetInfo();
  /**
   * @brief makes up movement not possible and injure player
   * @parm [in] playerData
   */
  void UpWall(PlayerData *player);
  /**
   * @brief makes down movement not possible and injure player
   * @parm [in] playerData
   */
  void DownWall(PlayerData *player);
  /**
   * @brief defines right direction
   * @parm [in] playerData
   */
  void RightWall(PlayerData *player);
  /**
   * @brief defines left direction
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
 * @class Storage Rooms.h  "Rooms.h"
 * @brief concrete class to define a Storage room
 */
class Storage : public Environment {
 public:
  /**
   * @brief default constructor
   */
  Storage();
  /**
   * @brief default destructor
   */
  virtual ~Storage();
  /**
   * @brief outputs the rooms info
   * @return a string  with room info
   */
  void GetInfo();
  /**
   * @brief makes up movement not possible and injure player
   * @parm [in] playerData
   */
  void UpWall(PlayerData *player);
  /**
   * @brief makes down movement not possible and injure player
   * @parm [in] playerData
   */
  void DownWall(PlayerData *player);
  /**
   * @brief defines right direction
   * @parm [in] playerData
   */
  void RightWall(PlayerData *player);
  /**
   * @brief defines left direction
   * @parm [in] playerData
   */
  void LeftWall(PlayerData *player);

 private:
  /**
   * @brief sets contents of locations inventory
   */
  void SetContents();
};
#endif //ROOMS_H_INCLUDED
