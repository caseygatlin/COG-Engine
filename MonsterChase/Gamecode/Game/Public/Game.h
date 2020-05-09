#pragma once

#include "../../Asteroids/Public/AsteroidSpawner.h"
#include "../../Player Ship/Public/PlayerShipSpawner.h"
#include "../Game Over/Public/GameOverScreen.h"

#include <Windows.h>
#include <vector>

class Game
{
public:
    Game() :
        m_AsteroidSpawner(this),
        m_PlayerShipSpawner(this),
        m_GameOverScreen()
    {}

    void Init();
    void EndGame();
    void ShutDown();

private:

    AsteroidSpawner m_AsteroidSpawner;
    PlayerShipSpawner m_PlayerShipSpawner;
    GameOverScreen m_GameOverScreen;
	
};
