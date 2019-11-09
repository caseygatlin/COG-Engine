#include "GameObject.h"
#include "Point2D.h"
#include "IGOComponent.h"


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
		for (int i = 0; i < m_numComponents; i++)
		{
			delete m_components[i];
		}
		delete[] m_components;

		//Copy over src character
		m_position = i_src.m_position;
		m_numComponents = i_src.m_numComponents;
		m_dir = i_src.m_dir;
		m_nameLength = i_src.m_nameLength;

		if (m_nameLength != 0)
		{
			m_name = new char[m_nameLength];
			for (int i = 0; i < m_nameLength; i++)
				m_name[i] = i_src.m_name[i];
		}
		else
			m_name = nullptr;

		if (m_numComponents != 0)
		{
			m_components = new IGOComponent*[m_numComponents];
			for (int i = 0; i < m_numComponents; i++)
			{
				m_components[i] = i_src.m_components[i]; //TODO: Account for assigning of components
			}
		}
		else
			m_components = nullptr;


		return (*this);
	}

	// Destructor
	GameObject::~GameObject()
	{
		delete[] m_name;

		for (int i = 0; i < m_numComponents; i++)
		{
			delete m_components[i];
		}

		delete[] m_components;
	}


	//Returns current position
	Point2D GameObject::getPosition() const
	{
		return m_position;
	}

	// Returns current direction
	char GameObject::getDir() const
	{
		return m_dir;
	}

	//Returns name
	char* GameObject::getName() const
	{
		return m_name;
	}

	// Sets the name of the GameObject
	void GameObject::setName(char* i_name, int i_length)
	{
		delete m_name;
		m_name = new char[i_length];
		m_nameLength = i_length;

		for (int i = 0; i < i_length; i++)
			m_name[i] = i_name[i];
	}


	// Changes the current direction of the object
	void GameObject::changeDir(char& i_dir)
	{
		m_dir = i_dir;
	}

	// Adds a given point to current location
	void GameObject::changePosition(const Point2D& i_addPoint)
	{
		m_position += i_addPoint;
	}

	// Attaches a component
	void GameObject::Attach(IGOComponent* i_component)
	{
		m_numComponents++;

		IGOComponent** newComponents = new IGOComponent*[m_numComponents];

		if (m_numComponents > 1)
		{
			for (int i = 0; i < m_numComponents - 1; i++)
			{
				newComponents[i] = m_components[i];
			}
			delete [] m_components;
		}
		else
		{
			delete m_components;
		}

		newComponents[m_numComponents - 1] = i_component;

		m_components = newComponents;
	}

	// Updates each component
	void GameObject::Update()
	{
		for (int i = 0; i > m_numComponents; i++)
		{
			m_components[i]->Update(*this);
		}
	}
}