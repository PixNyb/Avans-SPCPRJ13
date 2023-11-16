//
// Created by maxro on 12/11/2023.
//

#ifndef DEFUNBOBENGINE_LEVEL_FACTORY_HPP
#define DEFUNBOBENGINE_LEVEL_FACTORY_HPP

#include "abstract_scene_factory.hpp"
#include "memory"
#include "../../managers/prefab_manager.hpp"

class LevelFactory : public AbstractSceneFactory {
  private:
    std::shared_ptr<PrefabManager> prefabManager;

    std::vector<std::shared_ptr<GameObject>> addObjects(Scene &scene, const nlohmann::json& objectsJson);

  public:
    explicit LevelFactory(std::shared_ptr<PrefabManager> &PrefabManager);

    [[nodiscard]] Scene CreateScene(nlohmann::json sceneJson) override;
};

#endif // DEFUNBOBENGINE_LEVEL_FACTORY_HPP
