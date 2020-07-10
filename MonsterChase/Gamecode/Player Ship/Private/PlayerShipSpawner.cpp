
#include "../Public/PlayerShipSpawner.h"

#include "../../Game/Public/Game.h"
#include "Console/Public/ConsolePrint.h"
#include "JobSystem/Public/JobSystem.h"
#include "Spawning/Public/ObjectSpawner.h"
#include "Components/Public/ComponentType.h"
#include "Components/Public/PlayerControllerComponent.h"
#include "Components/Public/HealthComponent.h"
#include "Components/Public/IGOComponent.h"
#include "Physics/Collision/Public/Collision.h"

#include <Windows.h>

void PlayerShipSpawner::SpawnShip()
{
	using namespace Engine;

	Sleep(1000);

	SmartPtr<Physics::Collideable> playerShipCollideable;
	if (ObjectSpawner::SpawnCollideable("Content\\PlayerShipData.json", playerShipCollideable))
	{

		SmartPtr<GameObject> playerShipObject = playerShipCollideable->GetGameObject().Acquire();

		if (playerShipObject->HasComponent(ComponentType::PLAYER_INPUT))
		{

			SmartPtr<IGOComponent> healthComponentBase = CreateComponent<HealthComponent>();
			playerShipObject->Attach(healthComponentBase);

			SmartPtr<HealthComponent> healthComponent = healthComponentBase;

			healthComponent->SetHealth(1);
			healthComponent->SetMaxHitBufferTime(1000);

			playerShipCollideable->AssignCallback(std::bind(&PlayerShipSpawner::OnCollision, this));

		}
	}
}

void PlayerShipSpawner::OnCollision()
{

	using namespace Engine;
	using namespace Engine::ObjectSpawner;


	WeakPtr<GameObject> playerShipWeakPtr;

	if (GetFirstGameObjectWithController("Player", playerShipWeakPtr))
	{

		WeakPtr<IGOComponent> healthComponentWeakPtr;

		if (playerShipWeakPtr.Acquire()->GetComponent(ComponentType::HEALTH, healthComponentWeakPtr))
		{
			SmartPtr<HealthComponent> healthComponent = healthComponentWeakPtr.Acquire();

			if (healthComponent->TakeDamage())
			{
				m_GameInstance->EndGame();
			}
		}
	}
}
