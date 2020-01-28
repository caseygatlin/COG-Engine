#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>

namespace Engine
{
	//Class for an X,Y coordinate
	class Point2D
	{
	public:
		//Constructor
		Point2D(const float& x = 0.0F, const float& y = 0.0F) : m_x(x), m_y(y)				{}

		//Copy constructor
		Point2D(const Point2D& src)					: m_x(src.m_x), m_y(src.m_y)	{}

		//Assignment operators
		inline Point2D& operator=(const Point2D& src);
		inline Point2D& operator+=(const Point2D& rhs);
		inline Point2D& operator-=(const Point2D& rhs);
		inline Point2D& operator*=(const Point2D& rhs);
		inline Point2D& operator/=(const Point2D& rhs);

		//Postfix and prefix operators
		inline Point2D& operator++();
		inline Point2D	operator++(int);
		inline Point2D& operator--();
		inline Point2D	operator--(int);

		//Ostream <<
		inline friend std::ostream& operator<<(std::ostream& out, const Point2D& point);
		
		//Getters
		inline float X() const;
		inline float Y() const;

	private:
		//X and Y coordinates
		float m_x;
		float m_y;
	};

	//Mathematical operations
	inline Point2D	operator+(const Point2D lhs, const Point2D rhs);
	inline Point2D	operator-(const Point2D lhs, const Point2D rhs);
	inline Point2D	operator*(const Point2D lhs, const Point2D rhs);
	inline Point2D	operator/(const Point2D lhs, const Point2D rhs);
    inline Point2D  operator/(const Point2D lhs, const float rhs);

	// Equal /Not Equal to
	inline bool		operator==(Point2D const& lhs, Point2D const& rhs);
	inline bool		operator!=(Point2D const& lhs, Point2D const& rhs);
	
}

#include "Point2D-inl.h"


#endif