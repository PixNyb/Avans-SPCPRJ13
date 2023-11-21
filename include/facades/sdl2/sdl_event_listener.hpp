/**
 * @file inputhandler.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the SDLEventListener class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_INPUTHANDLER_HPP
#define DEFUNBOBENGINE_INPUTHANDLER_HPP

#include "key_code.hpp"
#include "key_event.hpp"
#include "mouse_event.hpp"
#include <SDL.h>
#include <memory>
#include <vector>

/**
 * @class SDLEventListener
 * @brief Handles input events using SDL2.
 *
 * SDLEventListener implements the input handling mechanism.
 * It is responsible for initializing SDL2's input system and retrieving
 * input events each frame, which can then be interpreted by the game engine.
 */
class SDLEventListener
{
  public:
    /**
     * @brief Destructor for SDLEventListener.
     */
    ~SDLEventListener();

    /**
     * @brief Polls SDL events and processes them.
     */
    void PollEvents();

    /**
     * @brief Retrieves the polled key events.
     * @return A vector of shared pointers to KeyEvent objects.
     */
    std::vector<std::shared_ptr<KeyEvent>> GetPolledKeyEvents() const;

    /**
     * @brief Retrieves the polled mouse events.
     * @return A vector of shared pointers to MouseEvent objects.
     */
    std::vector<std::shared_ptr<MouseEvent>> GetPolledMouseEvents() const;

  private:
    std::vector<std::shared_ptr<KeyEvent>> polledKeyEvents; ///< Vector to store polled key events.
    std::vector<std::shared_ptr<MouseEvent>>
        polledMouseEvents; ///< Vector to store polled mouse events.
};

#endif // DEFUNBOBENGINE_INPUTHANDLER_HPP
