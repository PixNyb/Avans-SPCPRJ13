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

/**
 * @class SceneManager
 *
 * @brief Manages scenes and their updates.
 */
class SceneManager
{
  private:
    std::shared_ptr<Scene> currentScene;

  public:
    SceneManager();
    ~SceneManager();

    /**
     * @brief Updates the current scene
     * @param deltaTime The time passed since the last frame
     */
    void Update(double deltaTime);

    /**
     * @brief Renders the current scene
     */
    void RenderScene();

    /**
     * @brief Sets the current scene
     * @param scene The scene to set
     */
    void SetScene(std::shared_ptr<Scene> scene);

    /**
     * @brief Checks if there is a scene
     * @return True if there is a scene, false otherwise
     */
    [[nodiscard]] bool HasScene() const;

    /**
     * @brief Gets the current scene
     * @return A weak pointer to the current scene
     */
    std::weak_ptr<Scene> GetScene();

    /**
     * @brief Clears the current scene and sets it to nullptr
     */
    void ClearScene();
};

#endif // DEFUNBOBENGINE_SCENE_MANAGER_HPP
