#include "Player.h"
#include <iostream>

Player::Player()
{
	m_health = 1;
	m_row = 0;
	m_column = 0;
	m_name = nullptr;
}

Player::~Player()
{
	delete[] m_name;
}

int Player::row() const
{
	return m_row;
}

int Player::column() const
{
	return m_column;
}

bool Player::isAlive() const
{
	return m_health > 0;
}

void Player::setName()
{
	int numLetters = 1;
	m_name = new char[1];
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

void Player::printName() const
{
	int k = 0;
	while (m_name[k] != '\0')
	{
		std::cout << m_name[k];
		k++;
	}
}

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

void Player::loseHealth()
{
	m_health--;
}