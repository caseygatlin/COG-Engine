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
		Point2D(int x = 0, int y = 0);

		//Copy constructor
		Point2D(const Point2D& src);

		//Assignment operators
		Point2D& operator=(const Point2D& src);
		Point2D& operator+=(Point2D rhs);
		Point2D& operator-=(Point2D rhs);
		Point2D& operator*=(Point2D rhs);
		Point2D& operator/=(Point2D rhs);
		Point2D& operator%=(Point2D rhs);

		//Postfix and prefix operators
		Point2D& operator++();
		Point2D operator++(int);
		Point2D& operator--();
		Point2D operator--(int);		

		//Ostream <<
		friend std::ostream& operator<<(std::ostream& out, const Point2D& point);
		
		//Getters
		int X() const;
		int Y() const;

	private:
		//X and Y coordinates
		int m_x;
		int m_y;
	};

	//Mathematical operations
	Point2D operator+(const Point2D lhs, const Point2D rhs);
	Point2D operator-(const Point2D lhs, const Point2D rhs);
	Point2D operator*(const Point2D lhs, const Point2D rhs);
	Point2D operator/(const Point2D lhs, const Point2D rhs);
	Point2D operator%(const Point2D lhs, const Point2D rhs);

	// Equal /Not Equal to
	bool operator==(Point2D const& lhs, Point2D const& rhs);
	bool operator!=(Point2D const& lhs, Point2D const& rhs);
	
}




#endif