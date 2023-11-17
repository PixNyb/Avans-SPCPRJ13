#include "listeners/mouse_listener.hpp"

void MouseListener::OnMouseMoved() {
    // Get latest mouse state.
    SDL_PumpEvents();

    int x;
    int y;

    SDL_GetMouseState(&x, &y);
}

void MouseListener::OnMouseClicked(const std::shared_ptr<MouseEvent>& event, const std::map<Event, std::vector<ActionType>>& actionTypeKeyBinds) {
    if (event->getType() & SDL_BUTTON(SDL_BUTTON_LEFT)) {

    }
}

void MouseListener::OnMousePressed() {

}

void MouseListener::OnMouseReleased() {

}