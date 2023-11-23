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
#include <algorithm>
#include <vector>

void SDLRect::Draw(SDL_Renderer* renderer) const {
    SDL_Rect sdlRect = toSDLRect();

    // Apply rotation
    auto rot = static_cast<double>(this->rotation);

    // Calculate the rotation center
    int centerX = sdlRect.x + sdlRect.w / 2;
    int centerY = sdlRect.y + sdlRect.h / 2;

    // Calculate the rotated coordinates using rotation and anchor
    int x1 = static_cast<int>(centerX + (sdlRect.x - centerX) * cos(rot) - (sdlRect.y - centerY) * sin(rot));
    int y1 = static_cast<int>(centerY + (sdlRect.x - centerX) * sin(rot) + (sdlRect.y - centerY) * cos(rot));
    int x2 = static_cast<int>(centerX + (sdlRect.x + sdlRect.w - centerX) * cos(rot) - (sdlRect.y - centerY) * sin(rot));
    int y2 = static_cast<int>(centerY + (sdlRect.x + sdlRect.w - centerX) * sin(rot) + (sdlRect.y - centerY) * cos(rot));
    int x3 = static_cast<int>(centerX + (sdlRect.x + sdlRect.w - centerX) * cos(rot) - (sdlRect.y + sdlRect.h - centerY) * sin(rot));
    int y3 = static_cast<int>(centerY + (sdlRect.x + sdlRect.w - centerX) * sin(rot) + (sdlRect.y + sdlRect.h - centerY) * cos(rot));
    int x4 = static_cast<int>(centerX + (sdlRect.x - centerX) * cos(rot) - (sdlRect.y + sdlRect.h - centerY) * sin(rot));
    int y4 = static_cast<int>(centerY + (sdlRect.x - centerX) * sin(rot) + (sdlRect.y + sdlRect.h - centerY) * cos(rot));

    // Draw the filled rotated rectangle
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(renderer, x3, y3, x4, y4);
    SDL_RenderDrawLine(renderer, x4, y4, x1, y1);
}