/**
 * @file input_manager.cpp
 * @author Martijn Vermeer
 * @brief This file contains the input manager class implementation.
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "input_manager.hpp"

InputManager::InputManager() : sdlInputHandler(std::make_unique<SDL2InputHandler>()) {}

void InputManager::Update() {
    sdlInputHandler->PollEvents();
    std::shared_ptr<KeyEvent> event = sdlInputHandler->GetPolledKeyEvents().back();

    if(keyEvent->GetIsKeyDown()) {
        listener->OnKeyPressed();
    }
    else {
        listener->OnKeyReleased();
    }

//    for(const auto& keyEvent : sdlInputHandler->GetPolledKeyEvents()) {
//        for (const auto& listener : keyListeners) {
//            if(keyEvent->GetIsKeyDown()) {
//                listener->OnKeyPressed();
//            }
//            else {
//                listener->OnKeyReleased();
//            }
//        }
//    }

//    for(const auto& mouseEvent : sdlInputHandler->getPolledMouseEvents()) {
//        for (const auto& listener : mouseListeners) {
//            switch(mouseEvent->getType()) {
//                case :
//                    listener->OnMouseMoved();
//                    break;
//                case :
//                    listener->OnMousePressed();
//                    break;
//                case :
//                    listener->OnMouseReleased();
//                    break;
//                default:
//                    break;
//            }
//        }
//    }
}

void InputManager::RegisterMouse(std::unique_ptr<IMouseListener> mouseListener) {
    mouseListeners.push_back(std::move(mouseListener));
}

void InputManager::RegisterKey(std::unique_ptr<IKeyListener> keyListener) {
    keyListeners.push_back(std::move(keyListener));
}

bool InputManager::ActionPressed(const ActionType& actionType) const {
    return std::find(actionsPressed.begin(), actionsPressed.end(), actionType) != actionsPressed.end();
}

bool InputManager::ActionReleased(const ActionType& actionType) const {
    return std::find(actionsReleased.begin(), actionsReleased.end(), actionType) != actionsReleased.end();
}

const std::unique_ptr<IInputHandler>& InputManager::GetSDLInputHandler() const {
    return sdlInputHandler;
}

void InputManager::Bind(const Event& key, const ActionType& actionType) {
    auto it = actionTypeKeyBinds.find(key);

    if(it == actionTypeKeyBinds.end()) {
        actionTypeKeyBinds[key].push_back(actionType);
    }
    else {
        actionTypeKeyBinds.emplace(key, std::vector<ActionType>{actionType});
    }
}