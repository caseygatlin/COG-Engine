#pragma once

#include "IGOComponent.h"
#include "GameObject.h"
#include "ComponentType.h"


namespace Engine
{

	// Component for moving from input given by the user
	class UserInputMovement : public IGOComponent
	{
	public:
		UserInputMovement() {};

				void			Update(GameObject& i_gameObject);
		inline	ComponentType	GetComponentType()		const;
				const void*		GetMemberVariables()	const { return nullptr; }

	};
}

#include "UserInputMovement-inl.h"