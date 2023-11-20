/**
 * @file physics_test.cpp
 * @author Daan Groot (d.groot3@student.avans.nl)
 * @brief This file tests the general working of the PhysicsManager/PhysicsFacade
 * @version 0.1
 * @date 2023-11-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "box_collider.hpp"
#include "circle_collider.hpp"
#include "game_object.hpp"
#include "physics_manager.hpp"
#include "rigidbody.hpp"
#include "gtest/gtest.h"
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

TEST(PhysicsTest, TestPhysics)
{
    std::vector<std::shared_ptr<GameObject>> objects;

    // create box
    auto obj = std::make_shared<GameObject>();
    Point point{600, 1000};
    Transform trs{point, 0, 1};
    auto body = std::make_shared<RigidBody>(10, 1, BodyType::dynamicBody);
    auto collider = std::make_shared<BoxCollider>();
    collider->Width(50);
    collider->Height(50);
    obj->AddComponent(body);
    obj->AddComponent(collider);
    obj->SetTransform(trs);

    // create circle
    auto obj1 = std::make_shared<GameObject>();
    Point point1{800, 1000};
    Transform trs1{point1, 0, 1};
    auto body1 = std::make_shared<RigidBody>(10, 1, BodyType::dynamicBody);
    auto collider1 = std::make_shared<CircleCollider>();
    collider1->Radius(25);
    obj1->AddComponent(body1);
    obj1->AddComponent(collider1);
    obj1->SetTransform(trs1);

    // create floor
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
    objects.push_back(obj1);
    objects.push_back(obj2);
    PhysicsManager physicsManager;
    physicsManager.CreateWorld(objects);
    //physicsManager.AddForce(obj1, 20, 0);

    bool running = true;
    int stepCounter = 0;
    while (running)
    {
        if (stepCounter == 500)
            running = false;
        physicsManager.Step();
        ++stepCounter;
    }

    EXPECT_EQ(obj->GetTransform().position.x, 600);
    EXPECT_LT(obj->GetTransform().position.y, 1000);
    EXPECT_GT(obj1->GetTransform().position.x, 800);
    EXPECT_LT(obj1->GetTransform().position.x, 820);
    EXPECT_LT(obj1->GetTransform().position.y, 1000);
    EXPECT_EQ(obj2->GetTransform().position.x, 0);
    EXPECT_EQ(obj2->GetTransform().position.y, 40);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
