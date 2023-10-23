#include "CommandManger.h"
#include "PlayerData.h"
#include "RoomCommands.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestRoomInteract, TestRoom0UP) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(0);
  Up* up = new Up(map, player);
  up->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 0);
  EXPECT_EQ(player->GetHealth(), 90);
  delete up;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom0Left) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(0);
  Left* left = new Left(map, player);
  left->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 0);
  EXPECT_EQ(player->GetHealth(), 90);
  delete left;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom0Right) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(0);
  Right* right = new Right(map, player);
  right->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 1);
  EXPECT_EQ(player->GetHealth(), 100);
  delete right;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom0Down) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(0);
  Down* down = new Down(map, player);
  down->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 0);
  EXPECT_EQ(player->GetHealth(), 90);
  delete down;
  delete player;
  delete map;
}
/*
 *  TestRoom 1
 */
TEST(TestRoomInteract, TestRoom1UP) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(1);
  Up* up = new Up(map, player);
  up->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 1);
  EXPECT_EQ(player->GetHealth(), 0);
  EXPECT_TRUE(player->Dead());
  delete up;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom1Left) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(1);
  Left* left = new Left(map, player);
  left->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 0);
  EXPECT_EQ(player->GetHealth(), 100);
  delete left;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom1Right) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(1);
  Right* right = new Right(map, player);
  right->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 2);
  EXPECT_EQ(player->GetHealth(), 100);
  delete right;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom1Down) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(1);
  Down* down = new Down(map, player);
  down->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 4);
  EXPECT_EQ(player->GetHealth(), 100);
  delete down;
  delete player;
  delete map;
}
/*
 *  TestRoom 2
 */
TEST(TestRoomInteract, TestRoom21UP) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(2);
  Up* up = new Up(map, player);
  up->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 2);
  EXPECT_EQ(player->GetHealth(), 90);
  delete up;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom2Left) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(2);
  Left* left = new Left(map, player);
  left->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 1);
  EXPECT_EQ(player->GetHealth(), 100);
  delete left;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom2Right) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(2);
  Right* right = new Right(map, player);
  right->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 2);
  EXPECT_EQ(player->GetHealth(), 90);
  delete right;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom2Down) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(2);
  Down* down = new Down(map, player);
  down->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 2);
  EXPECT_EQ(player->GetHealth(), 90);
  delete down;
  delete player;
  delete map;
}
/*
 *  TestRoom 3
 */
TEST(TestRoomInteract, TestRoom3UP) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(3);
  Up* up = new Up(map, player);
  up->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 3);
  EXPECT_EQ(player->GetHealth(), 90);
  delete up;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom3Left) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(3);
  Left* left = new Left(map, player);
  left->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 3);
  EXPECT_EQ(player->GetHealth(), 90);
  delete left;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom3Right) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(3);
  Right* right = new Right(map, player);
  right->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 4);
  EXPECT_EQ(player->GetHealth(), 100);
  delete right;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom3Down) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(3);
  Down* down = new Down(map, player);
  down->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 3);
  EXPECT_EQ(player->GetHealth(), 90);
  delete down;
  delete player;
  delete map;
}
/*
 *  TestRoom 4
 */
TEST(TestRoomInteract, TestRoom4UP) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(4);
  Up* up = new Up(map, player);
  up->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 1);
  EXPECT_EQ(player->GetHealth(), 100);
  delete up;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom4Left) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(4);
  Left* left = new Left(map, player);
  left->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 3);
  EXPECT_EQ(player->GetHealth(), 100);
  delete left;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom4Right) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(4);
  Right* right = new Right(map, player);
  right->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 5);
  EXPECT_EQ(player->GetHealth(), 100);
  delete right;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom4Down) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(4);
  Down* down = new Down(map, player);
  down->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 7);
  EXPECT_EQ(player->GetHealth(), 100);
  delete down;
  delete player;
  delete map;
}
/*
 *  TestRoom 5
 */
TEST(TestRoomInteract, TestRoom5UP) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(5);
  Up* up = new Up(map, player);
  up->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 5);
  EXPECT_EQ(player->GetHealth(), 90);
  delete up;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom5Left) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(5);
  Left* left = new Left(map, player);
  left->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 4);
  EXPECT_EQ(player->GetHealth(), 100);
  delete left;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom5Right) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(5);
  Right* right = new Right(map, player);
  right->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 5);
  EXPECT_EQ(player->GetHealth(), 90);
  delete right;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom5Down) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(5);
  Down* down = new Down(map, player);
  down->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 5);
  EXPECT_EQ(player->GetHealth(), 90);
  delete down;
  delete player;
  delete map;
}
/*
 *  TestRoom 6
 */
