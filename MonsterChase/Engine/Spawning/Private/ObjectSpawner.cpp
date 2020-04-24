#include "../Public/ObjectSpawner.h"
#include "../../Containers/Public/Pointers.h"
#include "../../Containers/Public/Point2D.h"
#include "../../GameObject/Public/GameObject.h"
#include "../../External/json.h"
#include "../../Physics/Public/PhysicsInfo.h"
#include "../../Physics/Public/Physics.h"
#include "../../World/Public/World.h"
#include "../../Graphics/Public/RenderData.h"
#include "../../Graphics/Public/Graphics.h"


#include<assert.h>
#include<vector>
#include<string>
#include<cstring>

namespace Engine
{
	namespace ObjectSpawner
	{
		static std::map<std::string, WeakPtr<GameObject>> Controllers;

		void SpawnGameObject(const std::string& i_jsonFileName)
		{
			SmartPtr<GameObject> spawnedObject;
			Physics::PhysicsInfo objectPhysicsInfo;
			Graphics::RenderData objectRenderData;

			std::vector<uint8_t> jsonFileData = JSONReader::LoadFile(i_jsonFileName);

			if (!jsonFileData.empty())
			{

				nlohmann::json jsonData = nlohmann::json::parse(jsonFileData);
				spawnedObject = JSONReader::JSONToGameObject(jsonData);

				World::AddGameObject(spawnedObject);

				std::string controllerName = JSONReader::JSONToController(jsonData);
				if (!controllerName.empty())
				{
					Controllers.insert({ controllerName, World::GetGameObject(World::GetNumGameObjects() - 1) });
				}

				objectPhysicsInfo = Physics::PhysicsInfo(
					World::GetGameObject(World::GetNumGameObjects() - 1),
					JSONReader::JSONToMass(jsonData),
					JSONReader::JSONToDrag(jsonData)
					);

				std::string texturePathStr = JSONReader::JSONToTexture(jsonData);

				char* texturePath = new char[texturePathStr.size() + 1];
				strcpy_s(texturePath, texturePathStr.size() + 1, texturePathStr.c_str());

				GLib::Sprites::Sprite* texture = Graphics::CreateSprite(texturePath);

				delete[] texturePath;

				objectRenderData = Graphics::RenderData(
					World::GetGameObject(World::GetNumGameObjects() - 1),
					texture
					);

				Physics::AddPhysicsInfo(objectPhysicsInfo);
				Graphics::AddRenderData(objectRenderData);

			}
		}

		void ClearControllers()
		{

			Controllers.clear();

		}
	}

	namespace JSONReader
	{
		SmartPtr<GameObject> JSONToGameObject(nlohmann::json& i_jsonData)
		{

			Point2D spawnPoint(GetSpawnPointFromJSON(i_jsonData["SpawnPoint"]));

			SmartPtr<GameObject> gameObject = GameObject::CreateGameObject(spawnPoint);

			return gameObject;

		}

		float JSONToMass(nlohmann::json& i_jsonData)
		{
			if (i_jsonData.contains("PhysicsInfo"))
			{
				if (i_jsonData["PhysicsInfo"].contains("Mass"))
				{
					return GetMassFromJSON(i_jsonData["PhysicsInfo"]["Mass"]);
				}
			}

			return 0.0F;

		}

		float JSONToDrag(nlohmann::json& i_jsonData)
		{
			if (i_jsonData.contains("PhysicsInfo"))
			{
				if (i_jsonData["PhysicsInfo"].contains("Drag"))
				{
					return GetDragFromJSON(i_jsonData["PhysicsInfo"]["Drag"]);
				}
			}

			return 0.0F;

		}

		std::string JSONToTexture(nlohmann::json& i_jsonData)
		{
			if (i_jsonData.contains("RenderData"))
			{
				if (i_jsonData["RenderData"].contains("Texture"))
				{
					return GetTextureFromJSON(i_jsonData["RenderData"]["Texture"]);
				}
			}

			return std::string();

		}

		std::string JSONToController(nlohmann::json& i_jsonData)
		{
			if (i_jsonData.contains("Controller"))
			{
				if (i_jsonData["Controller"].contains("Type"))
				{
					return GetTextureFromJSON(i_jsonData["Controller"]["Type"]);
				}
			}

			return std::string();

		}


		static Point2D GetSpawnPointFromJSON(const nlohmann::json& i_jsonData)
		{
			if (i_jsonData.is_array() && i_jsonData.size() == 2)
			{

				return Point2D(i_jsonData[0], i_jsonData[1]);

			}

			return Point2D(0.0F, 0.0F);

		}

		float GetMassFromJSON(const nlohmann::json& i_jsonData)
		{
			if (i_jsonData.is_number_float())
			{

				return i_jsonData;

			}

			return 0.0F;

		}

		float GetDragFromJSON(const nlohmann::json& i_jsonData)
		{
			if (i_jsonData.is_number_float())
			{

				return i_jsonData;

			}

			return 0.0F;

		}

		std::string GetTextureFromJSON(const nlohmann::json& i_jsonData)
		{
			if (i_jsonData.is_string())
			{

				return i_jsonData;

			}

			return std::string();

		}

		std::string GetControllerFromJSON(const nlohmann::json& i_jsonData)
		{
			if (i_jsonData.is_string())
			{

				return i_jsonData;

			}

			return std::string();

		}

		std::vector<uint8_t> LoadFile(const std::string& i_fileName)
		{
			std::vector<uint8_t> fileData;

			if (!i_fileName.empty())
			{
				FILE* pFile = nullptr;

				errno_t fopenError = fopen_s(&pFile, i_fileName.c_str(), "rb");
				if (fopenError == 0)
				{
					if (pFile != nullptr)
					{
						int FileIOError = fseek(pFile, 0, SEEK_END);
						assert(FileIOError == 0);

						long FileSize = ftell(pFile);
						assert(FileSize >= 0);

						FileIOError = fseek(pFile, 0, SEEK_SET);
						assert(FileIOError == 0);

						fileData.reserve(FileSize);
						fileData.resize(FileSize);

						size_t FileRead = fread(&fileData[0], 1, FileSize, pFile);
						assert(FileRead == FileSize);

						fclose(pFile);
					}
				}
			}

			return fileData;
		}
	}
}