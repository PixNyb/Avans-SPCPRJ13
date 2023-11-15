//
// Created by Eigenaar on 14-11-2023.
//

#include "box2d/debug_renderer.hpp"

#include <iostream>
#include <Box2D/Box2D.h>
#include <SDL.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const float TIME_STEP = 1.0f / 240.0f;
const int VELOCITY_ITERATIONS = 6;
const int POSITION_ITERATIONS = 2;
const double PixelScale = 0.5;

b2World* world;

SDL_Window* window;
SDL_Renderer* renderer;



void DebugRenderer::InitSDL() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Box2D with SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void DebugRenderer::CloseSDL() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void DebugRenderer::RenderBox(b2Body* body) {
    b2Vec2 position = body->GetPosition();
    float angle = body->GetAngle();

    int sdlX = static_cast<int>(position.x * PixelScale);
    int sdlY = SCREEN_HEIGHT - static_cast<int>(position.y * PixelScale);

    SDL_Rect boxRect;
    boxRect.x = sdlX;
    boxRect.y = sdlY;
    boxRect.w = 50;
    boxRect.h = 50;

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(renderer, &boxRect);
    SDL_RenderDrawLine(renderer, sdlX, sdlY,
                       static_cast<int>((position.x + 25 * cos(angle)) * PixelScale),
                       SCREEN_HEIGHT - static_cast<int>((position.y + 25 * sin(angle)) * PixelScale));
}

void DebugRenderer::Render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (b2Body* body = world->GetBodyList(); body; body = body->GetNext()) {
        RenderBox(body);
    }

    SDL_RenderPresent(renderer);
}

void DebugRenderer::Run(std::unique_ptr<b2World> bWorld) {
    InitSDL();

    world = bWorld.get();

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        world->Step(TIME_STEP, VELOCITY_ITERATIONS, POSITION_ITERATIONS);

        Render();
    }

    delete world;
    CloseSDL();
}