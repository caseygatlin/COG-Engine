#include "Game.h"
#include "Graphics/Public/Graphics.h"
#include "GLib.h"
#include <Windows.h>

void Game::Run()
{
    // IMPORTANT: first we need to initialize GLib
    bool bSuccess = GLib::Initialize(m_hInstance, m_nCmdShow, "GLibTest", -1, 800, 600);

    if (bSuccess)
    {
        // IMPORTANT (if we want keypress info from GLib): Set a callback for notification of key presses
        GLib::SetKeyStateChangeCallback(Engine::Graphics::TestKeyCallback);

        // Create a couple of sprites using our own helper routine CreateSprite
        m_pGoodGuy = Engine::Graphics::CreateSprite("data\\GoodGuy.dds");
        m_pBadGuy = Engine::Graphics::CreateSprite("data\\BadGuy.dds");

        bool bQuit = false;

        do
        {
            Engine::Graphics::Present(bQuit, m_pGoodGuy, m_pBadGuy);

        } while (bQuit == false);

        if (m_pGoodGuy)
            GLib::Sprites::Release(m_pGoodGuy);
        if (m_pBadGuy)
            GLib::Sprites::Release(m_pBadGuy);

        // IMPORTANT:  Tell GLib to shutdown, releasing resources.
        GLib::Shutdown();
    }

}