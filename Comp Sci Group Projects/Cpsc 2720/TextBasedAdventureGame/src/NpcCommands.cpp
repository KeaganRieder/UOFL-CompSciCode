#include "NpcCommands.h"

/*
 * Talk implementation
 */
Talk::Talk(GameMap *map, Coordinate *cords) {
  gameMap = map;
  Coordinates = cords;
}
Talk::~Talk() {
  Coordinates = nullptr;
  gameMap = nullptr;
}

void Talk::Run() {
  if (gameMap->GetRoom(Coordinates->GetX())->GetNPC() != nullptr) {
    gameMap->GetRoom(Coordinates->GetX())->GetNPC()->GetDialog();
  } else {
    std::cout << "there is no else here" << std::endl;
  }
}
/*
 * FinishQuest implementation
 */
FinishQuest::FinishQuest(GameMap *map, PlayerData *player) {
  gameMap = map;
  playerData = player;
}
FinishQuest::~FinishQuest() {
  playerData = nullptr;
  gameMap = nullptr;
}

void FinishQuest::Run() {
  if (gameMap->GetRoom(playerData->GetCords())->GetNPC() != nullptr) {
    gameMap->GetRoom(playerData->GetCords())->GetNPC()->FinsihQuest(playerData);
  } else {
    std::cout << "there is no else here" << std::endl;
  }
}
/*
 * Heal implementation
 */
Heal::Heal(GameMap *map, PlayerData *player) {
  gameMap = map;
  playerData = player;
}

Heal::~Heal() {
  playerData = nullptr;
  gameMap = nullptr;
}
void Heal::Run() {
  if (gameMap->GetRoom(playerData->GetCords())->GetNPC() != nullptr) {
    gameMap->GetRoom(playerData->GetCords())->GetNPC()->Heal(playerData);
  } else {
    std::cout << "there is no here who can heal you" << std::endl;
  }
}
