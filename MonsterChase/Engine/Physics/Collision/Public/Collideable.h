#pragma once

#include "../../../GameObject/Public/GameObject.h"
#include "../../../Containers/Public/Pointers.h"
#include "AABB.h"
#include "../../../Containers/Public/Matrix4.h"
#include "../../../Containers/Public/Point2D.h"

#include <functional>


namespace Engine
{
	namespace Physics
	{
		class Collideable
		{
		public:

			static SmartPtr<Collideable> CreateCollideable()
			{
				SmartPtr<Collideable> collideable(new Collideable());
				return collideable;
			}

			static SmartPtr<Collideable> CreateCollideable(WeakPtr<GameObject> i_pObject, AABB i_boundingBox)
			{
				SmartPtr<Collideable> collideable(new Collideable(i_pObject, i_boundingBox));
				return collideable;
			}

			Collideable(const Collideable& i_src) :
				m_pObject(i_src.m_pObject),
				m_BoundingBox(i_src.m_BoundingBox),
				m_RelativeToWorld(i_src.m_RelativeToWorld),
				m_BoundingBoxCenterInWorld(i_src.m_BoundingBoxCenterInWorld),
				m_CollisionCallback(i_src.m_CollisionCallback),
				m_IsCallbackBound(i_src.m_IsCallbackBound)
			{}

			Collideable& operator=(const Collideable& i_src)
			{

				if (this != &i_src)
				{

					m_pObject = i_src.m_pObject;
					m_BoundingBox = i_src.m_BoundingBox;
					m_RelativeToWorld = i_src.m_RelativeToWorld;
					m_BoundingBoxCenterInWorld = i_src.m_BoundingBoxCenterInWorld;

				}

				return (*this);

			}

			Collideable& operator=(const Collideable&& i_src) noexcept
			{

				m_pObject = i_src.m_pObject;
				m_BoundingBox = i_src.m_BoundingBox;
				m_RelativeToWorld = i_src.m_RelativeToWorld;
				m_BoundingBoxCenterInWorld = i_src.m_BoundingBoxCenterInWorld;

				return (*this);

			}

			inline void AssignCallback(std::function<void()> i_callback);
			inline void Update();
			inline void ExecuteCallback();

			inline WeakPtr<GameObject> GetGameObject() const;
			inline AABB GetBoundingBox() const;
			inline Matrix4 GetRelativeToWorld() const;
			inline Point2D GetBoundingBoxCenterInWorld() const;

		private:
			Collideable() :
				m_pObject(),
				m_BoundingBox(),
				m_RelativeToWorld(Matrix4::IdentityMatrix),
				m_BoundingBoxCenterInWorld(),
				m_CollisionCallback(),
				m_IsCallbackBound(false)
			{}

			Collideable(WeakPtr<GameObject> i_pObject, AABB i_boundingBox) :
				m_pObject(i_pObject),
				m_BoundingBox(i_boundingBox),
				m_RelativeToWorld(Matrix4::TranslationMatrix_ColVector(i_pObject.Acquire()->GetPosition())),
				m_BoundingBoxCenterInWorld(m_RelativeToWorld* i_boundingBox.Center),
				m_CollisionCallback(),
				m_IsCallbackBound(false)
			{}

			WeakPtr<GameObject> m_pObject;
			AABB m_BoundingBox;
			Matrix4 m_RelativeToWorld;
			Point2D m_BoundingBoxCenterInWorld;
			std::function<void()> m_CollisionCallback;
			bool m_IsCallbackBound;

		};

		inline bool operator==(const Collideable& i_lhs, const Collideable& i_rhs);
		inline bool operator!=(const Collideable& i_lhs, const Collideable& i_rhs);

	}
}

#include "Collideable-inl.h"