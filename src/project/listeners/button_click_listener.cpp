#include "button_click_listener.hpp"
#include "iostream"

ButtonClickListener::ButtonClickListener(const std::shared_ptr<Button> &button) : button(button), mousePos(0, 0) {}

void ButtonClickListener::SetMousePosition(const Point& mousePos)
{
    this->mousePos = mousePos;
}

void ButtonClickListener::OnMouseMoved() {
}

void ButtonClickListener::OnMouseClicked() {
    if(mousePos.x >= button->GetTransform().position.x && mousePos.x <= button->GetTransform().position.x + button->GetWidth() && mousePos.y >= button->GetTransform().position.y && mousePos.y <= button->GetTransform().position.y + button->GetHeight()) {
        button->Click();
    }
}

void ButtonClickListener::OnMousePressed() {
}

void ButtonClickListener::OnMouseReleased() {
}