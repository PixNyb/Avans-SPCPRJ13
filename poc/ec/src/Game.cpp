#include "Game.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

Game::Game() {
  // Initialize SDL2
  SDL_Init(SDL_INIT_VIDEO);

  // Create a window
  window =
      SDL_CreateWindow("EC Poc", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

  // Create a renderer
  renderer = SDL_CreateRenderer(window, -1, 0);
}

Game::~Game() {
  for (auto entity : entities) {
    delete entity;
  }
}

void Game::run() {
  std::cout << "Game is running" << std::endl;
  while (isRunning) {
    SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g,
                           backgroundColor.b, backgroundColor.a);
    SDL_RenderClear(renderer);

    // Pass the sdl events to the entities
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        isRunning = false;

      for (auto entity : entities)
        entity->update(event);

      SDL_RenderPresent(renderer);
    }

    SDL_Delay(16);
  }

  std::cout << "Game is stopped" << std::endl;
}

void Game::addEntity(Entity *entity) { entities.push_back(entity); }

void Game::removeEntity(Entity *entity) {
  entities.erase(std::remove(entities.begin(), entities.end(), entity),
                 entities.end());
}

std::vector<Entity *> Game::getEntities() const { return entities; }