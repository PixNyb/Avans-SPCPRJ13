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

KeyListener::KeyListener(KeyCode keyCode, bool isKeyDown) : keyEvent(keyCode, isKeyDown) {}

void KeyListener::SetKeyEvent(const KeyEvent& keyEvent) {
    this->keyEvent = keyEvent;
}

void KeyListener::OnKeyPressed() {

    if(keyEvent.GetKeyCode() == KeyCode::UP_ARROW) {
        std::cout << "Up arrow was pressed: " << std::endl;
    }

//    auto it = actionTypeKeyBinds.find(*event);
//
//    if (it != actionTypeKeyBinds.end()) {
//        for (const ActionType& actionType : it->second) {
//            const ActionType enumOfType = ActionType::convertStringToEnum(actionType.getName());
//
//            if (enumOfType == ActionType::JUMP) {
//            } else if (enumOfType == ActionType::GODOWN) {
//            } else if (enumOfType == ActionType::GOUP) {
//            } else if (enumOfType == ActionType::GOLEFT) {
//            } else if (enumOfType == ActionType::GORIGHT) {
//            } else if (enumOfType == ActionType::PAUSE) {
//            } else {
//            }
//        }
//    }

}

void KeyListener::OnKeyReleased() {

}