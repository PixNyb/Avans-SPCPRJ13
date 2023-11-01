#include <scene_system.h>

SceneSystem::SceneSystem() {

}

void SceneSystem::onStart(entt::registry &registry) {

}

void SceneSystem::onStop(entt::registry &registry) {

}

void SceneSystem::onUpdate(entt::registry &registry, float delta) {
    if (_current_scene != nullptr) {
        _current_scene->onUpdate(registry, delta);
        _current_scene->onRender(registry);
    }
}

void SceneSystem::change_scene(entt::registry &registry, std::shared_ptr<Scene>& new_scene) {
    if (_current_scene != nullptr) {
        _current_scene->onDetach(registry);
    }
    _current_scene = new_scene;

    if (_current_scene != nullptr) {
        _current_scene->onAttach(registry);
    }
}