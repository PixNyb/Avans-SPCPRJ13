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

#include <string>
#include <memory>
#include "ui_object.hpp"
#include "button.hpp"
#include "text.hpp"
#include "i_input_facade.hpp"

class ButtonFactory {
  public:
    static std::shared_ptr<UIObject> CreateButton(const std::shared_ptr<IInputFacade>& inputFacade, float width, float height, const std::string& text);
};

#endif // DEFUNBOBENGINE_BUTTON_FACTORY_HPP