//
// Created by maxro on 12/11/2023.
//

#ifndef DEFUNBOBENGINE_LEVEL_FACTORY_HPP
#define DEFUNBOBENGINE_LEVEL_FACTORY_HPP

#include "abstract_scene_factory.hpp"
#include "memory"
#include "prefab_manager.hpp"

class LevelFactory : public AbstractSceneFactory {
  private:
    std::shared_ptr<PrefabManager> prefabManager;

  public:
    LevelFactory(std::shared_ptr<PrefabManager> &PrefabManager);

    virtual Scene CreateScene(nlohmann::json sceneJson) const;
};

#endif // DEFUNBOBENGINE_LEVEL_FACTORY_HPP
