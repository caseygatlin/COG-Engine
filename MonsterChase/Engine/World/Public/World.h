#pragma once

#include "../../GameObject/Public/GameObject.h"
#include "../../Containers/Public/Pointers.h"
#include "../../HashedString/Public/HashedString.h"

namespace Engine
{
	namespace World
	{

		// Adds a GameObject to the world list
		void AddGameObject(SmartPtr<GameObject>& i_Object);

		// Destroys a GameObject in the world and elsewhere
		void DestroyGameObject(GameObject* i_Object);

		// Removes a GameObject from the world list
		void RemoveGameObject(WeakPtr<GameObject>& i_Object);

		// Updates the components of all GameObjects
		void Update(const float& i_dt);

		// Returns a GameObject at a given index
		WeakPtr<GameObject> GetGameObject(const size_t& i_index);

		// Returns the first GameObject with the given controller if possible
		bool GetFirstGameObjectWithController(HashedString i_ControllerName, WeakPtr<GameObject>& o_GameObject);

		// Returns the total number of GameObjects in the world
		size_t GetNumGameObjects();

		// Destroys the list of GameObjects in the world
		void Destroy();

	}
}