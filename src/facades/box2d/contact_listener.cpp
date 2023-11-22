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
    std::string tag = "empty";
    std::string tag2 = "empty";

    for (auto &pair: gameObjects) {
        if (pair.second->GetPosition().x == bodyA->GetPosition().x && pair.second->GetPosition().y == bodyA->GetPosition().y) {
            tag = pair.first->GetTag();
        }
        else if (pair.second->GetPosition().x == bodyB->GetPosition().x && pair.second->GetPosition().y == bodyB->GetPosition().y)
            tag2 = pair.first->GetTag();
    }
    std::cout << tag << " is touching " << tag2 << std::endl;

}

void ContactListener::EndContact(b2Contact* contact) {
    std::cout << "end contact" << std::endl;
}

ContactListener::ContactListener(std::map<std::shared_ptr<GameObject>, b2Body *> gameObjects) {
    this->gameObjects = std::move(gameObjects);
}

