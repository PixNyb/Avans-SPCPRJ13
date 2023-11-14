/**
 * @file sdl_circle.cpp
 * @author Robin Pijnappels
 * @brief TODO
 * @version 0.1
 * @date 14/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "sdl_circle.hpp"

void SDLCircle::Draw(SDL_Renderer* renderer) const {
    filledCircleRGBA(renderer, x, y, radius, 255, 255, 255, 255); // TODO: add color
}
