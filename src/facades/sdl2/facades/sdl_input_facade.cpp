/**
 * @file sdl_input_facade.cpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the SDLInputFacade class implementation.
 * @version 0.1
 * @date 2023-11-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "sdl_input_facade.hpp"
#include "point.hpp"
#include "sdl_input.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>

SDLInputFacade::SDLInputFacade() : input(std::make_unique<SDLInput>()) {}

void SDLInputFacade::Update() { input->Update(); }

bool SDLInputFacade::AnyKey() const { return input->IsAnyKeyPressed(); }

bool SDLInputFacade::AnyKeyDown() const { return input->IsAnyKeyDown(); }

bool SDLInputFacade::AnyKeyUp() const { return input->IsAnyKeyUp(); }

Point SDLInputFacade::GetMousePosition() const
{
    return Point(input->GetMousePosition().x, input->GetMousePosition().y);
}

double SDLInputFacade::GetAxis() const { return 0.0; }

bool SDLInputFacade::GetKey(KeyCode key) const
{
    return input->IsKeyPressed(static_cast<SDL_Scancode>(key));
}

bool SDLInputFacade::GetKeyDown(KeyCode key) const
{
    return input->IsKeyDown(static_cast<SDL_Scancode>(key));
}

bool SDLInputFacade::GetKeyUp(KeyCode key) const
{
    return input->IsKeyUp(static_cast<SDL_Scancode>(key));
}

bool SDLInputFacade::GetMouseButton(MouseButton which) const
{
    return input->IsMouseButtonPressed(static_cast<Uint8>(which));
}

bool SDLInputFacade::GetMouseButtonDown(MouseButton which) const
{
    return input->IsMouseButtonDown(static_cast<Uint8>(which));
}

bool SDLInputFacade::GetMouseButtonUp(MouseButton which) const
{
    return input->IsMouseButtonUp(static_cast<Uint8>(which));
}

void SDLInputFacade::RegisterAction(const std::string &action)
{
    if (keyActionMap.find(action) != keyActionMap.end() ||
        mouseActionMap.find(action) != mouseActionMap.end())
        throw std::runtime_error("Action already registered");

    keyActionMap[action] = std::vector<KeyCode>();
    mouseActionMap[action] = std::vector<MouseButton>();
}

void SDLInputFacade::UnregisterAction(const std::string &action)
{
    if (keyActionMap.find(action) == keyActionMap.end() &&
        mouseActionMap.find(action) == mouseActionMap.end())
        throw std::runtime_error("Action not registered");

    keyActionMap.erase(action);
    mouseActionMap.erase(action);
}

std::vector<KeyCode> SDLInputFacade::GetKeysForAction(const std::string &action) const
{
    if (keyActionMap.find(action) == keyActionMap.end())
        throw std::runtime_error("Action not registered");

    return keyActionMap.at(action);
}

std::vector<MouseButton> SDLInputFacade::GetMouseButtonsForAction(const std::string &action) const
{
    if (mouseActionMap.find(action) == mouseActionMap.end())
        throw std::runtime_error("Action not registered");

    return mouseActionMap.at(action);
}

std::vector<std::string> SDLInputFacade::GetActions() const
{
    std::vector<std::string> actions;

    for (auto it = keyActionMap.begin(); it != keyActionMap.end(); ++it)
        actions.push_back(it->first);

    for (auto it = mouseActionMap.begin(); it != mouseActionMap.end(); ++it)
        actions.push_back(it->first);

    std::sort(actions.begin(), actions.end());
    actions.erase(std::unique(actions.begin(), actions.end()), actions.end());

    return actions;
}

void SDLInputFacade::BindKey(KeyCode key, const std::string &action)
{
    if (keyActionMap.find(action) == keyActionMap.end())
        throw std::runtime_error("Action not registered");

    for (auto it = keyActionMap.begin(); it != keyActionMap.end(); ++it)
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            if (*it2 == key)
                throw std::runtime_error("Key already bound to another action");

    keyActionMap.at(action).push_back(key);
}

void SDLInputFacade::BindMouseButton(MouseButton button, const std::string &action)
{
    if (mouseActionMap.find(action) == mouseActionMap.end())
        throw std::runtime_error("Action not registered");

    for (auto it = mouseActionMap.begin(); it != mouseActionMap.end(); ++it)
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            if (*it2 == button)
                throw std::runtime_error("Mouse button already bound to another action");

    mouseActionMap.at(action).push_back(button);
}

void SDLInputFacade::UnbindKey(KeyCode key)
{
    for (auto it = keyActionMap.begin(); it != keyActionMap.end(); ++it)
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            if (*it2 == key)
            {
                it->second.erase(it2);
                return;
            }

    throw std::runtime_error("Key not bound to any action");
}

void SDLInputFacade::UnbindMouseButton(MouseButton button)
{
    for (auto it = mouseActionMap.begin(); it != mouseActionMap.end(); ++it)
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            if (*it2 == button)
            {
                it->second.erase(it2);
                return;
            }

    throw std::runtime_error("Mouse button not bound to any action");
}

std::string SDLInputFacade::GetActionForKey(KeyCode key) const
{
    for (auto it = keyActionMap.begin(); it != keyActionMap.end(); ++it)
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            if (*it2 == key)
                return it->first;

    throw std::runtime_error("Key not bound to any action");
}

std::string SDLInputFacade::GetActionForMouseButton(MouseButton button) const
{
    for (auto it = mouseActionMap.begin(); it != mouseActionMap.end(); ++it)
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            if (*it2 == button)
                return it->first;

    throw std::runtime_error("Mouse button not bound to any action");
}

// TODO: See if this can be optimised:
bool SDLInputFacade::AnyAction() const
{
    for (auto it = keyActionMap.begin(); it != keyActionMap.end(); ++it)
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            if (GetKey(*it2))
                return true;

    for (auto it = mouseActionMap.begin(); it != mouseActionMap.end(); ++it)
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            if (GetMouseButton(*it2))
                return true;

    return false;
}

bool SDLInputFacade::AnyActionDown() const
{
    for (auto it = keyActionMap.begin(); it != keyActionMap.end(); ++it)
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            if (GetKeyDown(*it2))
                return true;

    for (auto it = mouseActionMap.begin(); it != mouseActionMap.end(); ++it)
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            if (GetMouseButtonDown(*it2))
                return true;

    return false;
}

bool SDLInputFacade::AnyActionUp() const
{
    for (auto it = keyActionMap.begin(); it != keyActionMap.end(); ++it)
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            if (GetKeyUp(*it2))
                return true;

    for (auto it = mouseActionMap.begin(); it != mouseActionMap.end(); ++it)
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            if (GetMouseButtonUp(*it2))
                return true;

    return false;
}

bool SDLInputFacade::GetAction(const std::string &action) const
{
    if (keyActionMap.find(action) == keyActionMap.end() &&
        mouseActionMap.find(action) == mouseActionMap.end())
        throw std::runtime_error("Action not registered");

    for (auto it = keyActionMap.at(action).begin(); it != keyActionMap.at(action).end(); ++it)
        if (GetKey(*it))
            return true;

    for (auto it = mouseActionMap.at(action).begin(); it != mouseActionMap.at(action).end(); ++it)
        if (GetMouseButton(*it))
            return true;

    return false;
}

bool SDLInputFacade::GetActionDown(const std::string &action) const
{
    if (keyActionMap.find(action) == keyActionMap.end() &&
        mouseActionMap.find(action) == mouseActionMap.end())
        throw std::runtime_error("Action not registered");

    for (auto it = keyActionMap.at(action).begin(); it != keyActionMap.at(action).end(); ++it)
        if (GetKeyDown(*it))
            return true;

    for (auto it = mouseActionMap.at(action).begin(); it != mouseActionMap.at(action).end(); ++it)
        if (GetMouseButtonDown(*it))
            return true;

    return false;
}

bool SDLInputFacade::GetActionUp(const std::string &action) const
{
    if (keyActionMap.find(action) == keyActionMap.end() &&
        mouseActionMap.find(action) == mouseActionMap.end())
        throw std::runtime_error("Action not registered");

    for (auto it = keyActionMap.at(action).begin(); it != keyActionMap.at(action).end(); ++it)
        if (GetKeyUp(*it))
            return true;

    for (auto it = mouseActionMap.at(action).begin(); it != mouseActionMap.at(action).end(); ++it)
        if (GetMouseButtonUp(*it))
            return true;

    return false;
}
