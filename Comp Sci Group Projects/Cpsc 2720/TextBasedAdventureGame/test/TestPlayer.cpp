#include "PlayerData.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestPlayer, TestCreation) {
  PlayerData* player = new PlayerData();
  EXPECT_EQ(player->GetOxygen(), 100);
  EXPECT_EQ(player->GetHealth(), 100);
  EXPECT_EQ(player->GetCords()->GetX(), 1);
  EXPECT_EQ(player->GetScore(), 0);
  delete player;
}
TEST(TestPlayer, TestO2Damange) {
  PlayerData* player = new PlayerData();
  player->UpdateOxygen(-10);
  EXPECT_EQ(player->GetOxygen(), 90);
  player->UpdateOxygen(10);
  EXPECT_EQ(player->GetOxygen(), 100);
  player->UpdateOxygen(1999);
  EXPECT_EQ(player->GetOxygen(), 100);
  delete player;
}

TEST(TestPlayer, TestHPDamange) {
  PlayerData* player = new PlayerData();
  player->UpdateHealth(-10);
  EXPECT_EQ(player->GetHealth(), 90);
  player->UpdateHealth(10);
  EXPECT_EQ(player->GetHealth(), 100);
  delete player;
}

TEST(TestPlayer, TestOverFlowDamange) {
  PlayerData* player = new PlayerData();
  player->UpdateOxygen(-100);
  EXPECT_EQ(player->GetOxygen(), 0);
  EXPECT_EQ(player->GetHealth(), 90);
  player->UpdateHealth(-90);
  EXPECT_EQ(player->GetHealth(), 0);
  EXPECT_TRUE(player->Dead());
  delete player;
}
