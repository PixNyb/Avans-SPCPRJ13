/**
 * @file inputhandler.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the SDL2InputHandler class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * SDL2InputHandler is a concrete implementation of the IOFacade interface
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

#include <vector>
#include "event.hpp"
#include "io_facade.hpp"

/**
 * @class SDL2InputHandler
 * @brief Handles input events using SDL2.
 *
 * SDL2InputHandler implements the input handling mechanism defined by the IOFacade
 * interface. It is responsible for initializing SDL2's input system and retrieving
 * input events each frame, which can then be interpreted by the game engine.
 */
class SDL2InputHandler : public IOFacade {
public:
    /**
     * @brief Initializes SDL2 input handling.
     *
     * This method sets up any necessary SDL2 structures and prepares the system to
     * start processing input events.
     */
    void init() override;

    /**
     * @brief Polls for SDL2 input events and passes them to the engine.
     *
     * This method retrieves all pending SDL2 events and translates them into a
     * generic format understood by the engine, accumulating them in the provided
     * event vector.
     * @param events A reference to a vector where the polled events will be stored.
     */
    void pollEvents(std::vector<Event>& events) override;
};

#endif //DEFUNBOBENGINE_INPUTHANDLER_HPP