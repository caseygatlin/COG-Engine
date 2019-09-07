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

		//Assignment operator
		Point2D& operator=(const Point2D& src);

		//Addition
		Point2D operator+(const Point2D rhs);

		//Subtraction
		Point2D operator-(const Point2D rhs);

		//Multiplication
		Point2D operator*(const Point2D rhs);

		//Division
		Point2D operator/(const Point2D rhs);

		//Modulo
		Point2D operator%(const Point2D rhs);

		//Increment
		Point2D& operator++();
		Point2D operator++(int);

		//Decrement
		Point2D& operator--();
		Point2D operator--(int);

		//Equal to
		bool operator==(Point2D const& rhs) const;

		//Not equal to
		bool operator!=(Point2D const& rhs);

		//Addition assignment
		Point2D& operator+=(Point2D rhs);

		//Subtraction assignment
		Point2D& operator-=(Point2D rhs);

		//Multiplication assignment
		Point2D& operator*=(Point2D rhs);

		//Division assignment
		Point2D& operator/=(Point2D rhs);

		//Modulo assignment
		Point2D& operator%=(Point2D rhs);

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


}

#endif