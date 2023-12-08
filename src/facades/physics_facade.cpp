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
#include "box_collider.hpp"
#include "circle_collider.hpp"
#include "contact_listener.hpp"
#include "time.hpp"
#include <algorithm>
#include <utility>

const float TimeStep = 1.0f / 60.0f;
const int VelocityIterations = 12;
const int PositionIterations = 4;
const double MeterToPixel = 5;
const double PixelToMeter = 1 / MeterToPixel;
DebugRenderer debugRenderer;
std::vector<std::shared_ptr<GameObject>> newObjects;

PhysicsFacade::PhysicsFacade() { DEBUG = false; }

void PhysicsFacade::MakeBody(std::shared_ptr<GameObject> gameObject)
{
    b2BodyDef bodyDef;
    auto rigidbody = (*gameObject).GetComponent<RigidBody>();
    // set the body type
    if (rigidbody->GetBodyType() == BodyType::staticBody)
        bodyDef.type = b2_staticBody;
    if (rigidbody->GetBodyType() == BodyType::dynamicBody)
        bodyDef.type = b2_dynamicBody;
    if (rigidbody->GetBodyType() == BodyType::kinematicBody)
        bodyDef.type = b2_kinematicBody;
    bodyDef.allowSleep = true;
    auto transform = (*gameObject).GetTransform();
    // check for boxcollider or circlecollider and set its body position
    if ((*gameObject).GetComponent<BoxCollider>())
        bodyDef.position.Set(
            static_cast<float>(transform.position.x +
                               (*gameObject).GetComponent<BoxCollider>()->Width() / 2) *
                PixelToMeter,
            static_cast<float>(
                -(transform.position.y + (*gameObject).GetComponent<BoxCollider>()->Height() / 2)) *
                PixelToMeter);
    else
    {
        bodyDef.position.Set(
            static_cast<float>(transform.position.x +
                               (*gameObject).GetComponent<CircleCollider>()->Radius()) *
                PixelToMeter,
            static_cast<float>(
                -(transform.position.y + (*gameObject).GetComponent<CircleCollider>()->Radius())) *
                PixelToMeter);
    }
    // add the angle and insert the gameobject-body pair into the bodies list
    bodyDef.angle = static_cast<float>(transform.rotation);
    auto body = world->CreateBody(&bodyDef);
    body->SetGravityScale(rigidbody->GetGravityScale());
    bodies.insert(std::pair<std::shared_ptr<GameObject>, b2Body *>(gameObject, body));
}

void PhysicsFacade::PopulateWorld(std::vector<std::shared_ptr<GameObject>> gameObjects)
{
    if (world != nullptr && newObjects.empty())
    {
        newObjects = std::move(gameObjects);
        return;
    }

    // PhysicsFacade receives a list of gameobjects that contain a rigidbody
    // create the world where the bodies will be placed
    b2Vec2 gravity(0.0f, -9.8f);
    if (world == nullptr)
        world = std::make_unique<b2World>(gravity);

    // create a b2body for every gameobject
    for (auto &gameObject : gameObjects)
    {
        if (gameObject->GetComponent<RigidBody>())
            MakeBody(gameObject);
    }

    // add fixtures for every body
    for (auto object_pair = bodies.begin(); object_pair != bodies.end(); ++object_pair)
    {
        auto game_object = object_pair->first;
        auto body = object_pair->second;

        // create circles
        for (auto &circleCollider : game_object->GetComponents<CircleCollider>())
        {
            b2CircleShape circleShape{};
            circleShape.m_radius = static_cast<float>(circleCollider->Radius() * PixelToMeter);
            double area =
                game_object->GetComponent<RigidBody>()->GetBodyType() != BodyType::staticBody
                    ? ((circleCollider->Radius() * circleCollider->Radius()) * 2)
                    : 0.0f;
            SetFixture(body, &circleShape, game_object->GetComponent<RigidBody>(), area);
        }

        // create boxes
        for (auto &boxCollider : game_object->GetComponents<BoxCollider>())
        {
            b2PolygonShape boxShape{};
            boxShape.SetAsBox(static_cast<float>(boxCollider->Width() / 2 * PixelToMeter),
                              static_cast<float>(boxCollider->Height() / 2 * PixelToMeter));
            double area =
                game_object->GetComponent<RigidBody>()->GetBodyType() != BodyType::staticBody
                    ? (boxCollider->Width() * boxCollider->Height())
                    : 0.0f;
            SetFixture(body, &boxShape, game_object->GetComponent<RigidBody>(), area);
        }
    }

    auto *contactListener = new ContactListener(bodies);
    world->SetContactListener(contactListener);
}

