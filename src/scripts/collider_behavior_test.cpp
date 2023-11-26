/**
 * @file collider_behavior_test.cpp
 * @author Daan Groot (d.groot3@student.avans.nl)
 * @brief This file contains the PhysicsFacade class implementation.
 * @version 0.1
 * @date 2023-11-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "collider_behavior_test.hpp"

#include <utility>

void ColliderBehaviorTest::OnTriggerEnter2D(const Collider &collider)
{
    std::cout << "behavior executed" << std::endl;
    physicsManager.lock()->AddLinearImpulse(parent.lock(), 0, 20);
}

void ColliderBehaviorTest::OnTriggerExit2D(const Collider &collider) {}

void ColliderBehaviorTest::OnTriggerStay2D(const Collider &collider) {}

ColliderBehaviorTest::ColliderBehaviorTest(std::weak_ptr<PhysicsManager> physicsManagerPointer,
                                           std::weak_ptr<GameObject> parent)
{
    this->physicsManager = std::move(physicsManagerPointer);
    this->parent = std::move(parent);
}
