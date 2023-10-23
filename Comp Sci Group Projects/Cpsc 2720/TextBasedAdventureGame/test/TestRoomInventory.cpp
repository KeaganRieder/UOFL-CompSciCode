#include "GlobalVaribles.h"
#include "PlayerData.h"
#include "GameMap.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestRoomInventory, TestRoom0Items) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(0);
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItemName("medkit"), "medkit");

  delete player;
  delete map;
}
TEST(TestRoomInventory, TestRoom1Items) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(1);
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItemName("tools"), "tools");

  delete player;
  delete map;
}

TEST(TestRoomInventory, TestRoom2Items) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(2);
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItemName("patch"), "patch");

  delete player;
  delete map;
}
TEST(TestRoomInventory, TestRoom3Items) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(3);
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItemName("patch"), "");
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItem("patch"), nullptr);

  delete player;
  delete map;
}
TEST(TestRoomInventory, TestRoom4Items) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(4);
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItemName("airtank"), "airtank");

  delete player;
  delete map;
}
TEST(TestRoomInventory, TestRoom5Items) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(5);
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItemName("patch"), "");
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItem("patch"), nullptr);
  EXPECT_EQ(map->GetRoom(player->GetCords())
      ->GetReqInventory(), nullptr);

  delete player;
  delete map;
}
TEST(TestRoomInventory, TestRoom6Items) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(6);
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItem("airtank"), nullptr);
  EXPECT_EQ(map->GetRoom(player->GetCords())
      ->GetReqInventory()->GetItemName("tools"), "tools");
  EXPECT_EQ(map->GetRoom(player->GetCords())
      ->GetReqInventory()->GetItemName("shipparts"), "shipparts");
  EXPECT_EQ(map->GetRoom(player->GetCords())
      ->GetReqInventory()->GetItemName("reactorparts"), "reactorparts");

  delete player;
  delete map;
}
TEST(TestRoomInventory, TestRoom7Items) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(7);
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItemName("airtank"), "airtank");
  EXPECT_EQ(map->GetRoom(player->GetCords())
      ->GetReqInventory()->GetItemName("tools"), "tools");
  EXPECT_EQ(map->GetRoom(player->GetCords())
      ->GetReqInventory()->GetItemName("patch"), "patch");

  delete player;
  delete map;
}
TEST(TestRoomInventory, TestRoom8Items) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(8);
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItemName("airtank"), "airtank");
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItemName("tools"), "tools");

  delete player;
  delete map;
}
TEST(TestRoomInventory, TestRoom9Items) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(9);
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItemName("seacucumber"), "seacucumber");

  delete player;
  delete map;
}
TEST(TestRoomInventory, TestRoom10Items) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(10);
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItemName("seacucumber"), "");
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItem("seacucumber"), nullptr);

  delete player;
  delete map;
}
TEST(TestRoomInventory, TestRoom11Items) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(11);
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItemName("tools"), "tools");
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItemName("shipparts"), "shipparts");
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItemName("reactorparts"), "reactorparts");
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItemName("medal"), "medal");

  delete player;
  delete map;
}
