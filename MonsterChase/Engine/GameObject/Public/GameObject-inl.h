#pragma once
#include "GameObject.h"
#include "../../Containers/Public/Point2D.h"
#include "../../Components/Public/ComponentType.h"
#include "../../Containers/Public/Pointers.h"


namespace Engine
{
	//Returns current position
	inline Point2D GameObject::GetPosition() const
	{

		return m_Position;

	}

	// Returns current direction
	inline Point2D GameObject::GetDir() const
	{

		return m_Dir;

	}

    inline Point2D GameObject::GetVelocity() const
    {

        return m_Velocity;

    }

	// Changes the current direction of the object
	inline void GameObject::ChangeDir(const Point2D& i_dir)
	{

		m_Dir = i_dir;

	}

	// Adds a given point to current location
	inline void GameObject::ChangePosition(const Point2D& i_addPoint)
	{

		m_Position += i_addPoint;

	}

	inline void GameObject::SetPosition(const Point2D& i_position)
	{

		m_Position = i_position;

	}

	// Attaches a component
	inline void GameObject::Attach(SmartPtr<IGOComponent> i_component)
	{
		i_component->OnAttach(this);
		m_Components.push_back(i_component);

	}

	inline bool GameObject::HasComponent(const ComponentType& i_componentType) const
	{

		for (WeakPtr<IGOComponent> component : m_Components)
		{
			if (component.Acquire()->IsComponentType(i_componentType))
			{
				return true;
			}
		}

		return false;

	}

	inline bool GameObject::GetComponent(const ComponentType& i_componentType, WeakPtr<IGOComponent>& o_component) const
	{
		for (WeakPtr<IGOComponent> component : m_Components)
		{
			if (component.Acquire()->IsComponentType(i_componentType))
			{
				o_component = component;
				return true;
			}
		}

		return false;
	}

    inline void GameObject::SetVelocity(Point2D i_velocity)
    {

        m_Velocity = i_velocity;

    }

	

}