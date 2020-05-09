#include "../Public/GameObject.h"
#include "../../Containers/Public/Point2D.h"
#include "../../Components/Public/IGOComponent.h"
#include "../../Components/Public/ComponentType.h"
#include <stdlib.h>
#include <vector>


namespace Engine
{
	// Assignment Operator
	GameObject& GameObject::operator=(const GameObject& i_src)
	{

		//Check for aliasing
		if (&i_src != this)
		{
			//Destruct current character
			m_Components.clear();

			//Copy over src character non-pointer vars
			m_Position = i_src.m_Position;
			m_Dir = i_src.m_Dir;

			m_Components = i_src.m_Components;

		}

		return (*this);

	}

	// Equality operator
	bool GameObject::operator==(const GameObject& i_rhs)
	{

		bool positionEqual = m_Position == i_rhs.m_Position;
		bool velocityEqual = m_Velocity == i_rhs.m_Velocity;
		bool directionEqual = m_Dir == i_rhs.m_Dir;

		bool componentsEqual = true;
		size_t thisComponentsSize = m_Components.size();
		size_t rhsComponentsSize = i_rhs.m_Components.size();

		if (thisComponentsSize == rhsComponentsSize)
		{

			for (size_t i = 0; i < thisComponentsSize; i++)
			{

				if (GetComponentType(i) != i_rhs.GetComponentType(i))
				{

					componentsEqual = false;

				}
			}
		}

		else
		{

			componentsEqual = false;

		}

		return (positionEqual && velocityEqual && directionEqual && componentsEqual);

	}

	// Inequality operator
	bool GameObject::operator!=(const GameObject& i_rhs)
	{

		bool positionEqual = m_Position == i_rhs.m_Position;
		bool velocityEqual = m_Velocity == i_rhs.m_Velocity;
		bool directionEqual = m_Dir == i_rhs.m_Dir;

		bool componentsEqual = true;
		size_t thisComponentsSize = m_Components.size();
		size_t rhsComponentsSize = i_rhs.m_Components.size();

		if (thisComponentsSize == rhsComponentsSize)
		{

			for (size_t i = 0; i < thisComponentsSize; i++)
			{

				if (GetComponentType(i) != i_rhs.GetComponentType(i))
				{

					componentsEqual = false;

				}
			}
		}

		else
		{

			componentsEqual = false;

		}

		return (!positionEqual || !velocityEqual || !directionEqual || !componentsEqual);

	}


	// Destructor
	GameObject::~GameObject()
	{
		
		m_Components.clear();

	}


	// Updates each component
	void GameObject::Update(const float& i_dt)
	{

		for (WeakPtr<IGOComponent> component : m_Components)
		{

			component.Acquire()->Update(this, i_dt);

		}
	}
}