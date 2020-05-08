//Casey Gatlin
//Last updated 1/17/20

#include <iostream>
#include "../Game/Public/Game.h"
#include "Public/Engine.h"
#include <Windows.h>


int WINAPI wWinMain(HINSTANCE i_hInstance, HINSTANCE i_hPrevInstance, LPWSTR i_lpCmdLine, int i_nCmdShow)
{
	Engine::Init(i_hInstance, i_hPrevInstance, i_lpCmdLine, i_nCmdShow);

    Game game;
    game.Init();

    Engine::Run();

    game.ShutDown();
	Engine::Shutdown();

	return 0;
}




