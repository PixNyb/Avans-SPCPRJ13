#pragma once
#include "entt/entt.hpp"
#include "system.h"
#include <SDL.h>

// We need to forward declare GameObject here because of a circular reference
class GameObject;

class Scene
{
  public:
    explicit Scene(SDL_Renderer *render);
    ~Scene();
    void onAttach(entt::registry &registry);
    void onDetach(entt::registry &registry);
    void onUpdate(entt::registry &registry, float delta);
    void onRender(entt::registry &registry);
    GameObject createGameObject(entt::registry &registry);

  private:
    SDL_Renderer *_renderer;
    std::vector<GameObject> _game_objects;
};