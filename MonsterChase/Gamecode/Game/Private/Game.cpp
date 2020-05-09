#include "../Public/Game.h"
#include "Graphics/Public/Graphics.h"
#include "Physics/Public/Physics.h"
#include "GameObject/Public/GameObject.h"
#include "Public/Engine.h"
#include "World/Public/World.h"
#include "Containers/Public/Pointers.h"
#include "Spawning/Public/ObjectSpawner.h"
#include "JobSystem/Public/JobSystem.h"
#include "../../Asteroids/Public/AsteroidSpawner.h"
#include "../../Player Ship/Public/PlayerShipSpawner.h"
#include "GLib.h"
#include <vector>
#include <Windows.h>


void Game::Init()
{
    using namespace Engine::JobSystem;

    RunJob("SpawnShip", std::bind(&PlayerShipSpawner::SpawnShip, &m_PlayerShipSpawner), "Default");
    RunJob("AsteroidSpawner", std::bind(&AsteroidSpawner::SpawnAsteroids, &m_AsteroidSpawner), "Default");

}

void Game::EndGame()
{
    using namespace Engine;
    m_AsteroidSpawner.StopSpawning();
    World::Destroy();
    ObjectSpawner::ClearControllers();
    JobSystem::RunJob("Game Over", std::bind(&GameOverScreen::ShowScreen, &m_GameOverScreen), "Default");
    
}


void Game::ShutDown()
{

}