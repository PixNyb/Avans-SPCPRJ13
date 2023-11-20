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

#include "input_facade.hpp"
#include "key_event.hpp"
#include "mouse_event.hpp"
#include <stdexcept>

SDLInputFacade::SDLInputFacade() : eventListener(std::make_unique<SDLEventListener>()) {}

void SDLInputFacade::Update()
{
    eventListener->PollEvents();

    //    std::shared_ptr<KeyEvent> event = sdlInputHandler->GetPolledKeyEvents().back();
    //    std::unique_ptr<IKeyListener> keyListener = std::make_unique<KeyListener>();
    //
    //    if(event->GetIsKeyDown()) {
    //        keyListener->OnKeyPressed();
    //    }
    //    else {
    //        keyListener->OnKeyReleased();
    //    }

    for (const auto &keyEvent : eventListener->GetPolledKeyEvents())
    {
        if (keyEvent->IsProcessed())
        {
            continue;
        }

        keyEvent->MarkProcessed();

        for (const auto &listener : keyListeners)
        {
            if (keyEvent->GetIsKeyDown())
            {
                listener->OnKeyPressed();
            }
            else
            {
                listener->OnKeyReleased();
            }
        }
    }

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

void SDLInputFacade::RegisterMouseListener(std::unique_ptr<IMouseListener> mouseListener)
{
    mouseListeners.push_back(std::move(mouseListener));
}

void SDLInputFacade::RegisterKeyListener(std::unique_ptr<IKeyListener> keyListener)
{
    keyListeners.push_back(std::move(keyListener));
}

bool SDLInputFacade::ActionPressed(const ActionType &actionType) const
{
    return std::find(actionsPressed.begin(), actionsPressed.end(), actionType) !=
           actionsPressed.end();
}

bool SDLInputFacade::ActionReleased(const ActionType &actionType) const
{
    return std::find(actionsReleased.begin(), actionsReleased.end(), actionType) !=
           actionsReleased.end();
}

void SDLInputFacade::Bind(const Event &event, const ActionType &actionType)
{
    // KeyEvent *keyEvent = dynamic_cast<KeyEvent *>(&event);
    // MouseEvent *mouseEvent = dynamic_cast<MouseEvent *>(&event);

    // if (keyEvent != nullptr)
    //     RegisterKeyListener(
    //         std::make_unique<KeyListener>(keyEvent->GetKeyCode(), keyEvent->GetIsKeyDown()));
    // else if (mouseEvent != nullptr)
    //     // RegisterMouseListener(std::make_unique<MouseListener>(mouseEvent->GetKeyCode())
    //     std::logic_error("Mouse events are not yet supported.");
    // else
    //     throw std::invalid_argument("Event type is not supported.");

    RegisterKeyListener(std::make_unique<KeyListener>(event.GetKeyCode(), true));

    // TODO: Check this?
    auto it = actionTypeKeyBinds.find(event);
    if (it == actionTypeKeyBinds.end())
        actionTypeKeyBinds[event].push_back(actionType);
    else
        actionTypeKeyBinds.emplace(event, std::vector<ActionType>{actionType});
}