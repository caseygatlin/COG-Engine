#pragma once

class Game;

class AsteroidSpawner
{
public:
	AsteroidSpawner(Game* i_GameInstance) :
		m_GameInstance(i_GameInstance),
		m_bContinueSpawning(true)
	{}
	
	void SpawnAsteroids();

	void OnCollision();

private:
	Game* m_GameInstance;
	bool m_bContinueSpawning;

};
