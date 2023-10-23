/**
 * @Author: Logan Feit
 * @date 2023-03-16
 * @modified by Keagan
 * @date 2023-03-21
 */

#ifndef PLAYERDATA_H_INCLUDED
#define PLAYERDATA_H_INCLUDED
#include "Coordinate.h"
#include "Inventory.h"
#include <string>
#include <iostream>

class PlayerData {
 public:
  PlayerData();
  virtual ~PlayerData();
  /*
   * @brief Gets and returns players inventory
   * @return pointer to players inventory
   */
  Inventory* GetInventory();
  /*
   * @brief GetsPlayers Coordinate
   * @return pointer to players Coordinate
   */
  Coordinate* GetCords();
  /*
   * @breif kills player and sets cause of death
   * @parm [in] cause as an int
   */
  void Die();
  /*
   * @brief damages oxygen level if zero inflict damage to player
   */
  void UpdateOxygen(int damage);
  /*
   * @brief damage player
   */
  void UpdateHealth(int damage);
    /*
   * @brief adds bonus score when finishing quest
   */
  void addScore();
  /*
   *@brief refils players oxygen
   */
  void FillOxygen();
  /*
   * @brief gets players Oxygen level
   * @return Oxygen as int
   */
  int GetOxygen();
  /*
   * @brief gets players Health level
   * @return Health as int
   */
  int GetHealth();
  /*
   * @brief gets players Score level
   * @return returns current score as int
   */
  int GetScore();
  /*
   * @brief checks if player is dead
   * @return true if tehy are, false if not
   */
  bool Dead();

 private:
  int health;
  int oxygen;
  int score;
  bool dead;
  Coordinate *cords;
  Inventory *inventory;
};
#endif
