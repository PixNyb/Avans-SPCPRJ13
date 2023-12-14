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

void PhysicsManager::CreateWorld(std::vector<std::shared_ptr<GameObject>> gameObjects)
{
    physicsFacade.PopulateWorld(std::move(gameObjects));
}

void PhysicsManager::RemoveBody(const std::shared_ptr<GameObject> &gameObject)
{
    physicsFacade.DestroyBody(gameObject);
}

void PhysicsManager::CreateBody(const std::shared_ptr<GameObject>& object)
{
    std::cout << object->GetName() << std::endl;
    physicsFacade.AddBody(object);
}

void PhysicsManager::Step() { physicsFacade.Step(); }

void PhysicsManager::AddForce(const std::shared_ptr<GameObject> &gameObject, float vx, float vy)
{
    physicsFacade.AddForce(gameObject, vx, vy);
}

void PhysicsManager::AddLinearImpulse(const std::shared_ptr<GameObject> &gameObject, float vx,
                                      float vy)
{
    physicsFacade.AddLinearImpulse(gameObject, vx, vy);
}

void PhysicsManager::AddRotationalForce(const std::shared_ptr<GameObject> &gameObject, float amount)
{
    physicsFacade.AddRotation(gameObject, amount);
}

void PhysicsManager::Sleep(const std::shared_ptr<GameObject> &gameObject)
{
    physicsFacade.Sleep(gameObject);
}

void PhysicsManager::Wake(const std::shared_ptr<GameObject> &gameObject)
{
    physicsFacade.Wake(gameObject);
}

void PhysicsManager::UpdateRotation(const std::shared_ptr<GameObject> &gameObject, double rotation)
{
    physicsFacade.UpdateRotation(gameObject, rotation);
}

void PhysicsManager::UpdatePosition(const std::shared_ptr<GameObject> &gameObject, double xPos,
                                    double yPos)
{
    physicsFacade.UpdatePosition(gameObject, xPos, yPos);
}

void PhysicsManager::UpdateVelocity(const std::shared_ptr<GameObject> &gameObject, double vX,
                                    double vY)
{
    physicsFacade.UpdateVelocity(gameObject, vX, vY);
}
Point PhysicsManager::GetVelocity(const std::shared_ptr<GameObject> &gameObject)
{
    return physicsFacade.GetVelocity(gameObject);
}
