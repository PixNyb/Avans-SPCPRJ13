#pragma once

#include "scene.h"
#include <SDL.h>

namespace RenderSystem {
    void render(SDL_Renderer &renderer, entt::registry &registry);
    void beginRenderingCycle(SDL_Renderer& renderer);
    void endRenderingCycle(SDL_Renderer& renderer);
}