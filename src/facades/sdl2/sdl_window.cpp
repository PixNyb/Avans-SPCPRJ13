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

SDLWindow::SDLWindow(const char* title, int width, int height)
        : sdl_window(nullptr) { // This initializes the sdl_window pointer to nullptr.
    create(title, width, height);
}

SDLWindow::~SDLWindow() {
    destroy(); // Ensure the SDL_Window is properly destroyed.
}

void SDLWindow::create(const char* title, int width, int height) {
    if (sdl_window) {
        // If a window already exists, destroy it before creating a new one.
        SDL_DestroyWindow(sdl_window);
    }

    sdl_window = SDL_CreateWindow(
            title,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_SHOWN // Window flags (this could include SDL_WINDOW_OPENGL if using OpenGL, etc.)
    );

    if (!sdl_window) { // Make sure to check the correct variable.
        SDL_Log("Window could not be created: %s", SDL_GetError());
        // Handle error accordingly.
    }
}

void SDLWindow::destroy() {
    if (sdl_window) {
        SDL_DestroyWindow(sdl_window);
        sdl_window = nullptr;
    }
}

SDL_Window* SDLWindow::getSDLWindow() const {
    return sdl_window;
}
