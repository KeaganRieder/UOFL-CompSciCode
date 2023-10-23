/**
 * @author Jenil Jani <jenil.jani@uleth.ca>
 * @created on 2023-03-28
 * @author Logan Feit <logan.feit@uleth.ca>
 * @created on 2023-04-02
 */
#ifndef QUESTIEMS_H_INCLUDED
#define QUESTIEMS_H_INCLUDED
#include "Item.h"
#include <iostream>
#include <string>
/**
 * @class SeaCucumber SeaCucumber.h  "SeaCucumber.h"
 * @brief concrete class to define a SeaCucumber Item
 */
class SeaCucumber : public Item {
 public:
  /**
   * @brief default constructor
   */
  SeaCucumber();
  /**
   * @brief default destructor
   */
  ~SeaCucumber();
  void GetDescription();
};
/**
 * @class Medal Medal.h  "Medal.h"
 * @brief concrete class to define a Medal Item
 */
class Medal : public Item {
 public:
  /**
   * @brief default constructor
   */
  Medal();
  /**
   * @brief default destructor
   */
  ~Medal();
  void GetDescription();
};
#endif //QUESTIEMS_H_INCLUDED
