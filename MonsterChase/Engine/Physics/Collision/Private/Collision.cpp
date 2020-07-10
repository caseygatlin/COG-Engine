#include "../Public/Collision.h"
#include "../Public/Collideable.h"
#include "../../../Containers/Public/Pointers.h"
#include "../../../GameObject/Public/GameObject.h"
#include "../../../Synchronization/Public/Mutex.h"
#include "../../../Synchronization/Public/ScopeLock.h"

#include <algorithm> 
#include <vector>

namespace Engine
{
	namespace Physics
	{

		std::vector<SmartPtr<Collideable>> Collideables;
		Mutex CollideablesMutex;

		void AddCollideable(SmartPtr<Collideable>& i_Collideable)
		{
			ScopeLock Lock(CollideablesMutex);
			Collideables.push_back(i_Collideable);
		}

		void RemoveCollideable(WeakPtr<Collideable>& i_Collideable)
		{
			ScopeLock Lock(CollideablesMutex);
			SmartPtr<Collideable> collideableToRemove = i_Collideable.Acquire();

			for (auto& collideable : Collideables)
			{

				if (collideable && collideable == collideableToRemove)
				{

					if (collideable != Collideables.back())
					{

						std::swap(collideable, Collideables.back());

					}

					Collideables.pop_back();

				}
			}
		}

		void RemoveCollideable(WeakPtr<GameObject>& i_GameObject)
		{
			ScopeLock Lock(CollideablesMutex);
			for (SmartPtr<Collideable>& collideable : Collideables)
			{

				if (collideable && collideable->GetGameObject() == i_GameObject)
				{

					if (collideable != Collideables.back())
					{

						std::swap(collideable, Collideables.back());

					}

					Collideables.pop_back();

				}
			}
		}

		bool FindCollision(const float& i_dt, WeakPtr<Collideable>& o_Object1, WeakPtr<Collideable>& o_Object2)
		{
			bool collisionFound = false;
			const size_t numCollideables = GetNumCollideables();

			if (numCollideables > 1)
			{
				for (size_t i = 0; i < numCollideables - 1; i++)
				{
					for (size_t j = i + 1; j < numCollideables; j++)
					{
						if (CheckCollision(i_dt, GetCollideable(i), GetCollideable(j)))
						{

							o_Object1 = GetCollideable(i);
							o_Object2 = GetCollideable(j);

							return true;

						}
					}
				}
			}

			return false;
		}

		bool CheckCollision(const float& i_dt, WeakPtr<Collideable> i_Object1, WeakPtr<Collideable> i_Object2)
		{

			if (i_Object1 && i_Object2)
			{

				SmartPtr<Collideable> collideable_1 = i_Object1.Acquire();
				SmartPtr<Collideable> collideable_2 = i_Object2.Acquire();

				collideable_1->Update();
				collideable_2->Update();

				Point2D BBExtents_Collideable1 = collideable_1->GetBoundingBox().Extents;
				Point2D BBExtents_Collideable2 = collideable_2->GetBoundingBox().Extents;

				Point2D BBCenter_Collideable1 = collideable_1->GetBoundingBoxCenterInWorld();
				Point2D BBCenter_Collideable2 = collideable_2->GetBoundingBoxCenterInWorld();

				// X Axis
				float centerDistance_XAxis = fabsf(BBCenter_Collideable1.X() - BBCenter_Collideable2.X());
				float sumOfExtents_XAxis = BBExtents_Collideable1.X() + BBExtents_Collideable2.X();

				if (centerDistance_XAxis > sumOfExtents_XAxis)
				{

					return false;

				}


				// Y Axis
				float centerDistance_YAxis = fabsf(BBCenter_Collideable1.Y() - BBCenter_Collideable2.Y());
				float sumOfExtents_YAxis = BBExtents_Collideable1.Y() + BBExtents_Collideable2.Y();

				if (centerDistance_YAxis > sumOfExtents_YAxis)
				{

					return false;

				}

				return true;
			}

			return false;

		}

		WeakPtr<Collideable> GetCollideable(const size_t& i_index)
		{
			ScopeLock Lock(CollideablesMutex);

			if (i_index >= 0 && i_index < Collideables.size())
			{

				WeakPtr<Collideable> collideable = Collideables.at(i_index);
				return collideable;

			}

			return WeakPtr<Collideable>();

		}

		

		size_t GetNumCollideables()
		{
			ScopeLock Lock(CollideablesMutex);

			return Collideables.size();

		}

		void Destroy()
		{
			ScopeLock Lock(CollideablesMutex);

			Collideables.clear();
			Collideables.shrink_to_fit();

		}

		

	}
}


