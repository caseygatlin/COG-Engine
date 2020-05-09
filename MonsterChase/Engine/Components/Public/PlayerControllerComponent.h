#pragma once
#include "../../GameObject/Public/GameObject.h"
#include "ComponentType.h"
#include "IGOComponent.h"

namespace Engine
{
	
	class PlayerControllerComponent : public IGOComponent
	{
	public:

		// Constructor
		PlayerControllerComponent() :
			m_VKeyID_Up(0x0057),
			m_VKeyID_Down(0x0053),
			m_VKeyID_Left(0x0041),
			m_VKeyID_Right(0x0044)
		{}

		// Destructor
		inline virtual ~PlayerControllerComponent() {}

		// Executes on attachment to GameObject
		inline virtual void OnAttach(GameObject* i_gameObject) {}

		// Executes every tick
		inline virtual void Update(GameObject* i_gameObject, const float& i_dt) {}

		// Checks ComponentType
		inline virtual bool IsComponentType(const ComponentType& i_componentType) const;

		// Returns ComponentType
		inline virtual ComponentType GetComponentType() const;

		// Getters for Key IDs
		inline unsigned int GetVKeyIDUp() const;
		inline unsigned int GetVKeyIDDown() const;
		inline unsigned int GetVKeyIDLeft() const;
		inline unsigned int GetVKeyIDRight() const;

		// Setters for Key IDs
		inline void SetVKeyIDUp(const unsigned int& i_VKeyID_Up);
		inline void SetVKeyIDDown(const unsigned int& i_VKeyID_Down);
		inline void SetVKeyIDLeft(const unsigned int& i_VKeyID_Left);
		inline void SetVKeyIDRight(const unsigned int& i_VKeyID_Right);

	private:

		// Key IDs for the four input keys
		unsigned int m_VKeyID_Up;
		unsigned int m_VKeyID_Down;
		unsigned int m_VKeyID_Left;
		unsigned int m_VKeyID_Right;

	};

}

#include "PlayerControllerComponent-inl.h"