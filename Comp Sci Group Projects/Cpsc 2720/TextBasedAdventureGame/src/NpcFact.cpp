/**
* @author Logan Feit <logan.feit@uleth.ca>
* @date 2023-03-28
*/
#include <NpcFact.h>
NpcFact::NpcFact() {
}
NpcFact::~NpcFact() {
}
Npc* NpcFact::CreateNpc(NPCType type) {
    switch (type) {
        case NPCType::CHEF:
        return new Chef();
        break;
        case NPCType::CAPTAIN:
        return new Captain();
        break;
        case NPCType::MEDIC:
        return new Medic();
        break;
    }
    return nullptr;
}
