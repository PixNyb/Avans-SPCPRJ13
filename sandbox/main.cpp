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

#include "behaviour_script.hpp"
#include "json_reader.hpp"
#include "level_manager.hpp"
#include "prefab_manager.hpp"
#include "rigidbody.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Sandbox" << std::endl;

    auto sManager = std::make_shared<SceneManager>();
    auto pManager = std::make_shared<PrefabManager>();
    auto jReader = std::make_shared<JSONReader>();
    auto lvlManager = std::make_shared<LevelManager>(sManager, pManager, jReader);

    auto character = GameObject();
    character.AddComponent(std::make_shared<RigidBody>(0, 0, BodyType::dynamicBody));
    character.AddComponent(std::make_shared<BehaviourScript>());

    auto tree = GameObject();
    tree.AddComponent(std::make_shared<RigidBody>(0, 0, BodyType::staticBody));

    pManager->RegisterPrefab("Character", character);
    pManager->RegisterPrefab("Tree", tree);

    try
    {
        lvlManager->RegisterLevel(1, R"(C:\Users\maxro\Desktop\level1.json)");
        lvlManager->RegisterLevel(2, R"(C:\Users\maxro\Desktop\level2.json)");
    } catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }

    lvlManager->LoadLevel(1);
    auto scene1 = sManager->GetScene();

    lvlManager->LoadLevel(2);
    auto scene2 = sManager->GetScene();

    return 1;
}