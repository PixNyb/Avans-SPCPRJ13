//
// Created by maxro on 12/11/2023.
//

#include "level_factory.hpp"

LevelFactory::LevelFactory(std::shared_ptr<PrefabManager> &PrefabManager) : prefabManager(PrefabManager)
{}

Scene LevelFactory::CreateScene(nlohmann::json sceneJson) const
{
    auto scene = Scene();

    nlohmann::json objects = sceneJson.at("objects");
    for (const nlohmann::json& jsonObject : objects)
    {
        std::string name = jsonObject.at("name").template get<std::string>();
        auto gameObject = std::make_shared<GameObject>(name);

        gameObject->SetTag(jsonObject.at("tag").template get<std::string>());

        gameObject->SetActive(jsonObject.at("active").template get<bool>());

        gameObject->SetLayer(jsonObject.at("layer").template get<int>());

        scene.AddGameObject(gameObject);
    }

    return scene;
}
