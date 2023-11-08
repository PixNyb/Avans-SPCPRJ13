/**
 * @file scene_manager.hpp
 * @author melvin van bree
 * @brief Manages scenes
 * @version 0.1
 * @date 08/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_SCENE_MANAGER_HPP
#define DEFUNBOBENGINE_SCENE_MANAGER_HPP

#include "scene.hpp"

class SceneManager
{
  private:
    std::unique_ptr<Scene> currentScene;
  public:
        SceneManager();
        ~SceneManager();
        void SetScene(std::unique_ptr<Scene> scene);
        void RenderScene();
        bool HasScene() const;
        const Scene& GetScene();
};

#endif // DEFUNBOBENGINE_SCENE_MANAGER_HPP
