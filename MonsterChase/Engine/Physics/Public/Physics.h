#ifndef PHYSICS_H
#define PHYSICS_H

#include "PhysicsInfo.h"
#include <vector>


namespace Engine
{

	class GameObject;

	//Namespace for all classes and methods related to physics
	namespace Physics
	{
        static std::vector<PhysicsInfo> physicsInfo;

		void AddPhysicsInfo(const PhysicsInfo& i_physicsInfo);

        void Update(float i_dt);
	}
}

#endif // !PHYSICS_H

