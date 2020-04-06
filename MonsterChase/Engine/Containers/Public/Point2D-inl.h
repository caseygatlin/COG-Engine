#pragma once

namespace Engine
{
	//Assignment operators
	inline Point2D& Point2D::operator=(const Point2D& src)
	{
		if (&src == this)
			return (*this);

		m_x = src.m_x;
		m_y = src.m_y;

		return (*this);
	}

	inline Point2D& Point2D::operator+=(const Point2D& rhs)
	{
		m_x += rhs.m_x;
		m_y += rhs.m_y;
		return (*this);
	}

	inline Point2D& Point2D::operator-=(const Point2D& rhs)
	{
		m_x -= rhs.m_x;
		m_y -= rhs.m_y;
		return (*this);
	}

	inline Point2D& Point2D::operator*=(const Point2D& rhs)
	{
		m_x *= rhs.m_x;
		m_y *= rhs.m_y;
		return (*this);
	}

	inline Point2D& Point2D::operator/=(const Point2D& rhs)
	{
		m_x /= rhs.m_x;
		m_y /= rhs.m_y;
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
		float x = m_x++;
		float y = m_y++;
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
		float x = m_x--;
		float y = m_y--;
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
	inline float Point2D::X() const
	{
		return m_x;
	}

	inline float Point2D::Y() const
	{
		return m_y;
	}

	//Mathematical operations
	inline Point2D operator+(const Point2D lhs, const Point2D rhs)
	{
		float x = lhs.X() + rhs.X();
		float y = lhs.Y() + rhs.Y();
		Point2D p(x, y);
		return p;
	}

	inline Point2D operator-(const Point2D lhs, const Point2D rhs)
	{
		float x = lhs.X() - rhs.X();
		float y = lhs.Y() - rhs.Y();
		Point2D p(x, y);
		return p;
	}

	inline Point2D operator*(const Point2D lhs, const Point2D rhs)
	{
		float x = lhs.X() * rhs.X();
		float y = lhs.Y() * rhs.Y();
		Point2D p(x, y);
		return p;
	}

	inline Point2D operator/(const Point2D lhs, const Point2D rhs)
	{
		float x = lhs.X() / rhs.X();
		float y = lhs.Y() / rhs.Y();
		Point2D p(x, y);
		return p;
	}

	inline Point2D operator*(const Point2D lhs, const float rhs)
	{
		float x = lhs.X() * rhs;
		float y = lhs.Y() * rhs;
		Point2D p(x, y);
		return p;
	}

    inline Point2D operator/(const Point2D lhs, const float rhs)
    {
        float x = lhs.X() / rhs;
        float y = lhs.Y() / rhs;
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