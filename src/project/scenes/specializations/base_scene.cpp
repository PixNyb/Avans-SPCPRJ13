/**
 * @file base_scene.cpp
 * @author melvi
 * @brief TODO
 * @version 0.1
 * @date 08/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "base_scene.hpp"
#include <algorithm>

BaseScene::~BaseScene() {}
BaseScene::BaseScene() {}

void BaseScene::RemoveByName(const std::string &name) {
    auto it = std::remove_if(contents.begin(), contents.end(),[name](const auto& element) { return element->GetName() == name;});
    contents.erase(it, contents.end());
}
