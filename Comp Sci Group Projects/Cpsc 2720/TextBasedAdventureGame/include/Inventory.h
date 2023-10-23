/**
 * @Author Jenil Jani <jenil.jani@uleth.ca>
 * @date 2023-03-16
 * @modified by Keagan
 * @date 2023-03-21
 */
#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED
#include <Item.h>
#include <ItemStorage.h>
#include <GlobalVaribles.h>
#include <iostream>
#include <string>
#include <map>

class Inventory {
 public:
  /*
   * @breif constructor
   */
  Inventory();
  /*
   * @breif desturcter
   */
  ~Inventory();
  /*
   * @brief compares item in inventorys
   */
  bool CheckReqItems(Inventory *inventory);
  /*
   * @brief compares item in inventory
   * @parm [in] name of item
   * @return ture if has item otherwise return false
   */
  bool HasItem(std::string name);
  /*
    * @brief compares item in inventory
    * @parm [in]ietm to check for
    * @return ture if has item otherwise return false
    */
  bool HasItem(Item* item);
  /*
   * @brief gets item from inventory
   * @parm[in] itemName the item to get
   */
  Item* GetItem(std::string itemName);
  /*
   * @brief gets the name of the item
   * @return name if item isn't null
   * @return " " if it is
   */
  std::string GetItemName(std::string itemName);
  /*
   * @brief adds item to inventory
   * @parm[in] item the key to add
   */
  void AddItem(Item *item);
  /*
   * @brief adds item to inventory based on type
   * @parm[in] item itemType to be created
   */
  void AddItem(ItemType item, std::string name);
  /*
   * @brief Empty slot but doesn't delete item
   * @parm[in] itemName the item to remove
   */
  void EmptySlot(std::string itemName);
  /*
   * @brief removes an item form inventory
   * @parm[in] itemName the item to remove
   */
  void RemoveItem(std::string itemName);
  /*
    * @brief removes items form inventory following use
    * @parm[in] inventory the of items use from
    */
  void UseItems(Inventory *inventory);
  /*
   * @breif list contents of inventory
   */
  void ListContents();

 private:
  bool empty = true;
  std::map<std::string, Item*> contents;
  ItemStorage *itemFact;
};
#endif //INVENTORY_H_INCLUDED
