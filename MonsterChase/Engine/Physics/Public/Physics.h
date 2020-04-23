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


		//Takes away player health and returns true if collided
		//false otherwise
        void Init();

        void Update(float i_dt);
	}
}

#endif // !PHYSICS_H

