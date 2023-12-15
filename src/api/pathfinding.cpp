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
#include "box_collider.hpp"
#include "engine.hpp"
#include "pathfinding_manager.hpp"
#include "physics_manager.hpp"
#include "point.hpp"
#include "scene_manager.hpp"
#include "sprite.hpp"
#include "vector2d.hpp"
#include <iostream>
#include <memory>

Pathfinding::Pathfinding(std::weak_ptr<GameObject> parent, std::string targetId)
    : BehaviourScript(), _parent(std::move(parent)), _targetId(targetId)
{
}

Pathfinding::Pathfinding(const Pathfinding &other)
    : BehaviourScript(other), _parent(std::move(other._parent)), _targetId(other._targetId)
{
}

std::shared_ptr<Component> Pathfinding::Clone(std::weak_ptr<GameObject> parent)
{
    auto clone = std::make_shared<Pathfinding>(Pathfinding(*this));
    clone->_parent = std::move(parent);
    return clone;
}

void Pathfinding::OnStart()
{
    auto pathfindingManager = Engine::GetInstance()->Get<PathfindingManager>();
    if (pathfindingManager == nullptr)
        return;

    // Get the target gameobject
    auto scene = Engine::GetInstance()->Get<SceneManager>()->GetScene();

    // Find the target gameobject
    for (auto &gameObject : scene.lock()->contents)
        if (gameObject->GetName() == _targetId)
        {
            _target = gameObject;
            break;
        }

    auto parentPosition = _parent.lock()->GetTransform().position;
    auto parentCollider = _parent.lock()->GetComponent<BoxCollider>();
    auto parentBottom = Point(parentCollider->Width() / 2, parentCollider->Height());

    _path = pathfindingManager->GetPath(_parent.lock()->GetTransform().position,
                                        _target.lock()->GetTransform().position);

    this->_targetNode = _path[_path.size() - 1];
    this->hasStarted = true;
}

void Pathfinding::OnUpdate()
{
    // Move the parent to the next node in the path
    auto pathfindingManager = Engine::GetInstance()->Get<PathfindingManager>();
    if (pathfindingManager == nullptr)
        return;

    auto physicsManager = Engine::GetInstance()->Get<PhysicsManager>();
    auto parentPosition = _parent.lock()->GetTransform().position;
    auto parentCollider = _parent.lock()->GetComponent<BoxCollider>();
    auto parentBottom = Point(parentCollider->Width() / 2, parentCollider->Height());
    auto targetPosition = _target.lock()->GetTransform().position;
    auto targetCollider = _target.lock()->GetComponent<BoxCollider>();
    auto targetBottom = Point(targetCollider->Width() / 2, targetCollider->Height());
    auto closestNodeToTarget = pathfindingManager->FindClosestNode(targetPosition + targetBottom);

    if (_targetNode != nullptr && closestNodeToTarget != _targetNode)
    {
        std::cout << "Updating path..." << std::endl;
        _path = pathfindingManager->GetPath(parentPosition, targetPosition);
        _targetNode = _path[_path.size() - 1];
    }

    if (_path.size() > 0)
    {
        auto nextNode = _path[0];

        // Check if the parent is close enough to the next node
        std::cout << "Distance to next node: "
                  << nextNode->DistanceTo(parentPosition + parentBottom) << std::endl;

        if (nextNode->DistanceTo(parentPosition + parentBottom) <= 10)
        {
            // Remove the node from the path
            _path.erase(_path.begin());

            // Check if the path is empty
            if (_path.size() == 0)
            {
                // Set the velocity to 0 when the target is reached
                std::cout << "Target reached!" << std::endl;
                physicsManager->UpdateVelocity(_parent.lock(), 0, 0);
                return;
            }

            // Get the next node
            nextNode = _path[0];
        }

        // Move the parent towards the next node
        auto direction = nextNode->GetPosition() - parentPosition;
        auto vector = Vector2D(-direction.x, direction.y <= 0 ? direction.y : 0);
        vector.Direction();
        std::cout << "Moving towards next node: " << vector.x << ", " << vector.y << std::endl;

        physicsManager->UpdateVelocity(_parent.lock(), -vector.x, -vector.y);
        
    }
}