#include "PlayerData.h"
#include "GameMap.h"
#include "RoomCommands.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestDeaths, TestDrowning) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  Right* right = new Right(map, player);
  Left* left = new Left(map, player);

  EXPECT_EQ(player->GetOxygen(), 100);
  player->GetCords()->OverRideCord(10);
  left->Run();
  right->Run();
  EXPECT_EQ(player->GetOxygen(), 80);
  left->Run();
  right->Run();
  EXPECT_EQ(player->GetOxygen(), 60);
  left->Run();
  right->Run();
  EXPECT_EQ(player->GetOxygen(), 40);
  left->Run();
  right->Run();
  EXPECT_EQ(player->GetOxygen(), 20);
  left->Run();
  right->Run();
  EXPECT_EQ(player->GetOxygen(), 0);
  EXPECT_EQ(player->GetHealth(), 90);
  delete map;
  delete player;
  delete right;
  delete left;
}
TEST(TestDeaths, TestHeadBanging) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  Right* right = new Right(map, player);
  Left* left = new Left(map, player);

  EXPECT_EQ(player->GetOxygen(), 100);
  player->GetCords()->OverRideCord(3);
  left->Run();
  EXPECT_EQ(player->GetHealth(), 90);
  left->Run();
  EXPECT_EQ(player->GetHealth(), 80);
  left->Run();
  EXPECT_EQ(player->GetHealth(), 70);
  left->Run();
  EXPECT_EQ(player->GetHealth(), 60);
  left->Run();
  EXPECT_EQ(player->GetHealth(), 50);
  left->Run();
  EXPECT_EQ(player->GetHealth(), 40);
  left->Run();
  EXPECT_EQ(player->GetHealth(), 30);
  left->Run();
  EXPECT_EQ(player->GetHealth(), 20);
  left->Run();
  EXPECT_EQ(player->GetHealth(), 10);
  left->Run();
  EXPECT_EQ(player->GetHealth(), 0);
  EXPECT_TRUE(player->Dead());
  delete map;
  delete player;
  delete right;
  delete left;
}
