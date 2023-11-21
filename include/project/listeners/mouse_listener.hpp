/**
 * @file mouse_listener.hpp
 * @author Martijn Vermeer
 * @brief This file Defines the MouseListener class, which implements the IMouseListener interface.
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_MOUSE_LISTENER_HPP
#define DEFUNBOBENGINE_MOUSE_LISTENER_HPP

#include "imouse_listener.hpp"
#include "mouse_event.hpp"

/**
 * @class MouseListener
 * @brief Listens for mouse events and implements the IMouseListener interface.
 *
 * The MouseListener class is responsible for handling mouse events and implementing the
 * IMouseListener interface. It provides callbacks for mouse moved, mouse clicked,
 * mouse pressed, and mouse released events.
 */
class MouseListener : public IMouseListener
{
  public:
    /**
     * @brief Constructs a MouseListener with a specified mouse event.
     * @param mouseEvent The mouse event associated with the listener.
     */
    MouseListener(const MouseEvent &mouseEvent);

    /**
     * @brief Callback for when the mouse is moved.
     */
    void OnMouseMoved() override;

    /**
     * @brief Callback for when the mouse is clicked.
     */
    void OnMouseClicked() override;

    /**
     * @brief Callback for when a mouse button is pressed.
     */
    void OnMousePressed() override;

    /**
     * @brief Callback for when a mouse button is released.
     */
    void OnMouseReleased() override;

    /**
     * @brief Retrieves the mouse event associated with the listener.
     * @return The mouse event.
     */
    MouseEvent GetMouseEvent();

  private:
    MouseEvent mouseEvent; ///< The mouse event associated with the listener.
};

#endif // DEFUNBOBENGINE_MOUSE_LISTENER_HPP
