#pragma once

#include "RenderData.h"
#include <Windows.h>
#include <vector>

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
        static std::vector<RenderData> renderData;

        void Init(HINSTANCE i_hInstance, HINSTANCE i_hPrevInstance, LPWSTR i_lpCmdLine, int i_nCmdShow);
        void AddRenderData(const RenderData& i_renderData);
        void* LoadFile(const char* i_pFilename, size_t& o_sizefile);
        GLib::Sprites::Sprite* CreateSprite(const char* i_pFilename);
        void TestKeyCallback(unsigned int i_VKeyID, bool bWentDown);
        void Present();
        void Shutdown();


    }
}




