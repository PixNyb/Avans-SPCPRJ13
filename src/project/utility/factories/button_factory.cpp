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

std::shared_ptr<Button> ButtonFactory::CreateButton(const float width, const float height,
                                                    const int fontSize,
                                                    const std::string &buttonText)
{
    std::shared_ptr<Button> button = std::make_shared<Button>();
    button->SetWidth(width);
    button->SetHeight(height);
    button->SetTag(buttonText);

    auto text = std::make_shared<Text>(buttonText, buttonText, 1, width, height);
    text->SetFontSize(fontSize);
    text->SetText(buttonText);
    text->SetParent(button);

    return button;
}