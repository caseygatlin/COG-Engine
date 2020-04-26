#include "AsteroidSpawner.h"
#include "JobSystem/Public/JobSystem.h"
#include "Spawning/Public/ObjectSpawner.h"
#include <Windows.h>

void AsteroidSpawner::operator() ()
{
	Sleep(2000);

	Engine::ObjectSpawner::SpawnGameObject("Content\\AsteroidData.json");

	while (Engine::JobSystem::HasJobs("Default"))
	{
		Sleep(10);
	}

	if (!Engine::JobSystem::ShutdownRequested())
	{
		Engine::JobSystem::RequestShutdown();
	}
}