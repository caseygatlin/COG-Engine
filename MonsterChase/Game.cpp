#include "Game.h"
#include "Graphics/Public/Graphics.h"
#include "Physics/Public/Physics.h"
#include "GameObject/Public/GameObject.h"
#include "Public/Engine.h"
#include "GLib.h"
#include <vector>
#include <Windows.h>


void Game::Init()
{
    Engine::GameObject* player = new Engine::GameObject();
    Engine::AddGameObject(player);
    
    Engine::GameObject* monster = new Engine::GameObject();
    Engine::AddGameObject(monster);

    Engine::Graphics::Init(m_hInstance, m_hPrevInstance, m_lpCmdLine, m_nCmdShow);
    Engine::Physics::Init();
}


void Game::ShutDown()
{
    for (int i = 0; i < Engine::GetNumGameObjects(); i++)
    {
        delete Engine::GetGameObject(i);
    }
    for (int i = 0; i < Engine::GetNumGameObjects(); i++)
    {
        Engine::EraseGameObject();
    }
}