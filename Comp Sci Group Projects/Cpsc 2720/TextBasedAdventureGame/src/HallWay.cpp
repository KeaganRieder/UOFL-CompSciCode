#include <HallWay.h>

/*
 * HallwayEnd imp
 */
HallwayEnd::HallwayEnd() {
  name = "End of Hallway";
  inventory = new Inventory();
}
HallwayEnd::~HallwayEnd() {
  delete inventory;
}
void HallwayEnd::SetContents() {
}
void HallwayEnd::GetInfo() {
  std::cout << "> Currently in a " << name << std::endl;
  std::cout << "> You notice that there is only one ways to move" << std::endl
      << ">  right." << std::endl;
}
void HallwayEnd::UpWall(PlayerData *player) {
  std::cout << "> You decide to start jumping and end up slipping, "
      << std::endl << "injuring your self" << std::endl;
  player->UpdateHealth(-10);
}
void HallwayEnd::DownWall(PlayerData *player) {
  std::cout << "> You begin to walk but slip on a puddle, " << std::endl
      << "injuring your self" << std::endl;
  player->UpdateHealth(-10);
}
void HallwayEnd::RightWall(PlayerData *player) {
  std::cout << "> You move right" << std::endl;
  player->GetCords()->UpdateX(4);
}
void HallwayEnd::LeftWall(PlayerData *player) {
  std::cout << "> You begin to walk left, and end up hitting a wall"
      << std::endl << "injuring your self" << std::endl;
  player->UpdateHealth(-10);
}

/*
 * Elevator Imp
 */
Elevator::Elevator() {
  name = "Elevator Room";
  inventory = new Inventory();
  SetContents();
}
Elevator::~Elevator() {
  delete inventory;
}
void Elevator::SetContents() {
  inventory->AddItem(AIRTANK, "airtank");
}
void Elevator::GetInfo() {
  std::cout << "> Currently in a " << name << std::endl;
  std::cout << "> You notice that there are many ways out of this room:"
      << std::endl << "> Up,Down left or right." << std::endl
      << "> you also notice some crates " << "Which could contain items inside"
      << std::endl;
}
void Elevator::UpWall(PlayerData *player) {
  std::cout << "> You enter the elevator, and hit the Up arrow. " << std::endl
      << "after a few moments you feel the cabin stop and the doors open"
      << std::endl;
  player->GetCords()->UpdateX(1);
}
void Elevator::DownWall(PlayerData *player) {
  std::cout << "> You enter the elevator, and hit the down arrow. " << std::endl
      << "after a few moments you feel the cabin stop and the doors open."
      << std::endl;
  player->GetCords()->UpdateX(7);
}
void Elevator::RightWall(PlayerData *player) {
  std::cout << "> You move right" << std::endl;
  player->GetCords()->UpdateX(5);
}
void Elevator::LeftWall(PlayerData *player) {
  std::cout << "> You move left" << std::endl;
  player->GetCords()->UpdateX(3);
}
/*
 * TopAirlock Imp
 */
TopAirLock::TopAirLock() {
  name = "Surface AirLock";
  inventory = new Inventory();
  SetContents();
}
TopAirLock::~TopAirLock() {
  delete inventory;
}
void TopAirLock::SetContents() {
  inventory->AddItem(TOOLS, "tools");
  //inventory->AddItem(SHIPPARTS, "shipparts");
}
void TopAirLock::GetInfo() {
  std::cout << "> Currently in the " << name << std::endl;
  std::cout << "> You notice that there are many ways out of this room:"
      << std::endl << "> Up,Down left or right." << std::endl
      << "> you also notice some crates " << "Which could contain items inside"
      << std::endl;
}
void TopAirLock::UpWall(PlayerData *player) {
  std::cout << "> You decide to look up at the Airlock, and against your "
      << std::endl << "> better judgment think you can open it," << std::endl
      << "> even though your under water." << std::endl
      << "> after struggling for a bit you turn the wheel" << std::endl
      << "> just enough,that before you " << std::endl
      << "> can react water begins rushing in, and you find your self trapped,"
      << std::endl << "> and Sentencing Everyone on board to a watery grave."
      << std::endl;
  player->Die();
}
void TopAirLock::DownWall(PlayerData *player) {
  std::cout << "> You enter the elevator, and hit the down arrow. " << std::endl
      << "after a few moments you feel the cabin stop and the doors open."
      << std::endl;
  player->GetCords()->UpdateX(4);
}
void TopAirLock::RightWall(PlayerData *player) {
  std::cout << "> You move right" << std::endl;
  player->GetCords()->UpdateX(2);
}
void TopAirLock::LeftWall(PlayerData *player) {
  std::cout << "> You move left" << std::endl;
  player->GetCords()->UpdateX(0);
}
