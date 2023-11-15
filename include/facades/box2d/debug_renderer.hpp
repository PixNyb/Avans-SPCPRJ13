//
// Created by Eigenaar on 14-11-2023.
//

#ifndef DEFUNBOBENGINE_DEBUG_RENDERER_HPP
#define DEFUNBOBENGINE_DEBUG_RENDERER_HPP

#include <iostream>
#include <Box2D/Box2D.h>
#include <SDL.h>

class DebugRenderer {
public:
    void InitSDL();

    void CloseSDL();

    void Render();

    void RenderBox(b2Body* body);

    void Run(std::unique_ptr<b2World> b2World);
};


#endif //DEFUNBOBENGINE_DEBUG_RENDERER_HPP
