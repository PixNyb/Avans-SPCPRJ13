/**
 * @file sdl_surface.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the SDLSurface class implementation.
 * @version 0.1
 * @date 2023-11-08
 *
 * The SDLSurface class is responsible for managing SDL_Surface resources,
 * providing an interface for loading and retrieving an SDL_Surface from a file path.
 * It ensures that the loaded surface is properly released when the object is destroyed.
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "sdl_surface.hpp"
#include <SDL_image.h>
#include <iostream>

SDLSurface::SDLSurface(const char* filePath) {
    surface = IMG_Load(filePath);
    if (!surface) {
        std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
    }
}

SDLSurface::~SDLSurface() {
    if (surface) {
        SDL_FreeSurface(surface);
    }
}

SDL_Surface* SDLSurface::getSDLSurface() const {
    return surface;
}

