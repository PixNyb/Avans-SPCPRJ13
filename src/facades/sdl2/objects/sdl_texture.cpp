/**
 * @file sdl_texture.cpp
 * @author "Melvin van Bree"
 * @brief TODO
 * @version 0.1
 * @date 17/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "sdl_texture.hpp"
#include <SDL_image.h>

SDLTexture::SDLTexture(SDL_Renderer* renderer, const std::string& filePath) {
    SDL_Surface* surface = IMG_Load(filePath.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

SDL_Texture* SDLTexture::getSDLTexture() const {
    return texture;
}