#include "../Public/Physics.h"
#include "../../GameObject/Public/GameObject.h"
#include "../Public/PhysicsInfo.h"
#include "../../Public/Engine.h"
#include "../../Containers/Public/Point2D.h"
#include "GLib.h"
#include <vector>

namespace Engine
{

	//Namespace for all classes and methods related to physics
	namespace Physics
	{
        void Init()
        {
            for (int i = 0; i < GetNumGameObjects(); i++)
            {
                PhysicsInfo pi1;
                PhysicsInfo pi2;

                pi1.Init(GetGameObject(0), 1.0F, 1.0F);
                pi2.Init(GetGameObject(1), 2.0F, 2.0F);

                physicsInfo.push_back(pi1);
                physicsInfo.push_back(pi2);
            }
        }

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

        void Update(float i_dt)
        {
            for (int i = 0; i < physicsInfo.size(); i++)
            {
                physicsInfo.at(i).Update(i_dt);
            }
        }
	}
	
}