/// @file

#ifndef DEFUNBOBENGINE_IMOUSE_LISTENER_H
#define DEFUNBOBENGINE_IMOUSE_LISTENER_H

#include "color.hpp"
#include "point.hpp"
#include <string>

/**
 * @brief Interface for objects wanting to respond to mouse events.
 */
class IMouseListener
{
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

#endif // DEFUNBOBENGINE_IMOUSE_LISTENER_H
