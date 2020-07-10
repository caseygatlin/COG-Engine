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
		template<class S>
		friend class WeakPtr;

		template<class S>
		friend class SmartPtr;

	public:
		SmartPtr() :
			m_pReferenceCount(nullptr),
			m_pObject(nullptr)
		{}

		// Constructor
		explicit SmartPtr(T* i_pObject);

#pragma region Copy Constructors

#pragma region From SmartPtr

		// Copy constructor from SmartPtr of same template class.
		SmartPtr(const SmartPtr& i_src) :
			m_pReferenceCount(i_src.m_pReferenceCount),
			m_pObject(i_src.m_pObject)
		{
			if (m_pReferenceCount)
			{

				m_pReferenceCount->NumSmartPtrs++;

			}
		}   

		// Move copy constructor from SmartPtr of same template class.
		SmartPtr(SmartPtr&& i_src) noexcept :
			m_pReferenceCount(i_src.m_pReferenceCount),
			m_pObject(i_src.m_pObject)
		{

			i_src.m_pReferenceCount = nullptr;
			i_src.m_pObject = nullptr;

		}

		// Copy constructor from SmartPtr of different template class.
		template<class S>
		SmartPtr(const SmartPtr<S>& i_src) :
			m_pReferenceCount(i_src.m_pReferenceCount),
			m_pObject(static_cast<T*>(const_cast<S*>(i_src.m_pObject)))
		{
			if (m_pReferenceCount)
			{

				m_pReferenceCount->NumSmartPtrs++;

			}
		}

		// Move copy constructor from SmartPtr of different template class.
		template<class S>
		SmartPtr(SmartPtr<S>&& i_src) :
			m_pReferenceCount(i_src.m_pReferenceCount),
			m_pObject(static_cast<T*>(i_src.m_pObject))
		{

			i_src.m_pReferenceCount = nullptr;
			i_src.m_pObject = nullptr;

		}

#pragma endregion

#pragma region From WeakPtr

		// Copy constructor from WeakPtr of same template class.
		inline SmartPtr(const WeakPtr<T>& i_WeakPtr);

		// Move copy constructor from WeakPtr of same template class.
		SmartPtr(WeakPtr<T>&& i_WeakPtr) :
			m_pReferenceCount(i_WeakPtr.m_pReferenceCount),
			m_pObject(i_WeakPtr.m_pObject)
		{

			i_WeakPtr.m_pReferenceCount = nullptr;
			i_WeakPtr.m_pObject = nullptr;

		}

		// Copy constructor from WeakPtr of different template class
		template<class S>
		inline SmartPtr(const WeakPtr<S>& i_WeakPtr);

		// Move copy constructor from WeakPtr of different template class.
		template<class S>
		SmartPtr(WeakPtr<S>&& i_WeakPtr) :
			m_pReferenceCount(i_WeakPtr.m_pReferenceCount),
			m_pObject(i_WeakPtr.m_pObject)
		{

			i_WeakPtr.m_pReferenceCount = nullptr;
			i_WeakPtr.m_pObject = nullptr;

		}

#pragma endregion

#pragma endregion

#pragma region Assignment Operators

#pragma region From SmartPtr

		// Assignment operator from SmartPtr of same template class.
		inline SmartPtr& operator=(const SmartPtr& i_src);

		// Assignment operator from SmartPtr of different template class.
		template<class S>
		inline SmartPtr& operator=(const SmartPtr<S>& i_src);

		// Move assignment operator from SmartPtr of different template class.
		template<class S>
		inline SmartPtr& operator=(SmartPtr<S>&& i_src);

#pragma endregion

#pragma region From WeakPtr

		// Assignment operator from WeakPtr of same template class.
		inline SmartPtr& operator=(const WeakPtr<T>& i_src);

		// Assignment operator from WeakPtr of different template class.
		template<class S>
		inline SmartPtr& operator=(const WeakPtr<S>& i_src);

		// Move assignment operator from WeakPtr of different template class.
		template<class S>
		inline SmartPtr& operator=(WeakPtr<S>&& i_src);

#pragma endregion

#pragma region From Nullptr

		// Assignment operator from nullptr.
		inline SmartPtr& operator=(std::nullptr_t i_nullptr);

#pragma endregion

#pragma region From template class T

		// Assignment operator from pointer of template class.
		inline SmartPtr& operator=(T* i_src);

#pragma endregion

