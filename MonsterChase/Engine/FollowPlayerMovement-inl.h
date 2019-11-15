#pragma once
#include "ComponentType.h"
#include "FollowPlayerMovement.h"


namespace Engine
{
	inline ComponentType FollowPlayerMovement::GetComponentType() const
	{
		return FOLLOW_PLAYER_MOVEMENT;
	}
}