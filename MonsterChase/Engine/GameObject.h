#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Point2D.h"
#include <vector>


namespace Engine
{
	class IGOComponent;


	//Class for all objects with a position
	class GameObject
	{
	public:
		//Constructors
		GameObject() :
			m_position(0, 0),
			m_dir('n'),
			m_health(1),
			m_name(nullptr),
			m_nameLength(0), 
			m_components(std::vector<IGOComponent*>()) 
		{ }


		explicit GameObject(const Point2D& position, const int& i_health = 1) :
			m_position(position.X(), position.Y()), 
			m_dir('n'),
			m_health(i_health),
			m_name(nullptr),
			m_nameLength(0), 
			m_components(std::vector<IGOComponent*>()) 
		{ }

		// Copy constructor with option to change health
		GameObject(const GameObject& i_src, int i_health = -1);

		// Destructor
		~GameObject();

		// Assignment operator
		GameObject&		operator=(const GameObject& i_src);


		//Accessors --
		inline	Point2D	getPosition()	const;
		inline	char	getDir()		const;
		inline	char*	getName()		const;
		inline	bool	IsAlive()		const;



		// Mutators --
		// Sets the name of the GameObject
				void setName(char* i_name, int i_length);
		
		// Changes GameObject direction
		inline	void changeDir(char& i_dir);
		
		// Adds given point to current position
		inline	void changePosition(const Point2D& i_addPoint);

		// Attaches a component
		inline	void Attach(IGOComponent* i_component);

		// Reduces health
		inline	void ReduceHealth();

		// Updates each component
				void Update();

	private:
		Point2D						m_position;
		char						m_dir;
		int							m_health;
		char*						m_name;
		int							m_nameLength;
		std::vector<IGOComponent*>	m_components;
	};

}

#include "GameObject-inl.h"


#endif