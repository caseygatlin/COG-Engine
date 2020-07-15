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

#pragma region Public Methods
			
#pragma region Creators
			
			// Create a default Collideable.
			static SmartPtr<Collideable> CreateCollideable()
			{
				SmartPtr<Collideable> collideable(new Collideable());
				return collideable;
			}

			// Create a Collideable given a GameObject and bounding box.
			static SmartPtr<Collideable> CreateCollideable(WeakPtr<GameObject> i_pObject, AABB i_boundingBox)
			{
				SmartPtr<Collideable> collideable(new Collideable(i_pObject, i_boundingBox));
				return collideable;
			}
			
#pragma endregion

#pragma region Copy Constructor
			
			// Copy constructor.
			Collideable(const Collideable& i_src) :
				m_pObject(i_src.m_pObject),
				m_BoundingBox(i_src.m_BoundingBox),
				m_RelativeToWorld(i_src.m_RelativeToWorld),
				m_BoundingBoxCenterInWorld(i_src.m_BoundingBoxCenterInWorld),
				m_CollisionCallback(i_src.m_CollisionCallback),
				m_IsCallbackBound(i_src.m_IsCallbackBound)
			{}
			
#pragma endregion
			
#pragma region Assignment Operators

			// Assignment operator.
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

			// Move Assignment operator.
			Collideable& operator=(const Collideable&& i_src) noexcept
			{

				m_pObject = i_src.m_pObject;
				m_BoundingBox = i_src.m_BoundingBox;
				m_RelativeToWorld = i_src.m_RelativeToWorld;
				m_BoundingBoxCenterInWorld = i_src.m_BoundingBoxCenterInWorld;

				return (*this);

			}
			
#pragma endregion
			
#pragma region Update
			
			// Updates member variables to reflect current position.
			inline void Update();
			
#pragma endregion
			
#pragma region Callback

			// Assigns a function to call when a collision occurs.
			inline void AssignCallback(std::function<void()> i_callback);
			
			// Executes the collision callback. Called when collision occurs.
			inline void ExecuteCallback();
			
#pragma endregion

#pragma region Getters
			
			// Returns the GameObject of this Collideable.
			inline WeakPtr<GameObject> GetGameObject() const;
			
			// Returns the AABB Bounding Box of this Collideable.
			inline AABB GetBoundingBox() const;
			
			// Returns the Relative to World matrix of this Collideable.
			inline Matrix4 GetRelativeToWorld() const;
			
			// Returns the position of this Collideable's Bounding Box in World space.
			inline Point2D GetBoundingBoxCenterInWorld() const;
			
#pragma endregion
			
#pragma endregion

		private:
			
#pragma region Private Methods
			
			// Default constructor.
			Collideable() :
				m_pObject(),
				m_BoundingBox(),
				m_RelativeToWorld(Matrix4::IdentityMatrix),
				m_BoundingBoxCenterInWorld(),
				m_CollisionCallback(),
				m_IsCallbackBound(false)
			{}

			// Constructor given a GameObject and Bounding Box.
			Collideable(WeakPtr<GameObject> i_pObject, AABB i_boundingBox) :
				m_pObject(i_pObject),
				m_BoundingBox(i_boundingBox),
				m_RelativeToWorld(Matrix4::TranslationMatrix_ColVector(i_pObject.Acquire()->GetPosition())),
				m_BoundingBoxCenterInWorld(m_RelativeToWorld * i_boundingBox.Center),
				m_CollisionCallback(),
				m_IsCallbackBound(false)
			{}
			
#pragma endregion

#pragma region Private Variables

			WeakPtr<GameObject> 	m_pObject;			// GameObject of this Collideable
			AABB 			m_BoundingBox;			// Bounding Box that defines the collideable area.
			Matrix4 		m_RelativeToWorld;		// Relative to World transition matrix.
			Point2D 		m_BoundingBoxCenterInWorld;	// Bounding Box center in World space.
			std::function<void()> 	m_CollisionCallback;		// Callback to be executed on collision.
			bool 			m_IsCallbackBound;		// Whether or not the callback has been assigned.
			
#pragma endregion

		};

#pragma region Equality Operators
		
		inline bool operator==(const Collideable& i_lhs, const Collideable& i_rhs);
		inline bool operator!=(const Collideable& i_lhs, const Collideable& i_rhs);
		
#pragma endregion

	}
}

#include "Collideable-inl.h"
