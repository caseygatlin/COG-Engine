#pragma once
#include "../../GameObject/Public/GameObject.h"
#include "ComponentType.h"
#include "IGOComponent.h"

namespace Engine
{
	
	class HealthComponent : public IGOComponent
	{
	public:

		inline virtual ~HealthComponent() {}

		inline virtual void OnAttach(GameObject* i_gameObject) {}

		inline virtual void Update(GameObject* i_gameObject);

		inline virtual bool IsComponentType(const ComponentType& i_componentType) const;

		inline bool TakeDamage();

		size_t GetHealth() const;

		void SetHealth(const size_t& i_Health);

	private:

		size_t m_Health;

	};

}

#include "HealthComponent-inl.h"
