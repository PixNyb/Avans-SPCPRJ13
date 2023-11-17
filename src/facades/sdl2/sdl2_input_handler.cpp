#include "sdl2_input_handler.hpp"

void SDL2InputHandler::PollEvents(std::vector<Event>& events) {
    SDL_Event sdlEvent;

    while (SDL_PollEvent(&sdlEvent)) {
        if (sdlEvent.type == SDL_KEYDOWN || sdlEvent.type == SDL_KEYUP) {
            lastPolledKeyEvent = std::make_shared<KeyEvent>(sdlEvent);
            events.push_back(*lastPolledKeyEvent);
        }
        else if (sdlEvent.type == SDL_MOUSEBUTTONDOWN || sdlEvent.type == SDL_MOUSEBUTTONUP || sdlEvent.type == SDL_MOUSEMOTION) {
            lastPolledMouseEvent = std::make_shared<MouseEvent>(sdlEvent);
            events.push_back(*lastPolledMouseEvent);
        }
    }
}

std::shared_ptr<KeyEvent> SDL2InputHandler::getLastPolledKeyEvent() const {
    return lastPolledKeyEvent;
}

std::shared_ptr<MouseEvent> SDL2InputHandler::getLastPolledMouseEvent() const {
    return lastPolledMouseEvent;
}