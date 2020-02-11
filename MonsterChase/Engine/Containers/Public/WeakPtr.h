#pragma once

#include "ReferenceCount.h"

namespace Engine
{

	template<class T>
	class WeakPtr
	{
    public:
        


    private:

        ReferenceCount*     m_pReferenceCount;
        T*                  m_pObject;

	};
}


#include "WeakPtr-inl.h"