#include "pathfinding_manager.hpp"
#include "graph.hpp"
#include "pathfindable.hpp"
#include "scene.hpp"
#include <iostream>
#include <memory>

PathfindingManager::PathfindingManager() {}

PathfindingManager::~PathfindingManager() {}

void PathfindingManager::Update(std::shared_ptr<Scene> scene) { GenerateGraphForScene(scene); }

std::shared_ptr<Graph> PathfindingManager::GetGraph() const { return graph; }

void PathfindingManager::GenerateGraphForScene(std::shared_ptr<Scene> scene)
{
    if (scene == nullptr)
        return;

    this->scene = scene;
    std::cout << "Generating graph for scene: " << scene << std::endl;
    graph = std::make_shared<Graph>();

    for (const auto &gameObject : scene->contents)
    {
        auto pathfindable = gameObject->GetComponent<Pathfindable>();

        if (pathfindable != nullptr)
        {
            std::cout << "Found pathfindable: " << gameObject->GetName() << std::endl;
            auto nodes = pathfindable->GetNodes();

            for (const auto &node : nodes)
                graph->AddNode(node);
        }
    }

    std::cout << "Graph generated." << std::endl;
}

void PathfindingManager::Render() const
{
    if (scene == nullptr || graph == nullptr)
        return;

    std::cout << "Rendering graph for scene: " << scene << std::endl;

    for (const auto &gameObject : scene->contents)
    {
        auto pathfindable = gameObject->GetComponent<Pathfindable>();

        if (pathfindable != nullptr)
            pathfindable->RenderNodes();
    }
}