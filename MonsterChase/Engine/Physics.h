#ifndef PHYSICS_H
#define PHYSICS_H



namespace Engine
{

	class GameObject;

	//Namespace for all classes and methods related to physics
	namespace Physics
	{

		//Takes away player health and returns true if collided
		//false otherwise
		bool checkCollision(GameObject* player, GameObject* enemy);
	
	}
}

#endif // !PHYSICS_H

