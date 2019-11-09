#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Point2D.h"


namespace Engine
{
	class IGOComponent;


	//Class for all objects with a position
	class GameObject
	{
	public:
		//Constructors
		GameObject() : 
			m_position(0, 0), m_numComponents(0), m_dir('n'), m_name(nullptr), m_nameLength(0), m_components(nullptr) {}
		explicit GameObject(const Point2D& position) :
			m_position(position.X(), position.Y()), m_numComponents(0), m_dir('n'), m_name(nullptr), m_nameLength(0), m_components(nullptr) {}

		// Destructor
		~GameObject();

		// Assignment operator
		GameObject& operator=(const GameObject& i_src);

		//Accessors
		Point2D getPosition() const;
		char getDir() const;
		char* getName() const;


		void setName(char* i_name, int i_length);

		void changeDir(char& i_dir);

		// Adds given point to current position
		void changePosition(const Point2D& i_addPoint);

		// Attaches a component
		void Attach(IGOComponent* i_component);

		// Updates each component
		void Update();

	private:
		Point2D			m_position;
		int				m_numComponents;
		char			m_dir;
		char*			m_name;
		int				m_nameLength;
		IGOComponent**	m_components;



	};

}



#endif