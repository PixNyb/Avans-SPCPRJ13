#include "input_manager.hpp"

InputManager::InputManager() : sdlInputHandler(std::make_unique<SDL2InputHandler>()) {}

void InputManager::update(std::vector<SDL_Event>& events) {
    sdlInputHandler->PollEvents(events);

    for(const auto& keyEvent : sdlInputHandler->getPolledKeyEvents()) {
        for (const auto& listener : keyListeners) {
            switch(keyEvent->getType()) {
                case SDL_KEYDOWN:
                    listener->OnKeyPressed(keyEvent, actionTypeKeyBinds);
                    break;
                case SDL_KEYUP:
                    listener->OnKeyReleased();
                    break;
                default:
                    break;
            }
        }
    }

    for(const auto& mouseEvent : sdlInputHandler->getPolledMouseEvents()) {
        for (const auto& listener : mouseListeners) {
            switch(mouseEvent->getType()) {
                case SDL_MOUSEMOTION:
                    listener->OnMouseMoved(mouseEvent);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    listener->OnMousePressed(mouseEvent, actionTypeKeyBinds);
                    break;
                case SDL_MOUSEBUTTONUP:
                    listener->OnMouseReleased();
                    break;
                default:
                    break;
            }
        }
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

const std::unique_ptr<IInputHandler>& InputManager::getSDLInputHandler() const {
    return sdlInputHandler;
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