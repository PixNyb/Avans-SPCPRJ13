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

const double MeterToPixel = 50;
const double PixelToMeter = 1/MeterToPixel;

void ContactListener::BeginContact(b2Contact* contact) {
    auto bodyA = contact->GetFixtureA()->GetBody();
    auto bodyB = contact->GetFixtureB()->GetBody();

    for (auto &gameObject: gameObjects) {
        if (bodyA->GetPosition().x * MeterToPixel == gameObject->GetTransform().position.x && bodyA->GetPosition().y * MeterToPixel == gameObject->GetTransform().position.y) {
            std::string tag = "empty";
            for (auto &gameObject2: gameObjects) {
                if (bodyB->GetPosition().x * MeterToPixel == gameObject2->GetTransform().position.x && bodyB->GetPosition().y * MeterToPixel == gameObject2->GetTransform().position.y)
                    tag = gameObject2->GetTag();
            }
            std::cout << gameObject->GetTag() << " is touching " << tag << std::endl;
        }
    }
}

void ContactListener::EndContact(b2Contact* contact) {
    std::cout << "end contact" << std::endl;
}

ContactListener::ContactListener(std::vector<std::shared_ptr<GameObject>> gameObjects) {
    this->gameObjects = std::move(gameObjects);
}
