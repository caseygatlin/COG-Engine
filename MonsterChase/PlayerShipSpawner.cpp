
#include "PlayerShipSpawner.h"

#include "Console/Public/ConsolePrint.h"
#include "JobSystem/Public/JobSystem.h"
#include "Spawning/Public/ObjectSpawner.h"
#include "Physics/Collision/Public/Collision.h"

#include <Windows.h>

void PlayerShipSpawner::SpawnShip()
{
	Sleep(1000);

	Engine::ObjectSpawner::SpawnCollideable("Content\\PlayerShipData.json");
	Engine::Physics::GetCollideable(0).Acquire()->AssignCallback(std::bind(&PlayerShipSpawner::OnCollision, this));

	while (Engine::JobSystem::HasJobs("Default"))
	{
		Sleep(10);
	}

	if (!Engine::JobSystem::ShutdownRequested())
	{
		Engine::JobSystem::RequestShutdown();
	}
}

void PlayerShipSpawner::OnCollision()
{
	DEBUG_PRINT("Player Ship Collision Detected...\n");
}
