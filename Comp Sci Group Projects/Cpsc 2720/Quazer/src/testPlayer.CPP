#include "Player.h"

//using namespace std;
int main() {
	int playCredits;
	player player1;
	std::cout << player1.getCredits()<< "\n";

	std::cin >> playCredits;
	player1.setCredits(playCredits);
	//player1.highStakesOpen();

	if (player1.highStakesOpen())
	{
		std::cout << "You are eligible to play  higher stakes \n";
	}
	else {
		std::cout << "Please buy more Credits to play High stakes\n";
	}


	 if (player1.mediumStakesOpen())
	{
		std::cout << "You are eligible to play  medium stakes \n";
	}
	 else {
		 std::cout << "Please buy more Credits to play medium stakes\n";
	 }

	if (player1.lowStakesOpen())
	{
		std::cout << "You are eligible to play  low stakes \n";
	}
	else {
		std::cout << "Please buy more Credits to play low stakes\n";
	}
	return 0;
}
