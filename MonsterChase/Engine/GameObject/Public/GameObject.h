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

		static SmartPtr<GameObject> CreateGameObject(const Point2D& i_spawnPoint, const Point2D& i_spawnVelocity = Point2D(0.0F, 0.0F))
		{
			SmartPtr<GameObject> gameObject(new GameObject(i_spawnPoint, i_spawnVelocity));
			return gameObject;
		}

		// Destructor
		~GameObject();

		// Assignment operator
		GameObject&		operator=(const GameObject& i_src);

		//Accessors --
		inline	Point2D	getPosition()	const;
		inline	char	getDir()		const;
		inline	bool	IsAlive()		const;
        inline  Point2D getVelocity()   const;


		// Mutators --
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
			m_position(0.0f, 0.0f),
			m_velocity(0, 0),
			m_dir('n'),
			m_health(1),
			m_components(std::vector<IGOComponent*>())
		{ }

		GameObject(const Point2D& i_spawnPosition, const Point2D& i_spawnVelocity = Point2D(0.0F, 0.0F)) :
			m_position(i_spawnPosition),
			m_velocity(i_spawnVelocity),
			m_dir('n'),
			m_health(1),
			m_components(std::vector<IGOComponent*>())
		{ }

		Point2D						m_position;
        Point2D                     m_velocity;
		char						m_dir;
		int							m_health;
		std::vector<IGOComponent*>	m_components;
	};

}

#include "GameObject-inl.h"


#endif