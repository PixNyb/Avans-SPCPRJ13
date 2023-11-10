/**
 * @file io_facade.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the IOFacade interface definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * IOFacade is an interface for input/output handling in the game engine. It
 * defines a standard set of operations for initializing the input system and
 * polling for events, which can be implemented by various concrete input
 * systems like SDL, GLFW, etc.
 *
 * Implementations of IOFacade are responsible for translating system-specific
 * input events into a generic format that can be used by the game engine.
 *
 * @see Event
 * @see SDL2InputHandler
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_IO_FACADE_HPP
#define DEFUNBOBENGINE_IO_FACADE_HPP

#include <vector>
#include "event.hpp"
#include "sdl_window.hpp"

/**
 * @class IOFacade
 * @brief Interface for input/output handling in the game engine.
 *
 * This abstract class defines the necessary interface for input handling within
 * the engine. Concrete implementations are responsible for providing the logic
 * to initialize the input system and to poll for input events, returning them
 * in a consistent format.
 */
class IOFacade {
    SDLWindow sdlWindow;
public:
    /**
     * @brief Virtual destructor for IOFacade.
     */
    virtual ~IOFacade() = default;

    /**
     * @brief Initializes the input handling system.
     *
     * Must be implemented by the concrete subclass to set up the specific input
     * system in use, such as SDL2 or GLFW.
     */
    virtual void init() = 0;

    /**
     * @brief Polls for input events and populates the provided event vector.
     *
     * Must be implemented by the concrete subclass to check for new events from
     * the input system and translate them into a vector of Event objects.
     * @param events A reference to a vector where the polled events will be stored.
     */
    virtual void pollEvents(std::vector<Event>& events) = 0;

    /**
    * @brief Creates a window with the specified properties.
    *
    * This method must be implemented by the concrete subclass to handle the creation
            * of a window. It should specify the window's title, width, and height, and delegate
    * the actual creation process to a window management system, such as SDL2, abstracted
            * by the sdl_window.hpp class. The method should manage the lifecycle of the window
            * and ensure it integrates properly with the input/output handling system of the engine.
    *
    * @param title The title to be displayed on the window's title bar.
    * @param width The width of the window in pixels.
    * @param height The height of the window in pixels.
    */
    virtual void createWindow(const char* title, int width, int height) = 0;

    /**
     * @brief delay execution for a specified number of milliseconds.
     * @param ms The number of milliseconds to delay execution.
     */
    virtual void delay(unsigned int ms) = 0;

    virtual void destroyWindow() {
//        sdlWindow.destroy()
    }
};

#endif //DEFUNBOBENGINE_IO_FACADE_HPP
