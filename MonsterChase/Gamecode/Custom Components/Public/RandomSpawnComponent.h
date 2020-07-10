#pragma once

#include "GameObject/Public/GameObject.h"
#include "Components/Public/IGOComponent.h"
#include "Components/Public/ComponentType.h"
#include "Containers/Public/Pointers.h"

// Moves a GameObject to a random location upon attachment
class RandomSpawnComponent : public Engine::IGOComponent
{
public:

	// Constructor
	RandomSpawnComponent() :
		m_RandMax_X(300.0f),
		m_RandMin_X(-300.0f),
		m_RandMax_Y(400.0f),
		m_RandMin_Y(-400.0f)
	{}

	// Destructor
	inline virtual ~RandomSpawnComponent() {}

	// Changes the GameObjects position on attachment
	inline virtual void OnAttach(Engine::GameObject* i_gameObject);

	// Executes every tick
	inline virtual void Update(Engine::GameObject* i_gameObject, const float& i_dt);

	// Checks ComponentType
	inline virtual bool IsComponentType(const Engine::ComponentType& i_componentType) const;

	// Returns the ComponentType
	inline virtual Engine::ComponentType GetComponentType() const;

	// Sets the bounds for randomness
	inline void SetMaxMin(const float& i_RandMax_X, const float& i_RandMin_X, const float& i_RandMax_Y, const float& i_RandMin_Y);

private:

	// Randomness bounds for relocation
	float m_RandMax_X;
	float m_RandMin_X;
	float m_RandMax_Y;
	float m_RandMin_Y;

};


#include "RandomSpawnComponent-inl.h"