void PhysicsFacade::Step()
{
    double delta = std::clamp(Time::GetDeltaTime(), 0.0001, 2.0);
    double time = delta * Time::TimeScale() * 100 * (TimeStep);
    // run physics world
    // check if a new world has been requested

    // if not delete all the bodies that have been flagged for delete
    DeleteBodies();
    world->Step(static_cast<float>(time), VelocityIterations, PositionIterations);
    if (!newObjects.empty())
    {
        // if so, clear the bodies from the map and set them again with the new objects
        for (auto &pair : bodies)
            world->DestroyBody(pair.second);
        bodies.clear();
        PopulateWorld(newObjects);
        newObjects.clear();
    }
    // update all gameobjects
    for (auto object_pair = bodies.begin(); object_pair != bodies.end(); ++object_pair)
    {
        auto gameObject = object_pair->first;
        auto body = object_pair->second;
        auto bodyPos = body->GetPosition();
        if (gameObject->GetComponent<RigidBody>()->GetBodyType() == BodyType::dynamicBody ||
            gameObject->GetComponent<RigidBody>()->GetBodyType() == BodyType::kinematicBody)
        {
            auto oldTransform = gameObject->GetTransform();
            if (gameObject->GetComponent<BoxCollider>())
            {
                oldTransform.position.x = bodyPos.x * MeterToPixel -
                                          (gameObject->GetComponent<BoxCollider>()->Width() / 2);
                oldTransform.position.y = -bodyPos.y * MeterToPixel -
                                          (gameObject->GetComponent<BoxCollider>()->Height() / 2);
            }
            else
            {
                oldTransform.position.x = bodyPos.x * MeterToPixel;
                oldTransform.position.y = -bodyPos.y * MeterToPixel;
            }
            oldTransform.rotation = (body->GetAngle() * 180 / b2_pi);
            gameObject->SetTransform(oldTransform);
        }
    }
    if (DEBUG)
    {
        if (!debugRenderer.running)
            debugRenderer.Start();
        ShowDebug();
    }
}

void PhysicsFacade::SetFixture(b2Body *body, b2Shape *shape,
                               const std::shared_ptr<RigidBody> &rigidBody, double area)
{
    b2FixtureDef fixtureDef{};
    fixtureDef.shape = shape;
    if (rigidBody->GetBodyType() != BodyType::staticBody)
        fixtureDef.density = (float)rigidBody->GetMass() / (float)area;
    else
        fixtureDef.density = 0.0f;

    body->CreateFixture(&fixtureDef);
}

void PhysicsFacade::ShowDebug() { debugRenderer.Render(bodies); }

b2Body *PhysicsFacade::GetBodyByObject(const std::shared_ptr<GameObject> &gameObject)
{
    for (auto &pair : bodies)
    {
        if (pair.first->GetTransform().position.x == gameObject->GetTransform().position.x &&
            pair.first->GetTransform().position.y == gameObject->GetTransform().position.y)
            return pair.second;
    }
    return nullptr;
}

void PhysicsFacade::DestroyBody(const std::shared_ptr<GameObject> &gameObject)
{
    auto iterator = bodies.find(gameObject);
    if (b2Body *body = GetBodyByObject(gameObject))
    {
        world->DestroyBody(body);
    }
}

void PhysicsFacade::AddForce(const std::shared_ptr<GameObject> &gameObject, float vx, float vy)
{
    float newVX = vx * 100;
    float newVY = vy * 100;
    if (b2Body *body = GetBodyByObject(gameObject))
    {
        body->ApplyForce(b2Vec2(newVX, newVY), body->GetWorldCenter(), true);
    }
}

void PhysicsFacade::AddLinearImpulse(const std::shared_ptr<GameObject> &gameObject, float vx,
                                     float vy)
{
    float newVX = vx;
    float newVY = vy;
    b2Body *body = GetBodyByObject(gameObject);
    body->ApplyLinearImpulse(b2Vec2(newVX, newVY), body->GetWorldCenter(), true);
}

void PhysicsFacade::AddRotation(const std::shared_ptr<GameObject> &gameObject, float amount)
{
    b2Body *body = GetBodyByObject(gameObject);
    body->ApplyAngularImpulse(amount, false);
}

void PhysicsFacade::Sleep(const std::shared_ptr<GameObject> &gameObject)
{
    b2Body *body = GetBodyByObject(gameObject);
    body->SetAwake(false);
}

void PhysicsFacade::Wake(const std::shared_ptr<GameObject> &gameObject)
{
    b2Body *body = GetBodyByObject(gameObject);
    body->SetAwake(true);
}
void PhysicsFacade::UpdatePosition(const std::shared_ptr<GameObject> &gameObject, double xPos,
                                   double yPos)
{
    b2Body *body = GetBodyByObject(gameObject);
    body->SetTransform(b2Vec2(static_cast<float>(xPos), static_cast<float>(yPos)),
                       body->GetTransform().q.GetAngle());
}
void PhysicsFacade::UpdateRotation(const std::shared_ptr<GameObject> &gameObject, double rotation)
{
    b2Body *body = GetBodyByObject(gameObject);
    body->SetTransform(b2Vec2(body->GetTransform().p.x, body->GetTransform().p.y),
                       static_cast<float>(rotation));
}
void PhysicsFacade::UpdateVelocity(const std::shared_ptr<GameObject> &gameObject, double vX,
                                   double vY)
{
    b2Body *body = GetBodyByObject(gameObject);
    body->SetLinearVelocity(b2Vec2(static_cast<float>(vX), static_cast<float>(vY)));
}
void PhysicsFacade::DeleteBodies()
{
    std::vector<std::shared_ptr<GameObject>> delBodies;
    for (auto i = bodies.begin(); i != bodies.end(); i++)
    {
        if (!i->first->HasPhysics())
        {
            delBodies.push_back(i->first);
            world->DestroyBody(i->second);
        }
    }
    for (auto &object : delBodies)
    {
        bodies.erase(object);
    }
}

Point PhysicsFacade::GetVelocity(const std::shared_ptr<GameObject> &gameObject)
{
    b2Body *body = GetBodyByObject(gameObject);
    auto velocity = body->GetLinearVelocity();
    return {velocity.x, velocity.y};
}

PhysicsFacade::~PhysicsFacade() = default;
