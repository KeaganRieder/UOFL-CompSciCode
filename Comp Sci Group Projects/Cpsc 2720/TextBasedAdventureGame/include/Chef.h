/**
 * @author Logan Feit <logan.feit@uleth.ca>
 * @modified by Maxenne Jubane <maxenne.jubane@uleth.ca>
 * @date 2023-03-28
 */

#ifndef CHEF_H_INCLUDED
#define CHEF_H_INCLUDED
#include "Npc.h"

class Chef: public Npc {
 public:
  /**
   * @brief default constructor
   */
  Chef();
  /**
   * @brief default Destructor
   */
  virtual ~Chef();
  /**
   * @brief outputs the Npc dialog
   * @return Npc dialog as a string
   */
  void GetDialog();
  /**
   * @brief Checks status of NPC quest
   * @return bool value based on quest status
   */
  void FinsihQuest(PlayerData* player);
};
#endif // CHEF_H_INCLUDED
