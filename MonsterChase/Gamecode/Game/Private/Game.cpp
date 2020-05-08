#include "Game.h"
#include "Graphics/Public/Graphics.h"
#include "Physics/Public/Physics.h"
#include "GameObject/Public/GameObject.h"
#include "Public/Engine.h"
#include "World/Public/World.h"
#include "Containers/Public/Pointers.h"
#include "Spawning/Public/ObjectSpawner.h"
#include "JobSystem/Public/JobSystem.h"
#include "AsteroidSpawner.h"
#include "PlayerShipSpawner.h"
#include "GLib.h"
#include <vector>
#include <Windows.h>


void Game::Init()
{

    PlayerShipSpawner shipSpawner;

    Engine::JobSystem::RunJob("SpawnShip", std::bind(&PlayerShipSpawner::SpawnShip, &shipSpawner), "Default");
    Engine::JobSystem::RunJob("AsteroidSpawner", std::bind(AsteroidSpawner()), "Default");

}


void Game::ShutDown()
{

}