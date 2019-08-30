#include <iostream>
#include <conio.h>
#include "Game.h"
#include "Monster.h"
#include "Player.h"

Game::Game(int numMonsters, int rows, int columns)
{
	/*
	//Record the rows and columns
	m_rows = rows;
	m_columns = columns;

	//Set up a 2D array of the correct size
	m_field = new int*[rows];
	for (int i = 0; i < rows; i++)
		m_field[i] = new int[columns];
	*/


	m_numMonsters = numMonsters;
	m_monsters = new Monster* [numMonsters];

	m_player = new Player();

}

Game::~Game()
{
	for (int i = 0; i < m_rows; i++)
		delete[] m_field[i];
	delete[] m_field;

	for (int i = 0; i < m_numMonsters; i++)
		delete m_monsters[i];
	delete[] m_monsters;

	delete m_player;
}

void Game::play()
{
	for (int i = 0; i < m_numMonsters; i++)
	{
		m_monsters[i] = new Monster();
		std::cout << "What would you like to name Monster " << i << ": ";
		m_monsters[i]->setName();
	}
	std::cout << "What would you like to name the Player: ";
	m_player->setName();

	char input = 'c';
	while (input != 'q' && m_player->isAlive())
	{
		for (int i = 0; i < m_numMonsters; i++)
		{
			if (m_monsters[i]->isOlderAndLived())
			{
				m_monsters[i]->move();
				std::cout << "Monster ";
				m_monsters[i]->printName();
				std::cout << " at [" << m_monsters[i]->row() << ", " << m_monsters[i]->column() << "]" << std::endl;
			}
			else
			{
				delete m_monsters[i];
				//m_monsters[i] = m_monsters[m_numMonsters - 1];
			}
				
		}
		std::cout << "Player ";
		m_player->printName();
		std::cout << " at [" << m_player->row() << ", " << m_player->column() << "]" << std::endl;

		std::cout << "Press A to move left, D to move right, W to move up, S to move down, or Q to quit" << std::endl;
		input = _getch();
		m_player->move(input);

		for (int i = 0; i < m_numMonsters; i++)
			checkCollision(m_player, m_monsters[i]);
	}
}

void Game::checkCollision(Player* player, Monster* monster)
{
	if (player->column() == monster->column() && player->row() == monster->row())
		player->loseHealth();
}
