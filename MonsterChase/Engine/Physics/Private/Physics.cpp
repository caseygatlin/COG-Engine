#include "../Public/Physics.h"
#include "../../GameObject/Public/GameObject.h"

namespace Engine
{

	//Namespace for all classes and methods related to physics
	namespace Physics
	{

		//Checks the collision of a player and an enemy
		//Player loses health if there is a collision
		bool checkCollision(GameObject* player, GameObject* enemy)
		{

			if (player->getPosition() == enemy->getPosition())
			{

				player->ReduceHealth();
				return true;

			}

			return false;
		}
	}
	
}