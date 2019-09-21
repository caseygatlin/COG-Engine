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

	Point2D& Point2D::operator+=(Point2D rhs)
	{
		m_x += rhs.m_x;
		m_y += rhs.m_y;
		return (*this);
	}

	Point2D& Point2D::operator-=(Point2D rhs)
	{
		m_x -= rhs.m_x;
		m_y -= rhs.m_y;
		return (*this);
	}

	Point2D& Point2D::operator*=(Point2D rhs)
	{
		m_x *= rhs.m_x;
		m_y *= rhs.m_y;
		return (*this);
	}

	Point2D& Point2D::operator/=(Point2D rhs)
	{
		m_x /= rhs.m_x;
		m_y /= rhs.m_y;
		return (*this);
	}

	Point2D& Point2D::operator%=(Point2D rhs)
	{
		m_x %= rhs.m_x;
		m_y %= rhs.m_y;
		return (*this);
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

	//Mathematical operations
	Point2D operator+(const Point2D lhs, const Point2D rhs)
	{
		int x = lhs.X() + rhs.X();
		int y = lhs.Y() + rhs.Y();
		Point2D p(x, y);
		return p;
	}

	Point2D operator-(const Point2D lhs, const Point2D rhs)
	{
		int x = lhs.X() - rhs.X();
		int y = lhs.Y() - rhs.Y();
		Point2D p(x, y);
		return p;
	}

	Point2D operator*(const Point2D lhs, const Point2D rhs)
	{
		int x = lhs.X() * rhs.X();
		int y = lhs.Y() * rhs.Y();
		Point2D p(x, y);
		return p;
	}

	Point2D operator/(const Point2D lhs, const Point2D rhs)
	{
		int x = lhs.X() / rhs.X();
		int y = lhs.Y() / rhs.Y();
		Point2D p(x, y);
		return p;
	}

	Point2D operator%(const Point2D lhs, const Point2D rhs)
	{
		int x = lhs.X() % rhs.X();
		int y = lhs.Y() % rhs.Y();
		Point2D p(x, y);
		return p;
	}

	//Equal / Not Equal to
	bool operator==(Point2D const& lhs, Point2D const& rhs)
	{
		return (lhs.X() == rhs.X() && lhs.Y() == rhs.Y());
	}

	bool operator!=(Point2D const& lhs, Point2D const& rhs)
	{
		return !(lhs.X() == rhs.X() && lhs.Y() == rhs.Y());
	}

}