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
#include "../../HashedString/Public/HashedString.h"
#include "../../Components/Public/PlayerControllerComponent.h"
#include "../../Components/Public/IGOComponent.h"
#include "../../Physics/Collision/Public/Collision.h"
#include "../../Physics/Collision/Public/Collideable.h"
#include "../../Physics/Collision/Public/AABB.h"


#include<assert.h>
#include<vector>
#include<string>
#include<cstring>

namespace Engine
{
	namespace ObjectSpawner
	{
		
		// A map of all of the registered controllers (Player Controllers, etc.)
		static std::map<HashedString, WeakPtr<GameObject>> Controllers;

		
		bool SpawnGameObject(const std::string& i_jsonFileName, SmartPtr<GameObject>& o_gameObject)
		{
			
			// Declare local variables for various systems to be initialized in spawning.
			SmartPtr<GameObject> spawnedObject;
			Physics::PhysicsInfo objectPhysicsInfo;
			Graphics::RenderData objectRenderData;

			
			// Convert the JSON file into readable data.
			std::vector<uint8_t> jsonFileData = JSONReader::LoadFile(i_jsonFileName);

			
			// If there is data
			if (!jsonFileData.empty())
			{

				// Create a GameObject from the parsed JSON data and add it to the world.
				nlohmann::json jsonData = nlohmann::json::parse(jsonFileData);
				spawnedObject = JSONReader::JSONToGameObject(jsonData);
				World::AddGameObject(spawnedObject);

				
				// Check to see if JSON data lists a Controller. If so add it to the Controllers list.
				std::string controllerNameStr = JSONReader::JSONToController(jsonData);

				char* controllerName = new char[controllerNameStr.size() + 1];
				strcpy_s(controllerName, controllerNameStr.size() + 1, controllerNameStr.c_str());

				if (!controllerNameStr.empty())
				{
					
					Controllers.insert({ HashedString(controllerName), World::GetGameObject(World::GetNumGameObjects() - 1) });
					
				}

				delete[] controllerName;

				
				// Initialize the PhysicsInfo of the Spawned Object based on parameters in JSON.
				objectPhysicsInfo = Physics::PhysicsInfo(
					World::GetGameObject(World::GetNumGameObjects() - 1),
					JSONReader::JSONToMass(jsonData),
					JSONReader::JSONToDrag(jsonData)
					);

				
				// Locate the texture to be rendered for this Object and create a sprite with it.
				std::string texturePathStr = JSONReader::JSONToTexture(jsonData);

				char* texturePath = new char[texturePathStr.size() + 1];
				strcpy_s(texturePath, texturePathStr.size() + 1, texturePathStr.c_str());

				GLib::Sprites::Sprite* texture = Graphics::CreateSprite(texturePath);

				delete[] texturePath;

				
				// Initialize RenderData of the Spawned Object with sprite.
				objectRenderData = Graphics::RenderData(
					World::GetGameObject(World::GetNumGameObjects() - 1),
					texture
					);

				
				// Add the PhysicsInfo and RenderData to their respective lists.
				Physics::AddPhysicsInfo(objectPhysicsInfo);
				Graphics::AddRenderData(objectRenderData);

				
				// Output the Spawned Object and return success.
				o_gameObject = spawnedObject;
				return true;

			}

			// Otherwise return failure.
			return false;

		}

		bool SpawnCollideable(const std::string& i_jsonFileName, SmartPtr<Physics::Collideable>& o_collideable)
		{
			
			// Declare local variables for various systems to be initialized in spawning.
			SmartPtr<GameObject> spawnedObject;
			Physics::PhysicsInfo objectPhysicsInfo;
			Graphics::RenderData objectRenderData;
			SmartPtr<Physics::Collideable> spawnedCollideable;

			
			// Convert the JSON file into readable data.
			std::vector<uint8_t> jsonFileData = JSONReader::LoadFile(i_jsonFileName);

			
			// If there is data
			if (!jsonFileData.empty())
			{

				// Create a GameObject from the parsed JSON data and add it to the world.
				nlohmann::json jsonData = nlohmann::json::parse(jsonFileData);
				spawnedObject = JSONReader::JSONToGameObject(jsonData);
				World::AddGameObject(spawnedObject);

				
				// Create a Collideable containing the GameObject with the bounding box specified in JSON.
				spawnedCollideable = Physics::Collideable::CreateCollideable(
					spawnedObject,
					JSONReader::JSONToAABB(jsonData)
					);

				
				// Add this created collideable to the Collideables list.
				Physics::AddCollideable(spawnedCollideable);

				
				// Check to see if JSON data lists a Controller. If so add it to the Controllers list.
				std::string controllerNameStr = JSONReader::JSONToController(jsonData);

				char* controllerName = new char[controllerNameStr.size() + 1];
				strcpy_s(controllerName, controllerNameStr.size() + 1, controllerNameStr.c_str());

				if (!controllerNameStr.empty())
				{
					
					RegisterController(HashedString(controllerName), spawnedObject);
					
				}

				delete[] controllerName;

				
				// Initialize the PhysicsInfo of the Spawned Object based on parameters in JSON.
				objectPhysicsInfo = Physics::PhysicsInfo(
					spawnedObject,
					JSONReader::JSONToMass(jsonData),
					JSONReader::JSONToDrag(jsonData)
				);

				
				// Locate the texture to be rendered for this Object and create a sprite with it.
				std::string texturePathStr = JSONReader::JSONToTexture(jsonData);

				char* texturePath = new char[texturePathStr.size() + 1];
				strcpy_s(texturePath, texturePathStr.size() + 1, texturePathStr.c_str());

				GLib::Sprites::Sprite* texture = Graphics::CreateSprite(texturePath);

				delete[] texturePath;

				
				// Initialize RenderData of the Spawned Object with sprite.
				objectRenderData = Graphics::RenderData(
					spawnedObject,
					texture
				);

				
				// Add the PhysicsInfo and RenderData to their respective lists.
				Physics::AddPhysicsInfo(objectPhysicsInfo);
				Graphics::AddRenderData(objectRenderData);

				
				// Output the Collideable and return success.
				o_collideable = spawnedCollideable;
				return true;

			}

			// Otherwise return failure.
			return false;

		}

