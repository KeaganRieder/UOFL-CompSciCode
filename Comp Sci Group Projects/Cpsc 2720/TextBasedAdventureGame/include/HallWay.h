/**
 * @author Keagan Rieder <k.rieder@uleth.ca>
 * @date 2023-03-13
 */

#ifndef HALLWAY_H_INCLUDED
#define HALLWAY_H_INCLUDED

#include "Environment.h"
#include <iostream>
#include <string>
/**
 * @class Hallway Hallway.h  "Hallway.h"
 * @brief concrete class to define a Hallway room
 */
class HallWay : public Environment {
 public:
  /**
   * @brief default constructor
   */
  HallWay();
  /**
   * @brief default destructor
   */
  virtual ~HallWay();
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
   * @brief @brief defines left direction
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
 * @class HallwayEnd Hallway.h  "Hallway.h"
 * @brief concrete class to define a Hallway room
 */
class HallwayEnd : public Environment {
 public:
  /**
   * @brief default constructor
   */
  HallwayEnd();
  /**
   * @brief default destructor
   */
  virtual ~HallwayEnd();
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
   * @brief @brief defines left direction
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
 * @class Elevator Hallway.h  "Hallway.h"
 * @brief concrete class to define a Hallway room
 */
class Elevator : public Environment {
 public:
  /**
   * @brief default constructor
   */
  Elevator();
  /**
   * @brief default destructor
   */
  virtual ~Elevator();
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
   * @brief @brief defines left direction
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
 * @class TopAirLock Hallway.h  "Hallway.h"
 * @brief concrete class to define a TopAirLock room
 */
class TopAirLock : public Environment {
 public:
  /**
   * @brief default constructor
   */
  TopAirLock();
  /**
   * @brief default destructor
   */
  virtual ~TopAirLock();
  /**
   * @brief outputs the rooms info
   * @return a string  with room info
   */
  void GetInfo();
  /**
   * @brief Kills player
   * @parm [in] playerData
   */
  void UpWall(PlayerData *player);
  /**
   * @brief defines down movement
   * @parm [in] playerData
   */
  void DownWall(PlayerData *player);
  /**
   * @brief defines right direction
   * @parm [in] playerData
   */
  void RightWall(PlayerData *player);
  /**
   * @brief @brief defines left direction
   * @parm [in] playerData
   */
  void LeftWall(PlayerData *player);

 private:
  /**
   * @brief sets contents of locations inventory
   */
  void SetContents();
};
#endif // HALLWAY_H_INCLUDED
