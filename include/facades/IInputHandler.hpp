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
#include "mouse_event.hpp"
#include <iostream>
#include <vector>
#include <memory>

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
class IInputHandler {
public:
    virtual ~IInputHandler() = default;


    virtual void PollEvents() = 0;

    /**
     * @brief Retrieves a vector of shared pointers to KeyEvents that have been polled.
     *
     * Must be implemented by the concrete subclass to provide a collection of KeyEvents
     * that have been captured from the input system.
     * @return A vector of shared pointers to KeyEvent objects.
     */
    [[nodiscard]] virtual std::vector<std::shared_ptr<KeyEvent>> GetPolledKeyEvents() const = 0;

    /**
     * @brief Retrieves a vector of shared pointers to MouseEvents that have been polled.
     *
     * Must be implemented by the concrete subclass to provide a collection of MouseEvents
     * that have been captured from the input system.
     * @return A vector of shared pointers to MouseEvent objects.
     */
    [[nodiscard]] virtual std::vector<std::shared_ptr<MouseEvent>> GetPolledMouseEvents() const = 0;
};

#endif //DEFUNBOBENGINE_IINPUTHANDLER_HPP
