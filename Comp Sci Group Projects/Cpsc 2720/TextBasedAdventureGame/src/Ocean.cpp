#include <Ocean.h>
/*
 * sea lock
 */
SeaAirLock::SeaAirLock() {
  name = "Below AirLock";
  inventory = new Inventory();
}
SeaAirLock::~SeaAirLock() {
  delete inventory;
}
void SeaAirLock::GetInfo() {
  std::cout << "> Currently " << name << std::endl;
  std::cout << "> You notice that there are 3 ways Out of this room"
      << std::endl << "> Left, Right, Up into the ship." << std::endl
      << "> there also seems to be nothing of interest here" << std::endl;
}
void SeaAirLock::UpWall(PlayerData *player) {
  std::cout << "> You enter the elevator and move up a floor, " << std::endl;
  player->UpdateOxygen(-10);
  player->GetCords()->UpdateX(7);
}
void SeaAirLock::DownWall(PlayerData *player) {
  std::cout << "> You decide to attempt to dive to go through the ground "
      << std::endl << "However unlike your beliefs it's solid not some liquid"
      << std::endl;
  player->UpdateOxygen(-10);
  player->UpdateHealth(-10);
}
void SeaAirLock::RightWall(PlayerData *player) {
  std::cout << "> You move right" << std::endl;
  player->UpdateOxygen(-10);
  player->GetCords()->UpdateX(11);
}
void SeaAirLock::LeftWall(PlayerData *player) {
  std::cout << "> You move left" << std::endl;
  player->UpdateOxygen(-10);
  player->GetCords()->UpdateX(9);
}

/*
 * Cave implementation
 */
Cave::Cave() {
  name = "Cave";
  inventory = new Inventory();
  SetContents();
}
Cave::~Cave() {
  delete inventory;
}
void Cave::SetContents() {
  inventory->AddItem(TOOLS, "tools");
  inventory->AddItem(SHIPPARTS, "shipparts");
  inventory->AddItem(REACTORPARTS, "reactorparts");
  inventory->AddItem(MEDAL, "medal");
}
void Cave::GetInfo() {
  std::cout << "> Currently in a " << name << std::endl;
  std::cout << "> You notice that there is only one way to move" << std::endl
      << "> left or right." << std::endl << "> you also a ruined ship "
      << "Which might contain some loot." << std::endl;
}

void Cave::UpWall(PlayerData *player) {
  std::cout << "> You decide to swim towards the hull of the sub hull. "
      << std::endl << "> and banging your head against it,Damaging Yourself"
      << std::endl;
  player->UpdateOxygen(-10);
  player->UpdateHealth(-10);
}

void Cave::DownWall(PlayerData *player) {
  std::cout << "> You decide to swim towards the Sandy floor. " << std::endl
      << "> and end up hitting your head against the floor, Damaging Yourself."
      << std::endl;
  player->UpdateOxygen(-10);
  player->UpdateHealth(-10);
}

void Cave::RightWall(PlayerData *player) {
  std::cout << "> You decide to move towards the caves eastern wall,"
      << std::endl << "> and end up crashing into it, damaging your self"
      << std::endl;
  player->UpdateOxygen(-10);
  player->UpdateHealth(-10);
}

void Cave::LeftWall(PlayerData *player) {
  std::cout << "> You move left" << std::endl;
  player->UpdateOxygen(-10);
  player->GetCords()->UpdateX(10);
}
/*
 * Reef implementation
 */
Reef::Reef() {
  name = "Reef";
  inventory = new Inventory();
  SetContents();
}
Reef::~Reef() {
  delete inventory;
}
void Reef::SetContents() {
  inventory->AddItem(SEACUCUMBER, "seacucumber");
}
void Reef::GetInfo() {
  std::cout << "> Currently in a " << name << std::endl;
  std::cout << "> You notice that there is only one way to move" << std::endl
      << "> right" << std::endl << "> you also a patch of sea cucumbers "
      << std::endl;
}

void Reef::UpWall(PlayerData *player) {
  std::cout << "> You decide to swim towards the hull of the sub hull. "
      << std::endl << "> and banging your head against it, Damaging Yourself"
      << std::endl;
  player->UpdateOxygen(-10);
  player->UpdateHealth(-10);
}
void Reef::DownWall(PlayerData *player) {
  std::cout << "> You decide to swim towards the Sandy floor. " << std::endl
      << "> and end up hitting your head against the floor, Damaging Yourself."
      << std::endl;
  player->UpdateOxygen(-10);
  player->UpdateHealth(-10);
}

void Reef::RightWall(PlayerData *player) {
  std::cout << "> You move right" << std::endl;
  player->UpdateOxygen(-10);
  player->GetCords()->UpdateX(10);
}
void Reef::LeftWall(PlayerData *player) {
  std::cout << "> you decide to move left, to admire the beauty or the open sea"
      << std::endl
      << "> but the beauty is soon interrupted as you find you self being"
      << std::endl << " >eaten by a shark" << std::endl;
  player->Die();
}
