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

void PhysicsManager::CreateBody(std::shared_ptr<GameObject> gameObject)
{
    physicsFacade.MakeBody(std::move(gameObject));
}

void PhysicsManager::Step() { physicsFacade.Step(); }

void PhysicsManager::AddForce(const std::shared_ptr<GameObject> &gameObject, float vx, float vy)
{
    if (!gameObject->HasPhysics())
    {
        return;
    }

    physicsFacade.AddForce(gameObject, vx, vy);
}

void PhysicsManager::AddLinearImpulse(const std::shared_ptr<GameObject> &gameObject, float vx,
                                      float vy)
{
    if (!gameObject->HasPhysics())
    {
        return;
    }
    physicsFacade.AddLinearImpulse(gameObject, vx, vy);
}

void PhysicsManager::AddRotationalForce(const std::shared_ptr<GameObject> &gameObject, float amount)
{
    if (!gameObject->HasPhysics())
    {
        return;
    }
    physicsFacade.AddRotation(gameObject, amount);
}

void PhysicsManager::Sleep(const std::shared_ptr<GameObject> &gameObject)
{
    if (!gameObject->HasPhysics())
    {
        return;
    }
    physicsFacade.Sleep(gameObject);
}

void PhysicsManager::Wake(const std::shared_ptr<GameObject> &gameObject)
{
    if (!gameObject->HasPhysics())
    {
        return;
    }
    physicsFacade.Wake(gameObject);
}

void PhysicsManager::UpdateRotation(const std::shared_ptr<GameObject> &gameObject, double rotation)
{
    if (!gameObject->HasPhysics())
    {
        return;
    }

    physicsFacade.UpdateRotation(gameObject, rotation);
}

void PhysicsManager::UpdatePosition(const std::shared_ptr<GameObject> &gameObject, double xPos,
                                    double yPos)
{
    if (!gameObject->HasPhysics())
    {
        return;
    }

    physicsFacade.UpdatePosition(gameObject, xPos, yPos);
}

void PhysicsManager::UpdateVelocity(const std::shared_ptr<GameObject> &gameObject, double vX,
                                    double vY)
{
    if (!gameObject->HasPhysics())
    {
        return;
    }
    physicsFacade.UpdateVelocity(gameObject, vX, vY);
}
Point PhysicsManager::GetVelocity(const std::shared_ptr<GameObject> &gameObject)
{
    if (!gameObject->HasPhysics())
    {
        return {0, 0};
    }
    return physicsFacade.GetVelocity(gameObject);
}
