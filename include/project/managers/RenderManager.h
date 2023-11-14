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
class RenderManager
{
  private:
    void Render(const Point &renderPoint, const GameObject &gameObject);
  public:
    RenderManager();
    ~RenderManager();

    void Render();
};

#endif // DEFUNBOBENGINE_SRC_PROJECT_MANAGERS_RENDERMANAGER_H
