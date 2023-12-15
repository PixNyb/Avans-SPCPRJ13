/**
 * @file pathfinding_manager.hpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the PathfindingManager class definition.
 * @version 0.1
 * @date 2023-12-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "graph.hpp"
#include "point.hpp"
#include "scene.hpp"
#include <memory>
#include <vector>

/**
 * @class PathfindingManager
 * @brief The PathfindingManager class represents a pathfinding manager.
 *
 * The PathfindingManager class is a manager that can be used to generate a graph for a scene and
 * find paths between nodes. It uses the Pathfindable components of GameObjects to generate the
 * graph.
 */
class PathfindingManager
{
  public:
    /**
     * @brief Construct a new PathfindingManager object
     */
    PathfindingManager();

    /**
     * @brief Destroy the PathfindingManager object
     */
    ~PathfindingManager();

    /**
     * @brief Update the PathfindingManager object to generate a graph for the scene.
     *
     * @param scene The scene to update.
     */
    void Update(std::shared_ptr<Scene> scene);

    /**
     * @brief Get the Graph object
     *
     * @return A shared pointer to the graph.
     */
    std::shared_ptr<Graph> GetGraph() const;

    /**
     * @brief Get the Path object
     *
     * @param start The start point.
     * @param end The end point.
     * @return A vector of shared pointers to the nodes in the path.
     */
    std::vector<std::shared_ptr<Node>> GetPath(Point start, Point end) const;

    /**
     * @brief Get the Path object
     *
     * @param start The start node.
     * @param end The end node.
     * @return A vector of shared pointers to the nodes in the path.
     */
    std::vector<std::shared_ptr<Node>> GetPath(std::shared_ptr<Node> start,
                                               std::shared_ptr<Node> end) const;

    /**
     * @brief Find the closest node to a point.
     *
     * @param point The point to find the closest node to.
     * @return A shared pointer to the closest node.
     */
    std::shared_ptr<Node> FindClosestNode(Point point) const;

  private:
    void GenerateGraphForScene(std::shared_ptr<Scene> scene); // Generate the graph for the scene.
    std::shared_ptr<Graph> _graph;                            // The graph.
    std::shared_ptr<Scene> _scene;                            // The scene.
};