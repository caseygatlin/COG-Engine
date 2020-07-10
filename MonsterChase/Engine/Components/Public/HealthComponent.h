#pragma once
#include "../../GameObject/Public/GameObject.h"
#include "ComponentType.h"
#include "IGOComponent.h"

namespace Engine
{
	
	class HealthComponent : public IGOComponent
	{
	public:

		// Constructor
		HealthComponent() :
			m_Health(1),
			m_CurrentHitBufferTime(0.0f),
			m_MaxHitBufferTime(0.0f),
			m_TookDamage(false)
		{}

		// Destructor
		inline virtual ~HealthComponent() {}

		// Executes on attachment to GameObject
		inline virtual void OnAttach(GameObject* i_gameObject) {}

		// Executes every tick
		inline virtual void Update(GameObject* i_gameObject, const float& i_dt);

		// Checks ComponentType
		inline virtual bool IsComponentType(const ComponentType& i_componentType) const;

		// Returns ComponentType
		inline virtual ComponentType GetComponentType() const;

		//Decreases health and signals if dead
		inline bool TakeDamage();

		// Returns current health
		size_t GetHealth() const;

		// Sets the current health of this component
		void SetHealth(const size_t& i_Health);

		// Sets the amount of invincibility time per hit.
		void SetMaxHitBufferTime(const float& i_MaxTime);

	private:

		size_t	m_Health;
		float	m_CurrentHitBufferTime;
		float	m_MaxHitBufferTime;
		bool	m_TookDamage;

	};

}

#include "HealthComponent-inl.h"
