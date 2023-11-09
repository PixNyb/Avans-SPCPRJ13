/// @file

#ifndef AVANS_SPCPRJ13_BUTTON_H
#define AVANS_SPCPRJ13_BUTTON_H

#include "ui_object.hpp"
#include <functional>
#include <utility>

/**
 * @brief Instances of this class are clickable user interface items.
 */
 // TODO: Add listener for button clicks and attach to input manager somehow
class Button : public UIObject {
public:
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
