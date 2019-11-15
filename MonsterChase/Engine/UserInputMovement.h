#pragma once

#include "IGOComponent.h"
#include "GameObject.h"
#include "ComponentType.h"


namespace Engine
{

	class UserInputMovement : public IGOComponent
	{
	public:
		UserInputMovement() {};

		void Update(GameObject& i_gameObject);
		inline ComponentType GetComponentType() const;

	};
}

#include "UserInputMovement-inl.h"