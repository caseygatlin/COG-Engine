#pragma once

#include "IGOComponent.h"
#include "GameObject.h"



namespace Engine
{

	class FollowPlayerMovement : public IGOComponent
	{
	public:
		FollowPlayerMovement(const GameObject* i_player) : m_playerToFollow(i_player) {}

		void Update(GameObject& i_gameObject);


	private:
		const GameObject* m_playerToFollow;

	};
}