#include "FollowPlayerMovement.h"
#include "Point2D.h"
#include "GameObject.h"


namespace Engine
{
	void FollowPlayerMovement::Update(GameObject& i_gameObject)
	{
		Point2D playerPos = m_playerToFollow->getPosition();
		Point2D objectPos = i_gameObject.getPosition();

		if (playerPos.X() < objectPos.X())
		{
			i_gameObject.changePosition(Point2D(-1, 0));
		}
		else if (playerPos.X() > objectPos.X())
		{
			i_gameObject.changePosition(Point2D(1, 0));
		}

		if (playerPos.Y() < objectPos.Y())
		{
			i_gameObject.changePosition(Point2D(0, -1));
		}
		else if (playerPos.Y() > objectPos.Y())
		{
			i_gameObject.changePosition(Point2D(0, 1));
		}
	}

}