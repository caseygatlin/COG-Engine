#pragma once

#include "Pointers.h"

namespace Engine
{
	//------------- Smart Ptr Class-----------------
#pragma region Smart Ptr

	template<class T>
	inline SmartPtr<T>::SmartPtr(T* i_pObject)
	{

		if (i_pObject)
		{
			m_pReferenceCount = new ReferenceCount(1, 0);
		}
		else
		{
			m_pReferenceCount = nullptr;
		}

		m_pObject = i_pObject;

	}

	template<class T>
	inline SmartPtr<T>::SmartPtr(const WeakPtr<T>& i_WeakPtr)
	{
		if (i_WeakPtr.m_pReferenceCount)
		{
			// If there are no smart pointers, create one and set the object to nullptr
			if (i_WeakPtr.m_pReferenceCount->NumSmartPtrs == 0)
			{

				m_pReferenceCount = i_WeakPtr.m_pReferenceCount;
				m_pObject = nullptr;

				if (m_pReferenceCount)
				{

					m_pReferenceCount->NumSmartPtrs++;

				}
			}

			// if there are smart pointers, create one and add reference count
			else
			{

				m_pReferenceCount = i_WeakPtr.m_pReferenceCount;
				m_pObject = i_WeakPtr.m_pObject;

				if (m_pReferenceCount)
				{

					m_pReferenceCount->NumSmartPtrs++;

				}

			}
		}

		else
		{

			m_pReferenceCount = nullptr;
			m_pObject = nullptr;

		}
		
	}

	template<class T>
	template<class S>
	inline SmartPtr<T>::SmartPtr(const WeakPtr<S>& i_WeakPtr)
	{
		// If there are no smart pointers, create one and set the object to nullptr
		if (i_WeakPtr.m_pReferenceCount->NumSmartPtrs == 0)
		{

			m_pReferenceCount = i_WeakPtr.m_pReferenceCount;
			m_pObject = nullptr;

			if (m_pReferenceCount)
			{

				m_pReferenceCount->NumSmartPtrs++;

			}
		}

		// if there are smart pointers, create one and add reference count
		else
		{

			m_pReferenceCount = i_WeakPtr.m_pReferenceCount;
			m_pObject = i_WeakPtr.m_pObject;

			if (m_pReferenceCount)
			{

				m_pReferenceCount->NumSmartPtrs++;

			}

		}
	}

