#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../../Containers/Public/Point2D.h"
#include "../../Containers/Public/Pointers.h"
#include <vector>


namespace Engine
{
	class IGOComponent;


	//Class for all objects with a position
	class GameObject
	{
	public:

		static SmartPtr<GameObject> CreateGameObject()
		{
			SmartPtr<GameObject> gameObject(new GameObject());
			return gameObject;
		}

		// Destructor
		~GameObject();

		// Assignment operator
		GameObject&		operator=(const GameObject& i_src);

		//Accessors --
		inline	Point2D	getPosition()	const;
		inline	char	getDir()		const;
		inline	char*	getName()		const;
		inline	bool	IsAlive()		const;
        inline  Point2D getVelocity()   const;



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

        inline  void SetVelocity(Point2D i_velocity);


		// Updates each component
				void Update();

	private:

		//Constructors
		GameObject() :
			m_position(-180.0F, 100.0F),
			m_velocity(0, 0),
			m_dir('n'),
			m_health(1),
			m_name(nullptr),
			m_nameLength(0),
			m_components(std::vector<IGOComponent*>())
		{ }

		Point2D						m_position;
        Point2D                     m_velocity;
		char						m_dir;
		int							m_health;
		char*						m_name;
		int							m_nameLength;
		std::vector<IGOComponent*>	m_components;
	};

}

#include "GameObject-inl.h"


#endif