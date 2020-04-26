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

    Engine::ObjectSpawner::SpawnGameObject("Content\\PlayerShipData.json");
    Engine::ObjectSpawner::SpawnGameObject("Content\\AsteroidData.json");

}


void Game::ShutDown()
{

}