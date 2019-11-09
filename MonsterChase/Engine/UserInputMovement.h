#pragma once

#include "IGOComponent.h"
#include "GameObject.h"



namespace Engine
{

	class UserInputMovement : public IGOComponent
	{
	public:
		UserInputMovement() {};

		void Update(GameObject& i_gameObject);

	};
}