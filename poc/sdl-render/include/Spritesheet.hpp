#pragma once
#include <SDL.h>

class Spritesheet
{
public:
    Spritesheet(SDL_Renderer *renderer, int w, int h);
    void update();
    void render();

private:
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Rect playerRect;
    int frameTime;
    int textureWidth, textureHeight;
    int frameWidth, frameHeight;
};
