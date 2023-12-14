/**
 * @file pathfinding.cpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the Pathfinding class implementation.
 * @version 0.1
 * @date 2023-12-13
 *
 * @copyright Copyright (c) 2023
 */

#include "pathfinding.hpp"
#include "engine.hpp"
#include "pathfinding_manager.hpp"
#include "physics_manager.hpp"
#include "sprite.hpp"
#include "vector2d.hpp"
#include <iostream>

Pathfinding::Pathfinding(std::shared_ptr<GameObject> parent, std::shared_ptr<GameObject> target)
    : BehaviourScript(), _parent(parent), _target(target)
{
}

Pathfinding::Pathfinding(const Pathfinding &other)
    : BehaviourScript(other), _parent(other._parent), _target(other._target)
{
}

std::shared_ptr<Component> Pathfinding::Clone(std::weak_ptr<GameObject> parent)
{
    return std::make_shared<Pathfinding>(Pathfinding(*this));
}

void Pathfinding::OnStart()
{
    auto pathfindingManager = Engine::GetInstance()->Get<PathfindingManager>();
    if (pathfindingManager == nullptr)
        return;

    // Why are both the positions 0,0?
    _path = pathfindingManager->GetPath(_parent->GetTransform().position,
                                        _target->GetTransform().position);

    this->hasStarted = true;
}

void Pathfinding::OnUpdate()
{
    // Move the parent to the next node in the path
    if (_path.size() > 0)
    {
        auto nextNode = _path[0];
        auto parentPosition = _parent->GetTransform().position;
        auto physicsManager = Engine::GetInstance()->Get<PhysicsManager>();

        // Check if the parent is close enough to the next node
        if (nextNode->DistanceTo(parentPosition) < 1)
        {
            // Remove the node from the path
            _path.erase(_path.begin());

            // Check if the path is empty
            if (_path.size() == 0)
                return;

            // Get the next node
            nextNode = _path[0];
        }

        // Move the parent towards the next node
        auto direction = nextNode->GetPosition() - parentPosition;
        auto vector = Vector2D(direction.x, direction.y);
        vector.Normalize();
        std::cout << "Direction: " << vector.x << ", " << vector.y << std::endl;

        // If the direction is to the left, flip the sprite
        if (direction.x < 0)
        {
            auto sprite = _parent->GetComponent<Sprite>();
            sprite->FlipSprite(true, false);
        }
        else
        {
            auto sprite = _parent->GetComponent<Sprite>();
            sprite->FlipSprite(false, false);
        }

        // Using the physicsmanager produces errors since it can't find the parent's body2d
        // instance.
        physicsManager->UpdateVelocity(_parent, vector.x * 10, vector.y * 10);
    }
}