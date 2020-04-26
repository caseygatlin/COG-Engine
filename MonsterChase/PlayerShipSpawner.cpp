
#include "PlayerShipSpawner.h"

#include "JobSystem/Public/JobSystem.h"
#include "Spawning/Public/ObjectSpawner.h"

#include <Windows.h>

void PlayerShipSpawner::SpawnShip()
{
	Sleep(1000);

	Engine::ObjectSpawner::SpawnGameObject("Content\\PlayerShipData.json");

	while (Engine::JobSystem::HasJobs("Default"))
	{
		Sleep(10);
	}

	if (!Engine::JobSystem::ShutdownRequested())
	{
		Engine::JobSystem::RequestShutdown();
	}
}