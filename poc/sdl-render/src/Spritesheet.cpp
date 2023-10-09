#include "../include/Spritesheet.h"
#include "SDL_image.h"

Spritesheet::Spritesheet(SDL_Renderer *render, int w, int h) {
    const int FPS = 60;
    int frameTime = 0;
    SDL_Rect playerRect;

    SDL_Surface *loadedSurface = IMG_Load("../assets/lego_spritesheet.png");

    if(loadedSurface) {
        SDL_Texture *texture = SDL_CreateTextureFromSurface(render, loadedSurface);
        SDL_FreeSurface(loadedSurface);

        int textureWidth, textureHeight;
        SDL_QueryTexture(texture, nullptr, nullptr, &textureWidth, &textureHeight);

        int frameWidth = textureWidth / 8;
        int frameHeight = textureHeight / 3;

        playerRect.x = playerRect.y = 0;
        playerRect.w = frameWidth;
        playerRect.h = frameHeight;

        SDL_SetRenderDrawColor(render, 0,0,0,0);

        while(true) {
            frameTime++;

            if(frameTime % (FPS / 6) == 0) {
                frameTime = 0;
                playerRect.x += frameWidth;

                if(playerRect.x >= textureWidth) {
                    playerRect.x = 0;
                }
            }

            SDL_RenderClear(render);

            SDL_Rect dstRect;
            dstRect.x = (w - frameWidth) / 2;
            dstRect.y = (h - frameHeight) / 2;
            dstRect.w = frameWidth;
            dstRect.h = frameHeight;

            SDL_RenderCopy(render, texture, &playerRect, &dstRect);
            SDL_RenderPresent(render);

            SDL_Delay(1000 / FPS);
        }
    }
};