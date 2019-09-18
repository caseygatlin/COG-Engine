#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Point2D.h"

namespace Engine
{
	//Class for all objects with a position
	class GameObject
	{
	public:
		//Constructors
		GameObject() : m_position(0, 0) {}
		GameObject(Point2D position) : m_position(position.X(), position.Y()) {}

		//Accessor
		Point2D getPosition() const;

	protected:
		Point2D m_position;

	};

}



#endif