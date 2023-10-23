#include "PlayerData.h"
#include "GameMap.h"
#include "ItemStorage.h"
#include "ItemCommands.h"
#include "RoomCommands.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestItemInteract, testFillAir) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  PickUp* pickUp = new PickUp(map, player);
  FillAir* fillAir = new FillAir(player);

  player->GetCords()->OverRideCord(8);
  EXPECT_EQ(player->GetOxygen(), 100);
  player->UpdateOxygen(-10);
  EXPECT_EQ(player->GetOxygen(), 90);
  fillAir->Run();
  EXPECT_EQ(player->GetOxygen(), 90);

  EXPECT_EQ(player->GetInventory()->GetItem("airtank"), nullptr);
  pickUp->Run("airtank");
  EXPECT_EQ(player->GetInventory()->GetItem("airtank")
      ->GetName(), "airtank");
  //filling air
  EXPECT_EQ(player->GetOxygen(), 90);
  fillAir->Run();
  EXPECT_EQ(player->GetOxygen(), 100);
  delete map;
  delete player;
  delete pickUp;
  delete fillAir;
}
TEST(TestItemInteract, testReactFix) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  PickUp* pickUp = new PickUp(map, player);
  FixRoom* fix = new FixRoom(map, player);
  player->GetCords()->OverRideCord(6);
  fix->Run();
  EXPECT_FALSE(map->GetRoom(player->GetCords())->RoomFixed());

  player->GetCords()->OverRideCord(11);
  EXPECT_EQ(player->GetInventory()->GetItem("tools"), nullptr);
  EXPECT_EQ(player->GetInventory()->GetItem("shipparts"), nullptr);
  EXPECT_EQ(player->GetInventory()->GetItem("reactorparts"), nullptr);
  pickUp->Run("tools");
  pickUp->Run("shipparts");
  pickUp->Run("reactorparts");
  EXPECT_EQ(player->GetInventory()->GetItem("tools")->GetName(),
      "tools");
  EXPECT_EQ(player->GetInventory()->GetItem("shipparts")->GetName(),
      "shipparts");
  EXPECT_EQ(player->GetInventory()->GetItem("reactorparts")->GetName(),
      "reactorparts");
  fix->Run();
  player->GetCords()->OverRideCord(6);
  fix->Run();
  EXPECT_TRUE(map->GetRoom(player->GetCords())->RoomFixed());
  EXPECT_EQ(player->GetInventory()->GetItem("patch"), nullptr);
  EXPECT_EQ(player->GetInventory()->GetItem("tools"), nullptr);
  delete map;
  delete player;
  delete fix;
  delete pickUp;
}
TEST(TestItemInteract, testFixAirLock) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  PickUp* pickUp = new PickUp(map, player);
  FixRoom* fix = new FixRoom(map, player);
  player->GetCords()->OverRideCord(7);
  fix->Run();
  EXPECT_FALSE(map->GetRoom(player->GetCords())->RoomFixed());

  player->GetCords()->OverRideCord(2);
  EXPECT_EQ(player->GetInventory()->GetItem("patch"), nullptr);
  EXPECT_EQ(player->GetInventory()->GetItem("tools"), nullptr);
  pickUp->Run("patch");
  EXPECT_EQ(player->GetInventory()->GetItem("patch")->GetName(),
      "patch");
  player->GetCords()->OverRideCord(8);
  //EXPECT_EQ(map->GetRoom(player->GetCords())->GetType(), "Storage");
  pickUp->Run("tools");
  EXPECT_EQ(player->GetInventory()->GetItem("tools")->GetName(),
      "tools");
  player->GetCords()->OverRideCord(7);
  fix->Run();
  EXPECT_TRUE(map->GetRoom(player->GetCords())->RoomFixed());
  EXPECT_EQ(player->GetInventory()->GetItem("patch"), nullptr);
  EXPECT_EQ(player->GetInventory()->GetItem("tools"), nullptr);
  delete map;
  delete player;
  delete pickUp;
  delete fix;
}

TEST(TestItemInteract, testDroping) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  PickUp* pickUp = new PickUp(map, player);
  Drop* drop = new Drop(map, player);

  player->GetCords()->OverRideCord(2);
  EXPECT_EQ(player->GetInventory()->GetItem("patch"), nullptr);
  EXPECT_EQ(map->GetRoomContents(player->GetCords())->GetItem("patch")
      ->GetName(), "patch");
  pickUp->Run("patch");
  EXPECT_EQ(player->GetInventory()->GetItem("patch")->GetName(),
      "patch");
  EXPECT_EQ(map->GetRoomContents(player->GetCords())
      ->GetItem("patch"), nullptr);
  drop->Run("patch");
  EXPECT_EQ(map->GetRoomContents(player->GetCords())->GetItem("patch")
      ->GetName(), "patch");
  EXPECT_EQ(player->GetInventory()->GetItem("patch"), nullptr);

  delete map;
  delete player;
  delete pickUp;
  delete drop;
}
