/**
 * @file sdl_rect.cpp
 * @author Robin Pijnappels
 * @brief TODO
 * @version 0.1
 * @date 14/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "sdl_rect.hpp"

void SDLRect::Draw(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // TODO: Add color customization
    SDL_Rect sdlRect = toSDLRect();
    SDL_RenderFillRect(renderer, &sdlRect);
}
