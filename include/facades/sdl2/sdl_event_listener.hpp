/**
 * @file inputhandler.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the SDLEventListener class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * SDLEventListener is a concrete implementation of the IOFacade interface
 * specific to the SDL2 library. It initializes SDL2 input handling and polls
 * for input events, passing them back to the engine for further processing.
 *
 * @see IOFacade
 * @see Event
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
 * SDLEventListener implements the input handling mechanism defined by the IOFacade
 * interface. It is responsible for initializing SDL2's input system and retrieving
 * input events each frame, which can then be interpreted by the game engine.
 */
class SDLEventListener
{
  public:
    void PollEvents();

    [[nodiscard]] std::vector<std::shared_ptr<KeyEvent>> GetPolledKeyEvents() const;

    [[nodiscard]] std::vector<std::shared_ptr<MouseEvent>> GetPolledMouseEvents() const;

  private:
    std::vector<std::shared_ptr<KeyEvent>> polledKeyEvents;
    std::vector<std::shared_ptr<MouseEvent>> polledMouseEvents;
};

#endif // DEFUNBOBENGINE_INPUTHANDLER_HPP
