#pragma once
#include "../GameObject/Public/GameObject.h"
#include <vector>
#include <stdint.h>

namespace Engine
{
	void Init();
	void Shutdown();

    void Run();
    bool QuitRequested();
}


