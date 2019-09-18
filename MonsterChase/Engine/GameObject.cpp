#include "GameObject.h"
#include "Point2D.h"


namespace Engine
{
	//Returns current position
	Point2D GameObject::getPosition() const
	{
		return m_position;
	}
}