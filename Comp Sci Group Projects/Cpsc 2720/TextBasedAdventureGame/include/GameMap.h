/**
 * @author Keagan Rieder <k.rieder@uleth.ca>
 * @date 2023-03-13
 */

#ifndef GAMEMAP_H_INCLUDED
#define GAMEMAP_H_INCLUDED

#include <PlayerData.h>
#include <Environment.h>
#include <MapGen.h>
#include <Inventory.h>
#include <GlobalVaribles.h>
#include <iostream>
#include <string>
#include <vector>

/**
 * @class GameMap Map.h  "Map.h"
 * @the games map
 */
class GameMap {
 public:
  /**
   * @brief default constructor
   */
  GameMap();
  /**
   * @brief Destructor
   */
  virtual ~GameMap();
  /**
   * @brief Creates the map
   */
  void CreateMap();
  /**
   * @brief Destroys the map
   */
  void DestoryMap();
  /**
   * @brief gets the room the current room
   * parm [in] cords players cords
   * @return pointer to Enviorment
   */
  Environment* GetRoom(Coordinate *cords);
  /**
   * @brief gets the room the current room
   * parm [in] x as int
   * @return pointer to Enviorment
   */
  Environment* GetRoom(int x);
  /**
   * @brief gets the room the rooms contents
   * parm [in] cords players cords
   * @return pointer to Inventory
   */
  Inventory* GetRoomContents(Coordinate *cords);

 private:
  std::vector<Environment*> gameMap;
  MapGen *mapGen;
};
#endif // GAMEMAP_H_INCLUDED

