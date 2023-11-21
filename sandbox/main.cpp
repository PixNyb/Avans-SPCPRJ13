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
#include <SDL.h>
#include <SDL_events.h>
#include <thread>

SDL_Event CreateKeyEvent(KeyCode key, EventType eventType)
{
    SDL_Event event;
    event.type = eventType == EventType::KEYPRESSED ? SDL_KEYDOWN : SDL_KEYUP;
    event.key.keysym.scancode = static_cast<SDL_Scancode>(key);
    event.key.keysym.sym = static_cast<SDL_Keycode>(key);
    event.key.keysym.mod = KMOD_NONE;
    event.key.repeat = 0;

    return event;
}

void SimulateKeyPress(KeyCode key)
{
    SDL_Event event = CreateKeyEvent(key, EventType::KEYPRESSED);
    SDL_PushEvent(&event);
}

SDL_Event CreateMouseEvent(KeyCode key, EventType eventType)
{
    SDL_Event event;
    event.type = eventType == EventType::MOUSEPRESSED ? SDL_MOUSEBUTTONDOWN : SDL_MOUSEBUTTONUP;
    event.key.keysym.scancode = static_cast<SDL_Scancode>(key);
    event.key.keysym.sym = static_cast<SDL_Keycode>(key);
    event.key.keysym.mod = KMOD_NONE;
    event.key.repeat = 0;

    return event;
}

void SimulateMousePress(KeyCode key) {
    SDL_Event event = CreateMouseEvent(key, EventType::MOUSEPRESSED);
    SDL_PushEvent(&event);
}

int main(int argc, char *argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create an SDL window
    SDL_Window* window = SDL_CreateWindow("SDL Key Press Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    auto engine = Engine::GetInstance();
    auto inputManager = engine->Get<IInputFacade>();

    inputManager->Bind(KeyEvent(KeyCode::UP_ARROW, EventType::KEYPRESSED), ActionType::JUMP);
    inputManager->Bind(KeyEvent(KeyCode::DOWN_ARROW, EventType::KEYPRESSED), ActionType::GODOWN);
    inputManager->Bind(KeyEvent(KeyCode::LEFT_ARROW, EventType::KEYPRESSED), ActionType::GOLEFT);
    inputManager->Bind(MouseEvent(KeyCode::MOUSE_LEFT, 0, 0, EventType::MOUSEPRESSED), ActionType::PAUSE);

    std::thread engineThread([&]() { engine->Start(); });

    // Event loop
    bool quit = false;
    while (!quit) {
        inputManager->Update();
    }

    // Cleanup
    SDL_DestroyWindow(window);
    SDL_Quit();

//    SimulateKeyPress(KeyCode::UP_ARROW);
//    SimulateMousePress(KeyCode::MOUSE_LEFT);

    engineThread.join();

    return 0;
}