#include "input_manager.hpp"

void InputManager::update() {
    std::vector<Event> events;

    sdlInputHandler = std::make_unique<SDL2InputHandler>();
    sdlInputHandler->PollEvents(events);

    // Update key listeners
    for (const auto& listener : keyListeners) {
        listener->OnKeyReleased();
        listener->OnKeyPressed(sdlInputHandler->getLastPolledKeyEvent(), actionTypeKeyBinds);
    }

    for (const auto& listener : mouseListeners) {
        listener->OnMouseMoved();
        listener->OnMousePressed();
        listener->OnMouseClicked(sdlInputHandler->getLastPolledMouseEvent(), actionTypeKeyBinds);
        listener->OnMouseReleased();
    }
}

void InputManager::registerMouse(std::unique_ptr<IMouseListener> mouseListener) {
    mouseListeners.push_back(std::move(mouseListener));
}

void InputManager::registerKey(std::unique_ptr<IKeyListener> keyListener) {
    keyListeners.push_back(std::move(keyListener));
}

bool InputManager::actionPressed(const ActionType& actionType) const {
    return std::find(actionsPressed.begin(), actionsPressed.end(), actionType) != actionsPressed.end();
}

bool InputManager::actionReleased(const ActionType& actionType) const {
    return std::find(actionsReleased.begin(), actionsReleased.end(), actionType) != actionsReleased.end();
}

void InputManager::bind(const Event& key, const ActionType& actionType) {
    auto it = actionTypeKeyBinds.find(key);

    if(it == actionTypeKeyBinds.end()) {
        actionTypeKeyBinds[key].push_back(actionType);
    }
    else {
        actionTypeKeyBinds.emplace(key, std::vector<ActionType>{actionType});
    }
}