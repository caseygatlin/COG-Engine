#pragma once

#include "ReferenceCount.h"

namespace Engine
{

	template<class T>
	class SmartPtr
	{
	public:

		// Constructor
		explicit SmartPtr(T* i_pObject) :
			m_pReferenceCount(new ReferenceCount(1, 0)),
			m_pObject(i_pObject)
		{}

		// Copy constructor
		SmartPtr(SmartPtr& i_src) :
			m_pObject(i_src.m_pObject),
			m_pReferenceCount(i_src.m_pReferenceCount)
		{

			(*m_pReferenceCount)++;
		
		}


		// Assignment operator
        // TODO: Inline, implement release
		SmartPtr& operator=(SmartPtr& i_src)
		{
			
			if (this == &i_src)
			{

				return (*this);
			
			}

			//Release

			m_pObject           = i_src.m_pObject;
			m_pReferenceCount   = i_src.m_pReferenceCount;

			(*m_pReferenceCount)++;

		}


		// Destructor
        // TODO: Inline, Implement release
        ~SmartPtr()
        {
            //Release
        }

        // -> Operator
        T* operator->();

        // * Operator
        T& operator*();

	private:

		ReferenceCount* m_pReferenceCount;
		T*				m_pObject

	};
}

#include "SmartPtr-inl.h"