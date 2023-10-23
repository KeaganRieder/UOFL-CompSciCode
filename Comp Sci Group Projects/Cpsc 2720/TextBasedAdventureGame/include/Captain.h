/**
 * @author Logan Feit <logan.feit@uleth.ca>
 * @modified by Maxenne Jubane <maxenne.jubane@uleth.ca>
 * @date 2023-03-28
 */

#ifndef CAPTAIN_H_INCLUDED
#define CAPTAIN_H_INCLUDED

#include <Npc.h>
#include <string>

class Captain : public Npc {
 public:
  /**
   * @brief default constructor
   */
  Captain();
  /**
   * @brief default Destructor
   */
  virtual ~Captain();
  /**
   * @brief outputs the Npc dialog
   * @return Npc dialog as a string
   */
  void GetDialog();
  /**
   * @brief Checks status of NPC quest
   */
  void FinsihQuest(PlayerData* player);
};
#endif // CAPTAIN_H_INCLUDED
