/**
 * @file scene.cpp
 * @author Robin Pijnappels
 * @brief This file contains the Scene class implementation.
 * @version 0.1
 * @date 2023-11-08
 *
 * Copyright Copyright (c) 2023
 *
 */

#include "scene.hpp"

void Scene::RenderScene() {}

void Scene::AddGameObject(const std::shared_ptr<GameObject> &gameObject)
{
    contents.push_back(gameObject);
}

std::weak_ptr<GameObject> Scene::FindGameObjectByName(const std::string &name)
{
    for (auto &gameObject : contents)
    {
        if (gameObject->GetName() == name)
            return gameObject;
    }

    return {};
}

std::vector<std::weak_ptr<GameObject>> Scene::FindGameObjectByTag(const std::string &tag)
{
    std::vector<std::weak_ptr<GameObject>> gameObjects;

    for (auto &gameObject : contents)
    {
        if (gameObject->GetTag() == tag)
            gameObjects.emplace_back(gameObject);
    }

    return gameObjects;
}

bool Scene::RemoveGameObjectByName(const std::string &name)
{
    for (auto it = contents.begin(); it != contents.end(); ++it)
    {
        if ((*it)->GetName() == name)
        {
            contents.erase(it);
            return true;
        }
    }

    return false;
}

bool Scene::RemoveGameObjectByTag(const std::string &tag)
{
    bool removed = false;

    for (auto it = contents.begin(); it != contents.end(); /* no increment here */)
    {
        if ((*it)->GetTag() == tag)
        {
            it = contents.erase(it);
            removed = true;
        }
        else
        {
            ++it;
        }
    }

    return removed;
}

void Scene::Clear() { contents.clear(); }

bool Scene::SetActiveStatus(const std::string &name, bool isActive)
{
    auto gameObject = FindGameObjectByName(name);
    auto gameObjectPtr = gameObject.lock();

    if (gameObjectPtr == nullptr)
        return false;

    gameObjectPtr->SetActive(isActive);
    return true;
}

std::weak_ptr<GameObject> Scene::CreateGameObject()
{
    auto go = std::make_shared<GameObject>();
    AddGameObject(go);
    return go;
}

template <typename GameObjectType, typename... Args>
std::weak_ptr<GameObjectType> Scene::CreateGameObject(Args &&...args)
{
    auto gameObject = std::make_shared<GameObjectType>(std::forward<Args>(args)...);
    AddGameObject(gameObject);
    return gameObject;
}
