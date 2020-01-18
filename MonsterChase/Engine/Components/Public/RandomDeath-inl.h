#pragma once

#include "RandomDeath.h"
#include "ComponentType.h"

namespace Engine
{

	ComponentType RandomDeath::GetComponentType() const
	{
		return ComponentType::RANDOM_DEATH;
	}

}