#include <MapGen.h>
MapGen::MapGen() {
}
MapGen::~MapGen() {
}
Environment* MapGen::CreateMapLocation(RoomType type) {
  switch (type) {
    case RoomType::BRIDGE:
      return new Bridge();
      break;
    case RoomType::HALLWAYEND:
      return new HallwayEnd();
      break;
    case RoomType::REACTOR:
      return new Reactor();
      break;
    case RoomType::STORAGE:
      return new Storage();
      break;
    case RoomType::ELEVATOR:
      return new Elevator();
      break;
    case RoomType::BARRACKS:
      return new Barracks();
      break;
    case RoomType::INFERMARY:
      return new Infirmary();
      break;
    case RoomType::AIRLOCK:
      return new AirLock();
      break;
    case RoomType::SEALOCK:
      return new SeaAirLock();
      break;
    case RoomType::CAVE:
      return new Cave();
      break;
    case RoomType::REEF:
      return new Reef();
      break;
    case RoomType::TOPAIRLOCK:
      return new TopAirLock();
      break;
  }
  return nullptr;
}
