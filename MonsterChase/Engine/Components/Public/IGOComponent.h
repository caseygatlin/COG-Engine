#pragma once
#include "ComponentType.h"
#include "../../Containers/Public/Pointers.h"


namespace Engine
{
	class GameObject;

	// Component Interface class
	class IGOComponent
	{
	public:

		// Virtual destructor
		virtual ~IGOComponent() {}

		// Executes on attachment to the given GameObject
		virtual void OnAttach(GameObject* i_gameObject) = 0;

		// Executes every tick
		virtual	void Update(GameObject* i_gameObject, const float& i_dt) = 0;

		// Checks ComponentType
		virtual	bool IsComponentType(const ComponentType& i_componentType)	const = 0;

		// Returns ComponentType
		virtual ComponentType GetComponentType() const = 0;

	};

	// Template function for creating new components for attachment
	template<class T>
	SmartPtr<IGOComponent> CreateComponent()
	{
		SmartPtr<IGOComponent> component(new T());
		return component;
	}
}

