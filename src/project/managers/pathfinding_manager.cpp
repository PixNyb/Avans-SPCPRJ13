#include "pathfinding_manager.hpp"
#include "graph.hpp"
#include "pathfindable.hpp"
#include "scene.hpp"

PathfindingManager::PathfindingManager() {}

PathfindingManager::~PathfindingManager() {}

void PathfindingManager::Update(std::shared_ptr<Scene> scene) { GenerateGraphForScene(scene); }

std::shared_ptr<Graph> PathfindingManager::GetGraph() const { return graph; }

void PathfindingManager::GenerateGraphForScene(std::shared_ptr<Scene> scene)
{
    graph = std::make_shared<Graph>();

    for (const auto &gameObject : scene->contents)
    {
        auto pathfindable = gameObject->GetComponent<Pathfindable>();

        if (pathfindable != nullptr)
        {
            auto nodes = pathfindable->GetNodes();

            for (const auto &node : nodes)
                graph->AddNode(node);
        }
    }

    // TODO: Add edges between nodes.
}