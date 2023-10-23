#include "GameMap.h"
GameMap::GameMap() {
  mapGen = new MapGen();
  CreateMap();
}

GameMap::~GameMap() {
  DestoryMap();
  delete mapGen;
}
void GameMap::CreateMap() {
  //gameMap[5*4];
  //adding rooms to map
  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    switch (i) {
      //INFERMARY
      case INFERMARY_CORDS:
        gameMap.push_back(mapGen->CreateMapLocation(INFERMARY));
        break;
        //TOPAIRLOCK
      case TOPAIRLOCK_CORDS:
        gameMap.push_back(mapGen->CreateMapLocation(TOPAIRLOCK));
        break;
        //BARRACKS
      case BARRACKS_CORDS:
        gameMap.push_back(mapGen->CreateMapLocation(BARRACKS));
        break;
        //HALLWAYEND
      case HALLWAYEND_CORDS:
        gameMap.push_back(mapGen->CreateMapLocation(HALLWAYEND));
        break;
        //ELEVATOR
      case ELEVATOR_CORDS:
        gameMap.push_back(mapGen->CreateMapLocation(ELEVATOR));
        break;
        //BRIDGE
      case BRIDGE_CORDS:
        gameMap.push_back(mapGen->CreateMapLocation(BRIDGE));
        break;
        //REACTOR
      case REACTOR_CORDS:
        gameMap.push_back(mapGen->CreateMapLocation(REACTOR));
        break;
        //AIRLOCK
      case AIRLOCK_CORDS:
        gameMap.push_back(mapGen->CreateMapLocation(AIRLOCK));
        break;
        //STORAGE
      case STORAGE_CORDS:
        gameMap.push_back(mapGen->CreateMapLocation(STORAGE));
        break;
        //REAF
      case REEF_CORDS:
        gameMap.push_back(mapGen->CreateMapLocation(REEF));
        break;
        //SEALOCK
      case SEALOCK_CORDS:
        gameMap.push_back(mapGen->CreateMapLocation(SEALOCK));
        break;
        //CAVE
      case CAVE_CORDS:
        gameMap.push_back(mapGen->CreateMapLocation(CAVE));
        break;
        //INVALID
      default:
        gameMap.push_back(nullptr);
    }
  }
}

void GameMap::DestoryMap() {
  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    delete gameMap[i];
  }
  gameMap.clear();
}

Environment* GameMap::GetRoom(Coordinate *cords) {
  return gameMap[cords->GetX() ];
}
Environment* GameMap::GetRoom(int x) {
  return gameMap[x];
}
Inventory* GameMap::GetRoomContents(Coordinate *cords) {
  return gameMap[cords->GetX()]->GetInventory();
}
/*
Environment* GameMap::GetRoom(int i) {
  return gameMap[i];
}
*/
