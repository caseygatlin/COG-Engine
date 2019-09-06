#include "Point2D.h"

namespace Engine
{
	//Constructor
	Point2D::Point2D(float x, float y)
	{
		m_x = x;
		m_y = y;
	}


	//Getters
	float Point2D::getX() const
	{
		return m_x;
	}

	float Point2D::getY() const
	{
		return m_y;
	}

	//Setters
	void Point2D::setX(float x)
	{
		m_x = x;
	}

	void Point2D::setY(float y)
	{
		m_y = y;
	}

}