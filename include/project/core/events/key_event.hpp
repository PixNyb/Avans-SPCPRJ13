/**
 * @file key_event.hpp
 * @author Martijn Vermeer
 * @brief This file contains the key event class definition.
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

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
