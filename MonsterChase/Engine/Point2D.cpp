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

	//Assignment operator
	Point2D& Point2D::operator=(const Point2D& src)
	{
		if (&src == this)
			return (*this);

		m_x = src.m_x;
		m_y = src.m_y;

		return (*this);
	}

	//Addition
	Point2D Point2D::operator+(const Point2D rhs)
	{
		int x = m_x + rhs.m_x;
		int y = m_y + rhs.m_y;
		Point2D p(x, y);
		return p;
	}

	//Subtraction
	Point2D Point2D::operator-(const Point2D rhs)
	{
		int x = m_x - rhs.m_x;
		int y = m_y - rhs.m_y;
		Point2D p(x, y);
		return p;
	}

	//Multiplication
	Point2D Point2D::operator*(const Point2D rhs)
	{
		int x = m_x * rhs.m_x;
		int y = m_y * rhs.m_y;
		Point2D p(x, y);
		return p;
	}

	//Division
	Point2D Point2D::operator/(const Point2D rhs)
	{
		int x = m_x / rhs.m_x;
		int y = m_y / rhs.m_y;
		Point2D p(x, y);
		return p;
	}

	//Modulo
	Point2D Point2D::operator%(const Point2D rhs)
	{
		int x = m_x % rhs.m_x;
		int y = m_y % rhs.m_y;
		Point2D p(x, y);
		return p;
	}

	//Prefix increment
	Point2D& Point2D::operator++()
	{
		++m_x;
		++m_y;
		return (*this);
	}

	//Postfix increment
	Point2D Point2D::operator++(int)
	{
		int x = m_x++;
		int y = m_y++;
		Point2D p(x, y);
		return p;
	}

	//Prefix decrement
	Point2D& Point2D::operator--()
	{
		--m_x;
		--m_y;
		return (*this);
	}

	//Postfix decrement
	Point2D Point2D::operator--(int)
	{
		int x = m_x--;
		int y = m_y--;
		Point2D p(x, y);
		return p;
	}


	//Equal to
	bool Point2D::operator==(Point2D const& rhs) const
	{
		return (m_x == rhs.m_x && m_y == rhs.m_y);
	}

	//Not equal to
	bool Point2D::operator!=(Point2D const& rhs)
	{
		return !(m_x == rhs.m_x && m_y == rhs.m_y);
	}

	//Addition assignment
	Point2D& Point2D::operator+=(Point2D rhs)
	{
		m_x += rhs.m_x;
		m_y += rhs.m_y;
		return (*this);
	}

	//Subtraction assignment
	Point2D& Point2D::operator-=(Point2D rhs)
	{
		m_x -= rhs.m_x;
		m_y -= rhs.m_y;
		return (*this);
	}

	//Multiplication assignment
	Point2D& Point2D::operator*=(Point2D rhs)
	{
		m_x *= rhs.m_x;
		m_y *= rhs.m_y;
		return (*this);
	}

	//Division assignment
	Point2D& Point2D::operator/=(Point2D rhs)
	{
		m_x /= rhs.m_x;
		m_y /= rhs.m_y;
		return (*this);
	}

	//Modulo assignment
	Point2D& Point2D::operator%=(Point2D rhs)
	{
		m_x %= rhs.m_x;
		m_y %= rhs.m_y;
		return (*this);
	}


	//Ostream <<
	std::ostream& operator<<(std::ostream& out, const Point2D& point)
	{
		out << "[" << point.m_x << ", " << point.m_y << "]";
		return out;
	}


	//Getters
	int Point2D::X() const
	{
		return m_x;
	}

	int Point2D::Y() const
	{
		return m_y;
	}
}