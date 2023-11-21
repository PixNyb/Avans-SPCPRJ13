/**
 * @file mouse_event.hpp
 * @author Martijn Vermeer
 * @brief This file contains the mouse event class definition.
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_MOUSE_EVENT_HPP
#define DEFUNBOBENGINE_MOUSE_EVENT_HPP

#include "event.hpp"

/**
 * @class MouseEvent
 * @brief Represents a mouse event.
 *
 * The MouseEvent class is derived from the base Event class and provides specific
 * functionality for mouse events.
 */
class MouseEvent : public Event
{
  public:
    /**
     * @brief Constructs a MouseEvent object.
     * @param buttonCode The code associated with the pressed or released mouse button.
     * @param x The X-coordinate of the mouse event.
     * @param y The Y-coordinate of the mouse event.
     * @param eventType The type of mouse event (button pressed, button released, etc.).
     */
    explicit MouseEvent(KeyCode keyCode, int x, int y, EventType);

    /**
     * @brief Gets the X-coordinate of the mouse event.
     * @return The X-coordinate.
     */
    int GetXPos() const;

    /**
     * @brief Gets the Y-coordinate of the mouse event.
     * @return The Y-coordinate.
     */
    int GetYPos() const;

  private:
    int x; ///< The X-coordinate of the mouse event.
    int y; ///< The Y-coordinate of the mouse event.
};

#endif // DEFUNBOBENGINE_MOUSE_EVENT_HPP
