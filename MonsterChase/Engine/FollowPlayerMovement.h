#pragma once

#include "IGOComponent.h"
#include "GameObject.h"
#include "ComponentType.h"



namespace Engine
{

	class FollowPlayerMovement : public IGOComponent
	{
	public:
		FollowPlayerMovement(const GameObject* i_player) : m_playerToFollow(i_player) {}
		~FollowPlayerMovement() { m_playerToFollow = nullptr; }

		void Update(GameObject& i_gameObject);
		inline ComponentType GetComponentType() const;


	private:
		const GameObject* m_playerToFollow;

	};
}

#include "FollowPlayerMovement-inl.h"