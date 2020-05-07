#include "AsteroidSpawner.h"

#include "Console/Public/ConsolePrint.h"
#include "JobSystem/Public/JobSystem.h"
#include "Spawning/Public/ObjectSpawner.h"
#include "Physics/Collision/Public/Collision.h"

#include <Windows.h>

void AsteroidSpawner::operator() ()
{
	Sleep(2000);

	Engine::ObjectSpawner::SpawnCollideable("Content\\AsteroidData.json");
	Engine::Physics::GetCollideable(1).Acquire()->AssignCallback(std::bind(&AsteroidSpawner::OnCollision, this));

	while (Engine::JobSystem::HasJobs("Default"))
	{
		Sleep(10);
	}

	if (!Engine::JobSystem::ShutdownRequested())
	{
		Engine::JobSystem::RequestShutdown();
	}
}

void AsteroidSpawner::OnCollision()
{
	DEBUG_PRINT("Asteroid Collision Detected...\n");
}