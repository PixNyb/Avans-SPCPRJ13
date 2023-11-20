/**
 * @file action_type.cpp
 * @author Martijn Vermeer
 * @brief This file contains the key event class implementation.
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "key_event.hpp"

KeyEvent::KeyEvent(KeyCode& keyCode, bool isKeyDown) : Event(keyCode) {
    this->isKeyDown = isKeyDown;
}

bool KeyEvent::GetIsKeyDown() const {
    return isKeyDown;
}
