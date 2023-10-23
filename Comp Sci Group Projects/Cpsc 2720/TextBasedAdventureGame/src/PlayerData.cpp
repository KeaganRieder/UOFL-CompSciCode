#include "PlayerData.h"

PlayerData::PlayerData() {
  health = 100;
  oxygen = 100;
  score = 0;
  cords = new Coordinate(1);
  inventory = new Inventory();
}
PlayerData::~PlayerData() {
  delete cords;
  delete inventory;
}

Inventory* PlayerData::GetInventory() {
  return inventory;
}

Coordinate* PlayerData::GetCords() {
  return cords;
}
void PlayerData::Die() {
  health = 0;
  dead = true;
}
void PlayerData::UpdateHealth(int damage) {
  health += damage;
  if (health > 100) {
    health = 100;
  } else if (health <= 0) {
    Die();
  } else {
    std::cout << "> Health:" << health << std::endl;
  }
}
void PlayerData::UpdateOxygen(int damage) {
  oxygen += damage;
  if (oxygen > 100) {
    oxygen = 100;
  } else if (oxygen <= 0) {
    std::cout << "> You have ran out of O2 and have taken damage" << std::endl;
    UpdateHealth(-10);
  }
  std::cout << "> Oxygen:" << oxygen << std::endl;
}
void PlayerData::addScore() {
    score += 50;
    std::cout << "Your bonus score is: "
    << score << std::endl;
}
void PlayerData::FillOxygen() {
  if (inventory->HasItem("airtank")) {
    oxygen = 100;
    std::cout << "> Refilled Oxygen:" << oxygen << std::endl;
    inventory->RemoveItem("airtank");
  } else {
    std::cout << "> Lacking a Airtank: " << oxygen << std::endl;
  }
}
int PlayerData::GetOxygen() {
  return oxygen;
}
int PlayerData::GetHealth() {
  return health;
}
int PlayerData::GetScore() {
  return score;
}
bool PlayerData::Dead() {
  return dead;
}
