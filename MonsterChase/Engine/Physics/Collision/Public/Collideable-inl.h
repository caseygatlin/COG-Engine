#pragma once

#include "Collideable.h"

namespace Engine
{
	namespace Physics
	{
		inline void Collideable::AssignCallback(std::function<void()> i_callback)
		{

			m_CollisionCallback = i_callback;
			m_IsCallbackBound = true;

		}

		inline void Collideable::Update()
		{

			m_RelativeToWorld = Matrix4::TranslationMatrix_ColVector(m_pObject.Acquire()->getPosition());
			m_BoundingBoxCenterInWorld = m_RelativeToWorld * m_BoundingBox.Center ;

		}

		inline void Collideable::ExecuteCallback()
		{

			if (m_IsCallbackBound)
			{

				m_CollisionCallback();

			}
		}

		inline WeakPtr<GameObject> Collideable::GetObject() const
		{

			return m_pObject;

		}

		inline AABB Collideable::GetBoundingBox() const
		{

			return m_BoundingBox;

		}

		inline Matrix4 Collideable::GetRelativeToWorld() const
		{

			return m_RelativeToWorld;

		}

		inline Point2D Collideable::GetBoundingBoxCenterInWorld() const
		{
			return m_BoundingBoxCenterInWorld;
		}

		inline bool operator==(const Collideable& i_lhs, const Collideable& i_rhs)
		{

			bool objectEqual = i_lhs.GetObject() == i_rhs.GetObject();
			bool boundingBoxEqual = i_lhs.GetBoundingBox() == i_rhs.GetBoundingBox();
			bool relativeToWorldEqual = i_lhs.GetRelativeToWorld() == i_rhs.GetRelativeToWorld();

			return (objectEqual && boundingBoxEqual && relativeToWorldEqual);

		}

		inline bool operator!=(const Collideable& i_lhs, const Collideable& i_rhs)
		{

			bool objectEqual = i_lhs.GetObject() == i_rhs.GetObject();
			bool boundingBoxEqual = i_lhs.GetBoundingBox() == i_rhs.GetBoundingBox();
			bool relativeToWorldEqual = i_lhs.GetRelativeToWorld() == i_rhs.GetRelativeToWorld();

			return (!objectEqual || !boundingBoxEqual || !relativeToWorldEqual);

		}
	}
}


