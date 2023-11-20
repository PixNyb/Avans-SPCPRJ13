/**
 * @file mouse_event.hpp
 * @author Martijn Vermeer
 * @brief This file contains the mouse event class definition.
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_MOUSE_EVENT_HPP
#define DEFUNBOBENGINE_MOUSE_EVENT_HPP

#include "event.hpp"
#include "SDL.h"

class MouseEvent : public Event {
public:
    explicit MouseEvent(SDL_Event& sdlEvent);

    [[nodiscard]] Uint8 getMouseButton() const;

    [[nodiscard]] SDL_Point getMousePos() const;
private:
    SDL_MouseButtonEvent sdlMouseButtonEvent;
};

#endif //DEFUNBOBENGINE_MOUSE_EVENT_HPP
