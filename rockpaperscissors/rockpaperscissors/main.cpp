#include "game.h"
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	bool uPlay = false;
	string fingerPlay;

		do {
				srand((unsigned int)time(NULL));
				string uEnter;
				game iPlay(uEnter);
				iPlay.displayGame();
				cin >> uEnter;
				if (uEnter == "rock" || uEnter == "paper" || uEnter == "scissors")
				{
					iPlay.play();
					cout << "Would you like to continue ? Please Enter (Yes or yes) or (No or N)" << endl;
					cin >> fingerPlay;
					if (fingerPlay == "Yes" || fingerPlay == "yes")
					{
						uPlay = true;
					}
					else
						uPlay = false;
				}
				else
				{
					cout << "not a valid input" << endl;
					cout << "Do you want to try again ? Please Enter Yes or yes if you want to try again" << endl;
					cin >> fingerPlay;
					if (fingerPlay == "Yes" || fingerPlay == "yes")
					{
						uPlay = true;
					}
					else
						uPlay = false;
				}
		} while (uPlay );

}