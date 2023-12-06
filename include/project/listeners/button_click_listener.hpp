/**
 * @file button_click_listener.hpp
 * @author "Martijn Vermeer"
 * @brief Defines the ButtonClickListener class.
 * @version 0.1
 * @date 24/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_BUTTON_CLICK_LISTENER_HPP
#define DEFUNBOBENGINE_BUTTON_CLICK_LISTENER_HPP

#include "button.hpp"
#include "imouse_listener.hpp"

/**
 * @class ButtonClickListener
 * @brief Listens to mouse events on a specific button.
 *
 * The ButtonClickListener class is responsible for handling mouse events (such as clicks,
 * presses, releases, and movement) on a specific button.
 */
class ButtonClickListener : public IMouseListener
{
  private:
    std::shared_ptr<Button> button; ///< The button being listened to.
    Point mousePos;                 ///< The current mouse position.

  public:
    /**
     * @brief Constructor for ButtonClickListener.
     * @param button A shared pointer to the button to listen to.
     */
    ButtonClickListener(const std::shared_ptr<Button> &button);

    /**
     * @brief Set the current mouse position.
     * @param mousePos The mouse position to set.
     */
    void SetMousePosition(const Point &mousePos);

    // IMouseListener interface implementations
    void OnMouseMoved() override;
    void OnMouseClicked() override;
    void OnMousePressed() override;
    void OnMouseReleased() override;
};

#endif // DEFUNBOBENGINE_BUTTON_CLICK_LISTENER_HPP
