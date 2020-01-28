#pragma once

#include "IGOComponent.h"
#include "ComponentType.h"
#include "../../GameObject/Public/GameObject.h"


namespace Engine
{

	// Component that implements 10% chance of GameObject death
	class RandomDeath : public IGOComponent 
	{
	public:

		void					Update(GameObject& i_gameObject);
		inline	ComponentType	GetComponentType()		const;
		const	void*			GetMemberVariables()	const { return nullptr; }

	};
}

#include "RandomDeath-inl.h"