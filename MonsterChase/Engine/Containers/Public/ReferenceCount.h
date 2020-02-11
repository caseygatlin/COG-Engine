#pragma once

#include <stdint.h>

namespace Engine
{

	struct ReferenceCount
	{

		ReferenceCount(size_t i_NumSmartPtrs, size_t i_NumWeakPtrs) :
			NumSmartPtrs(i_NumSmartPtrs),
			NumWeakPtrs(i_NumWeakPtrs)
		{}

		size_t NumSmartPtrs;
		size_t NumWeakPtrs;

	};
}