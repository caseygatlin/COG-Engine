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

void AsteroidSpawner::SpawnAsteroids()
{

	using namespace Engine;

	Sleep(2000);

	size_t numAsteroids = 0;

	while (m_bContinueSpawning)
	{
		Sleep(1000);

		numAsteroids++;

		SmartPtr<Physics::Collideable> asteroidCollideable;
		ObjectSpawner::SpawnCollideable("Content\\AsteroidData.json", asteroidCollideable);
		asteroidCollideable->AssignCallback(std::bind(&AsteroidSpawner::OnCollision, this));

		SmartPtr<GameObject> asteroid = asteroidCollideable->GetGameObject().Acquire();

		SmartPtr<IGOComponent> randomSpawnComponentBase = CreateComponent<RandomSpawnComponent>();
		SmartPtr<RandomSpawnComponent> randomSpawnComponent = randomSpawnComponentBase;

		if (numAsteroids % 2 == 0)
		{

			randomSpawnComponent->SetMaxMin(390, -390, 298, 299);

		}
		else
		{

			randomSpawnComponent->SetMaxMin(390, -390, -298, -299);

		}

		asteroid->Attach(randomSpawnComponentBase);


		Point2D asteroidPosition = asteroid->GetPosition();

		float asteroidDirX = (asteroidPosition.X() > 0) ? -1.0f : 1.0f;
		float asteroidDirY = (asteroidPosition.Y() > 0) ? -1.0f : 1.0f;

		asteroid->ChangeDir(Point2D(asteroidDirX, asteroidDirY));
	}
}

void AsteroidSpawner::StopSpawning()
{
	m_bContinueSpawning = false;
}

void AsteroidSpawner::OnCollision()
{

}