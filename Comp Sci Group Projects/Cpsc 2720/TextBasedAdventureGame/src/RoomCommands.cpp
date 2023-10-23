#include "RoomCommands.h"
/*
 * Up movement implementation
 */
Up::Up(GameMap *map, PlayerData *player) {
  gameMap = map;
  playerData = player;
}
Up::~Up() {
  Coordinates = nullptr;
  gameMap = nullptr;
}
void Up::Run() {
  gameMap->GetRoom(playerData->GetCords())->UpWall(playerData);
  Look info(gameMap, playerData->GetCords());
  info.Run();
}
/*
 * Down movement implementation
 */
Down::Down(GameMap *map, PlayerData *player) {
  gameMap = map;
  playerData = player;
}
Down::~Down() {
  Coordinates = nullptr;
  gameMap = nullptr;
}
void Down::Run() {
  gameMap->GetRoom(playerData->GetCords())->DownWall(playerData);
  Look info(gameMap, playerData->GetCords());
  info.Run();
}
/*
 * Left movement implementation
 */
Left::Left(GameMap *map, PlayerData *player) {
  gameMap = map;
  playerData = player;
}
Left::~Left() {
  Coordinates = nullptr;
  gameMap = nullptr;
}
void Left::Run() {
  gameMap->GetRoom(playerData->GetCords())->LeftWall(playerData);
  Look info(gameMap, playerData->GetCords());
  info.Run();
}
/*
 * Right movement implementation
 */
Right::Right(GameMap *map, PlayerData *player) {
  gameMap = map;
  playerData = player;
}
Right::~Right() {
  playerData = nullptr;
  gameMap = nullptr;
}

void Right::Run() {
  gameMap->GetRoom(playerData->GetCords())->RightWall(playerData);
  Look info(gameMap, playerData->GetCords());
  info.Run();
}
/*
 * Look movement implementation
 */
Look::Look(GameMap *map, Coordinate *cords) {
  gameMap = map;
  Coordinates = cords;
}
Look::~Look() {
  Coordinates = nullptr;
  gameMap = nullptr;
}
void Look::Run() {
  gameMap->GetRoom(Coordinates)->GetInfo();
}
/*
 * FixRoom implementation
 */
FixRoom::FixRoom(GameMap *map, PlayerData *player) {
  gameMap = map;
  playerData = player;
}
FixRoom::~FixRoom() {
  playerData = nullptr;
  gameMap = nullptr;
}
void FixRoom::Run() {
  gameMap->GetRoom(playerData->GetCords())->FixRoom(playerData->GetInventory());
}
