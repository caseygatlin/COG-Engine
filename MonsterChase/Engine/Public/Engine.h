#pragma once
#include "../GameObject/Public/GameObject.h"
#include <vector>
#include <stdint.h>
#include <Windows.h>

namespace Engine
{

	// Initializes the Graphics and Job System
	void Init(HINSTANCE i_hInstance, HINSTANCE i_hPrevInstance, LPWSTR i_lpCmdLine, int i_nCmdShow);

	// Removes all GameObjects and shuts down all engine processes
	void Shutdown();

	// Runs the core game loop
    void Run();

	// Checks if an engine shutdown has been requested
    bool QuitRequested();

}


