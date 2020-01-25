//Casey Gatlin
//Last updated 1/17/20

#include <iostream>
#include "Game.h"
#include "Public/Engine.h"
#include <Windows.h>


int WINAPI wWinMain(HINSTANCE i_hInstance, HINSTANCE i_hPrevInstance, LPWSTR i_lpCmdLine, int i_nCmdShow)
{
	//Announce engine start
	Engine::Init();

    Game game(i_hInstance, i_hPrevInstance, i_lpCmdLine, i_nCmdShow);
    game.Init();

    Engine::Run();

	//Announce engine shutdown
	Engine::Shutdown();
    game.ShutDown();


	return 0;
}




