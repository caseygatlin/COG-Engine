#include <iostream>
#include <conio.h>
#include "Game.h"
#include "Monster.h"
#include "Player.h"

//Constructor
Game::Game(int numMonsters)
{
	m_numMonsters = numMonsters;
	m_monsters = new Monster* [numMonsters];

	m_player = new Player();
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
	//Set the names for monsters and player
	for (int i = 0; i < m_numMonsters; i++)
	{
		m_monsters[i] = new Monster();
		std::cout << "What would you like to name Monster " << i << ": ";
		m_monsters[i]->setName();
	}
	std::cout << "What would you like to name the Player: ";
	//m_player->setName();


	//Main game loop
	char input = 'c';
	int turnNumber = 1;
	while (input != 'q' && m_player->isAlive())
	{
		//Age monsters and update position
		for (int i = 0; i < m_numMonsters; i++)
		{
			//If a monster lives, update and display position
			if (m_monsters[i]->isOlderAndLived())
			{
				m_monsters[i]->move();
				std::cout << "Monster ";
				m_monsters[i]->printName();
				std::cout << " at [" << m_monsters[i]->row() << ", " << m_monsters[i]->column() << "]" << std::endl;
			}

			//If a monster dies, delete it and resize monster array
			else
			{
				//Announce monster death
				std::cout << "Monster ";
				m_monsters[i]->printName();
				std::cout << " has died!" << std::endl;

				//Delete the dead monster
				*m_monsters[i] = *m_monsters[m_numMonsters - 1];
				delete m_monsters[m_numMonsters - 1];
				m_numMonsters--;

				//Resize the array
				Monster** tempArr = new Monster*[m_numMonsters];
				for (int j = 0; j < m_numMonsters; j++)
					tempArr[j] = new Monster(*m_monsters[j]);
				delete[] m_monsters;
				m_monsters = tempArr;

				//Move the monster that took its place and state their position
				//As long as it's in the array
				if (i < m_numMonsters)
				{
					m_monsters[i]->move();
					std::cout << "Monster ";
					m_monsters[i]->printName();
					std::cout << " at [" << m_monsters[i]->row() << ", " << m_monsters[i]->column() << "]" << std::endl;
				}
			}
				
		}

		//State player position
		std::cout << "Player ";
		//m_player->printName();
		//std::cout << " at [" << m_player->row() << ", " << m_player->column() << "]" << std::endl;

		//Get user input and update player position if needed
		std::cout << "Press A to move left, D to move right, W to move up, S to move down, or Q to quit" << std::endl;
		input = _getch();
		m_player->move(input);
		std::cout << std::endl;

		//Reduce player health if touching monster
		for (int i = 0; i < m_numMonsters; i++)
			checkCollision(m_player, m_monsters[i]);

		if (m_player->isAlive())
			if (turnNumber % 5 == 0 || m_numMonsters <= 3 )
				addMonster(m_monsters[turnNumber % m_numMonsters]);
		turnNumber++;
	}

	std::cout << "You played " << turnNumber << " turns." << std::endl;
}



//Player loses health if a monster is on the same spot
void Game::checkCollision(Player* player, Monster* monster)
{
	/*
	if (player->column() == monster->column() && player->row() == monster->row())
	{
		player->loseHealth();
		
		//If the player is dead, announce the death
		if (!player->isAlive())
		{
			std::cout << std::endl;
			std::cout << "Monster ";
			monster->printName();
			std::cout << " killed Player ";
			player->printName();
			std::cout << std::endl;
		}
			
	}
	*/
		
}



//Clones a monster already in existence and moves them slightly away
void Game::addMonster(Monster* clone)
{
	//Announces a new monster
	std::cout << std::endl;
	std::cout << "A clone of ";
	clone->printName();
	std::cout << " has been created!" << std::endl;
	std::cout << std::endl;



	//Increases number of monsters
	m_numMonsters++;

	//Resize the array
	Monster** tempArr = new Monster*[m_numMonsters];
	for (int j = 0; j < m_numMonsters - 1; j++)
		tempArr[j] = new Monster(*m_monsters[j]);
	delete[] m_monsters;
	m_monsters = tempArr;

	//Add the clone to the last position in the array
	m_monsters[m_numMonsters - 1] = new Monster(*clone, 10);
	m_monsters[m_numMonsters - 1]->move();
}

