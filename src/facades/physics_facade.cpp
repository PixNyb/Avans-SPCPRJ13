/**
 * @file physicsfacade.cpp
 * @author Daan Groot (d.groot3@student.avans.nl)
 * @brief This file contains the Collider class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "physics_facade.hpp"
#include "rigidbody.hpp"

PhysicsFacade::PhysicsFacade(std::vector<std::shared_ptr<GameObject>> &game_objects) {
    //// PhysicsFacade receives a list of gameobjects that contain a rigidbody
    this->game_objects = game_objects;
}

void PhysicsFacade::PopulateWorld() {
    //// create the world where the bodies will be placed
    b2Vec2 gravity(0, -9.8);
    bool doSleep = true;
    world = std::make_unique<b2World>(gravity);

    //// create a b2body for every gameobject that has a rigidbody
    for (auto game_object = game_objects.begin(); game_object != game_objects.end(); ++game_object) {
        b2BodyDef bodyDef;
        auto rigidbody = (*game_object)->GetComponent<RigidBody>();
        if (rigidbody->GetBodyType() == BodyType::staticBody)
            bodyDef.type = b2_staticBody;
        if (rigidbody->GetBodyType() == BodyType::dynamicBody)
            bodyDef.type = b2_dynamicBody;
        if (rigidbody->GetBodyType() == BodyType::kinematicBody)
            bodyDef.type = b2_kinematicBody;
        bodyDef.allowSleep = true;
        auto body = world->CreateBody(&bodyDef);
    }
}
