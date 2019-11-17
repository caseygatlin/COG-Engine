#include <stdlib.h>					//rand
#include "RandomDeath.h"
#include "GameObject.h"

namespace Engine
{

	// The GameObject has a 10% chance of dying
	void RandomDeath::Update(GameObject& i_gameObject)
	{
		int deathNum = std::rand() % 10;

		switch(deathNum)
		{

		case 0:
			while (i_gameObject.IsAlive())
			{
				i_gameObject.ReduceHealth();
			}
			break;

		default:
			break;

		}


	}

}