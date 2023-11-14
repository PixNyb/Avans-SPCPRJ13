//
// Created by maxro on 12/11/2023.
//

#ifndef DEFUNBOBENGINE_LEVEL_FACTORY_HPP
#define DEFUNBOBENGINE_LEVEL_FACTORY_HPP

#include "abstract_scene_factory.hpp"

class LevelFactory : public AbstractSceneFactory {
  public:
    virtual Scene CreateScene(nlohmann::json sceneJson) const;
};

#endif // DEFUNBOBENGINE_LEVEL_FACTORY_HPP
