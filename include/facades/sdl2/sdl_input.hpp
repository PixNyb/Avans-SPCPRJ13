/**
 * @file sdl_input.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the Input class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * The Input class is responsible for gathering and processing user input from
 * various devices like the keyboard and mouse. It provides methods to check the
 * current state of different input devices and to handle input events within the
 * game loop.
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_INPUT_HPP
#define DEFUNBOBENGINE_INPUT_HPP

#include <SDL.h>

/**
 * @class Input
 * @brief Handles keyboard and mouse input for the engine.
 *
 * This class provides a unified interface for input handling. It tracks the state
 * of input devices and provides functions to query the state of keys and mouse buttons.
 * It should be updated every frame to process the latest input events.
 */
class Input
{
  public:
    /**
     * @brief Construct a new Input object.
     *
     * Initializes the state of the input handling system.
     */
    Input();

    /**
     * @brief Destroy the Input object.
     *
     * Cleans up any resources or states used by the input handling system.
     */
    ~Input();

    /**
     * @brief Update the input state.
     *
     * Polls for new events from SDL and updates the state of input devices accordingly.
     */
    void update();

    /**
     * @brief Check if a specific key is currently pressed.
     * @param key The SDL_Scancode representing the key to check.
     * @return true if the key is pressed, false otherwise.
     */
    bool isKeyPressed(SDL_Scancode key) const;

    // Other input-related methods can be defined here.
};

#endif // DEFUNBOBENGINE_INPUT_HPP
