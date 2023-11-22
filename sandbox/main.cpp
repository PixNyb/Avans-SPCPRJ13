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
#include <vector>
#include "game_object.hpp"
#include "rigidbody.hpp"
#include "box_collider.hpp"
#include "circle_collider.hpp"
#include "physics_manager.hpp"

int main(int argc, char *argv[])
{
    PhysicsManager physicsManager;
    std::weak_ptr<PhysicsManager> physicsPointer = std::make_shared<PhysicsManager>(physicsManager);
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
    obj->SetPhysicsManager(physicsPointer);

    // create circle
    auto obj1 = std::make_shared<GameObject>();
    Point point1{200, 600};
    Transform trs1{point1, 0, 1};
    auto body1 = std::make_shared<RigidBody>(10, 1, BodyType::dynamicBody);
    auto collider1 = std::make_shared<CircleCollider>();
    collider1->Radius(25);
    obj1->AddComponent(body1);
    obj1->AddComponent(collider1);
    obj1->SetTransform(trs1);
    obj1->SetTag("circle");
    obj1->SetPhysicsManager(physicsPointer);

    // create floor
    auto obj3 = std::make_shared<GameObject>();
    Point point3{0, 20};
    Transform trs3{point3, 0, 1};
    auto body3 = std::make_shared<RigidBody>(10, 1, BodyType::dynamicBody);
    auto collider3 = std::make_shared<BoxCollider>();
    collider3->Width(800);
    collider3->Height(20);
    obj3->AddComponent(body3);
    obj3->AddComponent(collider3);
    obj3->SetTransform(trs3);
    obj3->SetTag("floor");
    obj3->SetPhysicsManager(physicsPointer);

    // create floor
    auto obj2 = std::make_shared<GameObject>();
    Point point2{0, 0};
    Transform trs2{point2, 0, 1};
    auto body2 = std::make_shared<RigidBody>(10, 1, BodyType::staticBody);
    auto collider2 = std::make_shared<BoxCollider>();
    collider2->Width(800);
    collider2->Height(20);
    obj2->AddComponent(body2);
    obj2->AddComponent(collider2);
    obj2->SetTransform(trs2);
    obj2->SetTag("floor");
    obj2->SetPhysicsManager(physicsPointer);

    objects.push_back(obj);
    objects.push_back(obj1);
    objects.push_back(obj2);
//    objects.push_back(obj3);
    physicsManager.CreateWorld(objects);
    physicsManager.AddForce(obj1, 20, 0);
    physicsManager.SetDebug(true);
    while (true)
    {
        physicsManager.Step();
    }
    std::cout << "Sandbox" << std::endl;
    return 1;
}