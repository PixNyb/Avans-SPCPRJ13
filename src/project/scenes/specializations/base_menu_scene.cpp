/**
 * @file base_menu_scene.cpp
 * @author melvi
 * @brief TODO
 * @version 0.1
 * @date 08/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "base_menu_scene.hpp"
#include <algorithm>

BaseMenuScene::BaseMenuScene() {}

BaseMenuScene::~BaseMenuScene() {}

void BaseMenuScene::AddText(const std::string &name, const std::string &text, const Point &position,
                            const int size, const Color &textColor, const std::string &font)
{
    const auto textComponent = std::make_shared<Text>(name, name, 0, size, size);
    textComponent->SetText(text);
    textComponent->SetFontSize(size);
    textComponent->SetTransform(Transform(position, 0, 0));
    textComponent->SetTextColor(textColor);

    contents.push_back(textComponent);
}

std::weak_ptr<Button> BaseMenuScene::AddButton(const std::string &name, const std::string &text,
                                               const Point &position, const Color &bgColor,
                                               const Color &textColor, const int textSize,
                                               const std::string &font)
{
    // TODO: Add bounding box using vector2D
    // TODO: Add background for button and text color, size and font
    const auto button = std::make_shared<Button>(name, name, 0, 500, 500);
    // TODO: Add text
    button->SetTransform(Transform(position, 0, 0));

    const auto textComponent = std::make_shared<Text>(name, name, 0, textSize, textSize);
    textComponent->SetText(text);
    textComponent->SetFontSize(textSize);
    textComponent->SetTransform(Transform(position, 0, 0));
    textComponent->SetTextColor(textColor);

    contents.push_back(button);
    contents.push_back(textComponent);
    return button;
}

std::weak_ptr<Button> BaseMenuScene::AddButton(const std::string &name, const std::string &text,
                                               const Point &position,
                                               const std::string &buttonBackgroundImagePath,
                                               const int textSize, const std::string &font)
{
    // TODO: Add bounding box using vector2D
    const auto button = std::make_shared<Button>(name, name, 0, 500, 200);
    button->SetTransform(Transform(position, 0, 0));

    const auto textComponent = std::make_shared<Text>(name, name, 0, textSize, textSize);
    textComponent->SetText(text);
    textComponent->SetFontSize(textSize);
    textComponent->SetTransform(Transform(position, 0, 0));

    // TODO: Add button background image
    contents.push_back(button);
    contents.push_back(textComponent);
    return button;
}
