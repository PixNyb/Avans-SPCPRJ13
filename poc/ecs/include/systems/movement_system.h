#pragma once

#include "system.h"

class MovementSystem : public System {
public:
    void onStart(entt::registry &registry) override;
    void onUpdate(entt::registry &registry, float delta) override;
    void onStop(entt::registry &registry) override;
};