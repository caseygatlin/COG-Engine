#pragma once
#include "RandomSpawnComponent.h"
#include "GameObject/Public/GameObject.h"
#include "Components/Public/ComponentType.h"


inline void RandomSpawnComponent::OnAttach(Engine::GameObject* i_gameObject)
{
	float randX = m_RandMin_X + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (m_RandMax_X - m_RandMin_X)));
	float randY = m_RandMin_Y + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (m_RandMax_Y - m_RandMin_Y)));

	i_gameObject->SetPosition(Engine::Point2D(randX, randY));
}

inline void RandomSpawnComponent::Update(Engine::GameObject* i_gameObject)
{

}

inline bool RandomSpawnComponent::IsComponentType(const Engine::ComponentType& i_componentType) const
{

	return i_componentType == Engine::ComponentType::RANDOM_SPAWN;

}

inline void RandomSpawnComponent::SetMaxMin(const float& i_RandMax_X, const float& i_RandMin_X, const float& i_RandMax_Y, const float& i_RandMin_Y)
{

	m_RandMax_X = i_RandMax_X;
	m_RandMin_X = i_RandMin_X;
	m_RandMax_Y = i_RandMax_Y;
	m_RandMin_Y = i_RandMin_Y;

}



