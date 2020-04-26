#pragma once
#include "../GameObject/Public/GameObject.h"
#include <vector>
#include <stdint.h>
#include <Windows.h>

namespace Engine
{
	void Init(HINSTANCE i_hInstance, HINSTANCE i_hPrevInstance, LPWSTR i_lpCmdLine, int i_nCmdShow);
	void Shutdown();

    void Run();
    bool QuitRequested();
}


