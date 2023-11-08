/**
 * @file base_scene.hpp
 * @author melvi
 * @brief TODO
 * @version 0.1
 * @date 08/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_BASE_SCENE_HPP
#define DEFUNBOBENGINE_BASE_SCENE_HPP

#include "scene.hpp"

class BaseScene : public Scene
{
  public:
    BaseScene();
    virtual ~BaseScene();
    virtual void RenderScene() override = 0;

    /**
     * @brief Updates the scene
     */
    virtual void UpdateScene() = 0;
};

#endif // DEFUNBOBENGINE_BASE_SCENE_HPP
