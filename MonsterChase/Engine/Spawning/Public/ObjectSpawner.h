#pragma once

#include "../../GameObject/Public/GameObject.h"
#include "../../Containers/Public/Point2D.h"
#include "../../Containers/Public/Pointers.h"
#include "../../Physics/Public/PhysicsInfo.h"
#include "../../External/json.h"

#include <assert.h>
#include <vector>

namespace Engine
{
	namespace ObjectSpawner
	{

		void SpawnGameObject(const std::string& i_jsonFileName);

		void ClearControllers();

	}

	namespace JSONReader
	{

		SmartPtr<GameObject> JSONToGameObject(nlohmann::json& i_jsonData);

		float JSONToMass(nlohmann::json& i_jsonData);

		float JSONToDrag(nlohmann::json& i_jsonData);

		std::string JSONToTexture(nlohmann::json& i_jsonData);

		std::string JSONToController(nlohmann::json& i_jsonData);

		static Point2D GetSpawnPointFromJSON(const nlohmann::json& i_jsonData);

		static float GetMassFromJSON(const nlohmann::json& i_jsonData);

		static float GetDragFromJSON(const nlohmann::json& i_jsonData);

		static std::string GetTextureFromJSON(const nlohmann::json& i_jsonData);

		static std::string GetControllerFromJSON(const nlohmann::json& i_jsonData);

		std::vector<uint8_t> LoadFile(const std::string& i_fileName);

	}
}