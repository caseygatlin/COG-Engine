#pragma once
#include "RandomSpawnComponent.h"
#include "ComponentType.h"


namespace Engine
{
	inline void RandomSpawnComponent::OnAttach(GameObject* i_gameObject)
	{
		float randX = m_RandMin + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (m_RandMax - m_RandMin)));
		float randY = m_RandMin + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (m_RandMax - m_RandMin)));

		i_gameObject->SetPosition(Point2D(randX, randY));
	}

	inline void RandomSpawnComponent::Update(GameObject* i_gameObject)
	{

	}

	inline bool RandomSpawnComponent::IsComponentType(const ComponentType& i_componentType) const
	{

		return i_componentType == ComponentType::RANDOM_SPAWN;

	}

	inline void RandomSpawnComponent::SetMaxMin(const float& i_RandMax, const float& i_RandMin)
	{

		m_RandMax = i_RandMax;
		m_RandMin = i_RandMin;

	}


}

