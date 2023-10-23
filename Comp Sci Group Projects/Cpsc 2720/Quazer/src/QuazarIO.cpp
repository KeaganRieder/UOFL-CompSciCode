//########################
// QuazarIO implementation
//########################
#include "QuazarIO.h"

//##########################
// Constructors/destructers
//##########################
QuazarIO::QuazarIO() {
  //setting  formating variables
  BorderLength = 40;
  spinValue = 0;
  stakes = " ";
}
QuazarIO::~QuazarIO() {
}

//#######################
// QuazarIO UI
//#######################

//main menu/start of program
void QuazarIO::MainMenu() {
  player.SetCredits(100);
  bool start = false;

  while (!start) {
    std::string input = " ";

    std::cout << std::setfill('#') << std::setw(BorderLength) << "\n\n\n"
        << std::setfill(' ') << std::setw(BorderLength - 18) << std::right
        << "QUAZAR!!" << "\n\n" << std::setw(BorderLength - 20) << std::right
        << "Play" << "\n\n" << std::setw(BorderLength - 20) << std::right
        << "Help" << "\n\n\n" << std::setfill('#') << std::setw(BorderLength)
        << "\n\n" << std::setfill(' ') << ">>> ";

    std::cin >> input;
    //making input lowercase and cleaning up any unwanted spaces
    MakeLowercase(input);

    std::cout << '\n' << std::setfill('#') << std::setw(BorderLength) << "\n"
        << std::endl << std::setfill(' ');

    //checking for valid input
    if (input == "play") {
      Run();
      start = true;
    } else if (input == "help") {
      Help();
    }

    //input was Invalid
    while (input != "play" && input != "help") {
      std::cout << "> Invalid Input please input either \n" << "> play or help";
      std::cout << "\n>>>";
      std::cin >> input;
      std::cout << std::setfill('#') << std::setw(BorderLength) << "\n"
          << std::endl << std::setfill(' ');
      MakeLowercase(input);

      if (input == "play") {
        Run();
        start = true;
      } else if (input == "help") {
        Help();
      }

      //loops again until input is valid
    }
  }
}

//displays helpful information about the how
//to play the game
void QuazarIO::Help() {
  std::cout << std::setfill('#') << std::setw(BorderLength) << "\n\n"
      << std::setfill(' ') << std::setw(BorderLength - 14) << "Quazar Help\n"
      << std::setw(BorderLength - 2) << " To player input commands at '>>>'\n "
      << std::setw(BorderLength - 5) << " these commands are listed out to\n"
      << std::setw(BorderLength - 10) << " you before prompted \n "
      << std::setw(BorderLength - 3) << " For rules check provided document\n\n"
      << std::setfill('#') << std::setw(BorderLength) << "\n\n"
      << std::setfill(' ');
}

//recursive function that serves as the games main
//program loop
void QuazarIO::Run() {
  bool exit = false;
  std::string input = " ";
  std::string medStakes = " ";
  std::string highStakes = " ";
  //checking what stakes player can player
  if (player.GetCredits() >= 100) {
    medStakes = "mediumstakes";
  }
  if (player.GetCredits() >= 200) {
    highStakes = "highstakes";
  }

  if (spinValue < 21) {
    std::cout << std::setfill('#') << std::setw(BorderLength) << "\n\n\n"
        << std::setfill(' ') << std::setw(BorderLength - 22) << std::right
        << spinValue << "\n\n\n";

    //chekcing to see if stakes has been choosen
    if (stakes == " ") {
      std::cout << std::setw(BorderLength - 10)
          << "Please choose what stakes you'd like:" << "\n\n"
          << std::setw(BorderLength - 20) << "lowstakes | " << medStakes
          << " | " << highStakes << "" << "\n\n" << std::setfill('#')
          << std::setw(BorderLength) << "\n\n" << std::setfill(' ') << ">>> ";

      std::cin >> stakes;
      std::cout << std::setfill('#') << std::setw(BorderLength) << "\n\n"
          << std::setfill(' ');
      MakeLowercase(stakes);

      //making sure input is correct
      while (stakes != "lowstakes" && stakes != "mediumstakes"
          && stakes != "highstakes") {
        std::cout << "> Invalid Input please input either \n"
            << "> lowstakes or " << medStakes << " or " << highStakes << ""
            << "\n>>> ";
        std::cin >> stakes;
        MakeLowercase(stakes);
        std::cout << std::setfill('#') << std::setw(BorderLength) << "\n"
            << std::endl << std::setfill(' ');
        //loops again until input is valid
      }
    }

    std::cout << std::setw(BorderLength - 13) << " What is your move?" << "\n\n"
        << std::setw(BorderLength - 7) << "Your options are as followed:"
        << "\n\n" << std::setw(BorderLength - 12) << " Spin | Stand | Help "
        << "\n\n" << std::setfill('#') << std::setw(BorderLength) << "\n\n"
        << std::setfill(' ') << "> current balance is " << player.GetCredits()
        << " credits\n>>> ";
    std::cin >> input;
    std::cout << std::setfill('#') << std::setw(BorderLength) << "\n\n"
        << std::setfill(' ');
    MakeLowercase(input);

    //checking for valid input
    while (input != "spin" && input != "stand" && input != "help") {
      std::cout << "> Invalid Input please input either \n"
          << "> Spin or Stand or Help" << "\n>>> ";
      std::cin >> input;
      MakeLowercase(input);
      std::cout << std::setfill('#') << std::setw(BorderLength) << "\n"
          << std::endl << std::setfill(' ');
      //loops again until input is valid
    }
  }
//setting buy in
  if (stakes == "lowstakes") {
    player.SetBuyIn(20);
  } else if (stakes == "mediumstakes") {
    player.SetBuyIn(100);
  } else if (stakes == "highstakes") {
    player.SetBuyIn(200);
  } else {
  }

  if (input == "spin" && spinValue < 21) {  //runing spinner
    Spin();
  } else if (input == "stand" || spinValue > 20) {
    //checking if player wants to quit
    std::cout << std::setfill('#') << std::setw(BorderLength) << "\n\n"
        << std::setfill(' ') << "> you have won/lost: " << CheckPayOut()
        << " credits\n" << "> Your new balance is " << player.GetCredits()
        << " credits\n" << "> would you Like to exit (y/n)?" << "\n>>> ";
    std::cin >> input;
    std::cout << std::setfill('#') << std::setw(BorderLength) << "\n\n"
        << std::setfill(' ');

    if (player.GetCredits() < 20) {
      GameOver(exit);
    }

    MakeLowercase(input);
    while (input != "n" && input != "y") {
      std::cout << "> Invalid Input please input either \n" << "> y or n"
          << "\n>>> ";
      std::cin >> input;
      MakeLowercase(input);
      std::cout << std::setfill('#') << std::setw(BorderLength) << "\n"
          << std::endl << std::setfill(' ');
    }
    if (input == "y") {
      exit = true;
    }

    stakes = " ";
    spinValue = 0;

  } else if (input == "help" && spinValue < 21) {  //displays help screen
    Help();
  } else {
  }

  //checking if to run again
  if (input == "y" || player.GetCredits() < 20) {  //check credits
    GameOver(exit);
  } else {
    Run();
  }
}

