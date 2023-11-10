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

#include "managers/scene_manager.hpp"

SceneManager::SceneManager() {}

SceneManager::~SceneManager() = default;

void SceneManager::SetScene(std::shared_ptr<Scene> scene) { currentScene = std::move(scene); }

void SceneManager::RenderScene() { currentScene->RenderScene(); }

std::weak_ptr<Scene> SceneManager::GetScene() { return currentScene; }

bool SceneManager::HasScene() const { return currentScene != nullptr; }