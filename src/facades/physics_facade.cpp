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
#include "circle_collider.hpp"
#include "box_collider.hpp"

PhysicsFacade::PhysicsFacade() {
}

void PhysicsFacade::MakeBody(std::shared_ptr<GameObject> game_object) {
    b2BodyDef bodyDef;
    auto rigidbody = (*game_object).GetComponent<RigidBody>();
    if (rigidbody->GetBodyType() == BodyType::staticBody)
        bodyDef.type = b2_staticBody;
    if (rigidbody->GetBodyType() == BodyType::dynamicBody)
        bodyDef.type = b2_dynamicBody;
    if (rigidbody->GetBodyType() == BodyType::kinematicBody)
        bodyDef.type = b2_kinematicBody;
    bodyDef.allowSleep = true;
    auto transform = (*game_object).GetComponent<Transform>();
    bodyDef.position.Set(static_cast<float>(transform->position.x), static_cast<float>(transform->position.y));
    bodyDef.angle = static_cast<float>(transform->rotation);
    auto body = world->CreateBody(&bodyDef);
    bodies.insert(std::pair<std::shared_ptr<GameObject>, b2Body *>(game_object, body));
}

void PhysicsFacade::PopulateWorld(std::vector<std::shared_ptr<GameObject>> game_objects) {
    //// PhysicsFacade receives a list of gameobjects that contain a rigidbody
    //// create the world where the bodies will be placed
    b2Vec2 gravity(0, -9.8);
    world = std::make_unique<b2World>(gravity);

    //// create a b2body for every gameobject
    for (auto &game_object: game_objects) {
        MakeBody(game_object);
    }

    //// add fixtures for every body
    for (auto object_pair = bodies.begin(); object_pair != bodies.end(); ++object_pair) {
        auto game_object = object_pair->first;
        auto body = object_pair->second;

        //// create circles
        for (auto &circleCollider: game_object->GetComponents<CircleCollider>()) {
            b2CircleShape circleShape{};
            circleShape.m_radius = static_cast<float>(circleCollider->Radius());
            double area = game_object->GetComponent<RigidBody>()->GetBodyType() != BodyType::staticBody ? ((circleCollider->Radius() * circleCollider->Radius()) * 2) : 0.0f;
            SetFixture(body, &circleShape, game_object->GetComponent<RigidBody>(), area);
        }

        //// create boxes
        for (auto &boxCollider: game_object->GetComponents<BoxCollider>()) {
            b2PolygonShape boxShape{};
            boxShape.SetAsBox(static_cast<float>(boxCollider->Width() / 2.0), static_cast<float>(boxCollider->Height()));
            double area = game_object->GetComponent<RigidBody>()->GetBodyType() != BodyType::staticBody ? (boxCollider->Width() * boxCollider->Height()) : 0.0f;
            SetFixture(body, &boxShape, game_object->GetComponent<RigidBody>(), area);
        }
    }
}

void PhysicsFacade::Step() {

}

void PhysicsFacade::SetFixture(b2Body *body, b2Shape *shape, const std::shared_ptr<RigidBody> &rigidBody, double area) {
    b2FixtureDef fixtureDef{};
    fixtureDef.shape = shape;

    if (rigidBody->GetBodyType() != BodyType::staticBody)
    {
        fixtureDef.density = (float) rigidBody->GetMass() / (float) area;
    }
    else
    {
        fixtureDef.density = 0.0f;
    }

    body->CreateFixture(&fixtureDef);
}


