#include "graph.hpp"
#include "point.hpp"
#include <algorithm>
#include <cmath>
#include <memory>
#include <set>
#include <unordered_map>
#include <vector>

// Node definitions.
Node::Node(int x, int y) : _x(x), _y(y) {}

Node::Node(const Node &other)
{
    _x = other._x;
    _y = other._y;
}

Point Node::GetPosition() { return Point(_x, _y); }

float Node::DistanceTo(std::shared_ptr<Node> other)
{
    auto x = _x - other->GetX();
    auto y = _y - other->GetY();

    return std::sqrt((x * x) + (y * y));
}

float Node::DistanceTo(Point point)
{
    auto x = _x - point.x;
    auto y = _y - point.y;

    return std::sqrt((x * x) + (y * y));
}

int Node::GetX() { return _x; }

int Node::GetY() { return _y; }

// Link definitions.
Link::Link(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2) : _node1(node1), _node2(node2)
{
}

std::shared_ptr<Node> Link::GetNode1() { return _node1; }

std::shared_ptr<Node> Link::GetNode2() { return _node2; }

// Graph definitions.
void Graph::AddNode(std::shared_ptr<Node> node) { _nodes.push_back(node); }

void Graph::AddLink(Link link) { _links.push_back(std::make_shared<Link>(link)); }

bool Graph::AreNodesLinked(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2)
{
    for (const auto &link : _links)
    {
        if ((link->GetNode1() == node1 && link->GetNode2() == node2) ||
            (link->GetNode1() == node2 && link->GetNode2() == node1))
            return true;
    }

    return false;
}

std::shared_ptr<Node> Graph::GetNode(int index)
{
    if (index < 0 || index >= _nodes.size())
        return nullptr;

    return _nodes[index];
}

std::shared_ptr<Link> Graph::GetLink(int index)
{
    if (index < 0 || index >= _links.size())
        return nullptr;

    return _links[index];
}

int Graph::GetNodeCount() { return _nodes.size(); }

int Graph::GetLinkCount() { return _links.size(); }

std::vector<std::shared_ptr<Node>> Graph::GetPath(Point start, Point end)
{
    std::shared_ptr<Node> startNode = FindClosestNode(start);
    std::shared_ptr<Node> endNode = FindClosestNode(end);

    return GetPath(startNode, endNode);
}

std::vector<std::shared_ptr<Node>> Graph::GetPath(std::shared_ptr<Node> start,
                                                  std::shared_ptr<Node> end)
{
    // Collect f, g and h values for each node.
    std::unordered_map<std::shared_ptr<Node>, float> gValues;
    std::unordered_map<std::shared_ptr<Node>, float> hValues;
    std::unordered_map<std::shared_ptr<Node>, float> fValues;

    // Initialize the start node's g value to 0.
    gValues[start] = 0;

    // Calculate the h value for each node.
    for (const auto &node : _nodes)
    {
        hValues[node] = node->DistanceTo(end);
    }

    // Create an open set and add the start node to it.
    std::set<std::shared_ptr<Node>> openSet;
    openSet.insert(start);

    // Create a map to store the parent node for each node in the path.
    std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> parentMap;

    // Perform A* search algorithm.
    while (!openSet.empty())
    {
        // Find the node with the lowest f value in the open set.
        std::shared_ptr<Node> currentNode = *openSet.begin();
        for (const auto &node : openSet)
        {
            if (fValues[node] < fValues[currentNode])
            {
                currentNode = node;
            }
        }

        // If the current node is the end node, reconstruct the path and return it.
        if (currentNode == end)
        {
            std::vector<std::shared_ptr<Node>> path;
            std::shared_ptr<Node> node = end;
            while (node != nullptr)
            {
                path.push_back(node);
                node = parentMap[node];
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        // Remove the current node from the open set.
        openSet.erase(currentNode);

        // Get the neighbors of the current node.
        std::vector<std::shared_ptr<Node>> neighbors;
        for (const auto &link : _links)
        {
            if (link->GetNode1() == currentNode)
            {
                neighbors.push_back(link->GetNode2());
            }
            else if (link->GetNode2() == currentNode)
            {
                neighbors.push_back(link->GetNode1());
            }
        }

        // Calculate the g value for each neighbor.
        for (const auto &neighbor : neighbors)
        {
            float tentativeG = gValues[currentNode] + currentNode->DistanceTo(neighbor);

            // If the neighbor is not in the g values map or the new g value is lower,
            // update the g value and set the current node as the parent.
            if (!gValues.count(neighbor) || tentativeG < gValues[neighbor])
            {
                gValues[neighbor] = tentativeG;
                parentMap[neighbor] = currentNode;

                // Calculate the f value for the neighbor.
                fValues[neighbor] = gValues[neighbor] + hValues[neighbor];

                // Add the neighbor to the open set if it's not already in it.
                if (openSet.find(neighbor) == openSet.end())
                {
                    openSet.insert(neighbor);
                }
            }
        }
    }

    // If no path is found, return an empty vector.
    return std::vector<std::shared_ptr<Node>>();
}

std::shared_ptr<Node> Graph::FindClosestNode(Point point)
{
    std::shared_ptr<Node> closestNode = nullptr;
    float closestDistance = 0;

    for (const auto &node : _nodes)
    {
        float distance = node->DistanceTo(std::make_shared<Node>(point.x, point.y));

        if (closestNode == nullptr || distance < closestDistance)
        {
            closestNode = node;
            closestDistance = distance;
        }
    }

    return closestNode;
}