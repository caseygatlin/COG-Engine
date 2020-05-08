#pragma once
#include "HealthComponent.h"
#include "../../GameObject/Public/GameObject.h"
#include "ComponentType.h"


namespace Engine
{
	inline void HealthComponent::Update(GameObject* i_gameObject)
	{

	}

	inline bool HealthComponent::IsComponentType(const ComponentType& i_componentType) const
	{

		return i_componentType == ComponentType::HEALTH;

	}

	inline bool HealthComponent::TakeDamage()
	{

		if (--m_Health <= 0)
		{ 
			return true; 
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
}

