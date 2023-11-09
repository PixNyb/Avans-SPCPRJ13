#include "Renderer.hpp"
#include "Spritesheet.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char *args[])
{
    int windowWidth = 800;
    int windowHeight = 600;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        return 1;
    }

    Renderer renderer(windowWidth, windowHeight);
    Spritesheet spritesheet(renderer.getSDLRenderer(), windowWidth, windowHeight);

    SDL_Surface *bgSurface = IMG_Load("assets/indianaBob.png");
    if (bgSurface == nullptr)
    {
        SDL_Log("Unable to load image: %s", IMG_GetError());
        return 1;
    }

    SDL_Texture *bgTexture = SDL_CreateTextureFromSurface(renderer.getSDLRenderer(), bgSurface);
    SDL_FreeSurface(bgSurface);

    if (bgTexture == nullptr)
    {
        SDL_Log("Unable to create texture: %s", SDL_GetError());
        return 1;
    }

    bool quit = false;
    SDL_Event e;
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        renderer.clear();
        renderer.drawImage(bgTexture, 0, 0, windowWidth, windowHeight);
        renderer.drawRectangle(50, 50, 100, 100);
        // renderer.drawCircle(400, 300, 50);

        spritesheet.update();
        spritesheet.render();

        renderer.present();
        SDL_Delay(16); // Around 60 FPS
    }

    SDL_DestroyTexture(bgTexture);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
