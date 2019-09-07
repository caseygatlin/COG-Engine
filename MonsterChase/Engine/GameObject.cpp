#include "GameObject.h"
#include "Point2D.h"


namespace Engine
{
	//Constructor
	//Default assigns object zero zero position
	GameObject::GameObject()
	{
		m_position = Point2D(0, 0);
	}

	//Returns current position
	Point2D GameObject::getPosition() const
	{
		return m_position;
	}
}