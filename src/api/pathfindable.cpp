#include "pathfindable.hpp"
#include "box_collider.hpp"
#include "circle.hpp"
#include "core_constants.hpp"
#include "engine.hpp"
#include "io_facade.hpp"
#include "point.hpp"
#include <iostream>
#include <memory>

Pathfindable::Pathfindable(std::weak_ptr<GameObject> parent)
{
    _parent = parent.lock();
    CreateAndStoreNodes();
}

Pathfindable::~Pathfindable() {}

std::shared_ptr<Component> Pathfindable::Clone(std::weak_ptr<GameObject> parent)
{
    return std::make_shared<Pathfindable>(parent);
    CreateAndStoreNodes();
}

Pathfindable::Pathfindable(const Pathfindable &other)
{
    _parent = other._parent;
    _nodes = other._nodes;
    CreateAndStoreNodes();
}

std::vector<std::shared_ptr<Node>> Pathfindable::GetNodes() const { return _nodes; }

void Pathfindable::CreateAndStoreNodes()
{
    std::cout << "Creating nodes for: " << _parent->GetName() << std::endl;
    // Find the collider of the parent GameObject.
    auto collider = _parent->GetComponent<BoxCollider>();
    auto transform = _parent->GetTransform();

    if (collider == nullptr)
        throw std::runtime_error("No collider found on GameObject with Pathfindable component: '" +
                                 _parent->GetName() + "'.");

    // Calculate the amount of nodes needed to cover the collider.
    auto width = collider->Width();
    auto nodeCount = static_cast<int>(width / CoreConstants::Pathfinding::NODE_SPACING);

    std::cout << "Node count: " << nodeCount << std::endl;

    // Place a node at each corner of the collider.
    auto topLeft = transform.position.x;
    auto topRight = transform.position.x + width;

    auto top = transform.position.y;

    // Evenly distribute the nodes between the top left and top right corner.
    auto nodeSpacing = (topRight - topLeft) / nodeCount;

    for (int i = 0; i < nodeCount; i++)
    {
        std::cout << "Creating node: " << topLeft + (nodeSpacing * i) << ", " << top << std::endl;
        auto node = std::make_shared<Node>(topLeft + (nodeSpacing * i), top);
        _nodes.push_back(node);
    }
}

void Pathfindable::RenderNodes() const
{
    auto renderer = Engine::GetInstance()->Get<IOFacade>();

    for (auto &node : _nodes)
    {
        auto circle = Circle(*new Vector2D(node->GetX(), node->GetY()), 5);
        circle.SetFillColor(CoreConstants::Pathfinding::NODE_COLOR);
        renderer->DrawShape(circle);
    }
}
