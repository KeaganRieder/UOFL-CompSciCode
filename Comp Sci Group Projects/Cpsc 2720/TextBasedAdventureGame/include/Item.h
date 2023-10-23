/**
 * @author Jenil Jani <jenil.jani@uleth.ca>
 * @created on 2023-03-16
 * @last modifided on 31-03-2023
 */
#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <iostream>
#include <string>

class Item {
 public:
  /**
   * @brief Default Constructor
   */
  Item();
  /**
   * @brief Default Destructor
   */
  virtual ~Item();
  /**
   * @brief Outputs description of item
   * @return string of words
   */
  virtual void GetDescription() = 0;
  /**
   * @brief Gets item name
   * @return name of item
   */
  std::string GetName();

 protected:
  std::string name;
};
#endif //ITEM_H_INCLUDED
