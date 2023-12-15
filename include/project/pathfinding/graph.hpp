/**
 * @file graph.hpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the Graph, Node and Link classes.
 * @version 0.1
 * @date 2023-12-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_GRAPH_HPP
#define DEFUNBOBENGINE_GRAPH_HPP

#include "point.hpp"
#include <memory>
#include <vector>

/**
 * @class Node
 * @brief This class represents a node in a graph.
 *
 * This class represents a node in a graph, it contains the x and y coordinates of the node in the
 * game world. It also contains the cost of the node, the heuristic cost of the node and the total
 * cost of the node.
 */
class Node : public std::enable_shared_from_this<Node>
{
  public:
    /**
     * @brief Constructs a new Node.
     *
     * @param x The x coordinate of the node.
     * @param y The y coordinate of the node.
     */
    Node(int x, int y);

    /**
     * @brief Constructs a new Node based on another Node.
     *
     * @param other The node to copy,
     */
    Node(const Node &other);

    /**
     * @brief Check the distance to another node.
     *
     * @param other The node to compare to.
     * @return The distance to the other node.
     */
    float DistanceTo(std::shared_ptr<Node> other);

    /**
     * @brief Check the distance to a point.
     *
     * @param point The point to compare to.
     * @return The distance to the point.
     */
    float DistanceTo(Point point);

    /**
     * @brief Get the x coordinate of the node.
     *
     * @return The x coordinate of the node.
     */
    int GetX();

    /**
     * @brief Get the y coordinate of the node.
     *
     * @return The y coordinate of the node.
     */
    int GetY();

    /**
     * @brief Get the position of the node.
     *
     * @return The position of the node.
     */
    Point GetPosition();

  private:
    int _x; ///< The x coordinate of the node in the level.
    int _y; ///< The y coordinate of the node in the level.
};

/**
 * @class Link
 * @brief This class represents a link in a graph.
 *
 * This class represents a link in a graph, it contains the index of the first node and the index
 * of the second node.
 */
class Link : public std::enable_shared_from_this<Link>
{
  public:
    /**
     * @brief Constructs a new Link.
     *
     * @param node1 The first node.
     * @param node2 The second node.
     */
    Link(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2);

    /**
     * @brief Get the first node.
     *
     * @return std::shared_ptr<Node> The first node.
     */
    std::shared_ptr<Node> GetNode1();

    /**
     * @brief Get the second node.
     *
     * @return std::shared_ptr<Node> The second node.
     */
    std::shared_ptr<Node> GetNode2();

  private:
    std::shared_ptr<Node> _node1; ///< The first node.
    std::shared_ptr<Node> _node2; ///< The second node.
};

/**
 * @class Graph
 * @brief This class represents a graph.
 *
 * This class represents a graph, it contains a vector of nodes and a vector of links. The nodes
 * are the nodes in the graph and the links are the links in the graph.
 */
class Graph : public std::enable_shared_from_this<Graph>
{
  public:
    /**
     * @brief Constructs a new Graph.
     */
    Graph() = default;

    /**
     * @brief Add a node to the graph.
     *
     * @param node The node to add.
     */
    void AddNode(std::shared_ptr<Node> node);

    /**
     * @brief Add a link to the graph.
     *
     * @param link The link to add.
     */
    void AddLink(Link link);

    /**
     * @brief Check if the given nodes are linked.
     *
     * @param node1 The first node.
     * @param node2 The second node.
     */
    bool AreNodesLinked(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2);

    /**
     * @brief Get the node at the given index.
     *
     * @param index The index of the node.
     */
    std::shared_ptr<Node> GetNode(int index);

    /**
     * @brief Get the link at the given index.
     *
     * @param index The index of the link.
     */
    std::shared_ptr<Link> GetLink(int index);

    /**
     * @brief Get the amount of nodes in the graph.
     *
     * @return The amount of nodes in the graph.
     */
    int GetNodeCount();

    /**
     * @brief Get the amount of links in the graph.
     *
     * @return The amount of links in the graph.
     */
    int GetLinkCount();

    /**
     * @brief Get the path from the starting point to the ending point using the A* algorithm.
     *
     * @param start The starting point.
     * @param end The ending point.
     * @return The path from the starting point to the ending point.
     */
    std::vector<std::shared_ptr<Node>> GetPath(Point start, Point end);

    /**
     * @brief Get the path from the starting node to the ending node using the A* algorithm.
     *
     * @param start The starting node.
     * @param end The ending node.
     * @return The path from the starting node to the ending node.
     */
    std::vector<std::shared_ptr<Node>> GetPath(std::shared_ptr<Node> start,
                                               std::shared_ptr<Node> end);

    /**
     * @brief Find the closest node to the given point.
     *
     * @param point
     * @return The closest node to the given point.
     */
    std::shared_ptr<Node> FindClosestNode(Point point);

  private:
    std::vector<std::shared_ptr<Node>> _nodes; ///< The nodes in the graph.
    std::vector<std::shared_ptr<Link>> _links; ///< The links in the graph.
};

#endif // DEFUNBOBENGINE_GRAPH_HPP