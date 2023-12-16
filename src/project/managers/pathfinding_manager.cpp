#include "pathfinding_manager.hpp"
#include "box_collider.hpp"
#include "circle.hpp"
#include "color.hpp"
#include "core_constants.hpp"
#include "game_object.hpp"
#include "graph.hpp"
#include "line.hpp"
#include "pathfindable.hpp"
#include "point.hpp"
#include "rectangle.hpp"
#include "rigidbody.hpp"
#include "scene.hpp"
#include "shape_component.hpp"
#include "transform.hpp"
#include "vector2d.hpp"
#include <cstdlib>
#include <iostream>
#include <memory>

PathfindingManager::PathfindingManager() {}

PathfindingManager::~PathfindingManager() {}

void PathfindingManager::Update(std::shared_ptr<Scene> scene) { GenerateGraphForScene(scene); }

std::shared_ptr<Graph> PathfindingManager::GetGraph() const { return _graph; }

void PathfindingManager::GenerateGraphForScene(std::shared_ptr<Scene> scene)
{
    if (scene == nullptr)
        return;

    this->_scene = scene;
    std::cout << "Generating graph for scene: " << scene << std::endl;

    // Find the graphGameObject in the scene contents
    std::shared_ptr<GameObject> graphGameObject = nullptr;
    for (const auto &gameObject : scene->contents)
        if (gameObject->GetName() == "Graph-Debug")
        {
            std::cout << "Found graph game object." << std::endl;
            graphGameObject = gameObject;

            if (graphGameObject->GetComponent<ShapeComponent>() == nullptr)
                graphGameObject->AddComponent(std::make_shared<ShapeComponent>());

            break;
        }

    // If the graphGameObject is not found, create one at (0, 0)
    if (graphGameObject == nullptr)
    {
        std::cout << "Graph game object not found, creating one..." << std::endl;
        graphGameObject = std::make_shared<GameObject>("Graph-Debug");
        graphGameObject->SetTransform(Transform(Point(0, 0), 0, 1));
        graphGameObject->AddComponent(std::make_shared<ShapeComponent>());
        scene->contents.push_back(graphGameObject);
    }

    _graph = std::make_shared<Graph>();
    auto shapeComponent = graphGameObject->GetComponent<ShapeComponent>();

    for (const auto &gameObject : scene->contents)
    {
        auto pathfindable = gameObject->GetComponent<Pathfindable>();

        if (pathfindable != nullptr && gameObject->IsActive())
        {
            std::cout << "Found pathfindable: " << gameObject->GetName() << std::endl;

            if (!pathfindable->IsGenerated())
                pathfindable->Generate();

            auto nodes = pathfindable->GetNodes();

            for (const auto &node : nodes)
            {
                // Check if there is already a node at this position
                bool nodeExists = false;
                for (int i = 0; i < _graph->GetNodeCount(); i++)
                {
                    auto existingNode = _graph->GetNode(i);
                    if (existingNode->GetX() == node->GetX() &&
                        existingNode->GetY() == node->GetY())
                    {
                        nodeExists = true;
                        break;
                    }
                }

                // Check if there's a collider at this position
                // TODO: Check different types of colliders and move this to the collider component
                bool colliderExists = false;
                for (const auto &collider : scene->contents)
                {
                    if (collider->GetComponent<BoxCollider>() != nullptr &&
                        collider->GetComponent<RigidBody>() != nullptr && collider->IsActive())
                    {
                        auto colliderTransform = collider->GetTransform();
                        auto colliderPosition = colliderTransform.position;
                        auto colliderWidth = collider->GetComponent<BoxCollider>()->Width();
                        auto colliderHeight = collider->GetComponent<BoxCollider>()->Height();

                        if (node->GetX() >= colliderPosition.x &&
                            node->GetX() <= colliderPosition.x + colliderWidth &&
                            node->GetY() >= colliderPosition.y &&
                            node->GetY() <= colliderPosition.y + colliderHeight)
                        {
                            colliderExists = true;
                            break;
                        }
                    }
                }

                if (!nodeExists && !colliderExists)
                {
                    _graph->AddNode(node);

                    if (CoreConstants::Debug::DrawNodes)
                    {
                        auto rect = Rectangle(
                            Vector2D(node->GetX() - CoreConstants::Pathfinding::NODE_SIZE / 2.0f,
                                     node->GetY() - CoreConstants::Pathfinding::NODE_SIZE / 2.0f),
                            CoreConstants::Pathfinding::NODE_SIZE,
                            CoreConstants::Pathfinding::NODE_SIZE);
                        rect.SetFillColor(CoreConstants::Pathfinding::NODE_COLOR);
                        shapeComponent->AddGeometry(std::make_shared<Rectangle>(rect));
                    }
                }
            }
        }
    }

    std::cout << "Graph nodes: " << _graph->GetNodeCount() << std::endl;

    // Link the nodes
    for (int i = 0; i < _graph->GetNodeCount(); i++)
    {
        auto node1 = _graph->GetNode(i);

        // Check a radius around the node for other nodes using
        // CoreConstants::Pathfinding::NODE_CONNECTION_RADIUS
        for (int j = 0; j < _graph->GetNodeCount(); j++)
        {
            if (i == j)
                continue;

            auto node2 = _graph->GetNode(j);

            // Check if the distance between the nodes is less than the radius
            if (node1->DistanceTo(node2) <=
                (CoreConstants::Pathfinding::NODE_CONNECTION_LENGTH >=
                         CoreConstants::Pathfinding::NODE_SPACING
                     ? CoreConstants::Pathfinding::NODE_CONNECTION_LENGTH
                     : CoreConstants::Pathfinding::NODE_SPACING))
            {
                // Check if the nodes are not already linked
                if (!_graph->AreNodesLinked(node1, node2))
                {
                    // Link the nodes
                    _graph->AddLink(Link(node1, node2));

                    if (CoreConstants::Debug::DrawNodes)
                    {
                        auto line = std::make_shared<Line>();
                        line->start = Vector2D(node1->GetX(), node1->GetY());
                        line->end = Vector2D(node2->GetX(), node2->GetY());
                        line->SetFillColor(CoreConstants::Pathfinding::NODE_CONNECTION_COLOR);
                        shapeComponent->AddGeometry(line);
                    }
                }
            }
        }
    }

    std::cout << "Graph links: " << _graph->GetLinkCount() << std::endl;

    std::cout << "Graph generated." << std::endl;
}

