/**
 * @file main.cpp
 * @author "Melvin van Bree"
 * @brief Used as a sandbox to test code without have to open up a game.
 * @version 0.1
 * @date 10/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "game_object.hpp"
#include "game_object_utility.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    std::shared_ptr<GameObject> root = std::make_shared<GameObject>();
    root->SetName("Root");
    std::shared_ptr<GameObject> child = std::make_shared<GameObject>();
    child->SetName("Child");
    child->SetParent(root);

    std::shared_ptr<GameObject> grandChild = std::make_shared<GameObject>();
    grandChild->SetName("GrandChild");
    grandChild->SetParent(child);

    std::cout << "Before setting anything to inactive" << std::endl;

    GameObjectUtility::ProcessActiveObjectsRecursively(
        root, [](const std::shared_ptr<GameObject> &gameObject)
        { std::cout << gameObject->GetName() << std::endl; });

    child->SetActive(false);

    std::cout << "After setting child to inactive" << std::endl;

    GameObjectUtility::ProcessActiveObjectsRecursively(
        root, [](const std::shared_ptr<GameObject> &gameObject)
        { std::cout << gameObject->GetName() << std::endl; });

    std::cout << "After setting root to inactive" << std::endl;

    root->SetActive(false);

    GameObjectUtility::ProcessActiveObjectsRecursively(
        root, [](const std::shared_ptr<GameObject> &gameObject)
        { std::cout << gameObject->GetName() << std::endl; });

    return 1;
}