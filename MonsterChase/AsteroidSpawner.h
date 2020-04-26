#pragma once


class AsteroidSpawner
{
public:
	AsteroidSpawner() :
		m_bContinueSpawning(true)
	{}
	
	void operator() ();

private:
	bool m_bContinueSpawning;
};
