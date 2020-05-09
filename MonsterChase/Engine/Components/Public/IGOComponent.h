#pragma once
#include "ComponentType.h"
#include "../../Containers/Public/Pointers.h"


namespace Engine
{
	class GameObject;

	class IGOComponent
	{
	public:

		virtual ~IGOComponent() {}
		virtual void OnAttach(GameObject* i_gameObject) = 0;
		virtual	void Update(GameObject* i_gameObject, const float& i_dt) = 0;
		virtual	bool IsComponentType(const ComponentType& i_componentType)	const = 0;
		virtual ComponentType GetComponentType() const = 0;

	};

	template<class T>
	SmartPtr<IGOComponent> CreateComponent()
	{
		SmartPtr<IGOComponent> component(new T());
		return component;
	}
}

