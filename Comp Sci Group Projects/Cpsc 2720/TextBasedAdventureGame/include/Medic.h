/**
 * @author Logan Feit <logan.feit@uleth.ca>
 * @modified by Maxenne Jubane <maxenne.jubane@uleth.ca>
 * @date 2023-03-28
 */

#ifndef MEDIC_H_INCLUDED
#define MEDIC_H_INCLUDED
#include <Npc.h>

class Medic : public Npc {
 public:
  /**
   * @brief default constructor
   */
  Medic();
  /**
   * @brief default Destructor
   */
  virtual ~Medic();
  /**
   * @brief outputs the Npc dialog
   */
  void GetDialog();
  /**
   * @brief heals Player
   * @parm [in] player as pointer to PlayerData
   */
  void Heal(PlayerData *player);
};
#endif  // MEDIC_H_INCLUDED
