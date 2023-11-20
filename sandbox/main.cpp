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

#include "engine.hpp"
#include "i_input_facade.hpp"
#include "key_code.hpp"
#include "key_event.hpp"
#include "key_listener.hpp"
#include "mouse_listener.hpp"
#include <SDL.h>
#include <SDL_events.h>
#include <thread>

SDL_Event createKeyEvent(KeyCode key, bool isKeyDown)
{
    SDL_Event event;
    event.type = isKeyDown ? SDL_KEYDOWN : SDL_KEYUP;
    event.key.keysym.scancode = static_cast<SDL_Scancode>(key);
    event.key.keysym.sym = static_cast<SDL_Keycode>(key);
    event.key.keysym.mod = KMOD_NONE;
    event.key.repeat = 0;

    return event;
}

void simulateKeyPress(KeyCode key)
{
    SDL_Event event = createKeyEvent(key, true);
    SDL_PushEvent(&event);
}

int main(int argc, char *argv[])
{
    auto engine = Engine::GetInstance();
    auto inputManager = engine->Get<IInputFacade>();

    inputManager->Bind(KeyEvent(KeyCode::UP_ARROW, true), ActionType::JUMP);

    std::thread engineThread([&]() { engine->Start(); });

    simulateKeyPress(KeyCode::UP_ARROW);

    engineThread.join();

    return 0;
}