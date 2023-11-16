/**
 * @file debug_renderer.hpp
 * @author Daan Groot (d.groot3@student.avans.nl)
 * @brief This file contains the debugrendere class defenition.
 * @version 0.1
 * @date 2023-11-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_DEBUG_RENDERER_HPP
#define DEFUNBOBENGINE_DEBUG_RENDERER_HPP

#include <iostream>
#include <Box2D/Box2D.h>
#include <SDL.h>
#include "game_object.hpp"
#include <map>

class DebugRenderer {
public:
    DebugRenderer();
    ~DebugRenderer();

    /**
     * Opens SDL
     */
    void InitSDL();

    /**
     * Closes SDL
     */
    void CloseSDL();

    /**
     * Renders entire bodies and delegates rendering shapes to render shape
     * @param bodies the gameobjects and bodies together
     */
    void Render(std::map<std::shared_ptr<GameObject>, b2Body *> &bodies);

    /**
     * Renders a specific shape
     * @param gameObject the gameobject that contains the shape
     */
    void RenderShapes(std::shared_ptr<GameObject> gameObject);

};


#endif //DEFUNBOBENGINE_DEBUG_RENDERER_HPP
