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
#include "ikey_listener.hpp"
#include "imouse_listener.hpp"
#include "key_event.hpp"
#include "mouse_event.hpp"
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
    virtual ~IInputFacade() = default;

    virtual void Update() = 0;

    virtual void RegisterMouseListener(std::unique_ptr<IMouseListener> mouseListener) = 0;

    virtual void RegisterKeyListener(std::unique_ptr<IKeyListener> keyListener) = 0;

    virtual bool ActionPressed(const ActionType &actionType) const = 0;

    virtual bool ActionReleased(const ActionType &actionType) const = 0;

    virtual void Bind(const Event &key, const ActionType &actionType) = 0;
};

#endif // DEFUNBOBENGINE_IINPUTHANDLER_HPP
