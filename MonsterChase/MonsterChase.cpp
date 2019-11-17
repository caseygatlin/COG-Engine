//Casey Gatlin
//Last updated 9/06/19
//
//This program runs a simple game where the player must
//avoid running into monsters on a 2D grid by selecting 
//a direction in which to move. Monsters are occasionally
//cloned and follow the player.

#include <iostream>
#include "Game.h"
#include "Engine.h"

int main()
{
	//Announce engine start
	Engine::Init();


	//Prompt for number of monsters
	int		numMonsters;
	bool	askAgain		= true;

	while (askAgain)
	{

		std::cout	<< "How many monsters to start: ";
		std::cin	>> numMonsters;

		if (numMonsters <= 0)
		{

			std::cout << "Invalid number of monsters." << std::endl;
			askAgain = true;

		}
		else
		{
			
			askAgain = false;

		}
	}
	

	//Play the game
	Game game(numMonsters);
	game.play();

	//Announce engine shutdown
	Engine::Shutdown();


	return 0;
}
