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

void SDL2InputHandler::PollEvents(std::vector<SDL_Event>& sdlEvents) {
    for(SDL_Event sdlEvent : sdlEvents) {
        if (sdlEvent.type == SDL_KEYDOWN || sdlEvent.type == SDL_KEYUP) {
            polledKeyEvents.emplace_back(std::make_shared<KeyEvent>(sdlEvent));
        }
        else if (sdlEvent.type == SDL_MOUSEBUTTONDOWN || sdlEvent.type == SDL_MOUSEBUTTONUP || sdlEvent.type == SDL_MOUSEMOTION) {
            polledMouseEvents.emplace_back(std::make_shared<MouseEvent>(sdlEvent));
        }
    }
}

std::vector<std::shared_ptr<KeyEvent>> SDL2InputHandler::getPolledKeyEvents() const {
    return polledKeyEvents;
}

std::vector<std::shared_ptr<MouseEvent>> SDL2InputHandler::getPolledMouseEvents() const {
    return polledMouseEvents;
}