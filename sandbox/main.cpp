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

#include "box_collider.hpp"
#include "game_object.hpp"
#include "physics_manager.hpp"
#include <iostream>
#include <memory>

int main(int argc, char *argv[])
{
    std::vector<std::shared_ptr<GameObject>> objects;

    //// create object
    auto obj = std::make_shared<GameObject>();
    Point point{600, 2500};
    Transform trs{point, 0, 1};
    auto body = std::make_shared<RigidBody>(10, 1, BodyType::dynamicBody);
    auto collider = std::make_shared<BoxCollider>();
    collider->Width(50);
    collider->Height(50);
    obj->AddComponent(body);
    obj->AddComponent(collider);
    obj->SetTransform(trs);

    auto obj2 = std::make_shared<GameObject>();
    Point point2{0, 40};
    Transform trs2{point2, 0, 1};
    auto body2 = std::make_shared<RigidBody>(10, 1, BodyType::staticBody);
    auto collider2 = std::make_shared<BoxCollider>();
    collider2->Width(5000);
    collider2->Height(20);
    obj2->AddComponent(body2);
    obj2->AddComponent(collider2);
    obj2->SetTransform(trs2);

    objects.push_back(obj);
    objects.push_back(obj2);
    PhysicsManager physicsManager;
    physicsManager.CreateWorld(objects);
    while (true) {
        physicsManager.Step();
    }
    std::cout << "Sandbox" << std::endl;
    //    auto engine = Engine::getInstance();

    return 1;
}