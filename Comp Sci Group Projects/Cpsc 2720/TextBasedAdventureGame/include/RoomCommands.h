/**
 * @author Keagan Rieder <k.rieder@uleth.ca>
 * @author Maxenne Jubane <maxenne.jubane@uleth.ca>
 * @date 2023-03-28
 */

#ifndef ROOM_COMMANDS_H_INCLUDED
#define ROOM_COMMANDS_H_INCLUDED
#include "Command.h"
#include <iostream>
#include <string>
/**
 * @class Up RoomCommands.h  "RoomCommands.h"
 * @brief class to define a command to move up
 */
class Up : public Command {
 public:
  /**
   * @brief default constructor
   * @parm [in] map as pointer to game map
   * @parm [in] cords as pointer to Coordinate
   */
  Up(GameMap *map, PlayerData *player);
  /**
   * @brief default destructor
   */
  virtual ~Up();

  /**
   * @brief runs comamnd
   */
  void Run();
};

/**
 * @class Up RoomCommands.h  "RoomCommands.h"
 * @brief class to define a command to move down
 */
class Down : public Command {
 public:
  /**
   * @brief default constructor
   * @parm [in] map as pointer to game map
   * @parm [in] cords as pointer to Coordinate
   */
  Down(GameMap *map, PlayerData *player);
  /**
   * @brief default destructor
   */
  virtual ~Down();

  /**
   * @brief runs comamnd
   */
  void Run();
};

/**
 * @class left RoomCommands.h  "RoomCommands.h"
 * @brief class to define a command to move left
 */
class Left : public Command {
 public:
  /**
   * @brief default constructor
   * @parm [in] map as pointer to game map
   * @parm [in] cords as pointer to Coordinate
   */
  Left(GameMap *map, PlayerData *player);
  /**
   * @brief default destructor
   */
  virtual ~Left();

  /**
   * @brief runs comamnd
   */
  void Run();
};

/**
 * @class right RoomCommands.h  "RoomCommands.h"
 * @brief class to define a command to move right
 */
class Right : public Command {
 public:
  /**
   * @brief default constructor
   * @parm [in] map as pointer to game map
   * @parm [in] cords as pointer to Coordinate
   */
  Right(GameMap *map, PlayerData *player);
  /**
   * @brief default destructor
   */
  virtual ~Right();

  /**
   * @brief runs comamnd
   */
  void Run();
};

/**
 * @class Look RoomCommands.h  "RoomCommands.h"
 * @brief abstract class to define a commands
 */
class Look : public Command {
 public:
  /**
   * @brief default constructor
   * @parm [in] map as pointer to game map
   * @parm [in] cords as pointer to Coordinate
   */
  Look(GameMap *map, Coordinate *cords);
  /**
   * @brief default destructor
   */
  virtual ~Look();

  /**
   * @brief runs comamnd
   */
  void Run();
};
/**
 * @class FixRoom RoomCommands.h  "RoomCommands.h"
 * @brief abstract class to define a commands
 */
class FixRoom : public Command {
 public:
  /**
   * @brief default constructor
   * @parm [in] map as pointer to game map
   * @parm [in] player as pointer to PlayerData
   */
  FixRoom(GameMap *map, PlayerData *player);
  /**
   * @brief default destructor
   */
  virtual ~FixRoom();

  /**
   * @brief runs comamnd
   */
  void Run();
};
#endif // ROOM_COMMANDS_H_INCLUDED
