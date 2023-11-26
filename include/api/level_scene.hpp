/**
 * @file level_scene.hpp
 * @author Maxuuuu
 * @brief Defines the LevelScene class for creating a level.
 * @version 0.1
 * @date 20/11/2023
 *
 * @copyright Copyright (c) 2023
 */

#ifndef DEFUNBOBENGINE_LEVEL_SCENE_HPP
#define DEFUNBOBENGINE_LEVEL_SCENE_HPP

#include "scene.hpp"

class LevelScene : public Scene
{
  public:
    /**
     * @brief This function is responsible for rendering the contents of the LevelScene.
     */
    void RenderScene() override;
};

#endif // DEFUNBOBENGINE_LEVEL_SCENE_HPP
