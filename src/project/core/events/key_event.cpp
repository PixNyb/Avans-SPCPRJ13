#include "key_event.hpp"

KeyEvent::KeyEvent(SDL_Event& sdlEvent) : Event(sdlEvent.type), sdlKeyboardEvent{} {
    sdlKeyboardEvent.keysym.scancode = sdlEvent.key.keysym.scancode;
}

SDL_Scancode KeyEvent::getKeyCode() const {
    return sdlKeyboardEvent.keysym.scancode;
}