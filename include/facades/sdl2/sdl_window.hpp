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
 * The Create function initializes the SDL_Window, and the Destroy function
 * ensures it is properly destroyed when no longer needed.
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_WINDOW_HPP
#define DEFUNBOBENGINE_WINDOW_HPP

#include "sdl_render.hpp"
#include <SDL.h>
#include <iostream>

/**
 * @class SDLWindow
 * @brief Manages creation, display, and destruction of an SDL_Window.
 *
 * This class wraps the SDL_Window structure and provides methods to
 * create and destroy a window. It is responsible for handling the window's
 * lifecycle and providing a means to retrieve the SDL_Window pointer.
 */
class SDLWindow
{
    SDL_Window *SdlWindow; ///< Pointer to the SDL_Window managed by this class.
    SDL_Renderer *SdlRenderer;

  public:
    /**
     * @brief Construct a new SDLWindow object but does not create the window.
     *
     * The actual window is created using the Create function. This allows for
     * delayed window creation or re-creation if needed.
     * @param title The title of the window.
     * @param width The width of the window in pixels.
     * @param height The height of the window in pixels.
     */
    SDLWindow(const char *title, int width, int height);

    /**
     * @brief Destroys the SDLWindow object, ensuring the SDL_Window is properly destroyed.
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
    void Create(const char *title, int width, int height);

    /**
     * @brief Destroys the SDL_Window managed by this object.
     *
     * This function is called by the destructor and can also be called manually
     * to destroy the window without destroying the SDLWindow object itself.
     */
    void Destroy();

    /**
     * @brief Retrieves the underlying SDL_Window pointer.
     * @return SDL_Window* A pointer to the managed SDL_Window.
     */
    SDL_Window *GetSDLWindow() const;

    /**
     * @brief Retrieves the underlying SDL_Render pointer.
     * @return SDL_Render* A pointer to the managed SDL_Render.
     */
    SDL_Renderer *GetRenderer() const;

    /**
     * @brief Delays execution for a specified duration.
     *
     * Introduces a pause in processing, useful for controlling frame rates.
     * @param ms Delay duration in milliseconds.
     */
    void Delay(unsigned int ms) { SDL_Delay(ms); }

    /**
     * @brief Creates an SDL_Renderer associated with the window.
     *
     * Initializes the renderer for this window, enabling accelerated rendering.
     * If the renderer cannot be created, an error message is displayed.
     */
    void CreateRenderer();

    /**
     * @brief Clears the rendering target.
     *
     * Prepares the screen for new rendering operations by clearing existing content.
     */
    void ClearScreen();

    /**
     * @brief Presents the rendered content on the screen.
     *
     * Updates the window with rendered graphics, finalizing the current frame.
     */
    void PresentScreen();
};

#endif // DEFUNBOBENGINE_WINDOW_HPP
