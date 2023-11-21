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

int main(int argc, char *argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create an SDL window
    SDL_Window *window = SDL_CreateWindow("SDL Key Press Example", SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (!window)
    {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    auto engine = Engine::GetInstance();
    auto inputManager = engine->Get<IInputFacade>();

    inputManager->Bind(KeyEvent(KeyCode::UP_ARROW, EventType::KEYPRESSED), ActionType::JUMP);
    inputManager->Bind(KeyEvent(KeyCode::DOWN_ARROW, EventType::KEYPRESSED), ActionType::GODOWN);
    inputManager->Bind(KeyEvent(KeyCode::LEFT_ARROW, EventType::KEYPRESSED), ActionType::GOLEFT);
    inputManager->Bind(MouseEvent(KeyCode::MOUSE_LEFT, 0, 0, EventType::MOUSEPRESSED),
                       ActionType::PAUSE);

    std::thread engineThread([&]() { engine->Start(); });

    // Event loop
    bool quit = false;
    while (!quit)
    {
        inputManager->Update();
    }

    // Cleanup
    SDL_DestroyWindow(window);
    SDL_Quit();

    engineThread.join();

    return 0;
}