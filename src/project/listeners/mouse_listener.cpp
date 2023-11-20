/**
 * @file mouse_listener.cpp
 * @author Martijn Vermeer
 * @brief This file contains the mouse listener class implementation.
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "listeners/mouse_listener.hpp"

void MouseListener::OnMouseMoved() {
    // Get latest mouse state.
//    SDL_PumpEvents();
//
//    int x = event->getMousePos().x;
//    int y = event->getMousePos().y;
//
//    SDL_GetMouseState(&x, &y);
}

void MouseListener::OnMouseClicked() {

}

void MouseListener::OnMousePressed() {
//    auto it = actionTypeKeyBinds.find(*event);
//
//    if (it != actionTypeKeyBinds.end()) {
//        for (const ActionType& actionType : it->second) {
//            const ActionType enumOfType = ActionType::convertStringToEnum(actionType.getName());
//        }
//    }
}

void MouseListener::OnMouseReleased() {

}