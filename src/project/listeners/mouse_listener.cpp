#include "listeners/mouse_listener.hpp"

void MouseListener::OnMouseMoved(const std::shared_ptr<MouseEvent>& event) {
    // Get latest mouse state.
    SDL_PumpEvents();

    int x = event->getMousePos().x;
    int y = event->getMousePos().y;

    SDL_GetMouseState(&x, &y);
}

void MouseListener::OnMouseClicked() {

}

void MouseListener::OnMousePressed(const std::shared_ptr<MouseEvent>& event, const std::map<Event, std::vector<ActionType>>& actionTypeKeyBinds) {
    auto it = actionTypeKeyBinds.find(*event);

    if (it != actionTypeKeyBinds.end()) {
        for (const ActionType& actionType : it->second) {
            const ActionType enumOfType = ActionType::convertStringToEnum(actionType.getName());

            if (enumOfType == ActionType::JUMP) {
            } else if (enumOfType == ActionType::GODOWN) {
            } else if (enumOfType == ActionType::GOUP) {
            } else if (enumOfType == ActionType::GOLEFT) {
            } else if (enumOfType == ActionType::GORIGHT) {
            } else if (enumOfType == ActionType::PAUSE) {
            } else {
            }
        }
    }
}

void MouseListener::OnMouseReleased() {

}