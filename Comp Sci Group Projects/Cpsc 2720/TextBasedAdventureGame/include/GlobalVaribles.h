/**
 * @author Keagan Rieder <k.rieder@uleth.ca>
 * @date 2023-03-19
 */
#ifndef GLOBALVARIBLES_H_INCLUDED
#define GLOBALVARIBLES_H_INCLUDED

/**
 * @brief the maps width
 */
const int WIDTH = 4;
/**
 * @brief the maps Height
 */
const int HEIGHT = 4;

/**
 * @brief the spawn room varible
 */
const int INFERMARY_CORDS = 0;
const int TOPAIRLOCK_CORDS = 1;
const int BARRACKS_CORDS = 2;
const int HALLWAYEND_CORDS = 3;
const int ELEVATOR_CORDS = 4;
const int BRIDGE_CORDS = 5;
const int REACTOR_CORDS = 6;
const int AIRLOCK_CORDS = 7;
const int STORAGE_CORDS = 8;
const int REEF_CORDS = 9;
const int SEALOCK_CORDS = 10;
const int CAVE_CORDS = 11;


/**
 * @brief Rooms in the game
 */
enum RoomType {
  AIR,
  BRIDGE,
  HALLWAYEND,
  REACTOR,
  STORAGE,
  ELEVATOR,
  BARRACKS,
  INFERMARY,
  AIRLOCK,
  SEALOCK,
  CAVE,
  REEF,
  TOPAIRLOCK,
};
/**
 * @brief items in the game
 */
enum ItemType {
  EMPTY,
  AIRTANK,
  SHIPPARTS,
  REACTORPARTS,
  PATCH,
  TOOLS,
  SEACUCUMBER,
  MEDKIT,
  MEDAL,
};
/**
 * @brief NPCS in the game
 */
enum NPCType {
  NONE,
  MEDIC,
  CHEF,
  CAPTAIN,
};

#endif //GLOBALVARIBLES_H_INCLUDED
