//
// Created by Robin on 30-10-2023.
//

#include "button.hpp"

Button::Button() : interactable(true), onClick(nullptr)
{
    // Default constructor initialization
}

void Button::SetInteractable(bool state)
{
    interactable = state;
}

bool Button::IsInteractable() const
{
    return interactable;
}

void Button::SetOnClick(void (*callback)())
{
    onClick = callback;
}

void Button::TriggerClick()
{
    if (interactable && onClick)
    {
        onClick(); // Execute the callback when the button is clicked
    }
}
