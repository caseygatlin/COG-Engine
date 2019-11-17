#pragma once
#include "GameObject.h"
#include "ComponentType.h"


namespace Engine
{
	

	class IGOComponent
	{
	public:

		virtual void Update(GameObject& i_gameObject) = 0;
		virtual ComponentType GetComponentType() const = 0;
		virtual const void* GetMemberVariables() const = 0;

	};
}

