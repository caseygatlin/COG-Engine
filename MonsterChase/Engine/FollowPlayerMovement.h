#pragma once

#include "IGOComponent.h"
#include "GameObject.h"
#include "ComponentType.h"



namespace Engine
{

	// Component for following another GameObject
	class FollowPlayerMovement : public IGOComponent
	{
	public:
		FollowPlayerMovement	(const GameObject* i_player) : m_playerToFollow(i_player)						{}
		FollowPlayerMovement	(const FollowPlayerMovement& i_src) : m_playerToFollow(i_src.m_playerToFollow)	{}
		~FollowPlayerMovement	()																				{ m_playerToFollow = nullptr; }

		inline	FollowPlayerMovement&	operator=(const FollowPlayerMovement& i_src);
				void					Update(GameObject& i_gameObject);
		inline	ComponentType			GetComponentType()		const;
		inline	const void*				GetMemberVariables()	const;


	private:
		const	GameObject*				m_playerToFollow;

	};
}

#include "FollowPlayerMovement-inl.h"