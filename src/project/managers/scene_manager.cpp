/**
 * @file scene_manager.cpp
 * @author Melvin van Bree
 * @brief Implementation of the SceneManager class, handling scene transitions and management in the game engine.
 * @version 0.1
 * @date 08/11/2023
 *
 * This file contains the implementation of the SceneManager class. The SceneManager is responsible for managing
 * scenes within the game engine, including setting, updating, rendering, and transitioning between different scenes.
 * It plays a critical role in the scene lifecycle, ensuring smooth transitions and consistent updates to the current scene.
 * This class is essential for the overall scene management strategy in a dynamic game environment.
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "managers/scene_manager.hpp"

SceneManager::SceneManager() {}



#include "managers/scene_manager.hpp"

SceneManager::SceneManager() {}

SceneManager::~SceneManager() = default;

void SceneManager::SetScene(std::shared_ptr<Scene> scene) { currentScene = std::move(scene); }

void SceneManager::RenderScene() { currentScene->RenderScene(); }

std::weak_ptr<Scene> SceneManager::GetScene() { return currentScene; }

bool SceneManager::HasScene() const { return currentScene != nullptr; }

void SceneManager::Update(float deltaTime)
{
    if (currentScene != nullptr)
    {
        currentScene->Update(deltaTime);
    }
}
void SceneManager::ClearScene()
{
    if (currentScene != nullptr)
    {
        currentScene->Clear();
        currentScene = nullptr;
    }
}
