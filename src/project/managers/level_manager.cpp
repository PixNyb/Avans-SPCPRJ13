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

LevelManager::LevelManager(std::shared_ptr<SceneManager> &sManager, std::shared_ptr<PrefabManager> &pManager, std::shared_ptr<JSONReader> &jReader)
    : levels(),
      sceneManager(sManager),
      levelFactory(std::make_unique<LevelFactory>(pManager)),
      jsonReader(jReader)
{}

LevelManager::~LevelManager() = default;

void LevelManager::RegisterLevel(int id, std::string filePath)
{
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
        auto levelJson = jsonReader->ConvertFileToJson(path->second);

        // Create level based on the JSON.
        auto level = levelFactory->CreateScene(levelJson);

        // Update the current scene.
        sceneManager->SetScene(level);
    }
    catch (std::exception &e) // TODO: Check for other exception typing.
    {
        // TODO: Rethrow error or just return?
    }
}