//
// Created by Robin on 13-11-2023.
//

#include "sdl_init.hpp"

SDLInit::SDLInit() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
    }
}
