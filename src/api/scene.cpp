/// @file
#include "scene.hpp"

void Scene::RenderScene() {}
void Scene::AddGameObject(const std::shared_ptr<GameObject> &gameObject)
{
    contents.push_back(gameObject);
}
std::weak_ptr<GameObject> Scene::findGameObjectByName(const std::string &name)
{
    for (auto &gameObject : contents)
    {
        if (gameObject->GetName() == name)
        {
            return gameObject;
        }
    }

    return {};
}
std::weak_ptr<GameObject> Scene::findGameObjectByTag(const std::string &tag)
{
    for (auto &gameObject : contents)
    {
        if (gameObject->GetTag() == tag)
        {
            return gameObject;
        }
    }

    return {};
}
bool Scene::removeGameObjectByName(const std::string &name)
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
bool Scene::removeGameObjectByTag(const std::string &tag)
{
    for (auto it = contents.begin(); it != contents.end(); ++it)
    {
        if ((*it)->GetTag() == tag)
        {
            contents.erase(it);
            return true;
        }
    }

    return false;
}
void Scene::Clear() { contents.clear(); }

bool Scene::SetActiveStatus(const std::string &name, bool isActive)
{
    auto gameObject = findGameObjectByName(name);
    auto gameObjectPtr = gameObject.lock();

    if (gameObjectPtr == nullptr)
    {
        return false;
    }
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

template <typename T> std::vector<std::weak_ptr<T>> Scene::GetAllByType()
{
    std::vector<std::weak_ptr<T>> result;
    for (auto &go : contents)
    {
        auto casted = std::dynamic_pointer_cast<T>(go);
        if (casted != nullptr)
        {
            result.push_back(casted);
        }
    }
    return result;
}