// outputs UI for gameover/exit screen
//Parameter exit is passed in to determine weather to display
//game over(exit = false) /exit(exit=true) screen
void QuazarIO::GameOver(bool exit) {
  if (exit) {
    MainMenu();
  } else {
    std::cout << std::setfill('#') << std::setw(BorderLength) << "\n\n\n"
        << std::setfill(' ') << std::setw(BorderLength - 18) << std::right
        << "Loser!!" << "\n\n" << std::setfill('#') << std::setw(BorderLength)
        << "\n\n" << std::setfill(' ') << ">>> ";
    MainMenu();
  }
}

//#######################
// QuazarIO Logic
//#######################
int QuazarIO::CheckPayOut() {
  if (spinValue == 15) {
    player.UpdateCredits(player.GetBuyIn() * 0.25f);
    return player.GetBuyIn() * 0.25f;
  } else if (spinValue == 16) {
    player.UpdateCredits(player.GetBuyIn() * .5);
    return player.GetBuyIn() * .5;
  } else if (spinValue == 17) {
    player.UpdateCredits(player.GetBuyIn());
    return player.GetBuyIn();
  } else if (spinValue == 18) {
    player.UpdateCredits(player.GetBuyIn() * 1.25);
    return player.GetBuyIn() * 1.25;
  } else if (spinValue == 19) {
    player.UpdateCredits(player.GetBuyIn() * 1.5);
    return player.GetBuyIn() * 1.5;
  } else if (spinValue == 20) {
    player.UpdateCredits(player.GetBuyIn() * 2);
    return player.GetBuyIn() * 2;
  } else {
    player.UpdateCredits(-1 * player.GetBuyIn());
    return -1 * player.GetBuyIn();
  }
}
//spinning
void QuazarIO::Spin() {
  Spinners *spinner;
  //input
  std::string rangeChoice = "";
  //set player buy in
  std::cout << std::setfill('#') << std::setw(BorderLength) << "\n\n"
      << std::setfill(' ')
      << "> please pick  your spin range: '1' for 1-8, '2' for 4-7" << "\n>>> ";
  std::cin >> rangeChoice;
  std::cout << std::setfill('#') << std::setw(BorderLength) << "\n\n"
      << std::setfill(' ');

  //std::cout<< "value before ="<<spinValue <<std::endl;

  //checking for valid input
  while (rangeChoice != "1" && rangeChoice != "2") {
    std::cout << "> Invalid Input please input either \n"
        << "> '1' for 1-8, or '2' for 4-7" << "\n>>> ";
    std::cin >> rangeChoice;
    std::cout << std::setfill('#') << std::setw(BorderLength) << "\n"
        << std::endl << std::setfill(' ');
    //loops again until input is valid
  }

  //running spinners
  if (stakes == "lowstakes") {
    player.SetBuyIn(20);
    PlayerSpinner playerSpin(stoi(rangeChoice));
    spinner = &playerSpin;
    spinValue += spinner->Run();
  } else if (stakes == "mediumstakes") {
    player.SetBuyIn(100);
    FairSpinner fairSpin(stoi(rangeChoice));
    spinner = &fairSpin;
    spinValue += spinner->Run();
  } else if (stakes == "highstakes") {
    player.SetBuyIn(200);
    HouseSpinner houseSpin(stoi(rangeChoice));
    spinner = &houseSpin;
    spinValue += spinner->Run();
  }
  //delete spinner;
  //std::cout<< "value after ="<<spinValue <<std::endl;
}

//making input lowercase
void QuazarIO::MakeLowercase(std::string &input) {
  size_t inputPos = 0;
  std::string lowercaseInput = "";
  //staring loweracse input at the start of input and cleanning it
  while (input[inputPos] == ' ') {
    inputPos++;
  }
  lowercaseInput = tolower(input[inputPos]);
  inputPos++;
  for (; inputPos < input.size(); inputPos++) {
    lowercaseInput += tolower(input[inputPos]);
  }

  input = lowercaseInput;
}
