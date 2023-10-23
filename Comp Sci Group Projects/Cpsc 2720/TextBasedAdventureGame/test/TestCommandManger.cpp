#include "GameMap.h"
#include "PlayerData.h"
#include "CommandManger.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestCommandManger, TestConstruct) {
  GameMap* map = new GameMap();
  PlayerData* player = new PlayerData();
  CommandManger* commandManger = new CommandManger(player, map);
  delete commandManger;
  delete map;
  delete player;
}
TEST(TestCommandManger, TestControlPanel) {
  GameMap* map = new GameMap();
  PlayerData* player = new PlayerData();
  CommandManger* commandManger = new CommandManger(player, map);
  EXPECT_TRUE(commandManger->RunCommand("u"));
  EXPECT_TRUE(commandManger->RunCommand("d"));
  EXPECT_TRUE(commandManger->RunCommand("l"));
  EXPECT_TRUE(commandManger->RunCommand("r"));
  EXPECT_TRUE(commandManger->RunCommand("look"));
  EXPECT_TRUE(commandManger->RunCommand("fix"));
  EXPECT_TRUE(commandManger->RunCommand("talk"));
  EXPECT_TRUE(commandManger->RunCommand("finishquest"));
  EXPECT_TRUE(commandManger->RunCommand("fillair"));
  EXPECT_TRUE(commandManger->RunCommand("heal"));
  EXPECT_FALSE(commandManger->RunCommand("GREEEN "));

  delete commandManger;
  delete map;
  delete player;
}
