#pragma once
#include "../../GameObject/Public/GameObject.h"
#include "ComponentType.h"
#include "IGOComponent.h"

namespace Engine
{
	
	class HealthComponent : public IGOComponent
	{
	public:

		HealthComponent() :
			m_Health(1),
			m_CurrentHitBufferTime(0.0f),
			m_MaxHitBufferTime(0.0f),
			m_TookDamage(false)
		{}

		inline virtual ~HealthComponent() {}

		inline virtual void OnAttach(GameObject* i_gameObject) {}

		inline virtual void Update(GameObject* i_gameObject, const float& i_dt);

		inline virtual bool IsComponentType(const ComponentType& i_componentType) const;

		inline virtual ComponentType GetComponentType() const;

		inline bool TakeDamage();

		size_t GetHealth() const;

		void SetHealth(const size_t& i_Health);
		void SetMaxHitBufferTime(const float& i_MaxTime);

	private:

		size_t m_Health;
		float m_CurrentHitBufferTime;
		float m_MaxHitBufferTime;
		bool m_TookDamage;
	};

}

#include "HealthComponent-inl.h"
