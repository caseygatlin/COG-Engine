#pragma once


class AsteroidSpawner
{
public:
	AsteroidSpawner() :
		m_bContinueSpawning(true)
	{}
	
	void operator() ();

	void OnCollision();

private:
	bool m_bContinueSpawning;
};
