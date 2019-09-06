#ifndef POINT2D_H
#define POINT2D_H

namespace Engine
{
	class Point2D
	{
	public:
		//Constructor
		Point2D(float x = 0, float y = 0);
		
		//Getters
		float getX() const;
		float getY() const;

		//Setters
		void setX(float x);
		void setY(float y);


	private:
		//X and Y coordinates
		float m_x;
		float m_y;
	};


}

#endif