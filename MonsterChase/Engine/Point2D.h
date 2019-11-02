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
		Point2D(int x = 0, int y = 0) : m_x(x), m_y(y) {}

		//Copy constructor
		Point2D(const Point2D& src) : m_x(src.m_x), m_y(src.m_y) {}

		//Assignment operators
		inline Point2D& operator=(const Point2D& src);
		inline Point2D& operator+=(Point2D rhs);
		inline Point2D& operator-=(Point2D rhs);
		inline Point2D& operator*=(Point2D rhs);
		inline Point2D& operator/=(Point2D rhs);
		inline Point2D& operator%=(Point2D rhs);

		//Postfix and prefix operators
		inline Point2D& operator++();
		inline Point2D operator++(int);
		inline Point2D& operator--();
		inline Point2D operator--(int);

		//Ostream <<
		inline friend std::ostream& operator<<(std::ostream& out, const Point2D& point);
		
		//Getters
		inline int X() const;
		inline int Y() const;

	private:
		//X and Y coordinates
		int m_x;
		int m_y;
	};

	//Mathematical operations
	inline Point2D operator+(const Point2D lhs, const Point2D rhs);
	inline Point2D operator-(const Point2D lhs, const Point2D rhs);
	inline Point2D operator*(const Point2D lhs, const Point2D rhs);
	inline Point2D operator/(const Point2D lhs, const Point2D rhs);
	inline Point2D operator%(const Point2D lhs, const Point2D rhs);

	// Equal /Not Equal to
	inline bool operator==(Point2D const& lhs, Point2D const& rhs);
	inline bool operator!=(Point2D const& lhs, Point2D const& rhs);
	
}

#include "Point2D-inl.h"


#endif