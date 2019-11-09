#pragma once
#include "GameObject.h"


namespace Engine
{
	class IGOComponent
	{
	public:

		virtual void Update(GameObject& i_gameObject) = 0;

	};
}

