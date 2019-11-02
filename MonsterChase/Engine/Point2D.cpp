#include "Point2D.h"

namespace Engine
{
	//Constructor
	Point2D::Point2D(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	//Copy constructor
	Point2D::Point2D(const Point2D& src)
	{
		m_x = src.m_x;
		m_y = src.m_y;
	}

	//Assignment operators
	Point2D& Point2D::operator=(const Point2D& src)
	{
		if (&src == this)
			return (*this);

		m_x = src.m_x;
		m_y = src.m_y;

		return (*this);
	}

	

}