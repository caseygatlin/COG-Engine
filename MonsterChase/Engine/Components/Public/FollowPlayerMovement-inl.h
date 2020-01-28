#pragma once
#include "ComponentType.h"
#include "FollowPlayerMovement.h"


namespace Engine
{
	inline FollowPlayerMovement& FollowPlayerMovement::operator=(const FollowPlayerMovement& i_src) 
	{
		m_playerToFollow = i_src.m_playerToFollow; 
	}

	inline const void* FollowPlayerMovement::GetMemberVariables() const
	{
		return static_cast<const void*>(m_playerToFollow);
	}

	inline ComponentType FollowPlayerMovement::GetComponentType() const
	{
		return ComponentType::FOLLOW_PLAYER_MOVEMENT;
	}

	

}