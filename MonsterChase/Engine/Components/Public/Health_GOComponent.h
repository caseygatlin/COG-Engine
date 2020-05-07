#pragma once
#include "../../GameObject/Public/GameObject.h"
#include "ComponentType.h"
#include "IGOComponent.h"
#include "../../Containers/Public/Pointers.h"


namespace Engine
{
	
	class Health_GOComponent : public IGOComponent
	{
	public:

		virtual void Update(GameObject& i_gameObject) {}

		virtual ComponentType GetComponentType() const { return ComponentType::HEALTH; }

		bool TakeDamage()
		{ 
			if (--m_Health <= 0) { return true; } 
			return false;
		}

		size_t GetHealth() const { return m_Health; }
		void SetHealth(size_t i_Health) { m_Health = i_Health; }

	private:
		size_t m_Health;
	};
}

