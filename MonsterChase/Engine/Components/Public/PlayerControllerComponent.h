#pragma once

#include "../../GameObject/Public/GameObject.h"
#include "ComponentType.h"
#include "IGOComponent.h"

namespace Engine
{
	
	class PlayerControllerComponent : public IGOComponent
	{
	public:

#pragma region Constructor Destructor

		// Constructor
		PlayerControllerComponent() :
			m_VKeyID_Up(0x0057),
			m_VKeyID_Down(0x0053),
			m_VKeyID_Left(0x0041),
			m_VKeyID_Right(0x0044)
		{}

		// Destructor
		inline virtual ~PlayerControllerComponent() {}
		
#pragma endregion

#pragma region Virtual Overrides

		// Executes on attachment to GameObject
		inline virtual void OnAttach(GameObject* i_gameObject) {}

		// Executes every tick
		inline virtual void Update(GameObject* i_gameObject, const float& i_dt) {}

		// Checks ComponentType
		inline virtual bool IsComponentType(const ComponentType& i_componentType) const;

		// Returns ComponentType
		inline virtual ComponentType GetComponentType() const;
		
#pragma endregion

#pragma region Getters

		// Gets the Key ID for the Up Input.
		inline unsigned int GetVKeyIDUp() const;
		
		// Gets the Key ID for the Down Input.
		inline unsigned int GetVKeyIDDown() const;
		
		// Gets the Key ID for the Left Input.
		inline unsigned int GetVKeyIDLeft() const;
		
		// Gets the Key ID for the Right Input.
		inline unsigned int GetVKeyIDRight() const;
		
#pragma endregion

#pragma region Setters
		
		// Sets the Key ID for the Up Input.
		inline void SetVKeyIDUp(const unsigned int& i_VKeyID_Up);
		
		// Sets the Key ID for the Down Input.
		inline void SetVKeyIDDown(const unsigned int& i_VKeyID_Down);
		
		// Sets the Key ID for the Left Input.
		inline void SetVKeyIDLeft(const unsigned int& i_VKeyID_Left);
		
		// Sets the Key ID for the Right Input.
		inline void SetVKeyIDRight(const unsigned int& i_VKeyID_Right);
		
#pragma endregion

	private:

#pragma region Key IDs

		// Key ID for the Up Input.
		unsigned int m_VKeyID_Up;
		
		// Key ID for the Down Input.
		unsigned int m_VKeyID_Down;
		
		// Key ID for the Left Input.
		unsigned int m_VKeyID_Left;
		
		// Key ID for the Right Input.
		unsigned int m_VKeyID_Right;
		
#pragma endregion

	};

}

#include "PlayerControllerComponent-inl.h"
