#include "pathfindable.hpp"
#include "box_collider.hpp"
#include "circle.hpp"
#include "core_constants.hpp"
#include "engine.hpp"
#include "io_facade.hpp"
#include "point.hpp"
#include "rectangle.hpp"
#include "shape_component.hpp"
#include <iostream>
#include <memory>

Pathfindable::Pathfindable(std::weak_ptr<GameObject> parent) { _parent = parent.lock(); }

Pathfindable::~Pathfindable() {}

std::shared_ptr<Component> Pathfindable::Clone(std::weak_ptr<GameObject> parent)
{
    auto object = std::make_shared<Pathfindable>(*this);
    object->_parent = parent.lock();
    return object;
}

Pathfindable::Pathfindable(const Pathfindable &other)
{
    _parent = other._parent;
    _nodes = other._nodes;
}

std::vector<std::shared_ptr<Node>> Pathfindable::GetNodes() const { return _nodes; }

bool Pathfindable::IsGenerated() const { return _generated; }

void Pathfindable::Generate()
{
    // Find the collider of the parent GameObject.
    auto collider = _parent->GetComponent<BoxCollider>();
    auto shapes = _parent->GetComponent<ShapeComponent>();
    auto transform = _parent->GetTransform();

    if (collider == nullptr)
        throw std::runtime_error("No collider found on GameObject with Pathfindable component: '" +
                                 _parent->GetName() + "'.");

    // Calculate the amount of nodes needed to cover the collider.
    auto width = collider->Width();

    // Divide the width by the node spacing and round up to get the amount of nodes.
    auto nodeCount = static_cast<int>(std::ceil(width / CoreConstants::Pathfinding::NODE_SPACING));

    // Calculate the spacing between the nodes.
    auto nodeSpacing = width / nodeCount;

    auto left = _parent->GetTransform().position.x;
    auto top = _parent->GetTransform().position.y;

    for (int i = 0; i <= nodeCount; i++)
    {
        auto node = std::make_shared<Node>(left + (nodeSpacing * i),
                                           top + CoreConstants::Pathfinding::NODE_Y_OFFSET);
        _nodes.push_back(node);
    }

    _generated = true;
}
