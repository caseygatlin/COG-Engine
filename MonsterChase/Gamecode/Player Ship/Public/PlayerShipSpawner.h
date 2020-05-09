#pragma once

#include "Containers/Public/Pointers.h"
#include "Components/Public/HealthComponent.h"

class Game;

class PlayerShipSpawner
{
public:
	PlayerShipSpawner(Game* i_GameInstance) :
		m_GameInstance(i_GameInstance)
	{}

	void SpawnShip();

	void OnCollision();

private:
	Game* m_GameInstance;

};