#pragma once

#include "ReferenceCount.h"

namespace Engine
{
	template<class T>
	class WeakPtr;

	//------------- Smart Ptr Class-----------------
#pragma region Smart Ptr

	template<class T>
	class SmartPtr
	{
	public:

		// Constructor
		explicit SmartPtr(T* i_pObject) :
			m_pReferenceCount(new ReferenceCount(1, 0)),
			m_pObject(i_pObject)
		{}

		// Constructor from WeakPtr
		explicit SmartPtr(WeakPtr& i_WeakPtr);

		// Copy constructor
		SmartPtr(SmartPtr& i_src) :
			m_pObject(i_src.m_pObject),
			m_pReferenceCount(i_src.m_pReferenceCount)
		{
			if (m_pReferenceCount)
			{

				m_pReferenceCount->NumSmartPtrs++;

			}
		}


		// Assignment operators
		inline SmartPtr& operator=(SmartPtr& i_src);
		inline SmartPtr& operator=(WeakPtr& i_src);
		inline SmartPtr& operator=(std::nullptr_t i_nullptr);

		// Destructor
		inline ~SmartPtr();

        // -> Operator
		inline T* operator->();

        // * Operator
		inline T& operator*();

		// Bool operator
		inline operator bool();


	private:

		// Release this SmartPtr as an owner
		inline void Release();

		ReferenceCount* m_pReferenceCount;
		T*				m_pObject

	};

#pragma endregion

	//------------- Weak Ptr Class-----------------
#pragma region Weak Ptr

	template<class T>
	class WeakPtr
	{
	public:
		// Constructor from SmartPtr
		WeakPtr(SmartPtr& i_src) :
			m_pObject(i_src.m_pObject),
			m_pReferenceCount(i_src.m_pReferenceCount)
		{
			if (m_pReferenceCount)
			{
				m_pReferenceCount->NumWeakPtrs++;
			}
		}

		// Copy constructor
		WeakPtr(WeakPtr& i_src) :
			m_pObject(i_src.m_pObject),
			m_pReferenceCount(i_src.m_pReferenceCount)
		{
			if (m_pReferenceCount)
			{
				m_pReferenceCount->NumWeakPtrs++;
			}
		}

		// Assignment operators
		inline WeakPtr& operator=(WeakPtr& i_src);
		inline WeakPtr& operator=(SmartPtr& i_src);
		inline WeakPtr& operator=(std::nullptr_t i_nullptr);

		// Destructor
		inline ~WeakPtr();

		// Acquire SmartPtr from this WeakPtr
		inline SmartPtr<T> Acquire();

		// Boolean operator
		inline operator bool();

	private:

		// Releases this WeakPtr as an observer
		inline void Release();

		ReferenceCount* m_pReferenceCount;
		T* m_pObject;

	};

#pragma endregion

}

#include "Pointers-inl.h"