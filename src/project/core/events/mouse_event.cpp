#include "mouse_event.hpp"

MouseEvent::MouseEvent(SDL_Event& sdlEvent) : Event(sdlEvent.type) {
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