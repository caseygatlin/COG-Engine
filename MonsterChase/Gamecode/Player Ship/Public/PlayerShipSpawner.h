#pragma once

#include "Containers/Public/Pointers.h"
#include "Components/Public/HealthComponent.h"

class Game;

// Spawns the player controlled ship
class PlayerShipSpawner
{
public:

	// Constructor
	PlayerShipSpawner(Game* i_GameInstance) :
		m_GameInstance(i_GameInstance)
	{}

	// Spawns the ship
	void SpawnShip();

	// Collision callback for ship (takes damage)
	void OnCollision();

private:
	Game* m_GameInstance;

};