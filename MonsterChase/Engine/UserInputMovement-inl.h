#pragma once
#include "ComponentType.h"


namespace Engine
{
	inline ComponentType UserInputMovement::GetComponentType() const
	{
		return ComponentType::USER_INPUT_MOVEMENT;
	}
}