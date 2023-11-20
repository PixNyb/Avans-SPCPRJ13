/**
 * @file mouse_event.cpp
 * @author Martijn Vermeer
 * @brief This file contains the mouse event class implementation.
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "mouse_event.hpp"

MouseEvent::MouseEvent(SDL_Event& sdlEvent) : Event(sdlEvent.type), sdlMouseButtonEvent{} {
    if (sdlEvent.type == SDL_MOUSEBUTTONDOWN || sdlEvent.type == SDL_MOUSEBUTTONUP) {
        sdlMouseButtonEvent = sdlEvent.button;
    } else if (sdlEvent.type == SDL_MOUSEMOTION) {
        sdlMouseButtonEvent.x = sdlEvent.motion.x;
        sdlMouseButtonEvent.y = sdlEvent.motion.y;
    }
}

Uint8 MouseEvent::getMouseButton() const {
    return sdlMouseButtonEvent.button;
}

SDL_Point MouseEvent::getMousePos() const {
    SDL_Point point;

    point.x = sdlMouseButtonEvent.x;
    point.y = sdlMouseButtonEvent.y;

    return point;
}