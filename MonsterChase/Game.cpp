#include <iostream>					//cout
#include <conio.h>					//_getch
#include <stdlib.h>					//rand
#include "Game.h"					//Game
#include "IGOComponent.h"			//Components
#include "FollowPlayerMovement.h"	//Components
#include "UserInputMovement.h"		//Components
#include "RandomDeath.h"			//Components
#include "Point2D.h"				//Positions
#include "Physics.h"				//Collisions


//Constructor
Game::Game(int numMonsters)
{
	//Create array of monsters
	m_numMonsters	= numMonsters;
	m_monsters		= new Engine::GameObject* [m_numMonsters];


	//Instantiate player
	m_player		= new Engine::GameObject();
	

	// Attach movement component to player
	Engine::UserInputMovement* pPlayerMovement = new Engine::UserInputMovement();

	m_player->Attach(pPlayerMovement);


	//Set names, positions, and health of monsters
	for (int i = 0; i < m_numMonsters; i++)
	{

		int xPos			= std::rand() % 200 - 99;
		int yPos			= std::rand() % 200 - 99;
		int monsterHealth	= std::rand() % 10 + 4;


#pragma warning (suppress: 6386) //Am allocating the correct number of monsters so didn't feel like it was neccesary to fix


		m_monsters[i]		= new Engine::GameObject(Engine::Point2D(xPos, yPos), monsterHealth);
		

		// Attach movement component to monster
		Engine::FollowPlayerMovement* pMonsterMovement = new Engine::FollowPlayerMovement(m_player);

		m_monsters[i]->Attach(pMonsterMovement);

		// Every other monster has a 10% chance of dying
		if (i % 2 == 0)
		{

			Engine::RandomDeath* pRandomDeath = new Engine::RandomDeath();
			m_monsters[i]->Attach(pRandomDeath);

		}


		// Set the name of the monster
		std::cout << "What would you like to name Monster " << i << ": ";


#pragma warning (suppress: 6385) //Am accessing the correct number of monsters so didn't feel like it was neccesary to fix

		setName(m_monsters[i]);

	}


	//Set the name of the player
	std::cout << "What would you like to name the Player: ";

	setName(m_player);

}



// Copy constructor
Game::Game(const Game& src)
{

	//Copy player
	m_player		= new Engine::GameObject();
	*m_player		= *(src.m_player);


	//Create an array of monsters the same size as src
	m_numMonsters	= src.m_numMonsters;
	m_monsters		= new Engine::GameObject*[m_numMonsters];


	//Copy monsters
	for (int i = 0; i < m_numMonsters; i++)
	{

		m_monsters[i]		= new Engine::GameObject();
		*(m_monsters[i])	= *(src.m_monsters[i]);

	}
}



// Assignment operator
Game& Game::operator=(const Game& src)
{

	//Check for aliasing
	if (&src == this)
	{

		return (*this);

	}


	//Destruct current game
	for (int i = 0; i < m_numMonsters; i++)
	{

		delete	m_monsters[i];

	}

	delete[]	m_monsters;
	delete		m_player;


	//Copy over src game
	m_player		= new Engine::GameObject();
	*m_player		= *(src.m_player);
	m_numMonsters	= src.m_numMonsters;
	m_monsters		= new Engine::GameObject*[m_numMonsters];

	for (int i = 0; i < m_numMonsters; i++)
	{

		m_monsters[i]		= new Engine::GameObject();
		*(m_monsters[i])	= *(src.m_monsters[i]);

	}

	return (*this);
}



//Destructor, frees monster array and player
Game::~Game()
{

	for (int i = 0; i < m_numMonsters; i++)
	{

		delete	m_monsters[i];

	}

	delete[]	m_monsters;
	delete		m_player;

}



//Main gameplay method
void Game::play()
{

	//Main game loop
	char	input		= 'c';
	int		turnNumber	= 1;

	while ( input != 'q' && m_player->IsAlive() )
	{
		updateMonsters();
		statePlayerLocation();
		getUserInput(input);


		//Exit the loop if Q is entered
		if (input == 'q')
		{

			turnNumber++;
			break;

		}
		
		updatePlayer(input);
		checkCollisions();


		//If the player is still alive, check to add a monster
		if (m_player->IsAlive())
		{

			//If the turn number is a multiple of 5 or there are few monsters, add a monster
			if (turnNumber % 5 == 0 || m_numMonsters <= 3)
			{

				addMonster(m_monsters[turnNumber % m_numMonsters]);

			}
		}
		

		//Increase turn number
		turnNumber++;

	}


	//Announce number of turns
	std::cout << "You played " << turnNumber - 1 << " turns." << std::endl;
}



