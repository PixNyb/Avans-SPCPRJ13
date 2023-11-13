#include "sdl_render.hpp"

void SDLRender::Clear() {
    SDL_RenderClear(Renderer);
}

void SDLRender::Present() {
    SDL_RenderPresent(Renderer);
}
