#include <Npc.h>

Npc::Npc() {
}
Npc::~Npc() {
}
std::string Npc::GetName() {
  return name;
}
Item* Npc::GetQuest() {
  if (item != nullptr) {
    std::cout << "[Quest]: I need you to get a " << item->GetName()
        << " for me." << std::endl;
    return item;
  } else {
    std::cout << "I don't need anything from you you. Sorry buddy."
        << std::endl;
    return nullptr;
  }
}

void Npc::FinsihQuest(PlayerData *player) {
  std::cout << "Like I said I don't need anything from you. Sorry buddy."
      << std::endl;
}
void Npc::Heal(PlayerData *player) {
  std::cout << "This Character doesn't heal" << std::endl;
}
