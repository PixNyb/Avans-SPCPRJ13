/**
 * @file level_manager.cpp
 * @author Maxuuuu
 * @brief Implementation of the LevelManager.
 * @version 0.1
 * @date 21/11/2023
 *
 * @copyright Copyright (c) 2023
 */

#include "level_manager.hpp"
#include "engine.hpp"
#include "physics_manager.hpp"
#include <filesystem>
#include <fmt/format.h>
#include <iostream>

LevelManager::LevelManager(std::shared_ptr<SceneManager> &sManager,
                           std::shared_ptr<PrefabManager> &pManager,
                           std::shared_ptr<JSONHandler> &jHandler)
    : levels(), sceneManager(sManager), prefabManager(pManager),
      levelFactory(std::make_unique<LevelFactory>(pManager)), jsonHandler(jHandler),
      levelFileExtension(".json")
{
}

LevelManager::~LevelManager() = default;

void LevelManager::RegisterLevel(int id, std::string filePath)
{
    auto path = std::filesystem::absolute(filePath).string();
    // Check if file exists.
    if (!std::filesystem::exists(path))
        throw std::runtime_error(fmt::format("No file was found at: '{}'", filePath));

    // Check for file extension.
    if (filePath.length() < levelFileExtension.length() ||
        (0 != filePath.compare(filePath.length() - levelFileExtension.length(),
                               levelFileExtension.length(), levelFileExtension)))
        throw std::runtime_error(fmt::format(
            "Level file is of a unsupported type. Expected type: '{}'", levelFileExtension));

    levels.insert(std::pair(id, filePath));
}

void LevelManager::LoadLevel(int id)
{
    auto path = levels.find(id);

    // No level found with the following id.
    if (path == levels.end())
        return;

    try
    {
        // Read level JSON.
        auto levelJson = jsonHandler->ConvertFileToJson(path->second);

        // Create level based on the JSON.
        auto level = levelFactory->CreateScene(levelJson);

        // Update the current scene.
        sceneManager->SetScene(level);
        // Update the physics.
        Engine::GetInstance()->Get<PhysicsManager>()->CreateWorld(level->contents);
    }
    catch (std::exception &e)
    {
        // TODO: Rethrow error or just return?
        std::cout << e.what() << std::endl;
    }
}

std::string LevelManager::SaveLevel(std::string &directory, std::string &filename)
{
    auto currentScene = sceneManager->GetScene();
    auto levelJson = nlohmann::json::object();

    // Convert the Camera to a json object and add it to the level json.
    auto cameraJson = CreateCameraJson(*currentScene.lock()->GetCamera());
    levelJson["camera"] = cameraJson;

    // Convert the GameObjects of the scene to json objects.
    nlohmann::json objects;
    for (const auto &gameObject : currentScene.lock()->contents)
    {
        // Check if the GameObject has a parent, if it does it should not be called here due
        // to only root objects needing to be in objects array. The level json has a recursive
        // structure of root components and their children. These children will be added in the
        // recursive function call.
        if (gameObject->GetParent() != nullptr)
            continue;

        auto objectJson = CreateGameObjectJson(*gameObject);
        objects.push_back(objectJson);
    }

    // Add the array of GameObjects to the level json.
    levelJson["objects"] = objects;

    // Write the json object to a file and return the resulting file path.
    auto filePath = jsonHandler->WriteJsonToFile(directory, filename, levelJson);

    return filePath;
}

nlohmann::json LevelManager::CreateGameObjectJson(GameObject &gameObject)
{
    auto objectJson = nlohmann::json::object();
    auto prefabId = gameObject.GetPrefabId();

    // If no prefab is registered by the prefab id, or a default value is found, an error is thrown.
    if (!prefabManager->HasPrefab(prefabId) || prefabId.empty())
        throw std::runtime_error(fmt::format("A GameObject needs to be a registered prefab "
                                             "before it can be saved. Unregistered type: '{}'",
                                             prefabId));

    // Add basic properties.
    objectJson["prefab"] = gameObject.GetPrefabId();
    objectJson["name"] = gameObject.GetName();
    objectJson["active"] = gameObject.IsActive();
    objectJson["layer"] = gameObject.GetLayer();

    // Add transform struct.
    auto transform = gameObject.GetTransform();
    objectJson["transform"] = {
        {"position", {{"x", transform.position.x}, {"y", transform.position.y}}},
        {"rotation", transform.rotation},
        {"scale", transform.scale}};

    nlohmann::json children;
    // Iterate over every child object in a recursive function call.
    for (const auto &child : gameObject.GetChildren())
    {
        // When push_back() is called the json turns into an array.
        children.push_back(CreateGameObjectJson(*child));
    }

    // The children array is added to the GameObject json.
    objectJson["children"] = children;

    return objectJson;
}

nlohmann::json LevelManager::CreateCameraJson(Camera &camera)
{
    auto cameraJson = nlohmann::json::object();

    // Add properties to the camera json.
    cameraJson["width"] = camera.GetAspectWidth();
    cameraJson["height"] = camera.GetAspectHeight();

    return cameraJson;
}
