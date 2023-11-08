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

BaseMenuScene::BaseMenuScene()
{
}

BaseMenuScene::~BaseMenuScene()
{
}

void BaseMenuScene::AddText(const std::string& name, const std::string &text, const Point &position, const int size, const std::string &font){
    const auto textComponent = std::make_shared<Text>(name, name, 0, size, size);
    textComponent->SetText(text);
    textComponent->SetFontSize(size);
    textComponent->SetTransform(Transform(position, 0, 0));
    // TODO: Add font and color

    contents.push_back(textComponent);
}

std::weak_ptr<Button> BaseMenuScene::AddButton(const std::string& name, const std::string &text, const Point &position, const Color &bgColor, const Color &textColor, const int textSize, const std::string &font){
    // TODO: Add bounding box using vector2D
    // TODO: Add background for button and text color, size and font
    const auto button = std::make_shared<Button>(name, name, 0, 500, 500);
    // TODO: Add text
    button->SetTransform(Transform(position, 0, 0));

    contents.push_back(button);
    return button;
}
std::weak_ptr<Button> BaseMenuScene::AddButton(const std::string& name, const std::string &text, const Point &position, const std::string &buttonBackgroundImagePath, const int textSize, const std::string &font){
    // TODO: Add bounding box using vector2D
    // TODO: Add background image for button and text color, size and font
    const auto button = std::make_shared<Button>(name, name, 0, 500, 500);
    // TODO: Add text
    button->SetTransform(Transform(position, 0, 0));

    contents.push_back(button);
    return button;
}