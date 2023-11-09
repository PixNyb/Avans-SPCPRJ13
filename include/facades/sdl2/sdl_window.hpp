/**
 * @file sdl_window.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the SDLWindow class definition for managing an SDL_Window.
 * @version 0.1
 * @date 2023-11-08
 *
 * The SDLWindow class provides a simple interface for creating, displaying, and
 * managing an SDL_Window. It encapsulates SDL window creation and destruction
 * and provides access to the underlying SDL_Window structure.
 *
 * The create function initializes the SDL_Window, and the destroy function
 * ensures it is properly destroyed when no longer needed.
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_WINDOW_HPP
#define DEFUNBOBENGINE_WINDOW_HPP

#include <SDL.h>

/**
 * @class SDLWindow
 * @brief Manages creation, display, and destruction of an SDL_Window.
 *
 * This class wraps the SDL_Window structure and provides methods to
 * create and destroy a window. It is responsible for handling the window's
 * lifecycle and providing a means to retrieve the SDL_Window pointer.
 */
class SDLWindow {
    SDL_Window* sdl_window; ///< Pointer to the SDL_Window managed by this class.

public:
    /**
     * @brief Construct a new Window object but does not create the window.
     *
     * The actual window is created using the create function. This allows for
     * delayed window creation or re-creation if needed.
     * @param title The title of the window.
     * @param width The width of the window in pixels.
     * @param height The height of the window in pixels.
     */
    SDLWindow(const char* title, int width, int height);

    /**
     * @brief Destroys the Window object, ensuring the SDL_Window is properly destroyed.
     */
    ~SDLWindow();

    /**
     * @brief Creates the SDL_Window with the specified properties.
     *
     * If a window was previously created, it will be destroyed and a new one created.
     * @param title The title of the window.
     * @param width The width of the window in pixels.
     * @param height The height of the window in pixels.
     */
    void create(const char* title, int width, int height);

    /**
     * @brief Destroys the SDL_Window managed by this object.
     *
     * This function is called by the destructor and can also be called manually
     * to destroy the window without destroying the Window object itself.
     */
    void destroy();

    /**
     * @brief Retrieves the underlying SDL_Window pointer.
     * @return SDL_Window* A pointer to the managed SDL_Window.
     */
    SDL_Window* getSDLWindow() const;
};

#endif //DEFUNBOBENGINE_WINDOW_HPP
