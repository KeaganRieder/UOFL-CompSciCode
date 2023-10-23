/**
 * @author Keagan Rieder <k.rieder@uleth.ca>
 * @date 2023-03-25
 */

#ifndef ITEMSTORAGE_H_INCLUDED
#define ITEMSTORAGE_H_INCLUDED

#include <Item.h>
#include <QuestItems.h>
#include <RepairItems.h>
#include <Consumables.h>
//#include <EmptySlot.h>
#include <GlobalVaribles.h>
/**
 * @class MapGen MapGen.h  "MapGen.h"
 * @Gets the concrete item  objects for the inventory
 */
class ItemStorage {
 public:
  /**
   * @brief default constructor
   */
  ItemStorage();
  /**
   * @brief default Destructor
   */
  virtual ~ItemStorage();
  /**
   * @breif create the specified Item type
   * @return pointer to Item object
   */
  Item* CreateItem(ItemType type);
};
#endif //ITEMSTORAGE_H_INCLUDED
