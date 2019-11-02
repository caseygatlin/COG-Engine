#pragma once

namespace Engine
{
	inline Point2D& Point2D::operator+=(Point2D rhs)
	{
		m_x += rhs.m_x;
		m_y += rhs.m_y;
		return (*this);
	}

	inline Point2D& Point2D::operator-=(Point2D rhs)
	{
		m_x -= rhs.m_x;
		m_y -= rhs.m_y;
		return (*this);
	}

	inline Point2D& Point2D::operator*=(Point2D rhs)
	{
		m_x *= rhs.m_x;
		m_y *= rhs.m_y;
		return (*this);
	}

	inline Point2D& Point2D::operator/=(Point2D rhs)
	{
		m_x /= rhs.m_x;
		m_y /= rhs.m_y;
		return (*this);
	}

	inline Point2D& Point2D::operator%=(Point2D rhs)
	{
		m_x %= rhs.m_x;
		m_y %= rhs.m_y;
		return (*this);
	}

	//Prefix increment
	inline Point2D& Point2D::operator++()
	{
		++m_x;
		++m_y;
		return (*this);
	}

	//Postfix increment
	inline Point2D Point2D::operator++(int)
	{
		int x = m_x++;
		int y = m_y++;
		Point2D p(x, y);
		return p;
	}

	//Prefix decrement
	inline Point2D& Point2D::operator--()
	{
		--m_x;
		--m_y;
		return (*this);
	}

	//Postfix decrement
	inline Point2D Point2D::operator--(int)
	{
		int x = m_x--;
		int y = m_y--;
		Point2D p(x, y);
		return p;
	}

	//Ostream <<
	inline std::ostream& operator<<(std::ostream& out, const Point2D& point)
	{
		out << "[" << point.m_x << ", " << point.m_y << "]";
		return out;
	}

	//Getters
	inline int Point2D::X() const
	{
		return m_x;
	}

	inline int Point2D::Y() const
	{
		return m_y;
	}

	//Mathematical operations
	inline Point2D operator+(const Point2D lhs, const Point2D rhs)
	{
		int x = lhs.X() + rhs.X();
		int y = lhs.Y() + rhs.Y();
		Point2D p(x, y);
		return p;
	}

	inline Point2D operator-(const Point2D lhs, const Point2D rhs)
	{
		int x = lhs.X() - rhs.X();
		int y = lhs.Y() - rhs.Y();
		Point2D p(x, y);
		return p;
	}

	inline Point2D operator*(const Point2D lhs, const Point2D rhs)
	{
		int x = lhs.X() * rhs.X();
		int y = lhs.Y() * rhs.Y();
		Point2D p(x, y);
		return p;
	}

	inline Point2D operator/(const Point2D lhs, const Point2D rhs)
	{
		int x = lhs.X() / rhs.X();
		int y = lhs.Y() / rhs.Y();
		Point2D p(x, y);
		return p;
	}

	inline Point2D operator%(const Point2D lhs, const Point2D rhs)
	{
		int x = lhs.X() % rhs.X();
		int y = lhs.Y() % rhs.Y();
		Point2D p(x, y);
		return p;
	}

	//Equal / Not Equal to
	inline bool operator==(Point2D const& lhs, Point2D const& rhs)
	{
		return (lhs.X() == rhs.X() && lhs.Y() == rhs.Y());
	}

	inline bool operator!=(Point2D const& lhs, Point2D const& rhs)
	{
		return !(lhs.X() == rhs.X() && lhs.Y() == rhs.Y());
	}
}