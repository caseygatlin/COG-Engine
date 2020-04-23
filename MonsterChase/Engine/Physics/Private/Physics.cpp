#include "../Public/Physics.h"
#include "../../GameObject/Public/GameObject.h"
#include "../Public/PhysicsInfo.h"
#include "../../Public/Engine.h"
#include "../../Containers/Public/Point2D.h"
#include "../../World/Public/World.h"
#include "../../Containers/Public/Pointers.h"
#include "GLib.h"
#include <vector>

namespace Engine
{

	//Namespace for all classes and methods related to physics
	namespace Physics
	{
        void Init()
        {
            PhysicsInfo pi1(World::GetGameObject(0), 10.0F, 1.25F);
            PhysicsInfo pi2(World::GetGameObject(1), 2.0F, 2.0F);

            physicsInfo.push_back(pi1);
            physicsInfo.push_back(pi2);
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