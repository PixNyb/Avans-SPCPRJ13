/**
 * @file main.cpp
 * @author "Melvin van Bree"
 * @brief Used as a sandbox to test code without have to open up a game.
 * @version 0.1
 * @date 10/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "input_manager.hpp"
#include "key_listener.hpp"
#include "mouse_listener.hpp"

void simulateKeyPress(char key) {
    SDL_Event keyEvent;

    keyEvent.type = SDL_KEYDOWN;
    keyEvent.key.keysym.sym = static_cast<SDL_Keycode>(key);
    keyEvent.key.keysym.mod = KMOD_NONE;

    SDL_PushEvent(&keyEvent);

    InputManager inputManager;

    //Register key
    std::unique_ptr<IKeyListener> keyListener = std::make_unique<KeyListener>();
    inputManager.registerKey(std::move(keyListener));

    std::vector<SDL_Event> events;
    events.push_back(keyEvent);

    inputManager.update(events);

    inputManager.bind(*inputManager.getSDLInputHandler()->getPolledKeyEvents().back(), ActionType::GOUP);

    inputManager.update(events);
}


void simulateMousePress() {
    SDL_Event mouseEvent;
    mouseEvent.type = SDL_MOUSEMOTION;
    mouseEvent.motion.x = 10;
    mouseEvent.motion.y = 20;
    mouseEvent.button.button = SDL_BUTTON_LEFT;
    SDL_PushEvent(&mouseEvent);

    InputManager inputManager;

    //Register mouse
    std::unique_ptr<IMouseListener> mouseListener = std::make_unique<MouseListener>();
    inputManager.registerMouse(std::move(mouseListener));

    std::vector<SDL_Event> events;
    events.push_back(mouseEvent);

    inputManager.update(events);

    inputManager.bind(*inputManager.getSDLInputHandler()->getPolledMouseEvents().back(), ActionType::PAUSE);

    inputManager.update(events);
}

int main(int argc, char *argv[])
{
    simulateKeyPress('A');
    simulateMousePress();

    return 1;
}