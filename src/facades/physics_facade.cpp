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

PhysicsFacade::PhysicsFacade(std::vector<std::shared_ptr<GameObject>> &game_objects) {
    this->game_objects = game_objects;
}

void PhysicsFacade::PopulateWorld() {
    b2Vec2 gravity(0, -9.8);
    bool doSleep = true;
    world = std::make_unique<b2World>(gravity);
}
