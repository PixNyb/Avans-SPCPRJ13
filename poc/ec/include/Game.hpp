#ifndef GAME_HPP
#define GAME_HPP

#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <vector>

class Game
{
  public:
    Game();
    ~Game();
    void run();
    void addEntity(Entity *entity);
    void removeEntity(Entity *entity);
    SDL_Renderer &getRenderer() const { return *renderer; }
    std::vector<Entity *> getEntities() const;

  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Color backgroundColor = {255, 255, 255, 255};

    bool isRunning = true;
    std::vector<Entity *> entities;
};

#endif