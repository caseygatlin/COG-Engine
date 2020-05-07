#include "../Public/Physics.h"
#include "../../GameObject/Public/GameObject.h"
#include "../Public/PhysicsInfo.h"
#include "../../Public/Engine.h"
#include "../../Containers/Public/Point2D.h"
#include "../../World/Public/World.h"
#include "../../Containers/Public/Pointers.h"
#include "../Collision/Public/Collision.h"
#include "GLib.h"
#include <vector>

namespace Engine
{

	//Namespace for all classes and methods related to physics
	namespace Physics
	{

        void AddPhysicsInfo(const PhysicsInfo& i_physicsInfo)
        {
            physicsInfo.push_back(i_physicsInfo);
        }

        void Update(float i_dt)
        {
            for (int i = 0; i < physicsInfo.size(); i++)
            {
                physicsInfo.at(i).Update(i_dt);
            }

            WeakPtr<Collideable> collideable_1;
            WeakPtr<Collideable> collideable_2;

            if (FindCollision(i_dt, collideable_1, collideable_2))
            {

                collideable_1.Acquire()->ExecuteCallback();
                collideable_2.Acquire()->ExecuteCallback();

            }
        }
	}
	
}