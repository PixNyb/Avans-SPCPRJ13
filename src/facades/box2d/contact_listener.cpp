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
    std::string tag1 = "empty";
    std::string tag2 = "empty";
    std::shared_ptr<GameObject> gameObjectA;
    std::shared_ptr<GameObject> gameObjectB;

    for (auto &pair: gameObjects) {
        if (pair.second == bodyA) {
            tag1 = pair.first->GetTag();
            gameObjectA = pair.first;
        }
        else if (pair.second == bodyB)
            tag2 = pair.first->GetTag();
            gameObjectA = pair.first;
    }
    std::cout << tag1 << " is touching " << tag2 << std::endl;

    //activate the OnTriggerEnter2D() from behavior script on both sides

}

void ContactListener::EndContact(b2Contact* contact) {
    auto bodyA = contact->GetFixtureA()->GetBody();
    auto bodyB = contact->GetFixtureB()->GetBody();
    std::string tag1 = "empty";
    std::string tag2 = "empty";
    std::shared_ptr<GameObject> gameObjectA;
    std::shared_ptr<GameObject> gameObjectB;

    for (auto &pair: gameObjects) {
        if (pair.second == bodyA) {
            tag1 = pair.first->GetTag();
            gameObjectA = pair.first;
        }
        else if (pair.second == bodyB)
            tag2 = pair.first->GetTag();
            gameObjectB = pair.first;
    }
    std::cout << tag1 << " stopped touching " << tag2 << std::endl;

    //activate the OnTriggerExit2D() from behavior script on both sides

}

ContactListener::ContactListener(std::map<std::shared_ptr<GameObject>, b2Body *> gameObjects) {
    this->gameObjects = std::move(gameObjects);
}

