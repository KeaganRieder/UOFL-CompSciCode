/**
 * @author Keagan Rieder <k.rieder@uleth.ca>
 * @date 2023-04-02
 */

#ifndef OCEAN_H_INCLUDED
#define OCEAN_H_INCLUDED

#include "Environment.h"
#include <iostream>
#include <string>
/**
 * @class SeaPlains Ocean.h  "Ocean.h"
 * @brief concrete class to define a SeaPlains
 */
class SeaPlains : public Environment {
 public:
  /**
   * @brief default constructor
   */
  SeaPlains();
  /**
   * @brief default destructor
   */
  virtual ~SeaPlains();
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
   * @brief makes right movement not possible and injure player
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
 * @class Cave Ocean.h  "Ocean.h"
 * @brief concrete class to define a Cave
 */
class Cave : public Environment {
 public:
  /**
   * @brief default constructor
   */
  Cave();
  /**
   * @brief default destructor
   */
  virtual ~Cave();
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
   * @brief Makes not possible
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
 * @class Cave Ocean.h  "Ocean.h"
 * @brief concrete class to define a Reef
 */
class Reef : public Environment {
 public:
  /**
   * @brief default constructor
   */
  Reef();
  /**
   * @brief default destructor
   */
  virtual ~Reef();
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
   * @brief Makes not possible
   * @parm [in] playerData
   */
  void RightWall(PlayerData *player);
  /**
   * @brief Defines left movement
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
 * @class SeaLock AirLock.h  "AirLock.h"
 * @brief concrete class to define a AirLock room
 */
class SeaAirLock : public Environment {
 public:
  /**
   * @brief default constructor
   */
  SeaAirLock();
  /**
   * @brief default destructor
   */
  virtual ~SeaAirLock();
  /**
   * @brief outputs the rooms info
   * @return a string  with room info
   */
  void GetInfo();
  /**
   * @brief defines Up Movement
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
  void SetContents() {
  }
};
#endif //OCEAN_H_INCLUDED
