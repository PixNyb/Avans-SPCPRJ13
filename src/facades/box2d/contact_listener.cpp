/**
 * @file contact_listener.cpp
 * @author Daan Groot (d.groot3@student.avans.nl)
 * @brief This file contains the implementation of the class ContactListener
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "contact_listener.hpp"
#include "behaviour_script.hpp"
#include "box_collider.hpp"
#include "circle_collider.hpp"
#include <utility>

const double MeterToPixel = 50;
const double PixelToMeter = 1 / MeterToPixel;

void ContactListener::BeginContact(b2Contact *contact)
{
    // to make an object bounce you can set the contact restitution
    //    contact->SetRestitution(0.005);
    auto bodyA = contact->GetFixtureA()->GetBody();
    auto bodyB = contact->GetFixtureB()->GetBody();
    std::shared_ptr<GameObject> gameObjectA = FindGameObject(bodyA);
    std::shared_ptr<GameObject> gameObjectB = FindGameObject(bodyB);

    // activate the OnTriggerEnter2D() from behavior script on both sides
    for (auto &script : gameObjectA->GetComponents<BehaviourScript>())
    {
        if (gameObjectA->GetComponent<BoxCollider>())
            script->OnTriggerEnter2D(*gameObjectA->GetComponent<BoxCollider>());
        else
            script->OnTriggerEnter2D(*gameObjectA->GetComponent<CircleCollider>());
    }
    for (auto &script : gameObjectB->GetComponents<BehaviourScript>())
    {
        if (gameObjectB->GetComponent<BoxCollider>())
            script->OnTriggerEnter2D(*gameObjectB->GetComponent<BoxCollider>());
        else
            script->OnTriggerEnter2D(*gameObjectB->GetComponent<CircleCollider>());
    }
}

void ContactListener::EndContact(b2Contact *contact)
{
    auto bodyA = contact->GetFixtureA()->GetBody();
    auto bodyB = contact->GetFixtureB()->GetBody();
    std::shared_ptr<GameObject> gameObjectA = FindGameObject(bodyA);
    std::shared_ptr<GameObject> gameObjectB = FindGameObject(bodyB);

    // activate the OnTriggerExit2D() from behavior script on both sides
    for (auto &script : gameObjectA->GetComponents<BehaviourScript>())
    {
        if (gameObjectA->GetComponent<BoxCollider>())
            script->OnTriggerExit2D(*gameObjectA->GetComponent<BoxCollider>());
        else
            script->OnTriggerExit2D(*gameObjectA->GetComponent<CircleCollider>());
    }
    for (auto &script : gameObjectB->GetComponents<BehaviourScript>())
    {
        if (gameObjectB->GetComponent<BoxCollider>())
            script->OnTriggerExit2D(*gameObjectB->GetComponent<BoxCollider>());
        else
            script->OnTriggerExit2D(*gameObjectB->GetComponent<CircleCollider>());
    }
}

ContactListener::ContactListener(std::map<std::shared_ptr<GameObject>, b2Body *> gameObjects)
{
    this->gameObjects = std::move(gameObjects);
}

std::shared_ptr<GameObject> ContactListener::FindGameObject(b2Body *body)
{
    auto it = std::find_if(gameObjects.begin(), gameObjects.end(),
                           [body](const auto &pair) { return pair.second == body; });
    return (it != gameObjects.end()) ? it->first : nullptr;
}
