#include <iostream>		//cout
#include <conio.h>		//_getch
#include <stdlib.h>		//rand
#include "Game.h"		//Game
#include "Character.h"	//Characters
#include "Point2D.h"	//Positions
#include "Physics.h"	//Collisions

//Constructor
Game::Game(int numMonsters)
{
	//Create array of monsters
	m_numMonsters = numMonsters;
	m_monsters = new Engine::Character* [numMonsters];

	//Instantiate player
	m_player = new Engine::Character();

	//Set names, positions, and health of monsters
	for (int i = 0; i < m_numMonsters; i++)
	{
		int xPos = std::rand() % 200 - 99;
		int yPos = std::rand() % 200 - 99;
		int monsterHealth = std::rand() % 10 + 4;

		m_monsters[i] = new Engine::Character(Engine::Point2D(xPos, yPos), monsterHealth);

		std::cout << "What would you like to name Monster " << i << ": ";
		setName(m_monsters[i]);
	}

	//Set the name of the player
	std::cout << "What would you like to name the Player: ";
	setName(m_player);
}

Game::Game(const Game& src)
{
	//Copy player
	m_player = new Engine::Character();
	*m_player = *(src.m_player);

	//Create an array of monsters the same size as src
	m_numMonsters = src.m_numMonsters;
	m_monsters = new Engine::Character*[m_numMonsters];

	//Copy monsters
	for (int i = 0; i < m_numMonsters; i++)
	{
		m_monsters[i] = new Engine::Character();
		*(m_monsters[i]) = *(src.m_monsters[i]);
	}
}

Game& Game::operator=(const Game& src)
{
	//Check for aliasing
	if (&src == this)
		return (*this);

	//Destruct current game
	for (int i = 0; i < m_numMonsters; i++)
		delete m_monsters[i];
	delete[] m_monsters;

	delete m_player;

	//Copy over src game
	m_player = new Engine::Character();
	*m_player = *(src.m_player);

	m_numMonsters = src.m_numMonsters;
	m_monsters = new Engine::Character*[m_numMonsters];

	for (int i = 0; i < m_numMonsters; i++)
	{
		m_monsters[i] = new Engine::Character();
		*(m_monsters[i]) = *(src.m_monsters[i]);
	}

	return (*this);
}
	

//Destructor, frees monster array and player
Game::~Game()
{
	for (int i = 0; i < m_numMonsters; i++)
		delete m_monsters[i];
	delete[] m_monsters;

	delete m_player;
}



//Main gameplay method
void Game::play()
{
	//Main game loop
	char input = 'c';
	int turnNumber = 1;
	while (input != 'q' && m_player->isAlive())
	{
		//Age monsters and update position
		for (int i = 0; i < m_numMonsters; i++)
		{
			//If a monster lives, update and display position
			m_monsters[i]->loseHealth();
			if (m_monsters[i]->isAlive())
			{
				//Move monster
				int numSpaces = std::rand() % 11 - 5;
				m_monsters[i]->moveNumSpaces(numSpaces);

				//Say where it is
				std::cout << "Monster "
					<< m_monsters[i]->getName()
					<< " at "
					<< m_monsters[i]->getPosition()
					<< std::endl;
			}

			//If a monster dies, delete it and resize monster array
			else
			{
				//Announce monster death
				std::cout << "Monster " 
					<< m_monsters[i]->getName() 
					<< " has died!" 
					<< std::endl;

				//Delete the dead monster
				*m_monsters[i] = *m_monsters[m_numMonsters - 1];
				delete m_monsters[m_numMonsters - 1];
				m_numMonsters--;

				//Resize the array
				Engine::Character** tempArr = new Engine::Character*[m_numMonsters];
				for (int j = 0; j < m_numMonsters; j++)
					tempArr[j] = new Engine::Character(*m_monsters[j]);
				delete[] m_monsters;
				m_monsters = tempArr;

				//Iterate over the dead monster's replacement in the array
				i--;
			}
				
		}

		//State player position
		std::cout << "Player "
			<< m_player->getName()
			<< " at "
			<< m_player->getPosition()
			<< std::endl;

		//Get user input
		std::cout << "Press A to move left, D to move right, W to move up, S to move down, or Q to quit" << std::endl << std::endl;
		input = _getch();

		//Exit the loop if Q is entered
		if (input == 'q')
		{
			turnNumber++;
			break;
		}
		
		//Update player position if needed
		m_player->moveDir(input);
				

		//Reduce player health if collision detected
		for (int i = 0; i < m_numMonsters; i++)
		{
			//If there's a collision, check if player is dead
			if (Engine::Physics::checkCollision(m_player, m_monsters[i]))
			{
				//If player is now dead, announce death
				if (!m_player->isAlive())
				{
					std::cout << std::endl
						<< "Monster " 
						<< m_monsters[i]->getName() 
						<< " killed Player " 
						<< m_player->getName() 
						<< std::endl;
				}
			}
		}

		//If the player is still alive, check to add a monster
		if (m_player->isAlive())
			//If the turn number is a multiple of 5 or there are few monsters, add a monster
			if (turnNumber % 5 == 0 || m_numMonsters <= 3 )
				addMonster(m_monsters[turnNumber % m_numMonsters]);
		
		//Increase turn number
		turnNumber++;
	}

	//Announce number of turns
	std::cout << "You played " << turnNumber - 1 << " turns." << std::endl;
}


void Game::setName(Engine::Character* characterObj)
{
	//Defines an empty name in case of no user input
	int numLetters = 1;
	char* name = new char[numLetters];
	name[0] = '\0';

	//Gets user input and resizes accordingly
	char ch;
	std::cin >> ch;
	while (ch != '\n')
	{
		numLetters++;
		char* nameNew = new char[numLetters];
		nameNew[numLetters - 1] = '\0';
		nameNew[numLetters - 2] = ch;
		for (int j = 0; j < numLetters - 2; j++)
		{
			nameNew[j] = name[j];
		}
		delete[] name;
		name = nameNew;
		std::cin.get(ch);
	}

	characterObj->setName(name, numLetters);
	delete[] name;
}

//Clones a current monster and adds it to the game
void Game::addMonster(Engine::Character* monsterClone)
{
	//Announces the new monster
	std::cout << std::endl
		<< "A clone of " 
		<< monsterClone->getName() 
		<< " has been created!" 
		<< std::endl
		<< std::endl;



	//Increases number of monsters
	m_numMonsters++;

	//Resize the array
	Engine::Character** tempArr = new Engine::Character*[m_numMonsters];
	for (int j = 0; j < m_numMonsters - 1; j++)
		tempArr[j] = new Engine::Character(*m_monsters[j]);
	delete[] m_monsters;
	m_monsters = tempArr;

	//Add the clone to the last position in the array
	m_monsters[m_numMonsters - 1] = new Engine::Character(*monsterClone, 10);
}
