#include "Player.h"

Player::Player() {
  SetCredits(100);
  SetBuyIn(0);
}
Player::~Player() {
}
int Player::GetCredits() {
  return credits;
}
int Player::GetBuyIn() {
  //std::cout<<"buyin:"<<buyIn<<std::endl;
  return buyIn;
}
void Player::SetCredits(int value) {
  credits = value;
}
void Player::SetBuyIn(int value) {
  buyIn = value;
}
void Player::UpdateCredits(int value) {
  credits += value;
}
bool Player::HighStakesOpen() {
  if (credits >= 200) {
    return true;
  }
  return false;
}
bool Player::MediumStakesOpen() {
  if (credits >= 100) {
    return true;
  }
  return false;
}
