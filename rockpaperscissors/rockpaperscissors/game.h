#pragma once
#include <string>
using namespace std;

class game
{
public:
	game(string); // explicit value constructor initalizes the array with 3 elements
	~game();// destructor. deletes the array
	void displayGame(); //prints out the welcome screen for the game
	string displayWinnerOfGame(string);
	string play(); 
	string comparison(string);
	string winnerOfGame(string);

private:
	 string aArray[3];
	 int computerWins;
	 int playerWins;
	 string userInput;


};
