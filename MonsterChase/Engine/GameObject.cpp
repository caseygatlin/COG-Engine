#include "GameObject.h"
#include "Point2D.h"
#include "IGOComponent.h"
#include "ComponentType.h"
#include "UserInputMovement.h"
#include "FollowPlayerMovement.h"
#include <stdlib.h>
#include <vector>


namespace Engine
{
	// Assignment Operator
	GameObject& GameObject::operator=(const GameObject& i_src)
	{
		//Check for aliasing
		if (&i_src == this)
			return (*this);

		//Destruct current character
		delete[] m_name;
		while (!m_components.empty())
		{
			free(static_cast<void*>(m_components[m_components.size() - 1]));
			m_components.erase(m_components.end());
		}

		//Copy over src character non-pointer vars
		m_position = i_src.m_position;
		m_health = i_src.m_health;
		m_dir = i_src.m_dir;
		m_nameLength = i_src.m_nameLength;

		//Copy over name
		if (m_nameLength != 0)
		{
			m_name = new char[m_nameLength];
			for (int i = 0; i < m_nameLength; i++)
				m_name[i] = i_src.m_name[i];
		}
		else
		{
			m_name = nullptr;
		}

		//Copy over components
		if (!i_src.m_components.empty())
		{
			for (int i = 0; i < i_src.m_components.size(); i++)
			{
				ComponentType compType = i_src.m_components[i]->GetComponentType();
				IGOComponent* compToAdd;


				switch (compType)
				{
				case USER_INPUT_MOVEMENT:
					compToAdd = static_cast<IGOComponent*>(malloc(sizeof(UserInputMovement)));
					break;
				case FOLLOW_PLAYER_MOVEMENT:
					compToAdd = static_cast<IGOComponent*>(malloc(sizeof(FollowPlayerMovement)));
					break;
				default:
					compToAdd = nullptr;
					break;
				}

				if (compToAdd)
				{
					*compToAdd = *(i_src.m_components[i]);
					m_components.push_back(compToAdd);
				}
			}
		}


		return (*this);
	}

	// Destructor
	GameObject::~GameObject()
	{
		delete[] m_name;

		for (int i = 0; i < m_components.size(); i++)
		{
			free(static_cast<void*>(m_components[i]));
		}

	}

	GameObject::GameObject(const GameObject& i_src, int i_health)
	{
		//Copy over src character non-pointer vars
		m_position = i_src.m_position;
		m_dir = i_src.m_dir;
		m_nameLength = i_src.m_nameLength;
		
		// Change health if specified
		if (i_health == -1)
		{
			m_health = i_src.m_health;
		}
		else
		{
			m_health = i_health;
		}

		//Copy over name
		if (m_nameLength != 0)
		{
			m_name = new char[m_nameLength];
			for (int i = 0; i < m_nameLength; i++)
				m_name[i] = i_src.m_name[i];
		}
		else
		{
			m_name = nullptr;
		}

		//Copy over components
		if (!(i_src.m_components.empty()))
		{
			for (int i = 0; i < i_src.m_components.size(); i++)
			{
				ComponentType compType = i_src.m_components[i]->GetComponentType();
				IGOComponent* compToAdd;


				switch (compType)
				{
				case USER_INPUT_MOVEMENT:
					compToAdd = static_cast<IGOComponent*>(malloc(sizeof(UserInputMovement)));
					break;
				case FOLLOW_PLAYER_MOVEMENT:
					compToAdd = static_cast<IGOComponent*>(malloc(sizeof(FollowPlayerMovement)));
					break;
				default:
					compToAdd = nullptr;
					break;
				}

				if (compToAdd)
				{
					*compToAdd = *(i_src.m_components[i]);
					m_components.push_back(compToAdd);
				}
			}
		}
	}


	// Sets the name of the GameObject
	void GameObject::setName(char* i_name, int i_length)
	{
		delete m_name;
		m_name = new char[i_length];
		m_nameLength = i_length;

		for (int i = 0; i < i_length; i++)
		{
			m_name[i] = i_name[i];
		}
	}

	// Updates each component
	void GameObject::Update()
	{
		for (int i = 0; i < m_components.size(); i++)
		{
			m_components[i]->Update(*this);
		}
	}
}