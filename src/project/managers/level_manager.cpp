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
                           std::shared_ptr<JSONReader> &jReader)
    : levels(), sceneManager(sManager), prefabManager(pManager),
      levelFactory(std::make_unique<LevelFactory>(pManager)), jsonReader(jReader),
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

std::string LevelManager::SaveLevel()
{
    auto currentScene = sceneManager->GetScene();
    nlohmann::json levelJson = {"objects", nlohmann::json::array()};

    for (const auto &gameObject : currentScene.lock()->contents)
    {
        auto prefabId = gameObject->GetPrefabId();

        if (!prefabManager->HasPrefab(prefabId))
            throw std::runtime_error(fmt::format("A GameObject needs to be a registered prefab "
                                                 "before it can be saved. Unregistered type: '{}'",
                                                 prefabId));

        // TODO: Save the prefab to the json.

    }

    // TODO: Return path of the newly stored level.
    return "Path";
}

void LevelManager::AddGameObject(nlohmann::json &levelJson, GameObject &gameObject) {}
