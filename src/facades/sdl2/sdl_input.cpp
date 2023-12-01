/**
 * @file sdl_input.cpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the SDLInput class implementation.
 * @version 0.1
 * @date 2023-11-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "sdl_input.hpp"

SDLInput::SDLInput()
{
    for (int i = 0; i < SDL_NUM_SCANCODES; ++i)
        keyState[static_cast<SDL_Scancode>(i)] = false;

    for (int i = 0; i < 6; ++i)
        mouseButtonState[static_cast<Uint8>(i)] = false;

    mousePosition = {0, 0};
}

void SDLInput::Update()
{
    frameKeyState.clear();
    frameMouseButtonState.clear();

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            keyState[event.key.keysym.scancode] = true;
            frameKeyState[event.key.keysym.scancode] = true;
            break;
        case SDL_KEYUP:
            keyState[event.key.keysym.scancode] = false;
            frameKeyState[event.key.keysym.scancode] = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            mouseButtonState[event.button.button] = true;
            frameMouseButtonState[event.button.button] = true;
            break;
        case SDL_MOUSEBUTTONUP:
            mouseButtonState[event.button.button] = false;
            frameMouseButtonState[event.button.button] = false;
            break;
        case SDL_MOUSEMOTION:
            mousePosition.x = event.motion.x;
            mousePosition.y = event.motion.y;
            break;
        case SDL_QUIT:
            shouldQuit = true;
            break;
        }
    }
}

bool SDLInput::IsKeyPressed(SDL_Scancode key) const
{
    auto it = keyState.find(key);

    if (it != keyState.end())
        return it->second;

    return false;
}

bool SDLInput::IsKeyDown(SDL_Scancode key) const
{
    auto it = frameKeyState.find(key);

    if (it != frameKeyState.end())
        return it->second;

    return false;
}

bool SDLInput::IsKeyUp(SDL_Scancode key) const
{
    auto it = frameKeyState.find(key);

    if (it != frameKeyState.end())
        return !it->second;

    return false;
}

bool SDLInput::IsAnyKeyPressed() const
{
    for (auto it = keyState.begin(); it != keyState.end(); ++it)
        if (it->second)
            return true;

    return false;
}

bool SDLInput::IsAnyKeyDown() const
{
    for (auto it = frameKeyState.begin(); it != frameKeyState.end(); ++it)
        if (it->second)
            return true;

    return false;
}

bool SDLInput::IsAnyKeyUp() const
{
    for (auto it = frameKeyState.begin(); it != frameKeyState.end(); ++it)
        if (!it->second)
            return true;

    return false;
}

bool SDLInput::IsMouseButtonPressed(Uint8 button) const
{
    auto it = mouseButtonState.find(button);

    if (it != mouseButtonState.end())
        return it->second;

    return false;
}

bool SDLInput::IsAnyMouseButtonPressed() const
{
    for (auto it = mouseButtonState.begin(); it != mouseButtonState.end(); ++it)
        if (it->second)
            return true;

    return false;
}

bool SDLInput::IsMouseButtonDown(Uint8 button) const
{
    auto it = frameMouseButtonState.find(button);

    if (it != frameMouseButtonState.end())
        return it->second;

    return false;
}

bool SDLInput::IsMouseButtonUp(Uint8 button) const
{
    auto it = frameMouseButtonState.find(button);

    if (it != frameMouseButtonState.end())
        return !it->second;
    else
        return false;
}

bool SDLInput::IsAnyMouseButtonDown() const
{
    for (auto it = frameMouseButtonState.begin(); it != frameMouseButtonState.end(); ++it)
        if (it->second)
            return true;

    return false;
}

SDL_Point SDLInput::GetMousePosition() const { return mousePosition; }

bool SDLInput::ShouldQuit() const { return shouldQuit; }