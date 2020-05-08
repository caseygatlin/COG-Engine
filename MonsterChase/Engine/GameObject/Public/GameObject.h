#pragma once

#include "../../Containers/Public/Point2D.h"
#include "../../Containers/Public/Pointers.h"
#include "../../Components/Public/IGOComponent.h"
#include "../../Components/Public/ComponentType.h"

#include <vector>


namespace Engine
{

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
		GameObject& operator=(const GameObject& i_src);

		//Accessors --
		inline	Point2D	GetPosition()	const;
		inline	Point2D	GetDir()		const;
		inline  Point2D GetVelocity()   const;


		// Mutators --
		// Changes GameObject direction
		inline void ChangeDir(const Point2D& i_dir);

		// Adds given point to current position.
		inline void ChangePosition(const Point2D& i_addPoint);

		// Sets the position to the one given.
		inline void  SetPosition(const Point2D& i_position);

		// Attaches a component
		inline void Attach(SmartPtr<IGOComponent> i_component);

		inline bool HasComponent(const ComponentType& i_componentType) const;
		inline bool GetComponent(const ComponentType& i_componentType, WeakPtr<IGOComponent>& o_component) const;

		// Sets the velocity of this object.
		inline void SetVelocity(Point2D i_velocity);

		// Updates each component
		void Update();

	private:

		//Constructors
		GameObject() :
			m_Position(0.0f, 0.0f),
			m_Velocity(0.0f, 0.0f),
			m_Dir(0.0f, 0.0f),
			m_Components(std::vector<SmartPtr<IGOComponent>>())
		{ }

		GameObject(const Point2D& i_spawnPosition, const Point2D& i_spawnVelocity = Point2D(0.0F, 0.0F)) :
			m_Position(i_spawnPosition),
			m_Velocity(i_spawnVelocity),
			m_Dir(0.0f, 0.0f),
			m_Components(std::vector<SmartPtr<IGOComponent>>())
		{ }

		Point2D								m_Position;
		Point2D								m_Velocity;
		Point2D								m_Dir;
		std::vector<SmartPtr<IGOComponent>>	m_Components;
	};

}

#include "GameObject-inl.h"