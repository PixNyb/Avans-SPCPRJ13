//
// Created by Robin Pijnappels on 08/11/2023.
//

#ifndef DEFUNBOBENGINE_SDL_SURFACE_HPP
#define DEFUNBOBENGINE_SDL_SURFACE_HPP

#include <SDL.h>

class SDLSurface {
private:
    SDL_Surface* surface;

public:
    SDLSurface(const char* filePath);
    ~SDLSurface();

    SDL_Surface* getSDLSurface() const;
};

#endif //DEFUNBOBENGINE_SDL_SURFACE_HPP
