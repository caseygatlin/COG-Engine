#include "../Public/GameOverScreen.h"

#include "GameObject/Public/GameObject.h"
#include "Containers/Public/Pointers.h"
#include "Spawning/Public/ObjectSpawner.h"
#include "JobSystem/Public/JobSystem.h"

void GameOverScreen::ShowScreen()
{

	using namespace Engine;

	SmartPtr<GameObject> gameOverText;
	ObjectSpawner::SpawnGameObject("Content\\GameOverData.json", gameOverText);

	while (JobSystem::HasJobs("Default")) {}

	if (!JobSystem::ShutdownRequested())
	{

		JobSystem::RequestShutdown();

	}
}
