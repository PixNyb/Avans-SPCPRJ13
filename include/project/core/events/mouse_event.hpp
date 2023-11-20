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

class MouseEvent : public Event {
public:
    explicit MouseEvent(KeyCode& keyCode);
private:
};

#endif //DEFUNBOBENGINE_MOUSE_EVENT_HPP
