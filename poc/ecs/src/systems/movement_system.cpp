#include "movement_system.h"
#include "input.h"
#include "position.h"

void MovementSystem::onUpdate(entt::registry &registry, float delta)
{
    auto view = registry.view<PositionComponent, const InputComponent>();

    view.each(
        [delta](PositionComponent &pos, const InputComponent &input)
        {
            // TODO: Obviously we want the physics engine to take this over
            if (input.movement_input.x != 0 || input.movement_input.y != 0)
            {
                pos.position2D.x += input.movement_input.x * 40 * delta;
                pos.position2D.y += input.movement_input.y * 40 * delta;
            }
        });
}

void MovementSystem::onStart(entt::registry &registry) {}

void MovementSystem::onStop(entt::registry &registry) {}
