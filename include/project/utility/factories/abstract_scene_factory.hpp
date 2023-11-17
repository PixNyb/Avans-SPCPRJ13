/**
* @file level_factory.hpp
* @author Maxuuuu
* @brief Abstract factory for creating scenes.
* @version 0.1
* @date 11/11/2023
*
* @copyright Copyright (c) 2023
*
*/

#ifndef DEFUNBOBENGINE_ABSTRACT_SCENE_FACTORY_HPP
#define DEFUNBOBENGINE_ABSTRACT_SCENE_FACTORY_HPP

#include "scene.hpp"
#include <nlohmann/json.hpp>

class AbstractSceneFactory {
  public:
    AbstractSceneFactory() = default;

    /**
     * @brief Creates a scene based on a provided JSON.
     * @param sceneJson The scene JSON.
     * @return The scene constructed based on the JSON.
     */
    virtual Scene CreateScene(nlohmann::json sceneJson) = 0;

};

#endif // DEFUNBOBENGINE_ABSTRACT_SCENE_FACTORY_HPP
