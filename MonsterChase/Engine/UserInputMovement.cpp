#include "UserInputMovement.h"
#include "GameObject.h"

namespace Engine
{
	void UserInputMovement::Update(GameObject& i_gameObject)
	{
		char dir = i_gameObject.getDir();

		switch (dir)
		{

		case 'w':
			i_gameObject.changePosition(Point2D(0, 1));
			break;

		case 'a':
			i_gameObject.changePosition(Point2D(-1, 0));
			break;

		case 's':
			i_gameObject.changePosition(Point2D(0, -1));
			break;

		case 'd':
			i_gameObject.changePosition(Point2D(1, 0));
			break;

		default:
			break;

		}
	}
}