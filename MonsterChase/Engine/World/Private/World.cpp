#pragma once

#include "../Public/World.h"
#include "../../GameObject/Public/GameObject.h"
#include "../../Containers/Public/Pointers.h"
#include "../../Physics/Collision/Public/Collision.h"
#include "../../Spawning/Public/ObjectSpawner.h"
#include <vector>


namespace Engine
{
	namespace World
	{
		std::vector<SmartPtr<GameObject>> GameObjects;

		void AddGameObject(SmartPtr<GameObject>& i_Object)
		{
			GameObjects.push_back(i_Object);
		}

		void DestroyGameObject(GameObject* i_Object)
		{
			WeakPtr<GameObject> objectToDestroy;

			for (SmartPtr<GameObject> gameObject : GameObjects)
			{
				if (*gameObject == *i_Object)
				{
					objectToDestroy = gameObject;
				}
			}

			RemoveGameObject(objectToDestroy);
			Physics::RemoveCollideable(objectToDestroy);
		}

		void RemoveGameObject(WeakPtr<GameObject>& i_Object)
		{
			SmartPtr<GameObject> objectToRemove = i_Object.Acquire();

			for (auto& gameObject : GameObjects)
			{
				if (gameObject == objectToRemove)
				{
					if (gameObject != GameObjects.back())
					{

						std::swap(gameObject, GameObjects.back());

					}

					GameObjects.pop_back();

				}
			}
		}

		void Update(const float& i_dt)
		{

			for (SmartPtr<GameObject>& gameObject : GameObjects)
			{
				if (gameObject)
				{

					gameObject->Update(i_dt);

				}
			}
		}

		WeakPtr<GameObject> GetGameObject(const size_t& i_index)
		{

			WeakPtr<GameObject> gameObject = GameObjects.at(i_index);
			return gameObject;

		}

		bool GetFirstGameObjectWithController(HashedString i_ControllerName, WeakPtr<GameObject>& o_GameObject)
		{

			return ObjectSpawner::GetFirstGameObjectWithController(i_ControllerName, o_GameObject);

		}

		size_t GetNumGameObjects()
		{

			return GameObjects.size();

		}

		void Destroy()
		{

			GameObjects.clear();
			GameObjects.shrink_to_fit();

		}
	}
}


