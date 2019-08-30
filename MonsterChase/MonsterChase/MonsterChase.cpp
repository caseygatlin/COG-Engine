#include <iostream>
#include <stdio.h>
#include "Game.h"
using namespace std;

int main()
{
	int numMonsters;
	std::cout << "How many monsters to start: ";
	std::cin >> numMonsters;
	Game game(numMonsters, 200, 200);
	game.play();



	return 0;
}
