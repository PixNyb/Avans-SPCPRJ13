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
    void RenderScene() override = 0;

    /**
     * @brief Updates the scene
     */
    virtual void UpdateScene() = 0;

    /**
     * @brief Remove a component from the scene
     * @param name The name of the component to be removed
     */
    void RemoveByName(const std::string& name);
};

#endif // DEFUNBOBENGINE_BASE_SCENE_HPP
