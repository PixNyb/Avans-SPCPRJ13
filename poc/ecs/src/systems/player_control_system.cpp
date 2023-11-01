#include "player_control_system.h"
#include "../core/input_manager.h"
#include "input.h"


void PlayerControlSystem::onStart(entt::registry &registry) {

}

void PlayerControlSystem::onStop(entt::registry &registry) {

}

void PlayerControlSystem::onUpdate(entt::registry &registry, float delta) {
    registry.view<InputComponent>().each([&](InputComponent& input) {
        if(InputManager::wasKeyPressed(SDL_SCANCODE_UP)){
            input.movement_input.y = -1.0f;
        }

        if(InputManager::wasKeyPressed(SDL_SCANCODE_DOWN)){
            input.movement_input.y = 1.0f;
        }

        if(InputManager::wasKeyPressed(SDL_SCANCODE_LEFT)){
            input.movement_input.x = -1.0f;
        }

        if(InputManager::wasKeyPressed(SDL_SCANCODE_RIGHT)){
            input.movement_input.x = 1.0f;
        }

        if(InputManager::wasKeyReleased(SDL_SCANCODE_UP) || InputManager::wasKeyReleased(SDL_SCANCODE_DOWN)){
            input.movement_input.y = 0;
        }

        if(InputManager::wasKeyReleased(SDL_SCANCODE_LEFT) || InputManager::wasKeyReleased(SDL_SCANCODE_RIGHT)){
            input.movement_input.x = 0;
        }
    });
}