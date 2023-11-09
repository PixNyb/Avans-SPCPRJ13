#include "SDL2/SDL_render.h"
#include "box.h"
#include "position.h"
#include "system.h"

#include "scene_manager.h"
#include "transform.h"

// TODO: Check if this is needed at all
// Could just be a namespace with methods??

namespace RenderSystem
{
void beginRenderingCycle(SDL_Renderer &renderer)
{
    SDL_RenderClear(&renderer);
    SDL_SetRenderDrawColor(&renderer, 0, 0, 0, 255);
}

void endRenderingCycle(SDL_Renderer &renderer) { SDL_RenderPresent(&renderer); }

void render(SDL_Renderer &renderer, entt::registry &registry)
{

    // Draw box components
    auto view = registry.view<PositionComponent, Box2DComponent>();
    for (auto entity : view)
    {
        auto &pos = view.get<PositionComponent>(entity);
        auto &box = view.get<Box2DComponent>(entity);

        SDL_Rect rect;
        rect.x = (int)pos.position2D.x;
        rect.y = (int)pos.position2D.y;
        rect.h = box.height;
        rect.w = box.width;

        SDL_SetRenderDrawColor(&renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(&renderer, &rect);

        // Reset color
        SDL_SetRenderDrawColor(&renderer, 0, 0, 0, 255);
    }
}
} // namespace RenderSystem
