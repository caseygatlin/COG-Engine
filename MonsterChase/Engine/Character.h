#ifndef CHARACTER_H
#define CHARACTER_H

#include "GameObject.h"
#include "Point2D.h"


namespace Engine
{
	//Class for GameObjects with names, health, and movement
	class Character : public GameObject
	{
	public:
		//Default constructor
		Character() : GameObject()
		{
			m_health = 1;
			m_nameLength = 0;
			m_name = nullptr;
		}

		//Constructor given a position and health
		explicit Character(Point2D position, int health = 1) : GameObject(position)
		{
			m_health = health;
			m_nameLength = 0;
			m_name = nullptr;
		}

		//Copy constructor with option to change health
		Character(const Character& src, int health = -1) : GameObject(src.getPosition())
		{
			if (health != -1)
				m_health = health;
			else
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
		}

		//Assignment operator
		Character& operator=(const Character& src);

		//Destructor
		~Character();

		//Accessors
		char* getName() const;

		//Modifiers
		void setName(char* name, int length);
		void moveNumSpaces(int numSpaces);
		void moveDir(char dir);
		void loseHealth();
		bool isAlive();

	private:
		int m_health;
		int m_nameLength;
		char* m_name;

	};
}

#endif
