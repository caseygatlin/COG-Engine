#pragma once

#include "../../GameObject/Public/GameObject.h"
#include "../../Containers/Public/Pointers.h"
#include "../../HashedString/Public/HashedString.h"

namespace Engine
{
	namespace World
	{

		void AddGameObject(SmartPtr<GameObject>& i_Object);
		void DestroyGameObject(GameObject* i_Object);
		void RemoveGameObject(WeakPtr<GameObject>& i_Object);

		void Update(const float& i_dt);

		WeakPtr<GameObject> GetGameObject(const size_t& i_index);
		bool GetFirstGameObjectWithController(HashedString i_ControllerName, WeakPtr<GameObject>& o_GameObject);
		size_t GetNumGameObjects();

		void Destroy();

	}
}