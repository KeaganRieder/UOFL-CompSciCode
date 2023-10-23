/**
 * @author Logan Feit <logan.feit@uleth.ca>
 * @date 2023-03-28
 */

#ifndef NPCFACT_H_INCLUDED
#define NPCFACT_H_INCLUDED

#include <GlobalVaribles.h>
#include <Npc.h>
#include <Chef.h>
#include <Captain.h>
#include <Medic.h>
/**
 * @class NpcFact NpcFact.h  "NpcFact.h"
 */
class NpcFact {
 public:
  /**
   * @brief default constructor
   */
  NpcFact();
  /**
   * @brief default Destructor
   */
  virtual ~NpcFact();
   /**
   * @breif create the specified Npc type
   * @return pointer to Npc object
   */
  Npc* CreateNpc(NPCType type);
};
#endif // NPCFACT_H_INCLUDED
