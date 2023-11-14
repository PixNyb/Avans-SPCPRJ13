/**
 * @file sdl_triangle.cpp
 * @author Robin Pijnappels
 * @brief TODO
 * @version 0.1
 * @date 14/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "sdl_triangle.hpp"

void SDLTriangle::Draw(SDL_Renderer* renderer) const {
    filledPolygonRGBA(renderer, vx, vy, 3, 255, 255, 255, 255); // TODO: add color
}
