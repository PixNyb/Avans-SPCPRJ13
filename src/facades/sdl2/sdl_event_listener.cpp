/**
 * @file sdl_input_handler.cpp
 * @author Martijn Vermeer
 * @brief This file contains the sdl input handler class implementation.
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "sdl_event_listener.hpp"

void SDLEventListener::PollEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        auto keyCode = static_cast<KeyCode>(event.key.keysym.scancode);

        switch (event.type)
        {
        case SDL_KEYUP:
            polledKeyEvents.emplace_back(std::make_shared<KeyEvent>(keyCode, false));
            break;

        case SDL_KEYDOWN:
            polledKeyEvents.emplace_back(std::make_shared<KeyEvent>(keyCode, true));
            break;

        case SDL_MOUSEMOTION:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
            polledMouseEvents.emplace_back(std::make_shared<MouseEvent>(keyCode));
            break;

        default:
            break;
        }
    };
}

std::vector<std::shared_ptr<KeyEvent>> SDLEventListener::GetPolledKeyEvents() const
{
    return polledKeyEvents;
}

std::vector<std::shared_ptr<MouseEvent>> SDLEventListener::GetPolledMouseEvents() const
{
    return polledMouseEvents;
}