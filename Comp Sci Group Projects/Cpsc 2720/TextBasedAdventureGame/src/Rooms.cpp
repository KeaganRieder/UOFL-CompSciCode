#include "Rooms.h"
/*
 * Brdige Imp
 */
Bridge::Bridge() {
  name = "Bridge";
  inventory = new Inventory();
  SetContents();
}
Bridge::~Bridge() {
  delete inventory;
  delete npc;
}
void Bridge::SetContents() {
  NpcFact fact;
  npc = fact.CreateNpc(CAPTAIN);
}
void Bridge::GetInfo() {
  std::cout << "> Currently in the " << name << std::endl;
  std::cout << "> You notice that there is one way out of this room:"
      << std::endl << "> left" << std::endl
      << "> you also notice the Captain is here" << std::endl
      << "> and may want something " << std::endl;
}
void Bridge::UpWall(PlayerData *player) {
  std::cout << "> You decide to Stand on a near by table" << std::endl
      << "> it ends up collapsing taking you with it," << std::endl;
  player->UpdateHealth(-10);
}
void Bridge::DownWall(PlayerData *player) {
  std::cout << "> You decide to walk, but end up slipping" << std::endl
      << "> on a puddle hitting your head " << std::endl;
  player->UpdateHealth(-10);
}
void Bridge::RightWall(PlayerData *player) {
  std::cout << "> You decide to walk right, without paying attention, "
      << std::endl << "> and end up bumping " << std::endl
      << "> the corner of a desk" << std::endl;
  player->UpdateHealth(-10);
}
void Bridge::LeftWall(PlayerData *player) {
  std::cout << "> You move left" << std::endl;
  player->GetCords()->UpdateX(4);
}
/*
 * Barracks Imp
 */
Barracks::Barracks() {
  name = "Barracks";
  inventory = new Inventory();
  SetContents();
}
Barracks::~Barracks() {
  delete inventory;
  delete npc;
}
void Barracks::SetContents() {
  NpcFact fact;
  npc = fact.CreateNpc(CHEF);
  inventory->AddItem(PATCH, "patch");
}
void Barracks::GetInfo() {
  std::cout << "> Currently in the " << name << std::endl;
  std::cout << "> You notice that there is one way out of this room:"
      << std::endl << "> left" << std::endl
      << "> you also notice the Chef is here" << std::endl
      << "> and may want something " << std::endl;
}
void Barracks::UpWall(PlayerData *player) {
  std::cout << "> You decide to start jumping on the bed " << std::endl
      << "> you end up falling an bumping your head," << std::endl;
  player->UpdateHealth(-10);
}
void Barracks::DownWall(PlayerData *player) {
  std::cout << "> You decide to walk, but end up slipping" << std::endl
      << "> on a puddle hitting your head " << std::endl;
  player->UpdateHealth(-10);
}
void Barracks::RightWall(PlayerData *player) {
  std::cout << "> You decide to walk right, without paying attention, "
      << std::endl << "> and end up bumping " << std::endl
      << "> a pot of boiling soup, burning you" << std::endl;
  player->UpdateHealth(-10);
}
void Barracks::LeftWall(PlayerData *player) {
  std::cout << "> You move left" << std::endl;
  player->GetCords()->UpdateX(1);
}
/*
 * infirmary Imp
 */
Infirmary::Infirmary() {
  name = "Infirmary";
  inventory = new Inventory();
  SetContents();
}
Infirmary::~Infirmary() {
  delete inventory;
  delete npc;
}
void Infirmary::SetContents() {
  NpcFact fact;
  npc = fact.CreateNpc(MEDIC);
  inventory->AddItem(MEDKIT, "medkit");
}
void Infirmary::GetInfo() {
  std::cout << "> Currently in the " << name << std::endl;
  std::cout << "> You notice that there is one way out of this room:"
      << std::endl << "> right" << std::endl
      << "> you also notice the Medic is here, and is able to heal you"
      << std::endl << "> but sadly the ship is low on medical supply"
      << std::endl;
}
void Infirmary::UpWall(PlayerData *player) {
  std::cout << "> You decide to start jumping on the bed " << std::endl
      << "> you end up falling an bumping your head," << std::endl;
  player->UpdateHealth(-10);
}
void Infirmary::DownWall(PlayerData *player) {
  std::cout << "> You decide to walk, but end up slipping" << std::endl
      << "> on a puddle hitting your head " << std::endl;
  player->UpdateHealth(-10);
}
void Infirmary::RightWall(PlayerData *player) {
  std::cout << "> You move right" << std::endl;
  player->GetCords()->UpdateX(1);
}
void Infirmary::LeftWall(PlayerData *player) {
  std::cout
      << "> you walk left, and crash into a IV drip, tumbling to the ground "
      << std::endl << "> and injuring yourself" << std::endl;
  player->UpdateHealth(-10);
}
/*
 * Storage Imp
 */
Storage::Storage() {
  name = "Storage";
  inventory = new Inventory();
  SetContents();
}
Storage::~Storage() {
  delete inventory;
  delete npc;
}
void Storage::SetContents() {
  inventory->AddItem(TOOLS, "tools");
  inventory->AddItem(AIRTANK, "airtank");
}
void Storage::GetInfo() {
  std::cout << "> Currently in the" << name << std::endl;
  std::cout << "> You notice that there is way out of this room:" << std::endl
      << "> left" << std::endl
      << "> you can see lots of items which may be of interest" << std::endl;
}
void Storage::UpWall(PlayerData *player) {
  std::cout << "> You decide to climb on some of the shelves " << std::endl
      << "> but sadly the one you choose is needing maintenance and ends"
      << std::endl << "crashing to the ground taking you with it" << std::endl;
  player->UpdateHealth(-10);
}
void Storage::DownWall(PlayerData *player) {
  std::cout << "> You decide to walk, but end up slipping" << std::endl
      << "> on a puddle hitting your head on a crate " << std::endl;
  player->UpdateHealth(-10);
}
void Storage::RightWall(PlayerData *player) {
  std::cout << "> You move right, but you hit your foot on "
  << " a crate and stub your toes." << std::endl;
  player->UpdateHealth(-10);
}
void Storage::LeftWall(PlayerData *player) {
  std::cout
      << "> You walk left" << std::endl;
  player->GetCords()->UpdateX(7);
}
