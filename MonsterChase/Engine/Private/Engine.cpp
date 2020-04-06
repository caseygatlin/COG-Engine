#include "../Public/Engine.h"
#include "../Timing/Public/Timing.h"
#include "../GLib/GLib.h"
#include "../Input/Public/Input.h"
#include "../Graphics/Public/Graphics.h"
#include "../Physics/Public/Physics.h"
#include <iostream>


namespace Engine
{
    extern std::vector<Engine::GameObject*> g_gameObjects = std::vector<Engine::GameObject*>();

    GameObject* GetGameObject(int i_index)
    {
        return g_gameObjects.at(i_index);
    }

    void AddGameObject(GameObject* i_gameObject)
    {
        g_gameObjects.push_back(i_gameObject);
    }

    size_t GetNumGameObjects()
    {
        return g_gameObjects.size();
    }

    void EraseGameObject()
    {
        g_gameObjects.erase(g_gameObjects.begin());
    }


	//Announces engine initialization
	void Init()
	{
		std::cout << "Engine Initialized.\n\n";
	}

    bool QuitRequested()
    {
        bool bQuit = false;

        // IMPORTANT: We need to let GLib do it's thing. 
        GLib::Service(bQuit);

        return bQuit;
    }

    void Run()
    {
        while (1)
        {
            float dt = Timing::CalcTimeSinceLastCall_ms();

            Input::Read();
            
            if (QuitRequested())
                break;

            //AI::Run(dt);

            Physics::Update(dt);

            Graphics::Present();
        }
    }

	//Announces engine shutdown
	void Shutdown()
	{
		std::cout << "\nShutting down...\n";

        Graphics::Shutdown();
	}

    
    
}