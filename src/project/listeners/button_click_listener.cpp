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

ButtonClickListener::ButtonClickListener(const Button &button)
    : button(button), inputFacade(*Engine::GetInstance()->Get<IInputFacade>())
{
}

void ButtonClickListener::OnMouseMoved() {}

void ButtonClickListener::OnMouseClicked()
{
    auto mousePos = inputFacade.GetMousePosition();

    if (mousePos.x >= button.GetTransform().position.x &&
        mousePos.x <= button.GetTransform().position.x + button.GetWidth() &&
        mousePos.y >= button.GetTransform().position.y &&
        mousePos.y <= button.GetTransform().position.y + button.GetHeight())
    {
        button.onClick();
    }
}

void ButtonClickListener::OnMousePressed() {}

void ButtonClickListener::OnMouseReleased() {}

void ButtonClickListener::Attach() { inputFacade.AddMouseListener(shared_from_this()); }

void ButtonClickListener::Detach() { inputFacade.RemoveMouseListener(shared_from_this()); }
