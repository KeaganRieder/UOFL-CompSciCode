#include "PlayerData.h"
#include "GameMap.h"
#include "ItemStorage.h"
#include "ItemCommands.h"
#include "RoomCommands.h"
#include "NpcCommands.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestNPCInteract, TestHealing) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(0);
  PickUp* pickUp = new PickUp(map, player);
  FinishQuest* finishQuest = new FinishQuest(map, player);

  Heal* heal = new Heal(map, player);
  heal->Run();

  EXPECT_EQ(player->GetInventory()->GetItem("medkit"), nullptr);
  pickUp->Run("medkit");
  EXPECT_EQ(player->GetInventory()->GetItem("medkit")
      ->GetName(), "medkit");
  heal->Run();
  EXPECT_EQ(player->GetHealth(), 100);
  player->UpdateHealth(-20);
  EXPECT_EQ(player->GetHealth(), 80);
  heal->Run();
  finishQuest->Run();
  EXPECT_EQ(player->GetHealth(), 100);
  EXPECT_EQ(map->GetRoom(player->GetCords())
      ->GetNPC()->GetQuest(), nullptr);
  delete map;
  delete player;
  delete pickUp;
  delete heal;
  delete finishQuest;
}

TEST(TestNPCInteract, TestCapatinQuest) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(11);
  PickUp* pickUp = new PickUp(map, player);
  FinishQuest* finishQuest = new FinishQuest(map, player);

  player->GetCords()->OverRideCord(11);
  EXPECT_EQ(player->GetInventory()->GetItem("medal"), nullptr);
  pickUp->Run("medal");
  EXPECT_EQ(player->GetInventory()->GetItem("medal")
      ->GetName(), "medal");
  player->GetCords()->OverRideCord(BRIDGE_CORDS);
  EXPECT_EQ(map->GetRoom(player->GetCords())
      ->GetNPC()->GetQuest()->GetName(), "medal");
  finishQuest->Run();
  EXPECT_EQ(map->GetRoom(player->GetCords())
      ->GetNPC()->GetQuest(), nullptr);
  EXPECT_EQ(player->GetInventory()->GetItem("medal"), nullptr);
  delete map;
  delete player;
  delete pickUp;
  delete finishQuest;
}
TEST(TestNPCInteract, TestChefQuest) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(9);
  PickUp* pickUp = new PickUp(map, player);
  Heal* heal = new Heal(map, player);
  FinishQuest* finishQuest = new FinishQuest(map, player);

  EXPECT_EQ(player->GetInventory()->GetItem("seacucumber"), nullptr);
  pickUp->Run("seacucumber");
  EXPECT_EQ(player->GetInventory()->GetItem("seacucumber")
      ->GetName(), "seacucumber");
  player->GetCords()->OverRideCord(BARRACKS_CORDS);
  EXPECT_EQ(map->GetRoom(player->GetCords())
      ->GetNPC()->GetQuest()->GetName(), "seacucumber");
  finishQuest->Run();

  heal->Run();
  EXPECT_EQ(map->GetRoom(player->GetCords())
      ->GetNPC()->GetQuest(), nullptr);
  EXPECT_EQ(player->GetInventory()->GetItem("seacucumber"), nullptr);
  delete map;
  delete player;
  delete pickUp;
  delete finishQuest;
  delete heal;
}
TEST(TestNPCInteract, TestTalking) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  Talk* talk = new Talk(map, player->GetCords());
  player->GetCords()->OverRideCord(BARRACKS_CORDS);
  talk->Run();
  player->GetCords()->OverRideCord(0);
  talk->Run();
  player->GetCords()->OverRideCord(BRIDGE_CORDS);
  talk->Run();
  delete map;
  delete player;
  delete talk;
}