		void RegisterController(HashedString i_ControllerName, WeakPtr<GameObject> o_GameObject)
		{
			
			// Add the controller to the Controllers list.
			Controllers.insert({ i_ControllerName, o_GameObject });

			
			// If the controller is a Player Controller, 
			// create and attach a Player Controller Component to the GameObject.
			if (i_ControllerName == "Player")
			{

				o_GameObject.Acquire()->Attach(CreateComponent<PlayerControllerComponent>());

			}
		}

		void RemoveController(HashedString i_ControllerName)
		{
			
			Controllers.erase(i_ControllerName);
			
		}

		bool GetFirstGameObjectWithController(HashedString i_ControllerName, WeakPtr<GameObject>& o_GameObject)
		{
			
			// Find the specified controller in the list.
			if (Controllers.find(i_ControllerName) != Controllers.end())
			{

				// Output GameObject and return success.
				o_GameObject = Controllers.at(i_ControllerName);
				return true;

			}

			// Otherwise return failure.
			return false;
			
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

			Point2D spawnPoint(GetPoint2DFromJSON(i_jsonData["SpawnPoint"]));

			SmartPtr<GameObject> gameObject = GameObject::CreateGameObject(spawnPoint);

			return gameObject;

		}

		Physics::AABB JSONToAABB(nlohmann::json& i_jsonData)
		{

			if (i_jsonData.contains("Collision") &&
				i_jsonData["Collision"].contains("Bounding Box") &&
				i_jsonData["Collision"]["Bounding Box"].contains("Extents") &&
				i_jsonData["Collision"]["Bounding Box"].contains("Center"))
			{
				Point2D center = GetPoint2DFromJSON(i_jsonData["Collision"]["Bounding Box"]["Center"]);
				Point2D extents = GetPoint2DFromJSON(i_jsonData["Collision"]["Bounding Box"]["Extents"]);
				
				return Physics::AABB(center, extents);

			}

			return Physics::AABB();
		}

		float JSONToMass(nlohmann::json& i_jsonData)
		{
			if (i_jsonData.contains("PhysicsInfo"))
			{
				if (i_jsonData["PhysicsInfo"].contains("Mass"))
				{
					return GetFloatFromJSON(i_jsonData["PhysicsInfo"]["Mass"]);
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
					return GetFloatFromJSON(i_jsonData["PhysicsInfo"]["Drag"]);
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
					return GetStringFromJSON(i_jsonData["RenderData"]["Texture"]);
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
					return GetStringFromJSON(i_jsonData["Controller"]["Type"]);
				}
			}

			return std::string();

		}

		float GetFloatFromJSON(const nlohmann::json& i_jsonData)
		{
			if (i_jsonData.is_number_float())
			{

				return i_jsonData;

			}

			return 0.0F;

		}

		std::string GetStringFromJSON(const nlohmann::json& i_jsonData)
		{
			if (i_jsonData.is_string())
			{

				return i_jsonData;

			}

			return std::string();

		}

		Point2D GetPoint2DFromJSON(const nlohmann::json& i_jsonData)
		{
			if (i_jsonData.is_array() && i_jsonData.size() == 2)
			{

				return Point2D(i_jsonData[0], i_jsonData[1]);

			}

			return Point2D(0.0F, 0.0F);
		}

		Matrix4 GetMatrix4FromJSON(const nlohmann::json& i_jsonData)
		{
			if (i_jsonData.is_array() && i_jsonData.size() == 16)
			{

				return Matrix4(
					i_jsonData[0], i_jsonData[1], i_jsonData[2], i_jsonData[3],
					i_jsonData[4], i_jsonData[5], i_jsonData[6], i_jsonData[7],
					i_jsonData[8], i_jsonData[9], i_jsonData[10], i_jsonData[11],
					i_jsonData[12], i_jsonData[13], i_jsonData[14], i_jsonData[15]
				);

			}

			return Matrix4::IdentityMatrix;
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
