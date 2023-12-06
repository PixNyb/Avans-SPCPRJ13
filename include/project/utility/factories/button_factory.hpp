/**
 * @file button_factory.hpp
 * @author "Martijn Vermeer"
 * @brief Contains the definition for the button factory.
 * @version 0.1
 * @date 24/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_BUTTON_FACTORY_HPP
#define DEFUNBOBENGINE_BUTTON_FACTORY_HPP

#include "button.hpp"
#include "i_input_facade.hpp"
#include "text.hpp"
#include "ui_object.hpp"
#include <memory>
#include <string>

/**
 * @class ButtonFactory
 * @brief Provides a factory for creating buttons in the graphical user interface.
 */
class ButtonFactory
{
  public:
    /**
     * @brief Creates a button UI element.
     * @param inputFacade Shared pointer to the input facade for handling user input.
     * @param width Width of the button.
     * @param height Height of the button.
     * @param fontSize Font size of the button text.
     * @param text Text to be displayed on the button.
     * @return Shared pointer to the created button UI element.
     */
    static std::shared_ptr<UIObject> CreateButton(const std::shared_ptr<IInputFacade> &inputFacade,
                                                  float width, float height, const int fontSize,
                                                  const std::string &text);
};

#endif // DEFUNBOBENGINE_BUTTON_FACTORY_HPP