	template<class T>
	inline SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr& i_src)
	{
		if (m_pObject != i_src.m_pObject)
		{

			Release();

			m_pObject = i_src.m_pObject;
			m_pReferenceCount = i_src.m_pReferenceCount;

			if (m_pReferenceCount)
			{

				m_pReferenceCount->NumSmartPtrs++;

			}
		}

		return (*this);

	}

	template<class T>
	template<class S>
	inline SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<S>& i_src)
	{
		if (m_pObject != i_src.m_pObject)
		{

			Release();

			m_pReferenceCount = i_src.m_pReferenceCount;
			m_pObject = i_src.m_pObject;

			if (m_pReferenceCount)
			{

				m_pReferenceCount->NumSmartPtrs++;

			}
		}

		return (*this);
	}

	template<class T>
	template<class S>
	inline SmartPtr<T>& SmartPtr<T>::operator=(SmartPtr<S>&& i_src)
	{
		if (m_pObject != i_src.m_pObject)
		{

			Release();

			m_pReferenceCount = i_src.m_pReferenceCount;
			m_pObject = i_src.m_pObject;

			i_src.m_pObject = nullptr;
			i_src.m_pReferenceCount = nullptr;

			if (m_pReferenceCount)
			{

				m_pReferenceCount->NumSmartPtrs++;

			}
		}

		return (*this);
	}

	template<class T>
	inline SmartPtr<T>& SmartPtr<T>::operator=(const WeakPtr<T>& i_src)
	{
		if (m_pObject != i_src.m_pObject)
		{

			Release();

			if (i_src.m_pReferenceCount && i_src.m_pReferenceCount->NumSmartPtrs > 0)
			{

				m_pObject = i_src.m_pObject;
				m_pReferenceCount = i_src.m_pReferenceCount;

			}

			else
			{

				m_pObject = nullptr;
				m_pReferenceCount = nullptr;

			}
		}

		return (*this);

	}

	template<class T>
	template<class S>
	inline SmartPtr<T>& SmartPtr<T>::operator=(const WeakPtr<S>& i_src)
	{
		if (m_pObject != i_src.m_pObject)
		{

			Release();

			if (i_src.m_pReferenceCount && i_src.m_pReferenceCount->NumSmartPtrs > 0)
			{

				m_pObject = i_src.m_pObject;
				m_pReferenceCount = i_src.m_pReferenceCount;

			}

			else
			{

				m_pObject = nullptr;
				m_pReferenceCount = nullptr;

			}
		}

		return (*this);

	}


	template<class T>
	template<class S>
	inline SmartPtr<T>& SmartPtr<T>::operator=(WeakPtr<S>&& i_src)
	{
		if (m_pObject != i_src.m_pObject)
		{

			Release();

			m_pObject = i_src.m_pObject;
			m_pReferenceCount = i_src.m_pReferenceCount;

			i_src.m_pObject = nullptr;
			i_src.m_pReferenceCount = nullptr;

		}

		return (*this);

	}

	template<class T>
	inline SmartPtr<T>& SmartPtr<T>::operator=(std::nullptr_t i_nullptr)
	{
		Release();

		m_pObject = nullptr;
		m_pReferenceCount = nullptr;

		return (*this);
	}

	template<class T>
	inline SmartPtr<T>& SmartPtr<T>::operator=(T* i_src)
	{
		if (m_pObject != i_src)
		{

			Release();

			m_pObject = i_src;
			
			if (i_src)
			{
				m_pReferenceCount = new ReferenceCount(1, 0);
			}
			else
			{
				m_pReferenceCount = nullptr;
			}
		}

		return (*this);
	}

	template<class T>
	inline SmartPtr<T>::~SmartPtr()
	{
		Release();
	}

	template<class T>
	inline T* SmartPtr<T>::operator->()
	{
		return m_pObject;
	}

	template<class T>
	inline T& SmartPtr<T>::operator*()
	{
		return (*m_pObject);
	}

	template<class T>
	inline SmartPtr<T>::operator bool()
	{
		return m_pObject != nullptr;
	}

	template<class T>
	inline bool SmartPtr<T>::operator==(const SmartPtr<T>& i_rhs)
	{

		bool objectsEqual = m_pObject == i_rhs.m_pObject;
		bool countEqual = m_pReferenceCount == i_rhs.m_pReferenceCount;

		return (objectsEqual && countEqual);

	}

	template<class T>
	template<class S>
	inline bool SmartPtr<T>::operator==(const SmartPtr<S>& i_rhs)
	{

		bool objectsEqual = m_pObject == i_rhs.m_pObject;
		bool countEqual = m_pReferenceCount == i_rhs.m_pReferenceCount;

		return (objectsEqual && countEqual);

	}

	template<class T>
	inline bool SmartPtr<T>::operator!=(const SmartPtr<T>& i_rhs)
	{

		bool objectsEqual = m_pObject == i_rhs.m_pObject;
		bool countEqual = m_pReferenceCount == i_rhs.m_pReferenceCount;

		return !(objectsEqual && countEqual);

	}

	template<class T>
	template<class S>
	inline bool SmartPtr<T>::operator!=(const SmartPtr<S>& i_rhs)
	{

		bool objectsEqual = m_pObject == i_rhs.m_pObject;
		bool countEqual = m_pReferenceCount == i_rhs.m_pReferenceCount;

		return !(objectsEqual && countEqual);

	}
	
	template<class T>
	inline void SmartPtr<T>::Release()
	{
		if (m_pReferenceCount)
		{
			if (--(m_pReferenceCount->NumSmartPtrs) == 0)
			{

				delete m_pObject;

				if (m_pReferenceCount->NumWeakPtrs == 0)
				{

					delete m_pReferenceCount;

				}
				else
				{
					m_pReferenceCount = nullptr;
				}
			}
			else
			{
				m_pObject = nullptr;
			}
		}
	}

#pragma endregion

	//------------- Weak Ptr Class-----------------
