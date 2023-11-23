/**
 * @file button.hpp
 * @author Robin Pijnappels
 * @version 0.1
 * @date 2023-11-12
 *
 * @brief Defines the Button class as a part of the user interface in a game engine.
 * Button is a UIObject subclass that represents clickable interface elements. It provides
 * functionalities for handling click events and executing registered click handlers.
 * This class is essential for creating interactive UI elements in games.
 *
 * @note Additional listeners and event handling mechanisms are planned for future versions.
 * @deprecated The onClick handler is deprecated and will be replaced by more flexible event
 * listeners.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef AVANS_SPCPRJ13_BUTTON_H
#define AVANS_SPCPRJ13_BUTTON_H

#include "ui_object.hpp"
#include <functional>
#include <utility>

/**
 * @class Button
 * @brief Represents a clickable user interface element.
 *
 * Instances of Button are interactive UI elements that can react to click events.
 * They support registration of custom click handlers for executing specific actions
 * when the button is clicked.
 */
class Button : public UIObject
{
  public:
    // TODO: Add listener for button clicks and attach to input manager somehow
    Button();
    Button(const std::string &name, const std::string &tag, int layer, float width, float height);
    /**
     * @brief This function is called when the button is clicked, which
     *        will trigger a call to the registered onClick member.
     */
    void Click();

    /**
     * @brief Register the onClick handler to be used when the button is clicked.
     * @param callback The function to register, usually a lambda. But this can be
     * @deprecated Other listeners should be used instead of this function
     */
    void OnClick(std::function<void()> callback) { onClick = std::move(callback); }

  private:
    /**
     * @brief When false, the button will not react to clicks.
     */
    bool interactable;

    /**
     * @brief The registered click handler.
     * @deprecated Other listeners should be used instead of this function
     */
    std::function<void()> onClick;
};

#endif // AVANS_SPCPRJ13_BUTTON_H