TEST(TestRoomInteract, TestRoom6UP) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(6);
  Up* up = new Up(map, player);
  up->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 6);
  EXPECT_EQ(player->GetHealth(), 90);
  delete up;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom6Left) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(6);
  Left* left = new Left(map, player);
  left->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 6);
  EXPECT_EQ(player->GetHealth(), 90);
  delete left;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom6Right) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(6);
  Right* right = new Right(map, player);
  right->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 7);
  EXPECT_EQ(player->GetHealth(), 100);
  delete right;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom6Down) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(6);
  Down* down = new Down(map, player);
  down->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 6);
  EXPECT_EQ(player->GetHealth(), 90);
  delete down;
  delete player;
  delete map;
}
/*
 *  TestRoom 7
 */
TEST(TestRoomInteract, TestRoom7UP) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(7);
  Up* up = new Up(map, player);
  up->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 4);
  EXPECT_EQ(player->GetHealth(), 100);
  delete up;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom7Left) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(7);
  Left* left = new Left(map, player);
  left->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 6);
  EXPECT_EQ(player->GetHealth(), 100);
  delete left;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom7Right) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(7);
  Right* right = new Right(map, player);
  right->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 8);
  EXPECT_EQ(player->GetHealth(), 100);
  delete right;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom7Down) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(7);
  Down* down = new Down(map, player);
  down->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 7);
  EXPECT_EQ(player->GetHealth(), 0);
  EXPECT_TRUE(player->Dead());
  delete down;
  delete player;
  delete map;
}
/*
 *  TestRoom 8
 */
TEST(TestRoomInteract, TestRoom8UP) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(8);
  Up* up = new Up(map, player);
  up->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 8);
  EXPECT_EQ(player->GetHealth(), 90);
  delete up;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom8Left) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(8);
  Left* left = new Left(map, player);
  left->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 7);
  EXPECT_EQ(player->GetHealth(), 100);
  delete left;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom8Right) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(8);
  Right* right = new Right(map, player);
  right->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 8);
  EXPECT_EQ(player->GetHealth(), 90);
  delete right;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom8Down) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(8);
  Down* down = new Down(map, player);
  down->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 8);
  EXPECT_EQ(player->GetHealth(), 90);
  delete down;
  delete player;
  delete map;
}
/*
 *  TestRoom 9
 */
TEST(TestRoomInteract, TestRoom9UP) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(9);
  Up* up = new Up(map, player);
  up->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 9);
  EXPECT_EQ(player->GetHealth(), 90);
  delete up;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom9Left) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(9);
  Left* left = new Left(map, player);
  left->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 9);
  EXPECT_EQ(player->GetHealth(), 0);
  delete left;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom9Right) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(9);
  Right* right = new Right(map, player);
  right->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 10);
  EXPECT_EQ(player->GetHealth(), 100);
  delete right;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom9Down) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(9);
  Down* down = new Down(map, player);
  down->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 9);
  EXPECT_EQ(player->GetHealth(), 90);
  delete down;
  delete player;
  delete map;
}
/*
 *  TestRoom 10
 */
TEST(TestRoomInteract, TestRoom10UP) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(10);
  Up* up = new Up(map, player);
  up->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 7);
  EXPECT_EQ(player->GetHealth(), 100);
  delete up;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom10Left) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(10);
  Left* left = new Left(map, player);
  left->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 9);
  EXPECT_EQ(player->GetHealth(), 100);
  delete left;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom10Right) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(10);
  Right* right = new Right(map, player);
  right->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 11);
  EXPECT_EQ(player->GetHealth(), 100);
  delete right;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom10Down) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(10);
  Down* down = new Down(map, player);
  down->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 10);
  EXPECT_EQ(player->GetHealth(), 90);
  delete down;
  delete player;
  delete map;
}
/*
 *  TestRoom 11
 */
TEST(TestRoomInteract, TestRoom11UP) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(11);
  Up* up = new Up(map, player);
  up->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 11);
  EXPECT_EQ(player->GetHealth(), 90);
  delete up;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom11Left) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(11);
  Left* left = new Left(map, player);
  left->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 10);
  EXPECT_EQ(player->GetHealth(), 100);
  delete left;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom11Right) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(11);
  Right* right = new Right(map, player);
  right->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 11);
  EXPECT_EQ(player->GetHealth(), 90);
  delete right;
  delete player;
  delete map;
}
TEST(TestRoomInteract, TestRoom11Down) {
  GameMap *map = new GameMap();
  PlayerData* player = new PlayerData();
  player->GetCords()->OverRideCord(11);
  Down* down = new Down(map, player);
  down->Run();
  EXPECT_EQ(player->GetCords()->GetX(), 11);
  EXPECT_EQ(player->GetHealth(), 90);
  delete down;
  delete player;
  delete map;
}
