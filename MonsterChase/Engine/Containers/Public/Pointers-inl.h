#pragma once

#include "Pointers.h"

namespace Engine
{
	//------------- Smart Ptr Class-----------------
#pragma region Smart Ptr

	template<class T>
	SmartPtr<T>::SmartPtr(WeakPtr<T>& i_WeakPtr)
	{
		// If there are no smart pointers, create one and set the object to nullptr
		if (i_WeakPtr.m_pReferenceCount->NumSmartPtrs == 0)
		{
			m_pReferenceCount = i_WeakPtr.m_pReferenceCount;
			m_pObject = nullptr;

			m_pReferenceCount->NumSmartPtrs++;
		}

		// if there are smart pointers, create one and add reference count
		else
		{
			m_pReferenceCount = i_WeakPtr.m_pReferenceCount;
			m_pObject = i_WeakPtr.m_pObject;

			m_pReferenceCount->NumSmartPtrs++;
		}
	}


	template<class T>
	SmartPtr<T>& SmartPtr<T>::operator=(SmartPtr& i_src)
	{
		if (this != &i_src)
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
	SmartPtr<T>& SmartPtr<T>::operator=(WeakPtr<T>& i_src)
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
	SmartPtr<T>& SmartPtr<T>::operator=(std::nullptr_t i_nullptr)
	{
		Release();

		m_pObject = nullptr;
		m_pReferenceCount = nullptr;

		return (*this);
	}

	template<class T>
	SmartPtr<T>::~SmartPtr()
	{
		Release();
	}

	template<class T>
	T* SmartPtr<T>::operator->()
	{
		return m_pObject;
	}

	template<class T>
	T& SmartPtr<T>::operator*()
	{
		return (*m_pObject);
	}

	template<class T>
	SmartPtr<T>::operator bool()
	{
		return m_pObject != nullptr;
	}
	
	template<class T>
	void SmartPtr<T>::Release()
	{
		if (m_pReferenceCount)
		{
			if (--(m_pReferenceCount->NumSmartPtrs) == 0)
			{

				m_pReferenceCount = nullptr;

				if (m_pReferenceCount->NumWeakPtrs == 0)
				{

					delete m_pReferenceCount;

				}
			}
		}
	}

#pragma endregion

	//------------- Weak Ptr Class-----------------
#pragma region Weak Ptr

	template<class T>
	WeakPtr<T>& WeakPtr<T>::operator=(WeakPtr<T>& i_src)
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
	WeakPtr<T>& WeakPtr<T>::operator=(SmartPtr<T>& i_src)
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
	WeakPtr<T>& WeakPtr<T>::operator=(std::nullptr_t i_nullptr)
	{

		Release();

		m_pReferenceCount = nullptr;
		m_pObject = nullptr;

		return (*this);

	}

	template<class T>
	WeakPtr<T>::~WeakPtr()
	{
		Release();
	}

	template<class T>
	SmartPtr<T> WeakPtr<T>::Acquire()
	{
		return SmartPtr<T>(*this);
	}

	template<class T>
	WeakPtr<T>::operator bool()
	{
		return m_pReferenceCount->NumSmartPtrs > 0;
	}

	template<class T>
	void WeakPtr<T>::Release()
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