/**
 * @file sdl_init.cpp
 * @author Robin Pijnappels
 * @brief This file contains the SDLInit class implementation.
 * @version 0.1
 * @date 2023-11-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "sdl_init.hpp"
#include <SDL_ttf.h>

SDLInit::SDLInit() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
    }

    if(TTF_Init() < 0) {
        std::cout << "Couldn't initialize TTF lib: " << TTF_GetError() << std::endl;
    }
}
