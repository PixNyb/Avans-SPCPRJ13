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

SDLInputFacade::SDLInputFacade() : eventListener(std::make_unique<SDLEventListener>()) {}

void SDLInputFacade::Update()
{
    eventListener->PollEvents();

    UpdateKeyEvents();
    UpdateMouseEvents();
}

void SDLInputFacade::UpdateKeyEvents()
{
    for (const auto &keyEvent : eventListener->GetPolledKeyEvents())
    {
        if (keyEvent->IsProcessed())
        {
            continue;
        }

        keyEvent->MarkProcessed();

        for (const auto &listener : keyListeners)
        {
            if (listener->GetKeyEvent().GetKeyCode() == keyEvent->GetKeyCode())
            {
                switch (keyEvent->GetEventType())
                {
                case EventType::KEYPRESSED:
                    listener->OnKeyPressed();
                    break;
                case EventType::KEYRELEASED:
                    listener->OnKeyReleased();
                    break;
                default:
                    break;
                }
            }
        }
    }
}

void SDLInputFacade::UpdateMouseEvents()
{
    for (const auto &mouseEvent : eventListener->GetPolledMouseEvents())
    {
        if (mouseEvent->IsProcessed())
        {
            continue;
        }

        mouseEvent->MarkProcessed();

        for (const auto &listener : mouseListeners)
        {
            if (listener->GetMouseEvent().GetKeyCode() == mouseEvent->GetKeyCode())
            {
                switch (mouseEvent->GetEventType())
                {
                case EventType::MOUSEMOVED:
                    listener->OnMouseMoved();
                    break;
                case EventType::MOUSEPRESSED:
                    listener->OnMousePressed();
                    break;
                case EventType::MOUSERELEASED:
                    listener->OnMouseReleased();
                    break;
                case EventType::MOUSECLICKED:
                    listener->OnMouseClicked();
                    break;
                default:
                    break;
                }
            }
        }
    }
}

void SDLInputFacade::RegisterMouseListener(std::unique_ptr<MouseListener> mouseListener)
{
    mouseListeners.push_back(std::move(mouseListener));
}

void SDLInputFacade::RegisterKeyListener(std::unique_ptr<KeyListener> keyListener)
{
    keyListeners.push_back(std::move(keyListener));
}

void SDLInputFacade::Bind(const Event &event, const ActionType &actionType)
{
    KeyEvent *keyEvent = const_cast<KeyEvent *>(dynamic_cast<const KeyEvent *>(&event));
    MouseEvent *mouseEvent = const_cast<MouseEvent *>(dynamic_cast<const MouseEvent *>(&event));

    if (keyEvent != nullptr)
        RegisterKeyListener(std::make_unique<KeyListener>(dynamic_cast<const KeyEvent &>(event)));
    else if (mouseEvent != nullptr)
        RegisterMouseListener(
            std::make_unique<MouseListener>(dynamic_cast<const MouseEvent &>(event)));
    else
        throw std::invalid_argument("Event type is not supported.");
}