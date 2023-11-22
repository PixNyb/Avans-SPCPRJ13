//
// Created by Eigenaar on 22-11-2023.
//

#include "collider_behavior_test.hpp"

#include <utility>

void ColliderBehaviorTest::OnTriggerEnter2D(const Collider &collider)
{
    std::cout << "behavior executed" << std::endl;
    physicsManager.lock()->AddForce(parent.lock(), 40, 0);
}

void ColliderBehaviorTest::OnTriggerExit2D(const Collider &collider) {}

void ColliderBehaviorTest::OnTriggerStay2D(const Collider &collider) {}

ColliderBehaviorTest::ColliderBehaviorTest(std::weak_ptr<PhysicsManager> physicsManagerPointer,
                                           std::weak_ptr<GameObject> parent)
{
    this->physicsManager = std::move(physicsManagerPointer);
    this->parent = std::move(parent);
}
