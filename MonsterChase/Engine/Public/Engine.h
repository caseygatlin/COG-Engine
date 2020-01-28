#pragma once
#include "../GameObject/Public/GameObject.h"
#include <vector>
#include <stdint.h>

namespace Engine
{

    GameObject* GetGameObject(int i_index);
    void AddGameObject(GameObject* i_gameObject);
    size_t GetNumGameObjects();
    void EraseGameObject();

	void Init();
	void Shutdown();

    void Run();
    bool QuitRequested();
}


