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


	// Destructor
	GameObject::~GameObject()
	{
		
		m_Components.clear();

	}


	// Updates each component
	void GameObject::Update()
	{

		for (WeakPtr<IGOComponent> component : m_Components)
		{

			component.Acquire()->Update(this);

		}
	}
}