#pragma once

#include "Collideable.h"
#include "../../../Containers/Public/Pointers.h"
#include "../../../GameObject/Public/GameObject.h"

namespace Engine
{
	namespace Physics
	{

		// Adds a collideable to  the collideables list.
		void AddCollideable(SmartPtr<Collideable>& i_Collideable);
		
		// Removes a collideable from the collideables list given a Collideable.
		void RemoveCollideable(WeakPtr<Collideable>& i_Collideable);
		
		// Removes a collideable from the collideables list given a GameObject.
		void RemoveCollideable(WeakPtr<GameObject>& i_GameObject);

		// Finds a possible collision between two collideables.
		bool FindCollision(const float& i_dt, WeakPtr<Collideable>& o_Object1, WeakPtr<Collideable>& o_Object2);
		
		// Checks whether a collision occurred between two collideables using Swept Separating Axis.
		bool CheckCollision(const float& i_dt, WeakPtr<Collideable> i_Object1, WeakPtr<Collideable> i_Object2);

		// Returns a WeakPtr to a collideable in the collideables list at a given index.
		WeakPtr<Collideable> GetCollideable(const size_t& i_index);
		
		// Returns the current size of the collideables list.
		size_t GetNumCollideables();
		
		// Empties the collideables list.
		void Destroy();

	}
}
