#include "scene.h"
#include "entt/entt.hpp"
#include "game_object.h"
#include "render_system.h"
#include "player_control_system.h"
#include "movement_system.h"

Scene::Scene(SDL_Renderer* renderer) {
    _renderer = renderer;
}

Scene::~Scene() = default;

void Scene::onAttach(entt::registry &registry) {

}

void Scene::onDetach(entt::registry &registry) {
    // TODO: Remove from registry

    // registry.destroy(_game_objects.begin(), _game_objects.end());
    // _game_objects.clear();
}

void Scene::onUpdate(entt::registry &registry, float delta) {

}

void Scene::onRender(entt::registry &registry) {

}

GameObject Scene::createGameObject(entt::registry &registry) {
    auto ptr = std::shared_ptr<Scene>(this);
    GameObject ent { registry.create(), ptr };
    _game_objects.push_back(ent);
    return ent;
}
