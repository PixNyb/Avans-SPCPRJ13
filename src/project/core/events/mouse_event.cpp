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

MouseEvent::MouseEvent(KeyCode keyCode, int x, int y, EventType eventType) : Event(keyCode, eventType)
{
    this->x = x;
    this->y = y;
}

int MouseEvent::GetXPos() const { return x; }
int MouseEvent::GetYPos() const { return y; }