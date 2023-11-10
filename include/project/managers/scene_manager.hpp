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
    std::shared_ptr<Scene> currentScene;
  public:
        SceneManager();
        ~SceneManager();
        void SetScene(std::shared_ptr<Scene> scene);
        void RenderScene();
        [[nodiscard]] bool HasScene() const;
        std::weak_ptr<Scene> GetScene();
};

#endif // DEFUNBOBENGINE_SCENE_MANAGER_HPP
