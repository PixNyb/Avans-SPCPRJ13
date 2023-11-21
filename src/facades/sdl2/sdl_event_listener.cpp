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

        // Get latest mouse state.
        SDL_PumpEvents();

        int x;
        int y;

        SDL_GetMouseState(&x, &y);

        switch (event.type)
        {
        case SDL_KEYDOWN:
            polledKeyEvents.emplace_back(std::make_shared<KeyEvent>(keyCode, EventType::KEYPRESSED));
            break;

        case SDL_KEYUP:
            polledKeyEvents.emplace_back(std::make_shared<KeyEvent>(keyCode, EventType::KEYRELEASED));
            break;

        case SDL_MOUSEMOTION:
            polledMouseEvents.emplace_back(std::make_shared<MouseEvent>(keyCode, x, y, EventType::MOUSEMOVED));
            break;

        case SDL_MOUSEBUTTONDOWN:
            polledMouseEvents.emplace_back(std::make_shared<MouseEvent>(keyCode, x, y, EventType::MOUSEPRESSED));
            break;

        case SDL_MOUSEBUTTONUP:
            polledMouseEvents.emplace_back(std::make_shared<MouseEvent>(keyCode, x, y, EventType::MOUSERELEASED));
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