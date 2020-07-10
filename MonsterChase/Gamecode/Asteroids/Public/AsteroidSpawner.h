#pragma once

class Game;

// Continually spawns asteroids until the player is hit
class AsteroidSpawner
{
public:

	// Constructor
	AsteroidSpawner(Game* i_GameInstance) :
		m_GameInstance(i_GameInstance),
		m_bContinueSpawning(true)
	{}
	
	// Spawns the asteroids
	void SpawnAsteroids();

	// Signals the spawner to stop
	void StopSpawning();

	// Collision callback for asteroids
	void OnCollision();

private:

	Game* m_GameInstance;
	bool m_bContinueSpawning;

};
