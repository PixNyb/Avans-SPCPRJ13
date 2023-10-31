#pragma once

#include <system.h>
#include "scene.h"

class SceneSystem : System {
public:
    SceneSystem();
    void onStop(entt::registry &registry) override;
    void onStart(entt::registry &registry) override;
    void onUpdate(entt::registry &registry, float delta) override;

    void change_scene(entt::registry &registry, std::shared_ptr<Scene>& new_scene);
private:
    std::shared_ptr<Scene> _current_scene {nullptr};
};