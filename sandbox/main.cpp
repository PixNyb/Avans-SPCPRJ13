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
#include "circle_collider.hpp"
#include "collider_behavior_test.hpp"
#include "game_object.hpp"
#include "physics_manager.hpp"
#include "rigidbody.hpp"
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::shared_ptr<PhysicsManager> physicsManager = std::make_shared<PhysicsManager>();
    std::vector<std::shared_ptr<GameObject>> objects;

    // create box
    auto obj = std::make_shared<GameObject>();
    Point point{20, 600};
    Transform trs{point, 0, 1};
    auto body = std::make_shared<RigidBody>(10, 1, BodyType::dynamicBody);
    auto collider = std::make_shared<BoxCollider>();
    collider->Width(50);
    collider->Height(50);
    obj->AddComponent(body);
    obj->AddComponent(collider);
    obj->SetTransform(trs);
    obj->SetTag("box");
    obj->SetPhysicsManager(physicsManager);

    // create circle
    auto obj1 = std::make_shared<GameObject>();
    Point point1{200, 600};
    Transform trs1{point1, 0, 1};
    auto body1 = std::make_shared<RigidBody>(10, 1, BodyType::dynamicBody);
    auto collider1 = std::make_shared<CircleCollider>();
    collider1->Radius(25);
    auto script = std::make_shared<ColliderBehaviorTest>(physicsManager, obj1);
    obj1->AddComponent(script);
    obj1->AddComponent(body1);
    obj1->AddComponent(collider1);
    obj1->SetTransform(trs1);
    obj1->SetTag("circle");
    obj1->SetPhysicsManager(physicsManager);

    // create floor
    auto obj2 = std::make_shared<GameObject>();
    Point point2{0, 0};
    Transform trs2{point2, 0.01, 1};
    auto body2 = std::make_shared<RigidBody>(10, 1, BodyType::staticBody);
    auto collider2 = std::make_shared<BoxCollider>();
    collider2->Width(800);
    collider2->Height(20);
    obj2->AddComponent(body2);
    obj2->AddComponent(collider2);
    obj2->SetTransform(trs2);
    obj2->SetTag("floor");
    obj2->SetPhysicsManager(physicsManager);

    objects.push_back(obj);
    objects.push_back(obj1);
    objects.push_back(obj2);
    physicsManager->CreateWorld(objects);
//    physicsManager->AddForce(obj1, 20, 0);
    physicsManager->SetDebug(true);
    while (true)
    {
        physicsManager->Step();
    }
    std::cout << "Sandbox" << std::endl;
    return 1;
}