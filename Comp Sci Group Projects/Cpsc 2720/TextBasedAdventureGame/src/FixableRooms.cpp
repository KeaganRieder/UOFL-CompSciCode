#include <FixableRooms.h>
Reactor::Reactor() {
  name = "Reactor";
  inventory = new Inventory();
  requiredItems = new Inventory();
  SetContents();
}
Reactor::~Reactor() {
  delete requiredItems;
  delete inventory;
}
void Reactor::SetContents() {
  requiredItems->AddItem(TOOLS, "tools");
  requiredItems->AddItem(SHIPPARTS, "shipparts");
  requiredItems->AddItem(REACTORPARTS, "reactorparts");
}

Inventory* Reactor::GetInventory() {
  std::cout << "> There is nothing of value here " << std::endl
      << " nor anywhere to store items" << std::endl;
  return inventory;
}
Inventory* Reactor::GetReqInventory() {
  return requiredItems;
}
void Reactor::GetInfo() {
  std::cout << "> Currently in the " << name << std::endl;
  std::cout << "> You notice that there is only one way to move" << std::endl
      << "> right." << std::endl << "> you also notice the reactor is damage "
      << std::endl << "and can be repaired using: " << std::endl;
  requiredItems->ListContents();
}
void Reactor::FixRoom(Inventory *inventory) {
  std::cout << "> You decide try and repair. " << std::endl;
  bool canFix = requiredItems->CheckReqItems(inventory);
  if (canFix) {
    std::cout << "> Using the items gather you manage to fix it" << std::endl;
    requiredItems->UseItems(inventory);
    fixed = true;
  }
}
void Reactor::UpWall(PlayerData *player) {
  std::cout << "> You decide to start jumping and end up slipping, "
      << std::endl << "injuring your self" << std::endl;
  player->UpdateHealth(-10);
}
void Reactor::DownWall(PlayerData *player) {
  std::cout << "> You begin to walk but slip on a puddle, " << std::endl
      << "injuring your self" << std::endl;
  player->UpdateHealth(-10);
}
void Reactor::RightWall(PlayerData *player) {
  std::cout << "> You move right" << std::endl;
  player->GetCords()->UpdateX(7);
}
void Reactor::LeftWall(PlayerData *player) {
  std::cout << "> You move left and run into a wall" << std::endl;
  player->UpdateHealth(-10);
}
/*
 * AirLock imp
 */
AirLock::AirLock() {
  name = "AirLock";
  inventory = new Inventory();
  requiredItems = new Inventory();
  SetContents();
}
AirLock::~AirLock() {
  delete inventory;
  delete requiredItems;
}
void AirLock::SetContents() {
  inventory->AddItem(AIRTANK, "airtank");
  requiredItems->AddItem(TOOLS, "tools");
  requiredItems->AddItem(PATCH, "patch");
}

Inventory* AirLock::GetInventory() {
  return inventory;
}
Inventory* AirLock::GetReqInventory() {
  return requiredItems;
}
void AirLock::GetInfo() {
  std::cout << "> Currently in the " << name << std::endl;
  std::cout << "> You notice that there are 4 ways Out of this room"
      << std::endl << "> Left, Right, Up or Down into the sea." << std::endl;
  if (!fixed) {
    std::cout << "> If you wish to enter the ocean, "
        << "you must first put on the Diving Suit," << std::endl
        << " which is damaged which to fix needs:" << std::endl;
  }
  requiredItems->ListContents();
  std::cout << "> you also notice some Items of Value: " << name << std::endl;
  inventory->ListContents();
}
void AirLock::FixRoom(Inventory *inventory) {
  std::cout << "> You decide to try and repair the diving gear. " << std::endl;
  bool canFix = requiredItems->CheckReqItems(inventory);
  if (canFix) {
    std::cout << "> Using the items gather you manage to fix it" << std::endl;
    requiredItems->UseItems(inventory);
    fixed = true;
  }
}
void AirLock::UpWall(PlayerData *player) {
  std::cout << "> You enter the elevator and move up a floor, " << std::endl;
  player->GetCords()->UpdateX(4);
}
void AirLock::DownWall(PlayerData *player) {
  std::cout << "> you enter the air lock " << std::endl;
  if (fixed) {
    std::cout
        << "> With the fixed diving gear, and leave the ship into the sea "
        << std::endl;
    player->GetCords()->UpdateX(10);
  } else {
    std::cout << "> With the broken diving gear, and as the chamber "
        << "begins to decompres" << std::endl
        << "> You regret not fixing the gear before hand,"
        << " as water rushes into the chamber " << std::endl
        << " > Shattering the your visors glass, killing you" << std::endl;
    player->Die();
  }
}
void AirLock::RightWall(PlayerData *player) {
  std::cout << "> You move right" << std::endl;
  player->GetCords()->UpdateX(8);
}
void AirLock::LeftWall(PlayerData *player) {
  std::cout << "> You move left" << std::endl;
  player->GetCords()->UpdateX(6);
}
