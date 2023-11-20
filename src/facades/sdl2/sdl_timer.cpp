/**
 * @file sdl_timer.cpp
 * @author Robin Pijnappels
 * @brief This file contains the SDLTimer class implementation.
 * @version 0.1
 * @date 2023-11-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "sdl_timer.hpp"

Timer::Timer() : startTicks(0), pausedTicks(0), paused(false), started(false) {}

void Timer::Start()
{
    started = true;
    paused = false;
    startTicks = SDL_GetTicks();
    pausedTicks = 0;
}

void Timer::Stop()
{
    started = false;
    paused = false;
    startTicks = 0;
    pausedTicks = 0;
}

void Timer::Pause()
{
    // Only pause if the timer is running and isn't already paused
    if (started && !paused)
    {
        paused = true;
        pausedTicks = SDL_GetTicks() - startTicks;
        startTicks = 0;
    }
}

void Timer::Unpause()
{
    // Only unpause if the timer is paused
    if (started && paused)
    {
        paused = false;
        startTicks = SDL_GetTicks() - pausedTicks;
        pausedTicks = 0;
    }
}

Uint32 Timer::GetTicks() const
{
    Uint32 time = 0;
    if (started)
    {
        if (paused)
        {
            time = pausedTicks;
        }
        else
        {
            time = SDL_GetTicks() - startTicks;
        }
    }
    return time;
}
