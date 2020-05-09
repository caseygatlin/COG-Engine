#pragma once

#include <stdint.h>

namespace Engine
{

	// Keeps track of the number of Smart and Weak ptrs
	// an object has.
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