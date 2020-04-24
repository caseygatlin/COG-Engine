#include "Game.h"
#include "Graphics/Public/Graphics.h"
#include "Physics/Public/Physics.h"
#include "GameObject/Public/GameObject.h"
#include "Public/Engine.h"
#include "World/Public/World.h"
#include "Containers/Public/Pointers.h"
#include "Spawning/Public/ObjectSpawner.h"
#include "GLib.h"
#include <vector>
#include <Windows.h>


void Game::Init()
{
    Engine::Graphics::Init(m_hInstance, m_hPrevInstance, m_lpCmdLine, m_nCmdShow);

    Engine::ObjectSpawner::SpawnGameObject("Content\\PlayerShipData.json");
    Engine::ObjectSpawner::SpawnGameObject("Content\\AsteroidData.json");

    Engine::Physics::Init();
}


void Game::ShutDown()
{
    Engine::World::Destroy();
}