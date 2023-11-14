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
#include <SDL.h>
#include "debug_renderer.hpp"

const float TimeStep = 1.0f / 60.0f;
const int32 VelocityIterations = 12;
const int32 PositionIterations = 4;
const int TimeIterations = 60;
const double PixelScale = 0.5;
const double GravityScale = 10.0;

PhysicsFacade::PhysicsFacade() = default;

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
    auto transform = (*game_object).GetTransform();
    bodyDef.position.Set(static_cast<float>(transform.position.x) * PixelScale, static_cast<float>(transform.position.y) * PixelScale);
    bodyDef.angle = static_cast<float>(transform.rotation) * b2_pi / 180;
    auto body = world->CreateBody(&bodyDef);
    bodies.insert(std::pair<std::shared_ptr<GameObject>, b2Body *>(game_object, body));
}

void PhysicsFacade::PopulateWorld(std::vector<std::shared_ptr<GameObject>> game_objects) {
    //// PhysicsFacade receives a list of gameobjects that contain a rigidbody
    //// create the world where the bodies will be placed
    b2Vec2 gravity(0.0f, -9.8f);
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
            circleShape.m_radius = static_cast<float>(circleCollider->Radius() * PixelScale);
            double area = game_object->GetComponent<RigidBody>()->GetBodyType() != BodyType::staticBody ? ((circleCollider->Radius() * circleCollider->Radius()) * 2) : 0.0f;
            SetFixture(body, &circleShape, game_object->GetComponent<RigidBody>(), area);
        }

        //// create boxes
        for (auto &boxCollider: game_object->GetComponents<BoxCollider>()) {
            b2PolygonShape boxShape{};
            boxShape.SetAsBox(static_cast<float>(boxCollider->Width() / 2.0 * PixelScale), static_cast<float>(boxCollider->Height() / 2.0 * PixelScale));
            double area = game_object->GetComponent<RigidBody>()->GetBodyType() != BodyType::staticBody ? (boxCollider->Width() * boxCollider->Height()) : 0.0f;
            SetFixture(body, &boxShape, game_object->GetComponent<RigidBody>(), area);
        }
    }

    //// set
}

void PhysicsFacade::Step() {
    //// run physics world
    world->Step(TimeStep, VelocityIterations, PositionIterations);
    world->DebugDraw();
    //// update all gameobjects
    for (auto object_pair = bodies.begin(); object_pair != bodies.end(); ++object_pair) {
        auto game_object = object_pair->first;
        auto body = object_pair->second;
        auto oldTransform =  game_object->GetTransform();

        for (const auto& boxCollider: game_object->GetComponents<BoxCollider>())
        {
            oldTransform.position.x += (body->GetPosition().x / PixelScale) - game_object->GetTransform().position.x;
            oldTransform.position.y += (body->GetPosition().y / PixelScale) - game_object->GetTransform().position.y;
            oldTransform.rotation = (body->GetAngle() * 180 / b2_pi);
            game_object->SetTransform(oldTransform);
        }

        for (const auto& circleCollider: game_object->GetComponents<CircleCollider>())
        {
            oldTransform.position.x += (body->GetPosition().x / PixelScale) - game_object->GetTransform().position.x;
            oldTransform.position.y += (body->GetPosition().y / PixelScale) - game_object->GetTransform().position.y;
            oldTransform.rotation = (body->GetAngle() * 180 / b2_pi);
            game_object->SetTransform(oldTransform);
        }
    }
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

void PhysicsFacade::ShowDebug() {
    DebugRenderer dr;
    CreateGround();
    dr.Run(std::move(world));
}

void PhysicsFacade::CreateGround() {
    // Define the ground body
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, 100.0f); // Set the position of the ground body
    groundBodyDef.type = b2BodyType::b2_staticBody;
    // Create the ground body
    b2Body* groundBody = world->CreateBody(&groundBodyDef);

    // Define the ground shape (as a static box)
    b2PolygonShape groundBox;
    groundBox.SetAsBox(5000.0f, 1.0f); // Set the dimensions of the ground box

    // Create the ground fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &groundBox;

    // Attach the fixture to the ground body
    groundBody->CreateFixture(&fixtureDef);
}

PhysicsFacade::~PhysicsFacade() = default;

