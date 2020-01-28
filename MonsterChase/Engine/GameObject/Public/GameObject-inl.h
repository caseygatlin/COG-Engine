#pragma once
#include "GameObject.h"
#include "../../Containers/Public/Point2D.h"


namespace Engine
{
	//Returns current position
	inline Point2D GameObject::getPosition() const
	{
		return m_position;
	}

	// Returns current direction
	inline char GameObject::getDir() const
	{
		return m_dir;
	}

	//Returns name
	inline char* GameObject::getName() const
	{
		return m_name;
	}

	// Check if health is zero
	inline bool GameObject::IsAlive() const
	{
		return (m_health > 0);
	}

    inline Point2D GameObject::getVelocity() const
    {
        return m_velocity;
    }

	// Changes the current direction of the object
	inline void GameObject::changeDir(char& i_dir)
	{
		m_dir = i_dir;
	}

	// Adds a given point to current location
	inline void GameObject::changePosition(const Point2D& i_addPoint)
	{
		m_position += i_addPoint;
	}

	// Attaches a component
	inline void GameObject::Attach(IGOComponent* i_component)
	{
		m_components.push_back(i_component);
	}

	// Reduces health
	inline void GameObject::ReduceHealth()
	{
		m_health--;
	}

    inline void GameObject::SetVelocity(Point2D i_velocity)
    {
        m_velocity = i_velocity;
    }

	

}