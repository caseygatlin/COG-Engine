#include "../Public/Engine.h"
#include <iostream>


namespace Engine
{
	//Announces engine initialization
	void Init()
	{
		std::cout << "Engine Initialized.\n\n";
	}

	//Announces engine shutdown
	void Shutdown()
	{
		std::cout << "\nShutting down...\n";
	}
}