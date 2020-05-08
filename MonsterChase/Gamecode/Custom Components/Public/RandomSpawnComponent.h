#pragma once

#include "GameObject/Public/GameObject.h"
#include "Components/Public/IGOComponent.h"
#include "Components/Public/ComponentType.h"
#include "Containers/Public/Pointers.h"


class RandomSpawnComponent : public Engine::IGOComponent
{
public:

	RandomSpawnComponent() :
		m_RandMax(400.0f),
		m_RandMin(-400.0f)
	{}

	inline virtual ~RandomSpawnComponent() {}

	inline virtual void OnAttach(Engine::GameObject* i_gameObject);

	inline virtual void Update(Engine::GameObject* i_gameObject);

	inline virtual bool IsComponentType(const Engine::ComponentType& i_componentType) const;

	inline void SetMaxMin(const float& i_RandMax_X, const float& i_RandMin_X, const float& i_RandMax_Y, const float& i_RandMin_Y);

private:

	float m_RandMax_X;
	float m_RandMin_X;
	float m_RandMax_Y;
	float m_RandMin_Y;

};


#include "RandomSpawnComponent-inl.h"

