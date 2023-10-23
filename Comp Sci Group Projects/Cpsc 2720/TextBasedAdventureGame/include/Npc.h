/**
 * @author Logan Feit <logan.feit@uleth.ca>
 * @date 2023-03-28
 */

#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include "PlayerData.h"
#include "string"
#include "Item.h"
#include "ItemStorage.h"
#include "GlobalVaribles.h"

/**
 * @class Npc Npc.h  "Npc.h"
 */
class Npc {
 public:
  /**
   * @brief default constructor
   */
  Npc();
  /**
   * @brief default Destructor
   */
  virtual ~Npc();
  /**
   * @brief default Destructor
   */
  virtual std::string GetName();
  /**
   * @brief outputs the Npc dialog
   * @return Npc dialog as a string
   */
  virtual void GetDialog()= 0;

  /**
   * @brief Updates status of Npc quest
   * @return bool value based on quest status
   */
  virtual void FinsihQuest(PlayerData *player);
  /**
   * @brief Gets info on quest
   * @return item need for quest
   */
  virtual Item* GetQuest();
  /**
   * @brief Gets info on quest
   * @return item need for quest
   */
  virtual void Heal(PlayerData *player);

 protected:
  std::string name;
  Item *item;
};
#endif  // NPCFACT_H_
