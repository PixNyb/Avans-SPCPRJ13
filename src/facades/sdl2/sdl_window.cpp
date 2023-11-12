/**
 * @file sdl_window.cpp
 * @author Robin Pijnappels
 * @brief Implementation of the Window class that wraps SDL2 window functionalities.
 * @version 0.1
 * @date 09/11/2023
 *
 * This implementation file provides the functionality to create and manage an SDL2 window.
 * It includes the methods to create a new window, set its properties, and handle its destruction.
 *
 */

#include "sdl_window.hpp"

SDLWindow::SDLWindow(const char *title, int width, int height) : SdlWindow(nullptr)
{ // This initializes the sdl_window pointer to nullptr.
    Create(title, width, height);
}

SDLWindow::~SDLWindow()
{
    Destroy(); // Ensure the SDL_Window is properly destroyed.
}

void SDLWindow::Create(const char *title, int width, int height)
{
    if (SdlWindow)
    {
        // If a window already exists, destroy it before creating a new one.
        SDL_DestroyWindow(SdlWindow);
    }

    SdlWindow =
        SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
                         SDL_WINDOW_SHOWN // Window flags (this could include SDL_WINDOW_OPENGL if
                                          // using OpenGL, etc.)
        );

    if (!SdlWindow)
    { // Make sure to check the correct variable.
        SDL_Log("Window could not be created: %s", SDL_GetError());
        // Handle error accordingly.
    }
}

void SDLWindow::Destroy()
{
    if (SdlWindow)
    {
        SDL_DestroyWindow(SdlWindow);
        SdlWindow = nullptr;
    }
}

SDL_Window *SDLWindow::GetSDLWindow() const { return SdlWindow; }
