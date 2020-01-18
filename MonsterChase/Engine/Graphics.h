#pragma once

#include <Windows.h>

namespace GLib
{
    namespace Sprites
    {
        struct Sprite;
    }
}


namespace Engine
{
    namespace Graphics
    {

        void* LoadFile(const char* i_pFilename, size_t& o_sizefile);
        GLib::Sprites::Sprite* CreateSprite(const char* i_pFilename);
        void TestKeyCallback(unsigned int i_VKeyID, bool bWentDown);
        bool Init(HINSTANCE i_hInstance, HINSTANCE i_hPrevInstance, LPWSTR i_lpCmdLine, int i_nCmdShow);
        void Present(bool& o_bQuit, GLib::Sprites::Sprite * i_pSprite_1, GLib::Sprites::Sprite * i_pSprite_2);
    }
}




