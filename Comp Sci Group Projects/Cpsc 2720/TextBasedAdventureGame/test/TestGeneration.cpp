#include "GameMap.h"
#include <NpcFact.h>
#include "Inventory.h"
#include "ItemStorage.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

/*
 * testing Itemgen
 */
TEST(TestMapGen, TestItemGen) {
  ItemStorage itemfact;

  Item* tool = itemfact.CreateItem(TOOLS);
  EXPECT_EQ(tool->GetName(), "tools");
  tool->GetDescription();
  delete tool;
  Item* seacucumber = itemfact.CreateItem(SEACUCUMBER);
  EXPECT_EQ(seacucumber->GetName(), "seacucumber");
  seacucumber->GetDescription();
  delete seacucumber;
  Item* shipparts = itemfact.CreateItem(SHIPPARTS);
  EXPECT_EQ(shipparts->GetName(), "shipparts");
  shipparts->GetDescription();
  delete shipparts;
  Item* reactorparts = itemfact.CreateItem(REACTORPARTS);
  EXPECT_EQ(reactorparts->GetName(), "reactorparts");
  reactorparts->GetDescription();
  delete reactorparts;
  Item* patch = itemfact.CreateItem(PATCH);
  EXPECT_EQ(patch->GetName(), "patch");
  patch->GetDescription();
  delete patch;
  Item* medkit = itemfact.CreateItem(MEDKIT);
  EXPECT_EQ(medkit->GetName(), "medkit");
  medkit->GetDescription();
  delete medkit;
  Item* medal = itemfact.CreateItem(MEDAL);
  EXPECT_EQ(medal->GetName(), "medal");
  medal->GetDescription();
  delete medal;
  Item* airtank = itemfact.CreateItem(AIRTANK);
  EXPECT_EQ(airtank->GetName(), "airtank");
  airtank->GetDescription();
  delete airtank;
}
/*
 * Testing room fact
 */
TEST(TestMapGen, TestRoomFact) {
  MapGen* gen = new MapGen();
  Environment* env = gen->CreateMapLocation(BRIDGE);
  EXPECT_EQ(env->GetType(), "Bridge");
  env->GetInfo();
  delete env;
  env = gen->CreateMapLocation(HALLWAYEND);
  EXPECT_EQ(env->GetType(), "End of Hallway");
  env->GetInfo();
  delete env;
  env = gen->CreateMapLocation(REACTOR);
  EXPECT_EQ(env->GetType(), "Reactor");
  env->GetInfo();
  delete env;
  env = gen->CreateMapLocation(STORAGE);
  EXPECT_EQ(env->GetType(), "Storage");
  env->GetInfo();
  delete env;
  env = gen->CreateMapLocation(ELEVATOR);
  EXPECT_EQ(env->GetType(), "Elevator Room");
  env->GetInfo();
  delete env;
  env = gen->CreateMapLocation(BARRACKS);
  EXPECT_EQ(env->GetType(), "Barracks");
  delete env;
  env = gen->CreateMapLocation(INFERMARY);
  EXPECT_EQ(env->GetType(), "Infirmary");
  env->GetInfo();
  delete env;
  env = gen->CreateMapLocation(AIRLOCK);
  EXPECT_EQ(env->GetType(), "AirLock");
  env->GetInfo();
  delete env;
  env = gen->CreateMapLocation(SEALOCK);
  EXPECT_EQ(env->GetType(), "Below AirLock");
  env->GetInfo();
  delete env;
  env = gen->CreateMapLocation(CAVE);
  EXPECT_EQ(env->GetType(), "Cave");
  env->GetInfo();
  delete env;
  env = gen->CreateMapLocation(REEF);
  EXPECT_EQ(env->GetType(), "Reef");
  env->GetInfo();
  delete env;
  env = gen->CreateMapLocation(TOPAIRLOCK);
  EXPECT_EQ(env->GetType(), "Surface AirLock");
  env->GetInfo();
  delete env;
  delete gen;
}
TEST(TestMapGen, TestMapGenration) {
  GameMap* map = new GameMap();
  //INFERMARY
  EXPECT_EQ(map->GetRoom(INFERMARY_CORDS)->GetType(), "Infirmary");
  //TOPAIRLOCK
  EXPECT_EQ(map->GetRoom(TOPAIRLOCK_CORDS)->GetType(), "Surface AirLock");
  //HALLWAYEND
  EXPECT_EQ(map->GetRoom(HALLWAYEND_CORDS)->GetType(), "End of Hallway");
  //ELEVATOR
  EXPECT_EQ(map->GetRoom(ELEVATOR_CORDS)->GetType(), "Elevator Room");
  //BRIDGE
  EXPECT_EQ(map->GetRoom(BRIDGE_CORDS)->GetType(), "Bridge");
  //REACTOR
  EXPECT_EQ(map->GetRoom(REACTOR_CORDS)->GetType(), "Reactor");
  //AIRLOCK
  EXPECT_EQ(map->GetRoom(AIRLOCK_CORDS)->GetType(), "AirLock");
  //STORAGE
  EXPECT_EQ(map->GetRoom(STORAGE_CORDS)->GetType(), "Storage");
  //REEF
  EXPECT_EQ(map->GetRoom(REEF_CORDS)->GetType(), "Reef");
  //SEALOCK
  EXPECT_EQ(map->GetRoom(SEALOCK_CORDS)->GetType(), "Below AirLock");
  //CAVE
  EXPECT_EQ(map->GetRoom(CAVE_CORDS)->GetType(), "Cave");
  delete map;
}
TEST(TestMapGen, TestNPCGenration) {
  GameMap* map = new GameMap();
  EXPECT_EQ(map->GetRoom(INFERMARY_CORDS)->GetNPC()->GetName(), "medic");
  EXPECT_EQ(map->GetRoom(BRIDGE_CORDS)->GetNPC()->GetName(), "captain");
  EXPECT_EQ(map->GetRoom(BARRACKS_CORDS)->GetNPC()->GetName(), "chef");
  EXPECT_EQ(map->GetRoom(7)->GetNPC(), nullptr);
  delete map;
}
TEST(TestMapGen, TestNPCItemGenration) {
  GameMap* map = new GameMap();
  EXPECT_EQ(map->GetRoom(INFERMARY_CORDS)->GetNPC()->GetQuest(), nullptr);
  EXPECT_EQ(map->GetRoom(BRIDGE_CORDS)->GetNPC()
      ->GetQuest()->GetName(), "medal");
  EXPECT_EQ(map->GetRoom(BARRACKS_CORDS)->GetNPC()
      ->GetQuest()->GetName(), "seacucumber");
  delete map;
}
TEST(TestMapGen, TestNPCNullGenration) {
  NpcFact* fact = new NpcFact();
  EXPECT_EQ(fact->CreateNpc(NONE), nullptr);
  delete fact;
}
TEST(TestMapGen, TestRoomNullGenration) {
  MapGen* fact = new MapGen();
  EXPECT_EQ(fact->CreateMapLocation(AIR), nullptr);
  delete fact;
}
