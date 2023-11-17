#ifndef DEFUNBOBENGINE_KEY_EVENT_HPP
#define DEFUNBOBENGINE_KEY_EVENT_HPP

#include "event.hpp"
#include <SDL.h>

class KeyEvent : public Event {
public:
    explicit KeyEvent(SDL_Event& sdlEvent);

    [[nodiscard]] SDL_Scancode getKeyCode() const;
private:
    SDL_KeyboardEvent sdlKeyboardEvent;
};

#endif //DEFUNBOBENGINE_KEY_EVENT_HPP
