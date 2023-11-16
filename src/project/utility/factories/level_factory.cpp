/**
* @file level_factory.cpp
* @author Maxuuuu
* @brief Implementation of the level factory.
* @version 0.1
* @date 11/11/2023
*
* @copyright Copyright (c) 2023
*
 */

#include "level_factory.hpp"

LevelFactory::LevelFactory(std::shared_ptr<PrefabManager> &PrefabManager) : prefabManager(PrefabManager)
{}

Scene LevelFactory::CreateScene(nlohmann::json sceneJson)
{
    auto scene = Scene();

    nlohmann::json objects = sceneJson.at("objects");
    addObjects(scene, objects);

    return scene;
}

std::vector<std::shared_ptr<GameObject>> LevelFactory::addObjects(Scene &scene, const nlohmann::json& objectsJson) {
    std::vector<std::shared_ptr<GameObject>> objects = {};
    for (const nlohmann::json& jsonObject : objectsJson)
    {
        auto gameObject = prefabManager->GetPrefab(jsonObject.at("prefab").template get<std::string >());

        gameObject.SetName(jsonObject.at("name").template get<std::string>());

        gameObject.SetTag(jsonObject.at("tag").template get<std::string>());

        gameObject.SetActive(jsonObject.at("active").template get<bool>());

        gameObject.SetLayer(jsonObject.at("layer").template get<int>());

        auto ptr = std::make_shared<GameObject>(gameObject);
        // Recursive function call.
        auto children = LevelFactory::addObjects(scene, jsonObject.at("objects"));
        for (const auto& child : children)
            child->SetParent(ptr);

        scene.AddGameObject(ptr);
        objects.push_back(ptr);
    }

    return objects;
}
