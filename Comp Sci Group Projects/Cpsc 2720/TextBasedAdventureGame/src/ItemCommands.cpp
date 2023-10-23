#include "ItemCommands.h"
/*
 * pickup implementation
 */
PickUp::PickUp(GameMap *map, PlayerData *player) {
  gameMap = map;
  playerData = player;
}
PickUp::~PickUp() {
  playerData = nullptr;
  gameMap = nullptr;
}
void PickUp::Run(std::string itemName) {
  if (itemName == "cancel") {
    std::cout << "> Picking Up item cancel" << std::endl;
  } else {
    std::cout << "> You PickUp " << itemName << std::endl;
    playerData->GetInventory()->AddItem(
        gameMap->GetRoomContents(playerData->GetCords())->GetItem(itemName));
    gameMap->GetRoomContents(playerData->GetCords())->EmptySlot(itemName);
  }
}
/*
 * drop implementation
 */
Drop::Drop(GameMap *map, PlayerData *player) {
  gameMap = map;
  playerData = player;
}
Drop::~Drop() {
  playerData = nullptr;
  gameMap = nullptr;
}
void Drop::Run(std::string itemName) {
  if (itemName == "cancel") {
    std::cout << "> Dropping item cancel" << std::endl;
  } else {
    std::cout << "> You Drop " << itemName << std::endl;
    gameMap->GetRoomContents(playerData->GetCords())->AddItem(
        playerData->GetInventory()->GetItem(itemName));
    playerData->GetInventory()->EmptySlot(itemName);
  }
}
/*
 * FillAir implementation
 */
FillAir::FillAir(PlayerData *player) {
  playerData = player;
}
FillAir::~FillAir() {
  playerData = nullptr;
}
void FillAir::Run() {
  playerData->FillOxygen();
}
