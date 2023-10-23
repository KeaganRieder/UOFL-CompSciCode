#include "UnderUs.h"

UnderUs::UnderUs() {
}
UnderUs::~UnderUs() {
  delete commandHandler;
  delete player;
  delete gameMap;
}
void UnderUs::MainMenu() {
    player = new PlayerData();
    gameMap = new GameMap();
    commandHandler = new CommandManger(player, gameMap);
  std::cout << std::endl;
  std::cout << "- MENU -" << std::endl << std::endl;

  std::cout << "PLAY" << std::endl;
  std::cout << "HELP" << std::endl;
  std::cout << "EXIT" << std::endl << std::endl;

  std::cout << "Enter a corresponding input on the Command Line -" << std::endl
      << ">> ";
  std::cin >> input;
  std::transform(input.begin(), input.end(), input.begin(), tolower);
  while (input != "play" && input != "help" && input != "exit") {
    std::cout << "Invalid Input. Please input a correct command "
        << "on the Command Line -" << std::endl << ">> ";
    std::cin >> input;
    std::transform(input.begin(), input.end(), input.begin(), tolower);
  }
  if (input == "play") {
    BackStory();
  } else if (input == "help") {
    Gethelp();
  } else if (input == "exit") {
    Exit();
  }
}
void UnderUs::GetCommands() {
  std::cout << std::endl << "- COMMON COMMANDS -" << std::endl << std::endl
      << "* This is a list of words you can type while playing the game *"
      << std::endl << std::endl << std::endl
      << "Look: Shows a description of the room" << std::endl << std::endl
      << "U, D, L, R: Moves you either Up, Down, Left or Right."
          " Depending on the letter." << std::endl << std::endl
      << "Fix: Fix anything broken with items"
          " in your inventory" << std::endl << std::endl
      << "PickUp: Take item in the room" << std::endl << std::endl
      << "Drop: Drop item in your inventory" << std::endl << std::endl
      << "Talk: Talk with the person in the room you're currently in."
      << std::endl << std::endl
      << "GetQuest: Get a quest from the person in the room." << std::endl
      << std::endl
      << "FinishQuest: Finish the quest given by the person in the room. "
      << "You must have finished the criteria before "
          "for it to be successful." << std::endl << std::endl
      << "FillAir: Fill the air in the Airlock" << std::endl << std::endl
      << "Help: Shows all commands that is accepted "
          "in the game." << std::endl << std::endl
      << "Exit: Exits out of the game" << std::endl << std::endl << std::endl
      << "- END OF COMMANDS LIST - " << std::endl << std::endl;
  if (playing == false) {
    MainMenu();
  }
}
void UnderUs::Gethelp() {
  GetCommands();
}
void UnderUs::BackStory() {
  std::cout << std::endl << "- UNDER US -" << std::endl << std::endl;

  std::cout << "You are a crew member in a submarine stuck "
      << "in the middle of the ocean." << std::endl
      << "Its reactor is damaged and in need of fixing." << std::endl
      << "It is your goal to help and "
      << "fix the problems in and around the submarine. " << std::endl
      << "Explore the ship, talk with your Crew Members, " << std::endl
      << "and find away to fix the Submarine and get it moving again."
        << std::endl << std::endl
      << "Good luck! Try to avoid danger!" << std::endl << std::endl;
    playing = true;
    GetCommands();
    commandHandler->RunCommand("look");
  Play();
}
void UnderUs::Play() {
  SendCommand();
  if (!playing) {
    //break recursion
  } else if (player->Dead()) {
    //break recursion
    GameOver();
  } else if (gameMap->GetRoom(REACTOR_CORDS)->RoomFixed() == true) {
    GameWon();
  } else {
    Play();
  }
}
void UnderUs::Exit() {
  std::cout << "Are you sure you want to Exit out?"
      << " Your progress will not be saved." << std::endl << std::endl;

  std::cout << "Enter 'Yes' to Confirm, and "
      "'No' to return back" << std::endl << ">> ";
  std::cin >> input;
  std::transform(input.begin(), input.end(), input.begin(), tolower);
  while (input != "yes" && input != "no") {
    std::cout << "Invalid Input. Please input a correct command "
        << "on the Command Line -" << std::endl << ">> ";
    std::cin >> input;
    std::transform(input.begin(), input.end(), input.begin(), tolower);
  }
  if (input == "yes") {
    playing = false;
    std::cout << std::endl << "Thanks for playing! Goodbye!" << std::endl;
    exit(0);
  }
  if (playing == false) {
    MainMenu();
  } else {
    Play();
  }
}
void UnderUs::SendCommand() {
  //todo output asking for comamnd/getting input
  std::cout << std::endl << ">> ";
  std::cin >> input;
  std::transform(input.begin(), input.end(), input.begin(), tolower);
  bool valid = false;
  do {
    if (input == "exit") {
      Exit();
      // playing = false;
      valid = true;
    } else if (input == "help") {
      Gethelp();
      valid = true;
    } else {
      valid = commandHandler->RunCommand(input);
    }
    if (!valid) {
      std::cout << "Invalid Input. Please input a valid "
          << "word from the command list." << std::endl << std::endl;
      GetCommands();
      std::cout << std::endl << ">> ";
      std::cin >> input;
      std::transform(input.begin(), input.end(), input.begin(), tolower);
    }
  } while (!valid);
}

