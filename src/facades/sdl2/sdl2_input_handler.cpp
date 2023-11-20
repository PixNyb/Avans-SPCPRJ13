/**
 * @file sdl2_input_handler.cpp
 * @author Martijn Vermeer
 * @brief This file contains the sdl input handler class implementation.
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "sdl2_input_handler.hpp"

void SDL2InputHandler::PollEvents() {
    SDL_Event event;

    int sdlKeyCode = static_cast<int>(event.key.keysym.scancode);
    KeyCode a = static_cast<KeyCode>(sdlKeyCode);

    while (SDL_PollEvent(&event)) {
        auto keyCode = static_cast<KeyCode>(event.key.keysym.scancode);

        if(event.type == SDL_KEYUP) {
            polledKeyEvents.emplace_back(std::make_shared<KeyEvent>(keyCode, false));
        }
        else if (event.type == SDL_KEYDOWN) {
            polledKeyEvents.emplace_back(std::make_shared<KeyEvent>(keyCode, true));
        }
        else if(event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
            polledMouseEvents.emplace_back(std::make_shared<MouseEvent>(keyCode));
        }
    };
}

std::vector<std::shared_ptr<KeyEvent>> SDL2InputHandler::GetPolledKeyEvents() const {
    return polledKeyEvents;
}

std::vector<std::shared_ptr<MouseEvent>> SDL2InputHandler::GetPolledMouseEvents() const {
    return polledMouseEvents;
}