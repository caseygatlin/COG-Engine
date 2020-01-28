#pragma once

#include "GameObject/Public/GameObject.h"
#include <Windows.h>
#include <vector>

namespace GLib
{
    namespace Sprites
    {
        struct Sprite;
    }
}

class Game
{
public:
    Game(HINSTANCE i_hInstance, HINSTANCE i_hPrevInstance, LPWSTR i_lpCmdLine, int i_nCmdShow) : 
        m_gameObjects(),
        m_hInstance(i_hInstance),
        m_hPrevInstance(i_hPrevInstance),
        m_lpCmdLine(i_lpCmdLine),
        m_nCmdShow(i_nCmdShow)
    {}

    void Init();
    void ShutDown();
    

private:
    std::vector<Engine::GameObject*> m_gameObjects;
    HINSTANCE m_hInstance;
    HINSTANCE m_hPrevInstance;
    LPWSTR m_lpCmdLine;
    int m_nCmdShow;
	
};
