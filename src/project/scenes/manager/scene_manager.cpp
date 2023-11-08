/**
 * @file scene_manager.cpp
 * @author melvi
 * @brief TODO
 * @version 0.1
 * @date 08/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "scene_manager.hpp"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::SetScene(std::unique_ptr<Scene> scene)
{
    currentScene = std::move(scene);
}

void SceneManager::RenderScene()
{
    currentScene->RenderScene();
}

const Scene& SceneManager::GetScene()
{
    if(!HasScene())
        throw std::runtime_error("No scene set");

    return *currentScene;
}

bool SceneManager::HasScene() const
{
    return currentScene != nullptr;
}