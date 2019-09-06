#include "Player.h"
#include <iostream>



//Destructor
Player::~Player()
{
	delete[] m_name;
}

//Returns player state
bool Player::isAlive() const
{
	return m_health > 0;
}

//Sets user-defined name
void Player::setName(char* name)
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

/*
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
*/

//Moves the character in a direction passed to it
void Player::move(char dir)
{
	switch (dir)
	{
	case 'w':
		setY(getPosition().getY() + 1);
		break;
	case 'a':
		setX(getPosition().getX() - 1);
		break;
	case 's':
		setY(getPosition().getY() - 1);
		break;
	case 'd':
		setX(getPosition().getX() + 1);
		break;
	default:
		break;
	}

}

//Reduces player health by 1
void Player::takeDamage()
{
	m_health--;
}