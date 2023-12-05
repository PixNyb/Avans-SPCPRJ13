/**
 * @file sdl_texture.cpp
 * @author "Melvin van Bree"
 * @brief SDLTexture is a wrapper for SDL_Texture
 * @version 0.1
 * @date 17/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "sdl_texture.hpp"
#include <SDL_image.h>
#include <iostream>

SDLTexture::SDLTexture(SDL_Renderer *renderer, const std::string &filePath)
{
    SDL_Surface *surface = IMG_Load(filePath.c_str());
    if (!surface)
    {
        std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
        texture = nullptr;
    }
    else
    {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        if (!texture)
        {
            std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
        }
    }
}

SDL_Texture *SDLTexture::GetSDLTexture() const { return texture; }