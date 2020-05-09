#pragma once
#include "HealthComponent.h"
#include "../../GameObject/Public/GameObject.h"
#include "../../Console/Public/ConsolePrint.h"
#include "ComponentType.h"


namespace Engine
{
	inline void HealthComponent::Update(GameObject* i_gameObject, const float& i_dt)
	{

		// If took damage, decrease hit buffer timer
		if (m_TookDamage)
		{

			m_CurrentHitBufferTime -= i_dt;

		}


		// If hit buffer timer is timed out, reset it as well as the TookDamage variable
		if (m_CurrentHitBufferTime < 0.0f)
		{

			m_CurrentHitBufferTime = m_MaxHitBufferTime;
			m_TookDamage = false;

		}
	}

	inline bool HealthComponent::IsComponentType(const ComponentType& i_componentType) const
	{

		return i_componentType == ComponentType::HEALTH;

	}

	inline ComponentType HealthComponent::GetComponentType() const
	{

		return ComponentType::HEALTH;

	}

	inline bool HealthComponent::TakeDamage()
	{

		// If hasn't taken damage yet, decrease health
		// and signal if dead.
		if (!m_TookDamage)
		{

			m_TookDamage = true;

			if (--m_Health <= 0)
			{

				m_Health = 0;
				return true;

			}
		}

		return false;

	}

	inline size_t HealthComponent::GetHealth() const
	{

		return m_Health;

	}

	inline void HealthComponent::SetHealth(const size_t& i_Health)
	{

		m_Health = i_Health;

	}
	inline void HealthComponent::SetMaxHitBufferTime(const float& i_MaxTime)
	{

		m_MaxHitBufferTime = i_MaxTime;

	}
}

