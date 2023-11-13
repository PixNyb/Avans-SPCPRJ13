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

#include <iostream>
#include "physics_facade.hpp"
#include "box_collider.hpp"


int main(int argc, char *argv[])
{
    std::vector<std::shared_ptr<GameObject>> objects;
    auto obj = std::make_shared<GameObject>();
    Point point {0, 0};
    Transform trs {point, 0, 1};
    obj->SetTransform(trs);
    auto body = std::make_shared<RigidBody>(10, 1, BodyType::dynamicBody);
    auto collider = std::make_shared<BoxCollider>();
    collider->Width(20);
    collider->Height(20);
    objects.push_back(obj);
    auto comp = obj->GetComponent<Collider>();
    PhysicsFacade pf;
//    pf.PopulateWorld(objects);
    std::cout << "Sandbox" << std::endl;
//    auto engine = Engine::getInstance();

    return 1;
}