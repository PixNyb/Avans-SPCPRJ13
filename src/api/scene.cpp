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

bool Scene::SetActiveStatus(const std::string &name, bool isActive) {
    auto gameObject = findGameObjectByName(name);
    auto gameObjectPtr = gameObject.lock();

    if (gameObjectPtr == nullptr) { return false; }
    gameObjectPtr->SetActive(isActive);
    return true;
}
