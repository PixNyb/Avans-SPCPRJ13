/**
 * @file base_level_scene.hpp
 * @author melvi
 * @brief TODO
 * @version 0.1
 * @date 08/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_BASE_LEVEL_SCENE_HPP
#define DEFUNBOBENGINE_BASE_LEVEL_SCENE_HPP

#include "base_scene.hpp"

/**
 * @brief Provides specializations for level scenes
 *
 */
class BaseLevelScene : public BaseScene
{
public:
    BaseLevelScene(int id);
    ~BaseLevelScene();
    virtual void RenderScene() override;
    virtual void UpdateScene() override;

    /**
     * @brief Starts the level.
     *
     */
    void StartLevel();

    /**
     * @brief Stops the level.
     *
     */
    void StopLevel();

    /**
     * @brief Loads the level.
     *
     * @param content
     */
    void LoadLevel(std::string& content);

    /**
     * @brief Get the Id object
     *
     * @return ID of the level.
     */
    int GetId() const;
private:
    int id;
};

#endif // DEFUNBOBENGINE_BASE_LEVEL_SCENE_HPP
