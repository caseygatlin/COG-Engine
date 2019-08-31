#include <iostream>
#include <stdlib.h>
#include "Monster.h"

//Constructor, randomizes position and life
Monster::Monster()
{
	m_lifetime = std::rand() % 10 + 4;
	m_row = std::rand() % 200 - 99;
	m_column = std::rand() % 200 - 99;
	m_name = nullptr;
	m_nameLength = 0;
}

//Copy constructor with option to add new lifetime
Monster::Monster(const Monster& src, int lifetime)
{
	if (lifetime != 0)
		m_lifetime = std::rand() % lifetime + 4;
	else
		m_lifetime = src.m_lifetime;

	m_column = src.m_column;
	m_row = src.m_row;
	m_nameLength = src.m_nameLength;
	m_name = new char[m_nameLength];
	for (int i = 0; i < m_nameLength; i++)
		m_name[i] = src.m_name[i];
}

//Assignment operator
Monster& Monster::operator=(const Monster& src)
{
	if (&src == this)
		return (*this);

	delete[] m_name;

	m_column = src.m_column;
	m_row = src.m_row;
	m_lifetime = src.m_lifetime;
	m_nameLength = src.m_nameLength;
	m_name = new char[m_nameLength];
	for (int i = 0; i < m_nameLength; i++)
		m_name[i] = src.m_name[i];
}

//Destructor
Monster::~Monster()
{
	delete[] m_name;
}

//Returns current row
int Monster::row() const
{
	return m_row;
}

//Returns current column
int Monster::column() const
{
	return m_column;
}

//Reduces lifetime, returns true if still alive
//false if dead
bool Monster::isOlderAndLived()
{
	m_lifetime--;
	if (m_lifetime <= 0)
		return false;
	return true;
}


//Sets user-defined name
void Monster::setName()
{
	//Defines an empty name in case of no user input
	m_nameLength = 1;
	m_name = new char[m_nameLength];
	m_name[0] = '\0';
	
	//Gets user input and resizes accordingly
	char ch;
	std::cin >> ch;
	while (ch != '\n')
	{
		m_nameLength++;
		char* nameNew = new char[m_nameLength];
		nameNew[m_nameLength - 1] = '\0';
		nameNew[m_nameLength - 2] = ch;
		for (int j = 0; j < m_nameLength - 2; j++)
		{
			nameNew[j] = m_name[j];
		}
		delete[] m_name;
		m_name = nameNew;
		std::cin.get(ch);
	}
}

//Prints the name of the monster, letter by letter
void Monster::printName() const
{
	int k = 0;
	while (m_name[k] != '\0')
	{
		std::cout << m_name[k];
		k++;
	}
}

//Moves the monster a random amount
void Monster::move()
{
	m_row += std::rand() % 11 - 5;
	m_column += std::rand() % 11 - 5;
}