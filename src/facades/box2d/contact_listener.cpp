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
#include <iostream>
#include <utility>

void ContactListener::BeginContact(b2Contact* contact) {
    auto bodyA = contact->GetFixtureA()->GetBody();
    auto bodyB = contact->GetFixtureB()->GetBody();

    for (auto &gameObject: gameObjects) {
        if (bodyA->GetPosition().x == gameObject->GetTransform().position.x && bodyA->GetPosition().y == gameObject->GetTransform().position.y) {
            std::cout << gameObject->GetTag() << " is touching something" << std::endl;
        }
        if (bodyB->GetPosition().x == gameObject->GetTransform().position.x && bodyB->GetPosition().y == gameObject->GetTransform().position.y) {
            std::cout << gameObject->GetTag() << " is touching something" << std::endl;
        }
    }
}

void ContactListener::EndContact(b2Contact* contact) {
    std::cout << "end contact" << std::endl;
}

ContactListener::ContactListener(std::vector<std::shared_ptr<GameObject>> gameObjects) {
    this->gameObjects = std::move(gameObjects);
}
