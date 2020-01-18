#pragma once

#include <Windows.h>

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
        m_pGoodGuy(nullptr), 
        m_pBadGuy(nullptr),
        m_hInstance(i_hInstance),
        m_hPrevInstance(i_hPrevInstance),
        m_lpCmdLine(i_lpCmdLine),
        m_nCmdShow(i_nCmdShow)
    {}

    void Run();
    

private:
    GLib::Sprites::Sprite* m_pGoodGuy;
    GLib::Sprites::Sprite* m_pBadGuy;
    HINSTANCE m_hInstance;
    HINSTANCE m_hPrevInstance;
    LPWSTR m_lpCmdLine;
    int m_nCmdShow;
	
};
