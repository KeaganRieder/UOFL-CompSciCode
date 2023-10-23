/**
 * @author Keagan Rieder <k.rieder@uleth.ca>
 * @date 2023-03-15
 */

#ifndef COORDINATE_H_INCLUDED
#define COORDINATE_H_INCLUDED

//#include "Exceptions.h"
#include "GlobalVaribles.h"
#include "Exceptions.h"
#include <iostream>
/**
 * @class Coordinate Coordinate.h  "Coordinate.h"
 * @the player's Coordinate
 */
class Coordinate {
 public:
  /**
   * @brief default constructor
   * @parm x sets xCord,
   */
  Coordinate(int x);
  /**
   * @brief Destructor
   */
  virtual ~Coordinate();
  /**
   * @brief overirdes cord to equail passed in x and y
   * @parm x sets xCord, y sets yCord
   */
  void OverRideCord(int x);
  /**
   * @brief changes xcord to new value
   * @parm x is what xCord is set to
   */
  void UpdateX(int x);
  /**
   * @brief changes xcord to new value
   * @return Returns value of xCord
   */
  int GetX();

 private:
  int cord;
};
#endif // COORDINATE_H_INCLUDED
