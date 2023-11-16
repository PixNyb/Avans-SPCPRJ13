/**
 * @file debug_renderer.cpp
 * @author Daan Groot (d.groot3@student.avans.nl)
 * @brief This file contains the debugrendere class implementation.
 * @version 0.1
 * @date 2023-11-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "box2d/debug_renderer.hpp"
#include "game_object.hpp"
#include "box_collider.hpp"
#include "circle_collider.hpp"
#include <Box2D/Box2D.h>
#include <SDL.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const double PixelScale = 0.5;

SDL_Window* window;
SDL_Renderer* renderer;

DebugRenderer::DebugRenderer() {
    InitSDL();
}

DebugRenderer::~DebugRenderer() {
    CloseSDL();
}

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

void DebugRenderer::RenderShapes(std::shared_ptr<GameObject> gameObject) {
    b2Vec2 position(static_cast<float>(gameObject->GetTransform().position.x), static_cast<float>(gameObject->GetTransform().position.y));

    int sdlX = static_cast<int>(position.x * PixelScale);
    int sdlY = SCREEN_HEIGHT - static_cast<int>(position.y * PixelScale);

    SDL_Rect boxRect;
    boxRect.x = sdlX;
    boxRect.y = sdlY;
    for (const auto &boxCollider: gameObject->GetComponents<BoxCollider>()) {
        boxRect.w = static_cast<int>(boxCollider->Width());
        boxRect.h = static_cast<int>(boxCollider->Height());
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderDrawRect(renderer, &boxRect);
    }

//    for (const auto &circleCollider: gameObject->GetComponents<CircleCollider>()) {
//
//    }
}

void DebugRenderer::Render(std::map<std::shared_ptr<GameObject>, b2Body*>& bodies) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (auto const& item : bodies) {
        RenderShapes(item.first);
    }

    SDL_RenderPresent(renderer);
}