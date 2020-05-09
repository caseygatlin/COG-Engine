#include "../Public/Engine.h"
#include "../Timing/Public/Timing.h"
#include "../GLib/GLib.h"
#include "../Input/Public/Input.h"
#include "../Graphics/Public/Graphics.h"
#include "../JobSystem/Public/JobSystem.h"
#include "../Spawning/Public/ObjectSpawner.h"
#include "../World/Public/World.h"
#include "../Physics/Public/Physics.h"
#include "../Physics/Collision/Public/Collision.h"
#include "../Console/Public/ConsolePrint.h"
#include <Windows.h>



namespace Engine
{

	//Announces engine initialization
	void Init(HINSTANCE i_hInstance, HINSTANCE i_hPrevInstance, LPWSTR i_lpCmdLine, int i_nCmdShow)
	{
        DEBUG_PRINT("Starting Engine...\n");


        Graphics::Init(i_hInstance, i_hPrevInstance, i_lpCmdLine, i_nCmdShow);

        JobSystem::CreateQueue("Default", 2);

        DEBUG_PRINT("Engine Initialized.\n");
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

            World::Update(dt);

            Physics::Update(dt);

            Graphics::Present();
        }
        
    }

	//Announces engine shutdown
	void Shutdown()
	{

        DEBUG_PRINT("Engine Shutting Down...\n");

        Graphics::Shutdown();
        Physics::Destroy();
        World::Destroy();
        ObjectSpawner::ClearControllers();

	}

    
    
}