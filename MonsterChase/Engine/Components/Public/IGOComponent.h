#pragma once
#include "../../GameObject/Public/GameObject.h"
#include "ComponentType.h"
#include "../../Containers/Public/Pointers.h"


namespace Engine
{
	template<class T>
	SmartPtr<IGOComponent> CreateComponent(T)
	{
		SmartPtr<IGOComponent> component(new T);
		return component;
	}

	class IGOComponent
	{
	public:

		virtual		void			Update(GameObject& i_gameObject)	= 0;
		virtual		ComponentType	GetComponentType()		const		= 0;

	};
}

