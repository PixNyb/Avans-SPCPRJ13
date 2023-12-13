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
#include "engine.hpp"
#include "i_input_facade.hpp"
#include "imouse_listener.hpp"

class IInputFacade;

/**
 * @class ButtonClickListener
 * @brief Listens to mouse events on a specific button.
 *
 * The ButtonClickListener class is responsible for handling mouse events (such as clicks,
 * presses, releases, and movement) on a specific button.
 */
class ButtonClickListener : public IMouseListener,
                            public std::enable_shared_from_this<ButtonClickListener>
{
  private:
    const Button &button; ///< The button being listened to.
    IInputFacade &inputFacade;

  public:
    /**
     * @brief Constructor for ButtonClickListener.
     * @param button A shared pointer to the button to listen to.
     */
    explicit ButtonClickListener(const Button &button);

    /**
     * @brief Called to attach the listener to the input manager.
     */
    void Attach();

    /**
     * @brief Called to detach the listener from the input manager.
     */
    void Detach();

    // IMouseListener interface implementations
    void OnMouseMoved() override;
    void OnMouseClicked() override;
    void OnMousePressed() override;
    void OnMouseReleased() override;
};

#endif // DEFUNBOBENGINE_BUTTON_CLICK_LISTENER_HPP
