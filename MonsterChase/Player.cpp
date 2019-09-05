#include "Player.h"
#include <iostream>

//Constructor, sets health and position
Player::Player()
{
	m_health = 1;
	m_row = 0;
	m_column = 0;
	m_name = nullptr;
}

//Destructor
Player::~Player()
{
	delete[] m_name;
}

//Returns player's row
int Player::row() const
{
	return m_row;
}

//Returns player's column
int Player::column() const
{
	return m_column;
}

//Returns player state
bool Player::isAlive() const
{
	return m_health > 0;
}

//Sets user-defined name
void Player::setName()
{
	//Defines an empty name in case of no user input
	int numLetters = 1;
	m_name = new char[numLetters];
	m_name[0] = '\0';

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
			nameNew[j] = m_name[j];
		}
		delete[] m_name;
		m_name = nameNew;
		std::cin.get(ch);
	}
}

//Prints the name of the player, letter by letter
void Player::printName() const
{
	int k = 0;
	while (m_name[k] != '\0')
	{
		std::cout << m_name[k];
		k++;
	}
}

//Moves the character in a direction passed to it
void Player::move(char dir)
{
	switch (dir)
	{
	case 'w':
		m_row++;
		break;
	case 'a':
		m_column--;
		break;
	case 's':
		m_row--;
		break;
	case 'd':
		m_column++;
		break;
	default:
		break;
	}

}

//Reduces player health by 1
void Player::loseHealth()
{
	m_health--;
}