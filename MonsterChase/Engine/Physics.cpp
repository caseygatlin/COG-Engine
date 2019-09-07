#include "Physics.h"
#include "Character.h"

namespace Engine
{
	//Namespace for all classes and methods related to physics
	namespace Physics
	{
		//Checks the collision of a player and an enemy
		//Player loses health if there is a collision
		bool checkCollision(Character* player, Character* enemy)
		{
			if (player->getPosition() == enemy->getPosition())
			{
				player->loseHealth();
				return true;
			}
			return false;
		}
	}
	
}