/**
 * @file imouse_listener.hpp
 * @author Robin Pijnappels
 * @version 0.1
 * @date 2023-11-12
 *
 * @brief Defines the IMouseListener interface for handling mouse events in the DefunBobEngine.
 * IMouseListener is an interface designed for objects that need to respond to various mouse events.
 * It includes virtual methods for handling mouse movements, clicks, presses, and releases,
 * enabling implementing classes to define specific behaviors for these user interactions.
 * This interface is essential for creating interactive and responsive game elements.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef DEFUNBOBENGINE_IMOUSE_LISTENER_H
#define DEFUNBOBENGINE_IMOUSE_LISTENER_H

#include <string>
#include "point.hpp"
#include "color.hpp"

/**
 * @class IMouseListener
 * @brief Interface for objects that respond to mouse events.
 *
 * IMouseListener provides a structure for objects to handle mouse input.
 * Implementing classes can define specific behaviors for mouse movement, clicks, presses, and releases.
 */
class IMouseListener {
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~IMouseListener() = default;

    /**
     * @brief Called whenever the mouse is moved.
     */
    virtual void OnMouseMoved() = 0;

    /**
     * @brief Called whenever a mouse button is clicked.
     */
    virtual void OnMouseClicked() = 0;

    /**
     * @brief Called each frame when a mouse button is still down.
     */
    virtual void OnMousePressed() = 0;

    /**
     * @brief Called whenever a mouse button is released.
     */
    virtual void OnMouseReleased() = 0;
};

#endif //DEFUNBOBENGINE_IMOUSE_LISTENER_H
