#include "listeners/key_listener.hpp"

void KeyListener::OnKeyPressed(const std::shared_ptr<KeyEvent>& event, const std::map<Event, std::vector<ActionType>>& actionTypeKeyBinds) {
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

void KeyListener::OnKeyReleased() {

}