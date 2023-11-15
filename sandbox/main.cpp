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
#include "physics_facade.hpp"
#include <iostream>
#include <memory>

int main(int argc, char *argv[])
{
    std::vector<std::shared_ptr<GameObject>> objects;

    //// create object
    auto obj = std::make_shared<GameObject>();
    Point point{600, 2500};
    Transform trs{point, 20, 1};
    auto body = std::make_shared<RigidBody>(10, 1, BodyType::dynamicBody);
    auto collider = std::make_shared<BoxCollider>();
    collider->Width(20);
    collider->Height(20);
    obj->AddComponent(body);
    obj->AddComponent(collider);
    obj->SetTransform(trs);

    objects.push_back(obj);
//    objects.push_back(floor);
    PhysicsFacade pf;
    pf.PopulateWorld(objects);
    pf.ShowDebug();

//    while (true) {
//        pf.Step();
//    }
    std::cout << "Sandbox" << std::endl;
    //    auto engine = Engine::getInstance();

    return 1;
}