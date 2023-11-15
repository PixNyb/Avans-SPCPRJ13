/**
 * @file RenderManager.h
 * @author "Melvin van Bree"
 * @brief TODO
 * @version 0.1
 * @date 14/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_SRC_PROJECT_MANAGERS_RENDERMANAGER_H
#define DEFUNBOBENGINE_SRC_PROJECT_MANAGERS_RENDERMANAGER_H

#include "game_object.hpp"
#include "point.hpp"
#include "graphics_facade.hpp"

class RenderManager
{
  private:
    /**
     * @brief Renders a game object if possible (contains specializations for different types)
     * @param gfx Graphics facade
     * @param cameraPoint Point of the camera (used for relative calculations compared to
     * absolute coordinates)
     * @param gameObject Game object to render
     */
    void Render(IOFacade &gfx, const Point &cameraPoint, const GameObject &gameObject);
  public:
    RenderManager();
    ~RenderManager();
    /**
     * @brief Renders all active game objects in the scene if possible
     */
    void Render();
};

#endif // DEFUNBOBENGINE_SRC_PROJECT_MANAGERS_RENDERMANAGER_H
