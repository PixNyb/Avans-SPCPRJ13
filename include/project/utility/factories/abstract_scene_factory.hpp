//
// Created by maxro on 12/11/2023.
//

#ifndef DEFUNBOBENGINE_ABSTRACT_SCENE_FACTORY_HPP
#define DEFUNBOBENGINE_ABSTRACT_SCENE_FACTORY_HPP

#include "../../../api/scene.hpp"
#include "nlohmann/json.hpp"

class AbstractSceneFactory {
  public:
    AbstractSceneFactory() = default;

    virtual Scene CreateScene(nlohmann::json sceneJson) = 0;

};

#endif // DEFUNBOBENGINE_ABSTRACT_SCENE_FACTORY_HPP
