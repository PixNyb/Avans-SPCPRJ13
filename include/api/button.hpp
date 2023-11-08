/// @file

#ifndef AVANS_SPCPRJ13_BUTTON_H
#define AVANS_SPCPRJ13_BUTTON_H

#include "ui_object.hpp"
#include <functional>

/**
 * @brief Instances of this class are clickable user interface items.
 */
class Button : public UIObject {
public:
    /**
     * @brief This function is called when the button is clicked, which
     *        will trigger a call to the registered onClick member.
     */
    void Click();

    /**
     * @brief Register the onClick handler to be used when the button is clicked.
     * @param callback The function to register, usually a lambda. But this can be
     *        any kind of callable.
     */
    void OnClick(std::function<void()> callback) { onClick = callback; }

private:
    /**
     * @brief When false, the button will not react to clicks.
     */
    bool interactable;

    /**
     * @brief The registered click handler.
     */
    std::function<void()> onClick;
};

#endif // AVANS_SPCPRJ13_BUTTON_H
