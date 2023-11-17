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
#include "circle_collider.hpp"
#include "polygon_collider.hpp"
#include <iostream>
#include <memory>

int main(int argc, char *argv[])
{
    std::vector<std::shared_ptr<GameObject>> objects;

    //// create box
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

    //// create circle
    auto obj1 = std::make_shared<GameObject>();
    Point point1{800, 1000};
    Transform trs1{point1, 0, 1};
    auto body1 = std::make_shared<RigidBody>(10, 1, BodyType::dynamicBody);
    auto collider1 = std::make_shared<CircleCollider>();
    collider1->Radius(25);
    obj1->AddComponent(body1);
    obj1->AddComponent(collider1);
    obj1->SetTransform(trs1);

    //// create polygon
    auto obj3 = std::make_shared<GameObject>();
    Point point3{900, 1000};
    Transform trs3{point3, 0, 1};
    auto body3 = std::make_shared<RigidBody>(10, 1, BodyType::staticBody);
    auto collider3 = std::make_shared<PolygonCollider>();
    std::vector<Point> vertices;
    vertices.emplace_back(0, 0);
    vertices.emplace_back(100, 40);
    vertices.emplace_back(200, 50);
    vertices.emplace_back(400, 80);
    vertices.emplace_back(700, 40);
    vertices.emplace_back(2000, 0);
    vertices.emplace_back(0, 0);
    collider3->Vertices(vertices);
    obj3->AddComponent(body3);
    obj3->AddComponent(collider3);
    obj3->SetTransform(trs3);

    //// create floor
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
    objects.push_back(obj3);
    PhysicsManager physicsManager;
    physicsManager.CreateWorld(objects);
    physicsManager.AddForce(obj1, 20, 0);
    while (true) {
        physicsManager.Step();
    }
    std::cout << "Sandbox" << std::endl;
    //    auto engine = Engine::getInstance();

    return 1;
}