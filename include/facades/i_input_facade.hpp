/**
 * @file IInputHandler.hpp
 * @author Martijn Vermeer
 * @brief This file contains the Input interface definition.
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_IINPUTHANDLER_HPP
#define DEFUNBOBENGINE_IINPUTHANDLER_HPP

#include "event.hpp"
#include "key_event.hpp"
#include "key_listener.hpp"
#include "mouse_event.hpp"
#include "mouse_listener.hpp"
#include <iostream>
#include <memory>
#include <vector>

/**
 * @class IInputHandler
 * @brief Interface for handling input events in a cross-platform manner.
 *
 * The `IInputHandler` class serves as an interface for handling input events in a way
 * that allows for abstraction and decoupling from specific input systems. Concrete
 * subclasses are expected to implement the methods defined in this interface to
 * provide functionality for polling input events and retrieving specific types of
 * events, such as KeyEvents and MouseEvents.
 */
class IInputFacade
{
  public:
    /**
     * @brief Virtual destructor for IInputFacade.
     */
    virtual ~IInputFacade() = default;

    /**
     * @brief Update the input state, usually called per frame.
     */
    virtual void Update() = 0;

    /**
     * @brief Register a mouse listener to receive mouse-related events.
     * @param mouseListener A unique pointer to the MouseListener to register.
     */
    virtual void RegisterMouseListener(std::unique_ptr<MouseListener> mouseListener) = 0;

    /**
     * @brief Register a key listener to receive key-related events.
     * @param keyListener A unique pointer to the KeyListener to register.
     */
    virtual void RegisterKeyListener(std::unique_ptr<KeyListener> keyListener) = 0;

    /**
     * @brief Bind a key event to a specific action.
     * @param key The key event to bind.
     * @param actionType The type of action to associate with the key event.
     */
    virtual void Bind(const Event &key, const ActionType &actionType) = 0;
};

#endif // DEFUNBOBENGINE_IINPUTHANDLER_HPP
