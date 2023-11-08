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

void BaseMenuScene::AddText(const std::string &text, const Point &position, const int size, const std::string &font){}

std::shared_ptr<Button> BaseMenuScene::AddButton(const std::string &text, const Point &position, const Color &bgColor, const Color &textColor, const int textSize, const std::string &font){
    return {};
}
std::shared_ptr<Button> BaseMenuScene::AddButton(const std::string &text, const Point &position, const std::string &buttonBackgroundImagePath, const int textSize, const std::string &font){
    return {};
}