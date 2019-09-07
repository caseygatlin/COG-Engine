#include "GameObject.h"
#include "Character.h"

namespace Engine
{
	//Assignment operator
	Character& Character::operator=(const Character& src)
	{
		//Check for aliasing
		if (&src == this)
			return (*this);
		
		//Destruct current character
		if (m_name != nullptr)
			delete[] m_name;

		//Copy over src character
		m_position = src.m_position;
		m_health = src.m_health;
		m_nameLength = src.m_nameLength;

		if (m_nameLength != 0)
		{
			m_name = new char[m_nameLength];
			for (int i = 0; i < m_nameLength; i++)
				m_name[i] = src.m_name[i];
		}
		else
			m_name = nullptr;
		
		return (*this);
	}

	//Destructor
	Character::~Character()
	{
		if (m_name != nullptr)
			delete[] m_name;
	}

	//Returns name
	char* Character::getName() const
	{
		return m_name;
	}

	//Sets name to a given name
	void Character::setName(char* name, int length)
	{
		m_name = new char[length];
		m_nameLength = length;

		for (int i = 0; i < length; i++)
			m_name[i] = name[i];
	}

	//Moves a number of spaces in both directions
	void Character::moveNumSpaces(int numSpaces)
	{
		m_position += Point2D(numSpaces, numSpaces);
	}

	//Moves one space in a given direction
	void Character::moveDir(char dir)
	{
		switch (dir)
		{
		case 'w':
			m_position = Point2D(m_position.X(), m_position.Y() + 1);
			break;
		case 'a':
			m_position = Point2D(m_position.X() - 1, m_position.Y());
			break;
		case 's':
			m_position = Point2D(m_position.X(), m_position.Y() - 1);
			break;
		case 'd':
			m_position = Point2D(m_position.X() + 1, m_position.Y());
			break;
		default:
			break;
		}
	}

	//Loses 1 health
	void Character::loseHealth()
	{
		m_health--;
	}

	//Checks if character is alive
	bool Character::isAlive()
	{
		return (m_health > 0);
	}
}