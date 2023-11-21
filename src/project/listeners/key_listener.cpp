/**
 * @file key_listener.cpp
 * @author Martijn Vermeer
 * @brief This file contains the key listener class implementation.
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "key_listener.hpp"

KeyListener::KeyListener(const KeyEvent& keyEvent) : keyEvent(keyEvent) {}

void KeyListener::OnKeyPressed() {
    switch(keyEvent.GetKeyCode()) {
    case KeyCode::UP_ARROW:
        break;
    case KeyCode::DOWN_ARROW:
        break;
    case KeyCode::LEFT_ARROW:
        break;
    case KeyCode::RIGHT_ARROW:
        break;
    default:
        break;
    }
}

void KeyListener::OnKeyReleased() {

}