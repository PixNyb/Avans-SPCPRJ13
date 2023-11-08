//
// Created by Robin Pijnappels on 08/11/2023.
//

#ifndef DEFUNBOBENGINE_SDL_TRIANGLE_HPP
#define DEFUNBOBENGINE_SDL_TRIANGLE_HPP

#include <SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

class SDLTriangle {
public:
    Sint16 vx[3];
    Sint16 vy[3];

    SDLTriangle(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 x3, Sint16 y3) {
        vx[0] = x1; vy[0] = y1;
        vx[1] = x2; vy[1] = y2;
        vx[2] = x3; vy[2] = y3;
    }

    void draw(SDL_Renderer* renderer) const {
        filledPolygonRGBA(renderer, vx, vy, 3, 255, 255, 255, 255); // TODO: add color
    }

};


#endif //DEFUNBOBENGINE_SDL_TRIANGLE_HPP