// Set the name of a given GameObject
void Game::setName(Engine::GameObject* characterObj)
{

	//Defines an empty name in case of no user input
	int		numLetters	= 1;
	char*	name		= new char[numLetters];
			name[0]		= '\0';


	//Gets user input and resizes accordingly
	char	ch;

	std::cin >> ch;

	while (ch != '\n')
	{

		numLetters++;

		char*	nameNew					= new char[numLetters];
				nameNew[numLetters - 1] = '\0';
				nameNew[numLetters - 2] = ch;

		for (int j = 0; j < numLetters - 2; j++)
		{

			nameNew[j] = name[j];

		}

		delete[]	name;
					name = nameNew;

		std::cin.get(ch);

	}

	characterObj->setName(name, numLetters);

	delete[] name;
}



//Clones a current monster and adds it to the game
void Game::addMonster(Engine::GameObject* monsterClone)
{

	//Announces the new monster
	std::cout	<< std::endl
				<< "A clone of " 
				<< monsterClone->getName() 
				<< " has been created!" 
				<< std::endl
				<< std::endl;


	//Increases number of monsters
	m_numMonsters++;


	//Resize the array
	Engine::GameObject** tempArr = new Engine::GameObject*[m_numMonsters];

	for (int j = 0; j < m_numMonsters - 1; j++)
	{

		tempArr[j] = new Engine::GameObject(*m_monsters[j]);

	}

	delete[]	m_monsters;
				m_monsters = tempArr;


	//Add the clone to the last position in the array
	m_monsters[m_numMonsters - 1] = new Engine::GameObject(*monsterClone, 10);

}



// Moves and ages monsters
void Game::updateMonsters()
{

	//Age monsters and update position
	for (int i = 0; i < m_numMonsters; i++)
	{

		//If a monster lives, update and display position
		m_monsters[i]->ReduceHealth();

		if (m_monsters[i]->IsAlive())
		{

			m_monsters[i]->Update();

			//Say where it is
			std::cout	<< "Monster "
						<< m_monsters[i]->getName()
						<< " at "
						<< m_monsters[i]->getPosition()
						<< std::endl;

		}


		//If a monster dies, delete it and resize monster array
		else
		{

			//Announce monster death
			std::cout	<< "Monster "
						<< m_monsters[i]->getName()
						<< " has died!"
						<< std::endl;


			//Delete the dead monster
			if (i == m_numMonsters - 1)
			{

				delete m_monsters[m_numMonsters - 1];
				i++;

			}

			else
			{

				delete m_monsters[i];

				m_monsters[i] = new Engine::GameObject(*m_monsters[m_numMonsters - 1]);

				delete m_monsters[m_numMonsters - 1];

			}
			
			m_numMonsters--;


			//Resize the array
			Engine::GameObject** tempArr = new Engine::GameObject*[m_numMonsters];

			for (int j = 0; j < m_numMonsters; j++)
			{

				tempArr[j] = new Engine::GameObject(*m_monsters[j]);

			}

			delete[]	m_monsters;
						m_monsters = tempArr;


			//Iterate over the dead monster's replacement in the array
			i--;
		}
	}
}



//Update player position if needed
void Game::updatePlayer(char& i_input)
{

	m_player->changeDir(i_input);
	m_player->Update();

}



//State player position
void Game::statePlayerLocation() const
{

	std::cout	<< "Player "
				<< m_player->getName()
				<< " at "
				<< m_player->getPosition()
				<< std::endl;

}



//Get user input
void Game::getUserInput(char& o_input) const
{

	std::cout	<< "Press A to move left, D to move right, W to move up, S to move down, or Q to quit" 
				<< std::endl 
				<< std::endl;

	o_input = _getch();

}



// Check for any collisions between Monsters and Players
void Game::checkCollisions()
{

	//Reduce player health if collision detected
	for (int i = 0; i < m_numMonsters; i++)
	{

		//If there's a collision, check if player is dead
		if (Engine::Physics::checkCollision(m_player, m_monsters[i]))
		{

			//If player is now dead, announce death
			if (!m_player->IsAlive())
			{

				std::cout	<< std::endl
							<< "Monster "
							<< m_monsters[i]->getName()
							<< " killed Player "
							<< m_player->getName()
							<< std::endl;

			}
		}
	}
}