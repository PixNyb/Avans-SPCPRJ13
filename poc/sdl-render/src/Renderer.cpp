#include "Renderer.hpp"
#include "Spritesheet.hpp"

Renderer::Renderer(int width, int height)
{
    window = SDL_CreateWindow("POC", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Renderer::clear()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Renderer::present()
{
    SDL_RenderPresent(renderer);
}

void Renderer::drawRectangle(int x, int y, int w, int h)
{
    SDL_Rect rect = {x, y, w, h};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Renderer::drawCircle(int x, int y, int radius)
{
    SDL_Color color = {0, 0, 0, 0};

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w;
            int dy = radius - h;

            if ((dx*dx + dy*dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}

void Renderer::drawImage(SDL_Texture *texture, int x, int y, int w, int h)
{
    SDL_Rect destRect = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
}

void Renderer::drawSprite(int w, int h) {
    Spritesheet spritesheet(this->renderer, w, h);
}

SDL_Renderer *Renderer::getSDLRenderer()
{
    return renderer;
}
