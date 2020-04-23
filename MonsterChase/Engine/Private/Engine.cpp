#include "../Public/Engine.h"
#include "../Timing/Public/Timing.h"
#include "../GLib/GLib.h"
#include "../Input/Public/Input.h"
#include "../Graphics/Public/Graphics.h"
#include "../Physics/Public/Physics.h"
#include <iostream>


namespace Engine
{

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