#pragma endregion

		// Destructor
		inline ~SmartPtr();

        // -> Operator
		inline T* operator->();

        // * Operator
		inline T& operator*();

		// Bool operator
		inline operator bool();

#pragma region Equality / Inequality Operators

		// Equality with SmartPtr of same template class.
		inline bool operator==(const SmartPtr& i_rhs);

		// Equality with SmartPtr of different template class.
		template<class S>
		inline bool operator==(const SmartPtr<S> & i_rhs);

		// Inequality with SmartPtr of same template class.
		inline bool operator!=(const SmartPtr& i_rhs);

		// Inequality with SmartPtr of different template class.
		template<class S>
		inline bool operator!=(const SmartPtr<S>& i_src);

#pragma endregion


	private:

		// Release this SmartPtr as an owner
		inline void Release();

		ReferenceCount* m_pReferenceCount;
		T* m_pObject;

	};

#pragma endregion

	//------------- Weak Ptr Class-----------------
#pragma region Weak Ptr

	template<class T>
	class WeakPtr
	{
		template<class S>
		friend class SmartPtr;

		template<class S>
		friend class WeakPtr;

	public:

		WeakPtr() :
			m_pReferenceCount(nullptr),
			m_pObject(nullptr)
		{}

#pragma region Copy Constructors

#pragma region From SmartPtr

		// Copy constructor from SmartPtr of different template class.
		template<class S>
		WeakPtr(const SmartPtr<S>& i_src) :
			m_pReferenceCount(i_src.m_pReferenceCount),
			m_pObject(const_cast<T*>(i_src.m_pObject))
		{
			if (m_pReferenceCount)
			{
				m_pReferenceCount->NumWeakPtrs++;
			}
		}

#pragma endregion 

#pragma region From WeakPtr

		// Copy constructor from WeakPtr of same template class.
		WeakPtr(const WeakPtr<T>& i_src) :
			m_pReferenceCount(i_src.m_pReferenceCount),
			m_pObject(i_src.m_pObject)
		{
			if (m_pReferenceCount)
			{
				m_pReferenceCount->NumWeakPtrs++;
			}
		}

		// Copy constructor from WeakPtr of different template class.
		template<class S>
		WeakPtr(const WeakPtr<S>& i_src) :
			m_pReferenceCount(i_src.m_pReferenceCount),
			m_pObject(i_src.m_pObject)
		{
			if (m_pReferenceCount)
			{
				m_pReferenceCount->NumWeakPtrs++;
			}
		}

#pragma endregion

#pragma endregion

#pragma region Assignment Operators

#pragma region From SmartPtr

		// Assignment operator from SmartPtr of same template class.
		inline WeakPtr<T>& operator=(const SmartPtr<T>& i_src);

		// Assignment operator from SmartPtr of different template class.
		template<class S>
		inline WeakPtr<T>& operator=(const SmartPtr<S>& i_src);

#pragma endregion

#pragma region From WeakPtr

		// Assignment operator from WeakPtr of same template class.
		inline WeakPtr<T>& operator=(const WeakPtr& i_src);

		// Assignment operator from WeakPtr of different template class.
		template<class S>
		inline WeakPtr<T>& operator=(const WeakPtr<S>& i_src);

#pragma endregion

#pragma region From Nullptr

		// Assignment operator from nullptr
		inline WeakPtr<T>& operator=(std::nullptr_t i_nullptr);

#pragma endregion

#pragma endregion

		// Destructor
		inline ~WeakPtr();

		// Acquire SmartPtr from this WeakPtr
		inline SmartPtr<T> Acquire();

		// Boolean operator
		inline operator bool();

#pragma region Equality / Inequality Operators

		// Equality with WeakPtr of same template class.
		inline bool operator==(const WeakPtr& i_rhs);

		// Equality with WeakPtr of different template class.
		template<class S>
		inline bool operator==(const WeakPtr<S>& i_rhs);

		// Inequality with WeakPtr of same template class.
		inline bool operator!=(const WeakPtr& i_rhs);

		// Inequality with WeakPtr of different template class.
		template<class S>
		inline bool operator!=(const WeakPtr<S>& i_src);

#pragma endregion

	private:

		// Releases this WeakPtr as an observer
		inline void Release();

		ReferenceCount* m_pReferenceCount;
		T* m_pObject;

	};

#pragma endregion

}

#include "Pointers-inl.h"