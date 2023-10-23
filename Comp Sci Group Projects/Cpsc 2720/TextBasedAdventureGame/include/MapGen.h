/**
 * @author Keagan Rieder <k.rieder@uleth.ca>
 * @date 2023-03-25
 */

#ifndef MAPGEN_H_INCLUDED
#define MAPGEN_H_INCLUDED

#include <Environment.h>
#include <FixableRooms.h>
#include <HallWay.h>
#include <Rooms.h>
#include <Ocean.h>
#include <GlobalVaribles.h>
/**
 * @class MapGen MapGen.h  "MapGen.h"
 * @Gets the concrete environment  objects for teh map
 */
class MapGen {
 public:
  /**
   * @brief default constructor
   */
  MapGen();
  /**
   * @brief default Destructor
   */
  virtual ~MapGen();
  /**
   * @breif create the specified Environment type
   * @return pointer to Environment object
   */
  Environment* CreateMapLocation(RoomType type);
};

#endif //MAPGEN_H_INCLUDED
