/**
 * @author Jenil Jani <jenil.jani@uleth.ca>
 * @created on 2023-03-16
 *  @author Logan Feit <logan.feit@uleth.ca>
 * @created on 2023-04-02
 * @author Keagan Rieder <k.rieder@uleth.ca>
 * @date 2023-03-25
 */
#ifndef REPAIRPARTS_H_INCLUDED
#define REPAIRPARTS_H_INCLUDED
#include "Item.h"
#include <iostream>
#include <string>
/**
 * @class ReactorParts ReactorParts.h  "ReactorParts.h"
 * @brief concrete class to define a ReactorParts Item
 */
class ReactorParts : public Item {
 public:
  /**
   * @brief default constructor
   */
  ReactorParts();
  /**
   * @brief default destructor
   */
  ~ReactorParts();
  void GetDescription();
};
/**
 * @class Patch Patch.h  "Patch.h"
 * @brief concrete class to define a Patch Item
 */
class Patch : public Item {
 public:
  /**
   * @brief default constructor
   */
  Patch();
  /**
   * @brief default destructor
   */
  ~Patch();
  void GetDescription();
};
class ShipParts : public Item {
 public:
  /**
   * @brief Default Constructor
   */
  ShipParts();
  /**
   * @brief Default Destructor
   */
  virtual ~ShipParts();
  /**
   * @brief Outputs description of item
   * @return string of words
   */
  void GetDescription();
};
/**
 * @class Tools Tools.h  "Tools.h"
 * @brief concrete class to define a Patch Item
 */
class Tools : public Item {
 public:
  /**
   * @brief Default Constructor
   */
  Tools();
  /**
   * @brief Default Destructor
   */
  virtual ~Tools();
  /**
   * @brief Outputs description of item
   * @return string of words
   */
  void GetDescription();
};
#endif //REPAIRPARTS_H_INCLUDED