#pragma region Weak Ptr

	template<class T>
	inline WeakPtr<T>& WeakPtr<T>::operator=(const SmartPtr<T>& i_src)
	{

		if (m_pObject != i_src.m_pObject)
		{

			Release();

			m_pObject = i_src.m_pObject;
			m_pReferenceCount = i_src.m_pReferenceCount;

			if (m_pReferenceCount)
			{
				m_pReferenceCount->NumWeakPtrs++;
			}
		}

		return (*this);
	}

	template<class T>
	template<class S>
	inline WeakPtr<T>& WeakPtr<T>::operator=(const SmartPtr<S>& i_src)
	{

		if (m_pObject != i_src.m_pObject)
		{

			Release();

			m_pObject = i_src.m_pObject;
			m_pReferenceCount = i_src.m_pReferenceCount;

			if (m_pReferenceCount)
			{
				m_pReferenceCount->NumWeakPtrs++;
			}
		}

		return (*this);
	}

	template<class T>
	inline WeakPtr<T>& WeakPtr<T>::operator=(const WeakPtr& i_src)
	{
		if (i_src.m_pReferenceCount)
		{
			if (m_pObject != i_src.m_pObject)
			{
				Release();

				m_pObject = i_src.m_pObject;
				m_pReferenceCount = i_src.m_pReferenceCount;

				if (m_pReferenceCount)
				{
					m_pReferenceCount->NumWeakPtrs++;
				}
			}

		}
		else
		{
			m_pReferenceCount = nullptr;
			m_pObject = nullptr;
		}


		return *this;



	}

	template<class T>
	template<class S>
	inline WeakPtr<T>& WeakPtr<T>::operator=(const WeakPtr<S>& i_src)
	{
		if (m_pObject != i_src.m_pObject)
		{
			Release();

			m_pObject = i_src.m_pObject;
			m_pReferenceCount = i_src.m_pReferenceCount;

			if (m_pReferenceCount)
			{
				m_pReferenceCount->NumWeakPtrs++;
			}
		}

		return *this;
	}

	template<class T>
	inline WeakPtr<T>& WeakPtr<T>::operator=(std::nullptr_t i_nullptr)
	{

		Release();

		m_pObject = nullptr;
		m_pReferenceCount = nullptr;

		return (*this);

	}

	template<class T>
	inline WeakPtr<T>::~WeakPtr()
	{
		Release();
	}

	template<class T>
	inline SmartPtr<T> WeakPtr<T>::Acquire()
	{
		return SmartPtr<T>(*this);
	}

	template<class T>
	inline WeakPtr<T>::operator bool()
	{
		if (m_pReferenceCount)
		{
			return m_pReferenceCount->NumSmartPtrs > 0;
		}

		return false;
	}

	template<class T>
	inline bool WeakPtr<T>::operator==(const WeakPtr<T>& i_rhs)
	{

		bool objectsEqual = m_pObject == i_rhs.m_pObject;
		bool countEqual = m_pReferenceCount == i_rhs.m_pReferenceCount;

		return (objectsEqual && countEqual);

	}

	template<class T>
	template<class S>
	inline bool WeakPtr<T>::operator==(const WeakPtr<S>& i_rhs)
	{

		bool objectsEqual = m_pObject == i_rhs.m_pObject;
		bool countEqual = m_pReferenceCount == i_rhs.m_pReferenceCount;

		return (objectsEqual && countEqual);

	}

	template<class T>
	inline bool WeakPtr<T>::operator!=(const WeakPtr<T>& i_rhs)
	{

		bool objectsEqual = m_pObject == i_rhs.m_pObject;
		bool countEqual = m_pReferenceCount == i_rhs.m_pReferenceCount;

		return !(objectsEqual && countEqual);

	}

	template<class T>
	template<class S>
	inline bool WeakPtr<T>::operator!=(const WeakPtr<S>& i_rhs)
	{

		bool objectsEqual = m_pObject == i_rhs.m_pObject;
		bool countEqual = m_pReferenceCount == i_rhs.m_pReferenceCount;

		return !(objectsEqual && countEqual);

	}

	template<class T>
	inline void WeakPtr<T>::Release()
	{
		if (m_pReferenceCount)
		{
			if (--(m_pReferenceCount->NumWeakPtrs) <= 0)
			{
				m_pReferenceCount->NumWeakPtrs = 0;

				if (m_pReferenceCount->NumSmartPtrs == 0)
				{
					delete m_pReferenceCount;
					m_pObject = nullptr;
					m_pReferenceCount = nullptr;
				}
			}
		}
	}

#pragma endregion

}