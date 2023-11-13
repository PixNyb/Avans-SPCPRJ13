/**
 * @file sdl_render.cpp
 * @author Robin Pijnappels
 * @brief This file contains the SDLRender class implementation.
 * @version 0.1
 * @date 2023-11-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "sdl_render.hpp"

void SDLRender::Clear() {
    SDL_RenderClear(Renderer);
}

void SDLRender::Present() {
    SDL_RenderPresent(Renderer);
}
