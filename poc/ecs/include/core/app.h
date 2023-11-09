#pragma once

#include "SDL.h"
#include "SDL_opengl.h"
#include "definitions.h"
#include "entt/entity/registry.hpp"
#include "scene_manager.h"
#include "system.h"

enum AppState
{
    RUNNING,
    PAUSED,
    EXIT
};

class App
{
  public:
    App();
    ~App();

    void start();
    void initSystems();

  private:
    int _screenWidth;
    int _screenHeight;

    std::vector<System *> _systems;
    SDL_Window *_window;
    SDL_Renderer *_renderer;
    AppState _state;
    entt::registry _primary_registry;

    void update(float delta);
    void test();
};