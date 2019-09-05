#include "Engine.h"
#include <iostream>


namespace Engine
{
	void Init()
	{
		std::cout << "Engine Initialized.\n";
	}

	void Shutdown()
	{
		std::cout << "Shutting down...\n";
	}
}