#pragma once

#include "../Public/World.h"
#include "../../GameObject/Public/GameObject.h"
#include "../../Containers/Public/Pointers.h"
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

		void RemoveGameObject(WeakPtr<GameObject>& i_Object)
		{
			SmartPtr<GameObject> objectToRemove = i_Object.Acquire();

			for (auto& gameObject : GameObjects)
			{
				if (gameObject == i_Object)
				{
					if (gameObject != GameObjects.back())
					{

						std::swap(gameObject, GameObjects.back());

					}

					GameObjects.pop_back();
				}
			}
		}

		WeakPtr<GameObject> GetGameObject(const size_t& i_index)
		{
			WeakPtr<GameObject> gameObject = GameObjects.at(i_index);
			return gameObject;
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


