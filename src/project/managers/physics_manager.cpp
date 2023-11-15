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

void PhysicsManager::CreateWorld(std::vector<std::shared_ptr<GameObject>> gameObjects) {
    physicsFacade.PopulateWorld(std::move(gameObjects));
}

void PhysicsManager::RemoveBody(std::shared_ptr<GameObject> gameObject) {
    physicsFacade.DestroyBody(std::move(gameObject));
}

void PhysicsManager::CreateBody(std::shared_ptr<GameObject> gameObject) {
    physicsFacade.MakeBody(std::move(gameObject));
}

void PhysicsManager::Step() {
    physicsFacade.Step();
}

void PhysicsManager::AddForce(std::shared_ptr<GameObject> gameObject, float vx, float vy) {
    physicsFacade.AddForce(gameObject, vx, vy);
}


