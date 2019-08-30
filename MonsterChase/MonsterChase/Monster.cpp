#include <iostream>
#include <stdlib.h>
#include "Monster.h"

Monster::Monster()
{
	m_lifetime = 10;
	m_row = std::rand() % 200 - 99;
	m_column = std::rand() % 200 - 99;
	m_name = nullptr;
}

Monster::~Monster()
{
	delete[] m_name;
}

int Monster::row() const
{
	return m_row;
}

int Monster::column() const
{
	return m_column;
}

bool Monster::isOlderAndLived()
{
	m_lifetime--;
	if (m_lifetime <= 0)
		return false;
	return true;
}


void Monster::setName()
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

void Monster::printName() const
{
	int k = 0;
	while (m_name[k] != '\0')
	{
		std::cout << m_name[k];
		k++;
	}
}

void Monster::move()
{
	m_row--;
	m_column--;
}