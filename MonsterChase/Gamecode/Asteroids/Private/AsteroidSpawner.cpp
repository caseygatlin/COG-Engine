#include "../Public/AsteroidSpawner.h"
#include "../../Custom Components/Public/RandomSpawnComponent.h"

#include "Console/Public/ConsolePrint.h"
#include "JobSystem/Public/JobSystem.h"
#include "Spawning/Public/ObjectSpawner.h"
#include "World/Public/World.h"
#include "Components/Public/IGOComponent.h"
#include "Containers/Public/Point2D.h"
#include "Physics/Collision/Public/Collision.h"

#include <Windows.h>

void AsteroidSpawner::operator() ()
{
	using namespace Engine;

	Sleep(2000);

	const size_t MaxNumAsteroids = 10;
	size_t numAsteroids = 0;

	while (JobSystem::HasJobs("Default"))
	{
		Sleep(4000);
		if (numAsteroids < MaxNumAsteroids)
		{
			numAsteroids++;
			ObjectSpawner::SpawnCollideable("Content\\AsteroidData.json");
			Physics::GetCollideable(numAsteroids).Acquire()->AssignCallback(std::bind(&AsteroidSpawner::OnCollision, this));

			SmartPtr<GameObject> asteroid = Engine::World::GetGameObject(numAsteroids).Acquire();
			asteroid->Attach(CreateComponent<RandomSpawnComponent>());
			Point2D asteroidPosition = asteroid->GetPosition();
			float asteroidDirX = (asteroidPosition.X() > 0) ? -1.0f : 1.0f;
			float asteroidDirY = (asteroidPosition.Y() > 0) ? -1.0f : 1.0f;
			asteroid->ChangeDir(Point2D(asteroidDirX, asteroidDirY));
		}

	}

	if (!JobSystem::ShutdownRequested())
	{
		JobSystem::RequestShutdown();
	}
}

void AsteroidSpawner::OnCollision()
{
	DEBUG_PRINT("Asteroid Collision Detected...\n");
}