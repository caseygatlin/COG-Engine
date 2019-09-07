#ifndef PHYSICS_H
#define PHYSICS_H



namespace Engine
{
	class Character; //for Character*

	//Namespace for all classes and methods related to physics
	namespace Physics
	{
		//Takes away player health and returns true if collided
		//false otherwise
		bool checkCollision(Character* player, Character* enemy);
	
	}
}

#endif // !PHYSICS_H

