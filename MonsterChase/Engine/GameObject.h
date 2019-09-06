#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Point2D.h"

namespace Engine
{
	class GameObject
	{
	public:
		GameObject(float x, float y) : m_position(x, y) {}


		Point2D getPosition() const;
		void setX(float x);
		void setY(float y);

		virtual void move();

	private:
		Point2D m_position;
	};

}



#endif