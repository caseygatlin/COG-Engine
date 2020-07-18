#pragma once

namespace Engine
{
	
	// Enum for differentiating the different types of attachable components.
	enum class ComponentType
	{

		HEALTH,			// Health Component - a health system for GameObjects.
		PLAYER_INPUT,		// Player Controller Component - handles player input for a GameObject.
		RANDOM_SPAWN,		// Random Spawn Component - Randomly generates spawn position for a GameObject.

	};
}
