#pragma once
#include "PlayerControllerComponent.h"
#include "ComponentType.h"


namespace Engine
{

	inline bool PlayerControllerComponent::IsComponentType(const ComponentType& i_componentType) const
	{

		return i_componentType == ComponentType::PLAYER_INPUT;

	}

	inline ComponentType PlayerControllerComponent::GetComponentType() const
	{
		return ComponentType::PLAYER_INPUT;
	}

	inline unsigned int PlayerControllerComponent::GetVKeyIDUp() const
	{

		return m_VKeyID_Up;

	}

	inline unsigned int PlayerControllerComponent::GetVKeyIDDown() const
	{

		return m_VKeyID_Down;

	}

	inline unsigned int PlayerControllerComponent::GetVKeyIDLeft() const
	{

		return m_VKeyID_Left;

	}

	inline unsigned int PlayerControllerComponent::GetVKeyIDRight() const
	{

		return m_VKeyID_Right;

	}

	inline void PlayerControllerComponent::SetVKeyIDUp(const unsigned int& i_VKeyID_Up)
	{

		m_VKeyID_Up = i_VKeyID_Up;

	}

	inline void PlayerControllerComponent::SetVKeyIDDown(const unsigned int& i_VKeyID_Down)
	{

		m_VKeyID_Down = i_VKeyID_Down;

	}

	inline void PlayerControllerComponent::SetVKeyIDLeft(const unsigned int& i_VKeyID_Left)
	{

		m_VKeyID_Left = i_VKeyID_Left;

	}

	inline void PlayerControllerComponent::SetVKeyIDRight(const unsigned int& i_VKeyID_Right)
	{

		m_VKeyID_Right = i_VKeyID_Right;

	}


}

