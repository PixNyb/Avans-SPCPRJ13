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

class MouseListener : public IMouseListener {
  public:
    MouseListener(const MouseEvent &mouseEvent);

    void OnMouseMoved() override;
    void OnMouseClicked() override;
    void OnMousePressed() override;
    void OnMouseReleased() override;

  private:
    MouseEvent mouseEvent;
};

#endif //DEFUNBOBENGINE_MOUSE_LISTENER_HPP
