/**
 * @file button_factory.cpp
 * @author "Martijn Vermeer"
 * @brief Implements the ButtonFactory class for creating and initializing buttons.
 * @version 0.1
 * @date 24/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "button_click_listener.hpp"
#include "iostream"

ButtonClickListener::ButtonClickListener(const std::shared_ptr<Button> &button)
    : button(button), mousePos(0, 0)
{
}

void ButtonClickListener::SetMousePosition(const Point &mousePos) { this->mousePos = mousePos; }

void ButtonClickListener::OnMouseMoved() {}

void ButtonClickListener::OnMouseClicked()
{
    if (mousePos.x >= button->GetTransform().position.x &&
        mousePos.x <= button->GetTransform().position.x + button->GetWidth() &&
        mousePos.y >= button->GetTransform().position.y &&
        mousePos.y <= button->GetTransform().position.y + button->GetHeight())
    {
        std::cout << "Button: " << button->GetTag() << " Pressed" << std::endl;
    }
}

void ButtonClickListener::OnMousePressed() {}

void ButtonClickListener::OnMouseReleased() {}