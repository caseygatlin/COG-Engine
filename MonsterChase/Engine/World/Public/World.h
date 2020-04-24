#pragma once

#include "../../GameObject/Public/GameObject.h"
#include "../../Containers/Public/Pointers.h"

namespace Engine
{
	namespace World
	{

		void AddGameObject(SmartPtr<GameObject>& i_Object);
		void RemoveGameObject(WeakPtr<GameObject>& i_Object);
		WeakPtr<GameObject> GetGameObject(const size_t& i_index);
		size_t GetNumGameObjects();
		void Destroy();

	}
}