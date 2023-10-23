#include <Environment.h>

Environment::Environment() {
}
Environment::~Environment() {
  //delete inventory;
}
std::string Environment::GetType() {
  return name;
}
Inventory* Environment::GetInventory() {
  return inventory;
}
Inventory* Environment::GetReqInventory() {
  std::cout << "You quickly look around for anything needing stuff" << std::endl
      << "> but find nothing." << std::endl;
  return nullptr;
}
Npc* Environment::GetNPC() {
  return npc;
}
void Environment::FixRoom(Inventory *inventory) {
  std::cout << "You quickly look around for anything broken, but find nothing."
      << std::endl;
}
bool Environment::RoomFixed() {
  return fixed;
}
