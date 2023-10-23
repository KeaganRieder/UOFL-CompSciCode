#include <ItemStorage.h>
ItemStorage::ItemStorage() {
}
ItemStorage::~ItemStorage() {
}
Item* ItemStorage::CreateItem(ItemType type) {
  switch (type) {
    case ItemType::SHIPPARTS:
      return new ShipParts();
      break;
    case ItemType::TOOLS:
      return new Tools();
      break;
    case ItemType::PATCH:
      return new Patch();
      break;
    case ItemType::REACTORPARTS:
      return new ReactorParts();
      break;
    case ItemType::SEACUCUMBER:
      return new SeaCucumber();
      break;
    case ItemType::MEDKIT:
      return new MedKit();
      break;
    case ItemType::AIRTANK:
      return new AirTank();
      break;
    case ItemType::MEDAL:
      return new Medal();
      break;
  }
  return nullptr;
}
