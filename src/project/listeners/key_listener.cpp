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
        std::cout << "up arrow updated" << std::endl;
        break;
    case KeyCode::DOWN_ARROW:
        std::cout << "down arrow updated" << std::endl;
        break;
    case KeyCode::LEFT_ARROW:
        std::cout << "left arrow updated" << std::endl;
        break;
    case KeyCode::RIGHT_ARROW:
        std::cout << "right arrow updated" << std::endl;
        break;
    default:
        break;
    }
}

void KeyListener::OnKeyReleased() {

}