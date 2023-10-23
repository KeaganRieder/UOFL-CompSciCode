#include "CommandManger.h"

CommandManger::CommandManger(PlayerData *player, GameMap *map) {
  playerData = player;
  gameMap = map;
  SetCommandArray();
}
CommandManger::~CommandManger() {
  delete up;
  delete down;
  delete left;
  delete right;
  delete look;
  delete fixRoom;
  delete talk;
  delete finishQuest;
  delete pickUp;
  delete drop;
  delete fillAir;
  delete heal;
  gameMap = nullptr;
  playerData = nullptr;
}
void CommandManger::SetCommandArray() {
  up = new Up(gameMap, playerData);
  down = new Down(gameMap, playerData);
  left = new Left(gameMap, playerData);
  right = new Right(gameMap, playerData);
  look = new Look(gameMap, playerData->GetCords());
  fixRoom = new FixRoom(gameMap, playerData);
  talk = new Talk(gameMap, playerData->GetCords());
  finishQuest = new FinishQuest(gameMap, playerData);
  pickUp = new PickUp(gameMap, playerData);
  drop = new Drop(gameMap, playerData);
  fillAir = new FillAir(playerData);
  heal = new Heal(gameMap, playerData);
}
//can't be tested using unit test, just test that each command
// individually works
bool CommandManger::RunCommand(std::string input) {
  if (input == "u") {
    up->Run();
    return true;
  } else if (input == "d") {
    down->Run();
    return true;
  } else if (input == "l") {
    left->Run();
    return true;
  } else if (input == "r") {
    right->Run();
    return true;
  } else if (input == "look") {
    look->Run();
    return true;
  } else if (input == "fix") {
    fixRoom->Run();
    return true;
  } else if (input == "talk") {
    talk->Run();
    return true;
  } else if (input == "finishquest") {
    finishQuest->Run();
    return true;
  } else if (input == "pickup") {
    if (gameMap->GetRoomContents(playerData->GetCords()) != nullptr) {
      pickUp->Run(
          GetItemName(gameMap->GetRoomContents(playerData->GetCords())));
      return true;
    }
  } else if (input == "drop") {
    if (gameMap->GetRoomContents(playerData->GetCords()) != nullptr) {
      drop->Run(GetItemName(playerData->GetInventory()));
      return true;
    }
  } else if (input == "fillair") {
    fillAir->Run();
    return true;
  } else if (input == "heal") {
    heal->Run();
    return true;
  }

  return false;
}
//can't be tested using unit test
std::string CommandManger::GetItemName(Inventory *inv) {
  std::string itemName;
  std::cout << "> Please  select and item from the given list " << std::endl
      << "> or input cancel to stop transfer: " << std::endl;
  inv->ListContents();
  std::cout << std::endl << ">> ";
  std::cin >> itemName;
  std::transform(itemName.begin(), itemName.end(), itemName.begin(), tolower);
  std::cout << std::endl;
//chekcing for valid input
  while (inv->GetItem(itemName) == nullptr && itemName != "cancel") {
    std::cout << std::endl
        << "> Please Valid select and item from the given list " << std::endl
        << "> or input 'cancel' to stop transfer: " << std::endl;
    inv->ListContents();
    std::cout << std::endl << ">> ";
    std::cin >> itemName;
    std::transform(itemName.begin(), itemName.end(), itemName.begin(), tolower);
  }
  return itemName;
}
