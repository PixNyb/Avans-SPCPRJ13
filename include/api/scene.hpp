/// @file

#ifndef AVANS_SPCPRJ13_SCENE_H
#define AVANS_SPCPRJ13_SCENE_H

#include <vector>
#include <memory>
#include "game_object.hpp"

/**
 * @brief Class representing a scene which can be rendered by the Camera.
 */
class Scene {
public:
    /**
     * @brief This function is called by a Camera to render the scene on the engine.
     */
    virtual void RenderScene() = 0;

    /**
     * @brief This property contains all the Game Object that are contained in this scene.
     */
    std::vector<std::shared_ptr<GameObject>> contents;
};

#endif // AVANS_SPCPRJ13_SCENE_H
