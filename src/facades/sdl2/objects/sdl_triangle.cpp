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
    auto x1 = vx[0];
    auto xy = vy[0];

    auto x2 = vx[1];
    auto y2 = vy[1];

    auto x3 = vx[2];
    auto y3 = vy[2];

    SDL_RenderDrawLine(renderer, x1, xy, x2, y2);
    SDL_RenderDrawLine(renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(renderer, x3, y3, x1, xy);
}
