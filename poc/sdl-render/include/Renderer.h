#pragma once
#include <SDL.h>

class Renderer
{
public:
    Renderer(int width, int height);
    ~Renderer();
    void clear();
    void present();
    void drawRectangle(int x, int y, int w, int h);
    void drawCircle(int x, int y, int radius);
    void drawImage(SDL_Texture *texture, int x, int y, int w, int h);
    SDL_Renderer *getSDLRenderer();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};
