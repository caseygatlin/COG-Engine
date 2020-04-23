#include "Game.h"
#include "Graphics/Public/Graphics.h"
#include "Physics/Public/Physics.h"
#include "GameObject/Public/GameObject.h"
#include "Public/Engine.h"
#include "World/Public/World.h"
#include "Containers/Public/Pointers.h"
#include "GLib.h"
#include <vector>
#include <Windows.h>


void Game::Init()
{
    Engine::SmartPtr<Engine::GameObject> player = Engine::GameObject::CreateGameObject();
    Engine::World::AddGameObject(player);

    Engine::SmartPtr<Engine::GameObject> monster = Engine::GameObject::CreateGameObject();
    Engine::World::AddGameObject(monster);

    Engine::Graphics::Init(m_hInstance, m_hPrevInstance, m_lpCmdLine, m_nCmdShow);
    Engine::Physics::Init();
}


void Game::ShutDown()
{
    Engine::World::Destroy();
}