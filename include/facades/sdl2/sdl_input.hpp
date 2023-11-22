/**
 * @file sdl_input.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @author Roël Couwenberg (contact@roelc.me)
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

#include "point.hpp"
#include <SDL.h>
#include <SDL_scancode.h>
#include <SDL_stdinc.h>
#include <unordered_map>

/**
 * @class SDLInput
 * @brief Handles keyboard and mouse input for the engine.
 *
 * This class provides a unified interface for input handling. It tracks the state
 * of input devices and provides functions to query the state of keys and mouse buttons.
 * It should be updated every frame to process the latest input events.
 */
class SDLInput
{
  public:
    /**
     * @brief Construct a new Input object.
     *
     * Initializes the state of the input handling system.
     */
    SDLInput();

    /**
     * @brief Destroy the Input object.
     *
     * Cleans up any resources or states used by the input handling system.
     */
    ~SDLInput();

    /**
     * @brief Update the input state.
     *
     * Polls for new events from SDL and updates the state of input devices accordingly.
     */
    void Update();

    /**
     * @brief Check if a specific key is currently pressed.
     * @param key The SDL_Scancode representing the key to check.
     * @return true if the key is pressed, false otherwise.
     */
    bool IsKeyPressed(SDL_Scancode key) const;

    /**
     * @brief Check if a specific key is pressed down this frame.
     * @param key The SDL_Scancode representing the key to check.
     * @return true if the key is down, false otherwise.
     */
    bool IsKeyDown(SDL_Scancode key) const;

    /**
     * @brief Check if a specific key is released this frame.
     * @param key The SDL_Scancode representing the key to check.
     * @return true if the key is released, false otherwise.
     */
    bool IsKeyUp(SDL_Scancode key) const;

    /**
     * @brief Check if any key is currently pressed.
     * @return true if any key is pressed, false otherwise.
     */
    bool IsAnyKeyPressed() const;

    /**
     * @brief Check if any key is pressed down this frame.
     * @return true if a key is down, false otherwise.
     */
    bool IsAnyKeyDown() const;

    /**
     * @brief Check if any key is released this frame.
     * @return true if a key is released, false otherwise.
     */
    bool IsAnyKeyUp() const;

    /**
     * @brief Check if a specific mouse button is currently pressed.
     * @param button The SDL button code representing the mouse button to check.
     * @return true if the mouse button is pressed, false otherwise.
     */
    bool IsMouseButtonPressed(Uint8 button) const;

    /**
     * @brief Check if any mouse button is currently pressed.
     * @return true if any mouse button is pressed, false otherwise.
     */
    bool IsAnyMouseButtonPressed() const;

    /**
     * @brief Check if a specific mouse button is pressed down this frame.
     * @param button The SDL button code representing the mouse button to check.
     * @return true if the mouse button is down, false otherwise.
     */
    bool IsMouseButtonDown(Uint8 button) const;

    /**
     * @brief Check if any mouse button is pressed down this frame.
     * @return true if a mouse button is down, false otherwise.
     */
    bool IsAnyMouseButtonDown() const;

    /**
     * @brief Check if a specific mouse button is released this frame.
     * @param button The SDL button code representing the mouse button to check.
     * @return true if the mouse button is released, false otherwise.
     */
    bool IsMouseButtonUp(Uint8 button) const;

    /**
     * @brief Check if any mouse button is released this frame.
     * @return true if a mouse button is released, false otherwise.
     */
    bool IsAnyMouseButtonUp() const;

    /**
     * @brief Get the current position of the mouse cursor.
     * @return The current position of the mouse cursor.
     */
    SDL_Point GetMousePosition() const;

  private:
    std::unordered_map<SDL_Scancode, bool>
        frameKeyState; ///< The current state of the keys that have changed this frame.
    std::unordered_map<Uint8, bool>
        frameMouseButtonState; ///< The current state of the mouse buttons that have changed this
                               ///< frame.
    std::unordered_map<SDL_Scancode, bool> keyState;  ///< The current state of all keys.
    std::unordered_map<Uint8, bool> mouseButtonState; ///< The current state of all mouse buttons.
    SDL_Point mousePosition;                          ///< The current position of the mouse cursor.
};

#endif // DEFUNBOBENGINE_INPUT_HPP
