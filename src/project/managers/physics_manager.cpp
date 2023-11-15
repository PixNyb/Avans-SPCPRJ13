/**
 * @file physics_manager.cpp
 * @author Daan Groot (d.groot3@student.avans.nl)
 * @brief This file contains the PhysicsManager class implementation.
 * @version 0.1
 * @date 2023-11-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "physics_manager.hpp"

#include <utility>

PhysicsManager::PhysicsManager() {

}

void PhysicsManager::CreateWorld(std::vector<std::shared_ptr<GameObject>> game_objects) {
    physicsFacade.PopulateWorld(std::move(game_objects));
}

void PhysicsManager::RemoveBody(std::shared_ptr<GameObject> game_object) {
    physicsFacade.DestroyBody(std::move(game_object));
}

void PhysicsManager::CreateBody(std::shared_ptr<GameObject> game_object) {
    physicsFacade.MakeBody(std::move(game_object));
}

void PhysicsManager::Step() {
    physicsFacade.Step();
}


