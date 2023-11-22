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
    int xPos = radius;
    int yPos = 0;
    int err = 0;

    while (xPos >= yPos) {
        SDL_RenderDrawPoint(renderer, xPos + x, yPos + y);
        SDL_RenderDrawPoint(renderer, -xPos + x, yPos + y);
        SDL_RenderDrawPoint(renderer, xPos + x, -yPos + y);
        SDL_RenderDrawPoint(renderer, -xPos + x, -yPos + y);
        SDL_RenderDrawPoint(renderer, yPos + x, xPos + y);
        SDL_RenderDrawPoint(renderer, -yPos + x, xPos + y);
        SDL_RenderDrawPoint(renderer, yPos + x, -xPos + y);
        SDL_RenderDrawPoint(renderer, -yPos + x, -xPos + y);

        if (err <= 0) {
            yPos += 1;
            err += 2 * yPos + 1;
        }

        if (err > 0) {
            xPos -= 1;
            err -= 2 * xPos + 1;
        }
    }
}
