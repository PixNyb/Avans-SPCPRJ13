//
// Created by Robin Pijnappels on 08/11/2023.
//

#ifndef DEFUNBOBENGINE_SDL_RECT_HPP
#define DEFUNBOBENGINE_SDL_RECT_HPP

#include <SDL.h>

class SDLRect {
public:
    int x, y, width, height;

    SDLRect(int x, int y, int width, int height)
            : x(x), y(y), width(width), height(height) {}

    SDL_Rect toSDLRect() const {
        return {x, y, width, height};
    }
};

#endif //DEFUNBOBENGINE_SDL_RECT_HPP
