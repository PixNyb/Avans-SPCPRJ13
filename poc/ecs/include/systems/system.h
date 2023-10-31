#pragma once

#include "entt/entt.hpp"

class System {
public:
    virtual void onUpdate(entt::registry &registry, float delta) = 0;
    virtual void onStart(entt::registry &registry) = 0;
    virtual void onStop(entt::registry &registry) = 0;
};