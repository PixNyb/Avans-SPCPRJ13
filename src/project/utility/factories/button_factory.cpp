/**
 * @file button_factory.cpp
 * @author "Martijn Vermeer"
 * @brief Contains the declaration for the button factory.
 * @version 0.1
 * @date 24/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "button_factory.hpp"

std::shared_ptr<UIObject> ButtonFactory::CreateButton(const std::shared_ptr<IInputFacade>& inputFacade, const float width, const float height,
                                                      const std::string &buttonText)
{
    std::shared_ptr<Button> button = std::make_shared<Button>();
    button->SetWidth(width);
    button->SetHeight(height);
    button->SetTag(buttonText);

    auto text = std::make_shared<Text>("start button", "start button", 1, 80, 80);
    text->SetText(buttonText);
    text->SetParent(button);

    auto buttonClickListener = std::make_shared<ButtonClickListener>(button);
    inputFacade->AddButtonClickListener(buttonClickListener);

    return button;
}