void UnderUs::GameOver() {
    playing = false;
    std::cout << "- GAME OVER -" << std::endl << std::endl
    << "You've lost the game!" << std::endl
    << std::endl << "Would you like to:" << std::endl
    << "Try Again?: Type 'menu'" << std::endl
    << "Exit?: Type 'exit'" << std::endl << std::endl
    << ">> ";
  std::cin >> input;
  std::transform(input.begin(), input.end(), input.begin(), tolower);
  while (input != "menu" && input != "exit") {
    std::cout << "Invalid Input. Please input a correct command "
        << "on the Command Line -" << std::endl << ">> ";
    std::cin >> input;
    std::transform(input.begin(), input.end(), input.begin(), tolower);
  }
    if (input == "menu") {
    delete commandHandler;
    delete player;
    delete gameMap;
        MainMenu();
    } else if (input == "exit") {
    std::cout << std::endl << "Thanks for playing! Goodbye!" << std::endl;
    exit(0);
    }
}
void UnderUs::GameWon() {
    playing = false;
    std::cout << "!- [GAME WON] -!" << std::endl << std::endl
    << "You've won the game!" << std::endl << std::endl;
    if (player->GetScore() == 50) {
        std::cout << "Well done! " << std::endl
        << "You and your crew members happily "
        << "get back to land safely. " << std::endl
        << "Some happier than others." << std::endl
        << "I wonder if there were others "
        << "you could have helped in some way"
        << std::endl;
    } else if (player->GetScore() == 100) {
        std::cout << "Congrats! You completed all the quests"
        << std::endl << "You and your crew members happily "
        << "get back to land safely, " << std::endl
        << "beloved treasure in hand!" << std::endl
        << "Because of this you get promoted to "
        << "Captain!!" << std::endl
        << "Yaarg! Ready to get back to sea matie?!"
        << std::endl;
    } else {
        std::cout << "Good job! You got back to land safely."
        << std::endl << "However your crew "
        << "mates look disappointed going home "
        << "empty handed." << std::endl
        << "I wonder if you could have helped them "
        << "in some way?" << std::endl;
    }
    std::cout << std::endl << "Would you like to:" << std::endl
    << "Play Again?: Type 'menu'" << std::endl
    << "Exit?: Type 'exit'" << std::endl << std::endl
    << ">> ";
  std::cin >> input;
  std::transform(input.begin(), input.end(), input.begin(), tolower);
  while (input != "menu" && input != "exit") {
    std::cout << "Invalid Input. Please input a correct command "
        << "on the Command Line -" << std::endl << ">> ";
    std::cin >> input;
    std::transform(input.begin(), input.end(), input.begin(), tolower);
  }
    if (input == "menu") {
    delete commandHandler;
    delete player;
    delete gameMap;
        MainMenu();
    } else if (input == "exit") {
    std::cout << std::endl << "Thanks for playing! Goodbye!" << std::endl;
    exit(0);
    }
}
