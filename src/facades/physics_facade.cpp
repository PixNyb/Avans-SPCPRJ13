/**
 * @file physicsfacade.cpp
 * @author Daan Groot (d.groot3@student.avans.nl)
 * @brief This file contains the PhysicsFacade class implementation.
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
#include "debug_renderer.hpp"
#include "polygon_collider.hpp"
#include "contact_listener.hpp"

const float TimeStep = 1.0f / 240.0f;
const int VelocityIterations = 12;
const int PositionIterations = 4;
const double MeterToPixel = 50;
const double PixelToMeter = 1/MeterToPixel;
DebugRenderer debugRenderer;

PhysicsFacade::PhysicsFacade() {
    DEBUG = false;
}

void PhysicsFacade::MakeBody(std::shared_ptr<GameObject> gameObject) {
    b2BodyDef bodyDef;
    auto rigidbody = (*gameObject).GetComponent<RigidBody>();
    if (rigidbody->GetBodyType() == BodyType::staticBody)
        bodyDef.type = b2_staticBody;
    if (rigidbody->GetBodyType() == BodyType::dynamicBody)
        bodyDef.type = b2_dynamicBody;
    if (rigidbody->GetBodyType() == BodyType::kinematicBody)
        bodyDef.type = b2_kinematicBody;
    bodyDef.allowSleep = true;
    auto transform = (*gameObject).GetTransform();
    bodyDef.position.Set(static_cast<float>(transform.position.x) * PixelToMeter,
                         static_cast<float>(transform.position.y) * PixelToMeter);
    bodyDef.angle = static_cast<float>(transform.rotation);
    auto body = world->CreateBody(&bodyDef);
    bodies.insert(std::pair<std::shared_ptr<GameObject>, b2Body *>(gameObject, body));
}

std::vector<std::shared_ptr<GameObject>> PhysicsFacade::GetAllGameObjects() {
    std::vector<std::shared_ptr<GameObject>> gameObjects;
    for (const auto& pair : bodies) {
        gameObjects.push_back(pair.first);
    }

    return gameObjects;
}

void PhysicsFacade::PopulateWorld(std::vector<std::shared_ptr<GameObject>> gameObjects) {
    // PhysicsFacade receives a list of gameobjects that contain a rigidbody
    // create the world where the bodies will be placed
    b2Vec2 gravity(0.0f, -9.8f);
    world = std::make_unique<b2World>(gravity);

    // create a b2body for every gameobject
    for (auto &gameObject: gameObjects) {
        MakeBody(gameObject);
    }

    // add fixtures for every body
    for (auto object_pair = bodies.begin(); object_pair != bodies.end(); ++object_pair) {
        auto game_object = object_pair->first;
        auto body = object_pair->second;

        // create circles
        for (auto &circleCollider: game_object->GetComponents<CircleCollider>()) {
            b2CircleShape circleShape{};
            circleShape.m_radius = static_cast<float>(circleCollider->Radius() * PixelToMeter);
            double area = game_object->GetComponent<RigidBody>()->GetBodyType() != BodyType::staticBody ? (
                    (circleCollider->Radius() * circleCollider->Radius()) * 2) : 0.0f;
            SetFixture(body, &circleShape, game_object->GetComponent<RigidBody>(), area);
        }

        // create boxes
        for (auto &boxCollider: game_object->GetComponents<BoxCollider>()) {
            b2PolygonShape boxShape{};
            boxShape.SetAsBox(static_cast<float>(boxCollider->Width() / 2 * PixelToMeter),
                              static_cast<float>(boxCollider->Height() / 2 * PixelToMeter));
            double area = game_object->GetComponent<RigidBody>()->GetBodyType() != BodyType::staticBody ? (
                    boxCollider->Width() * boxCollider->Height()) : 0.0f;
            SetFixture(body, &boxShape, game_object->GetComponent<RigidBody>(), area);
        }
    }

    auto *contactListener = new ContactListener(GetAllGameObjects());
    world->SetContactListener(contactListener);
}

void PhysicsFacade::Step() {
    // run physics world
    world->Step(TimeStep, VelocityIterations, PositionIterations);

    // update all gameobjects
    for (auto object_pair = bodies.begin(); object_pair != bodies.end(); ++object_pair) {
        auto gameObject = object_pair->first;
        auto body = object_pair->second;
        auto oldTransform = gameObject->GetTransform();
        oldTransform.position.x += (body->GetPosition().x * MeterToPixel) - gameObject->GetTransform().position.x;
        oldTransform.position.y += (body->GetPosition().y * MeterToPixel) - gameObject->GetTransform().position.y;
        oldTransform.rotation = (body->GetAngle() * 180 / b2_pi);
        gameObject->SetTransform(oldTransform);
    }
    if (DEBUG) {
        if (!debugRenderer.running)
            debugRenderer.Start();
        ShowDebug();
    }
}

void PhysicsFacade::SetFixture(b2Body *body, b2Shape *shape, const std::shared_ptr<RigidBody> &rigidBody, double area) {
    b2FixtureDef fixtureDef{};
    fixtureDef.shape = shape;

    if (rigidBody->GetBodyType() != BodyType::staticBody)
        fixtureDef.density = (float) rigidBody->GetMass() / (float) area;
    else
        fixtureDef.density = 0.0f;

    body->CreateFixture(&fixtureDef);
}

void PhysicsFacade::ShowDebug() {
    debugRenderer.Render(bodies);
}

void PhysicsFacade::DestroyBody(const std::shared_ptr<GameObject> &gameObject) {
    auto iterator = bodies.find(gameObject);
    if (iterator != bodies.end())
        world->DestroyBody(bodies.at(gameObject));
}

void PhysicsFacade::AddForce(const std::shared_ptr<GameObject> &gameObject, float vx, float vy) {
    float newVX = vx * 100;
    float newVY = vy * 100;
    auto iterator = bodies.find(gameObject);
    if (iterator != bodies.end()) {
        bodies.at(gameObject)->ApplyForce(b2Vec2(newVX, newVY), bodies.at(gameObject)->GetWorldCenter(), true);
    }
}

void PhysicsFacade::AddRotation(const std::shared_ptr<GameObject> &gameObject, float amount) {
    auto iterator = bodies.find(gameObject);
    if (iterator != bodies.end()) {
        bodies.at(gameObject)->ApplyAngularImpulse(amount, false);
    }
}

void PhysicsFacade::Sleep(const std::shared_ptr<GameObject> &gameObject) {
    auto iterator = bodies.find(gameObject);
    if (iterator != bodies.end()) {
        bodies.at(gameObject)->SetAwake(false);
    }
}

void PhysicsFacade::Wake(const std::shared_ptr<GameObject> &gameObject) {
    auto iterator = bodies.find(gameObject);
    if (iterator != bodies.end()) {
        bodies.at(gameObject)->SetAwake(true);
    }
}

PhysicsFacade::~PhysicsFacade() = default;

