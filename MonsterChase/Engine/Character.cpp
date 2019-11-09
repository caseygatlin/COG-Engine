#include "GameObject.h"
#include "Character.h"

namespace Engine
{
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