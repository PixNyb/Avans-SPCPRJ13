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

#include "mouse_listener.hpp"

MouseListener::MouseListener(const MouseEvent &mouseEvent) : mouseEvent(mouseEvent) {}

void MouseListener::OnMouseMoved() {
    mouseEvent.GetXPos();
    mouseEvent.GetYPos();
}

void MouseListener::OnMouseClicked() {

}

void MouseListener::OnMousePressed() {
    switch(mouseEvent.GetKeyCode())
    {
    case KeyCode::MOUSE_LEFT:
        break;
    case KeyCode::MOUSE_RIGHT:
        break;
    case KeyCode::MOUSE_MIDDLE:
        break;
    default:
        break;
    }
}

void MouseListener::OnMouseReleased() {

}