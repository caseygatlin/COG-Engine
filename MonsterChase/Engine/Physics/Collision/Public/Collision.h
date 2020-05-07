#pragma once

#include "Collideable.h"
#include "../../../Containers/Public/Pointers.h"

namespace Engine
{
	namespace Physics
	{

		void AddCollideable(SmartPtr<Collideable>& i_Collideable);
		void RemoveCollideable(WeakPtr<Collideable>& i_Collideable);

		bool FindCollision(const float& i_dt, WeakPtr<Collideable>& o_Object1, WeakPtr<Collideable>& o_Object2);
		bool CheckCollision(const float& i_dt, WeakPtr<Collideable> i_Object1, WeakPtr<Collideable> i_Object2);

		WeakPtr<Collideable> GetCollideable(const size_t& i_index);
		size_t GetNumCollideables();
		void Destroy();

	}
}