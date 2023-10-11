#include "Spritesheet.hpp"
#include <SDL2/SDL_image.h>

Spritesheet::Spritesheet(SDL_Renderer *renderer, int w, int h) : renderer(renderer), frameTime(0)
{
    SDL_Surface *loadedSurface = IMG_Load("../assets/lego_spritesheet.png");
    if (loadedSurface)
    {
        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        SDL_FreeSurface(loadedSurface);

        SDL_QueryTexture(texture, nullptr, nullptr, &textureWidth, &textureHeight);

        frameWidth = textureWidth / 8;
        frameHeight = textureHeight / 3;

        playerRect.x = playerRect.y = 0;
        playerRect.w = frameWidth;
        playerRect.h = frameHeight;
    }
}

void Spritesheet::update()
{
    frameTime++;
    if (frameTime % 10 == 0)
    {
        frameTime = 0;
        playerRect.x += frameWidth;
        if (playerRect.x >= textureWidth)
        {
            playerRect.x = 0;
        }
    }
}

void Spritesheet::render()
{
    SDL_Rect dstRect;
    dstRect.x = (800 - frameWidth) / 2;
    dstRect.y = (600 - frameHeight) / 2;
    dstRect.w = frameWidth;
    dstRect.h = frameHeight;

    SDL_RenderCopy(renderer, texture, &playerRect, &dstRect);
}
