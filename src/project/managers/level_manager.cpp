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

LevelManager::~LevelManager()
{}

void LevelManager::RegisterLevel(int id, std::string filePath)
{}

void LevelManager::LoadLevel(int id)
{}