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
#include "circle.hpp"
#include "core_constants.hpp"
#include "engine.hpp"
#include "pathfinding_manager.hpp"
#include "physics_manager.hpp"
#include "point.hpp"
#include "scene_manager.hpp"
#include "shape_component.hpp"
#include "sprite.hpp"
#include "transform.hpp"
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

    if (_path.size() != 0)
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
    auto parentHeight = _parent.lock()->GetComponent<BoxCollider>()->Height();
    auto parentWidth = _parent.lock()->GetComponent<BoxCollider>()->Width();

    auto parentPosition = _parent.lock()->GetTransform().position;
    auto parentBottom = Point(parentWidth / 2, parentHeight);
    auto parentBottomPosition = parentPosition + parentBottom;
    auto velocity = physicsManager->GetVelocity(_parent.lock());
    physicsManager->UpdateRotation(_parent.lock(), 0);

    auto targetPosition = _target.lock()->GetTransform().position;
    auto targetBottom = Point(_target.lock()->GetComponent<BoxCollider>()->Width() / 2,
                              _target.lock()->GetComponent<BoxCollider>()->Height());
    auto targetBottomPosition = targetPosition + targetBottom;

    auto closestNodeToTarget = pathfindingManager->FindClosestNode(targetBottomPosition);

    if (_targetNode == nullptr || closestNodeToTarget != _targetNode)
    {
        _path = pathfindingManager->GetPath(parentBottomPosition, targetBottomPosition);

        if (_path.size() != 0)
            this->_targetNode = _path[_path.size() - 1];
    }

    if (_targetNode != nullptr && _path.size() != 0)
    {
        auto nextNode = _path[0];

        if (nextNode->DistanceTo(_parent.lock()->GetTransform().position) <
            parentHeight - CoreConstants::Pathfinding::NODE_Y_OFFSET)
        {
            // Remove the node from the path
            _path.erase(_path.begin());

            // Check if the path is empty
            if (_path.size() == 0)
            {
                // Set the velocity to 0 when the target is reached
                return;
            }

            // Get the next node
            nextNode = _path[0];
        }

        // Move the parent towards the next node
        auto direction = nextNode->GetPosition() - _parent.lock()->GetTransform().position;
        auto vector = Vector2D(direction.x, -direction.y);
        vector.Direction();

        // If the next node is higher than the parent, jump
        if (nextNode->GetPosition().y < _parent.lock()->GetTransform().position.y + 100)
            physicsManager->UpdateVelocity(_parent.lock(), 0,
                                           600); // Insane jumping power
        else
        {
            physicsManager->UpdateVelocity(_parent.lock(), vector.x * 30, vector.y);
            if (vector.x < 0)
                _parent.lock()->GetComponent<Sprite>()->FlipSprite(true, false);
            else
                _parent.lock()->GetComponent<Sprite>()->FlipSprite(false, false);
        }
    }
}