std::vector<std::shared_ptr<Node>> PathfindingManager::GetPath(Point start, Point end) const
{
    if (_graph == nullptr)
        return std::vector<std::shared_ptr<Node>>();

    auto path = _graph->GetPath(start, end);

    if (CoreConstants::Debug::DrawNodes && path.size() > 0)
    {
        // Find the debug component and get the shape component
        std::shared_ptr<ShapeComponent> shapeComponent = nullptr;
        for (const auto &gameObject : _scene->contents)
            if (gameObject->GetName() == "Graph-Debug")
            {
                shapeComponent = gameObject->GetComponent<ShapeComponent>();
                break;
            }

        if (shapeComponent != nullptr)
        {
            auto color =
                Color(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f, 1);

            auto startNode = path[0];
            auto x = startNode->GetX();
            auto y = startNode->GetY();
            auto startCircle = Circle(Vector2D(x, y), CoreConstants::Pathfinding::NODE_TARGET_SIZE);
            startCircle.SetFillColor(color);

            auto endNode = path[path.size() - 1];
            x = endNode->GetX();
            y = endNode->GetY();
            auto endCircle = Circle(Vector2D(x, y), CoreConstants::Pathfinding::NODE_TARGET_SIZE);
            endCircle.SetFillColor(color);

            shapeComponent->AddGeometry(std::make_shared<Circle>(startCircle));
            shapeComponent->AddGeometry(std::make_shared<Circle>(endCircle));
        }
    }

    return path;
}

std::shared_ptr<Node> PathfindingManager::FindClosestNode(Point point) const
{
    if (_graph == nullptr)
        return nullptr;

    return _graph->FindClosestNode(point);
}