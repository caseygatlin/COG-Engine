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

	// Give time for window and player to initialize.
	Sleep(2000);

	// Initialize number of asteroids.
	size_t numAsteroids = 0;

	// Continuously spawn asteroids until signaled otherwise.
	while (m_bContinueSpawning)
	{
		// Wait for one second between spawning asteroids.
		Sleep(1000);
		numAsteroids++;

		// Create a SmartPtr of the asteroid.
		SmartPtr<Physics::Collideable> asteroidCollideable;
		
		// Call the ObjectSpawner to spawn a collideable based on given JSON data.
		ObjectSpawner::SpawnCollideable("Content\\AsteroidData.json", asteroidCollideable);
		
		// Assign a collision callback to the asteroid using std::bind.
		asteroidCollideable->AssignCallback(std::bind(&AsteroidSpawner::OnCollision, this));

		SmartPtr<GameObject> asteroid = asteroidCollideable->GetGameObject().Acquire();

		// Create a Random Spawn component
		SmartPtr<IGOComponent> randomSpawnComponentBase = CreateComponent<RandomSpawnComponent>();
		SmartPtr<RandomSpawnComponent> randomSpawnComponent = randomSpawnComponentBase;

		// Set spawn variables based on current asteroid count.
		if (numAsteroids % 2 == 0)
		{

			randomSpawnComponent->SetMaxMin(390, -390, 298, 299);

		}
		
		else
		{

			randomSpawnComponent->SetMaxMin(390, -390, -298, -299);

		}

		// Attach the Random Spawn component to the asteroid created earlier.
		asteroid->Attach(randomSpawnComponentBase);


		// Set the movement direction of the asteroid based on its spawned position.
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
	
	// Action to be performed on collision should be added here.
}
