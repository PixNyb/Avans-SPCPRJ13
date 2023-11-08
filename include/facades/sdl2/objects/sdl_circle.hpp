//
// Created by Robin Pijnappels on 08/11/2023.
//

#ifndef DEFUNBOBENGINE_SDL_CIRCLE_HPP
#define DEFUNBOBENGINE_SDL_CIRCLE_HPP

#include <SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

class SDLCircle {
public:
    int x, y, radius;

    SDLCircle(int x, int y, int radius)
            : x(x), y(y), radius(radius) {}

    void draw(SDL_Renderer* renderer) const {
        filledCircleRGBA(renderer, x, y, radius, 255, 255, 255, 255); // TODO: add color
    }
};
#endif //DEFUNBOBENGINE_SDL_CIRCLE_HPP
