/**
 * @author Jenil Jani <jenil.jani@uleth.ca>
 * @created on 2023-03-16
 * @author Logan Feit <logan.feit@uleth.ca>
 * @created on 2023-04-02
 */
#ifndef CONSUMABLES_H_INCLUDED
#define CONSUMABLES_H_INCLUDED
#include "Item.h"
#include <iostream>
#include <string>
/**
 * @class AirTank AirTank.h  "AirTank.h"
 * @brief concrete class to define a AirTank Item
 */
class AirTank : public Item {
 public:
  /**
   * @brief default constructor
   */
  AirTank();
  /**
   * @brief default destructor
   */
  ~AirTank();
  void GetDescription();
};
/**
 * @class MedKit MedKit.h  "MedKit.h"
 * @brief concrete class to define a MedKit Item
 */
class MedKit : public Item {
 public:
  /**
   * @brief default constructor
   */
  MedKit();
  /**
   * @brief default destructor
   */
  ~MedKit();
  void GetDescription();
};
#endif
