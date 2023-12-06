#include "graph.hpp"
#include <memory>

// Node definitions.
Node::Node(int x, int y) : _x(x), _y(y), _g(0), _h(0) {}

Node::Node(const Node &other)
{
    _x = other._x;
    _y = other._y;
}

int Node::GetX() { return _x; }

int Node::GetY() { return _y; }

int Node::GetG() { return _g; }

void Node::SetG(int g) { _g = g; }

int Node::GetH() { return _h; }

void Node::SetH(int h) { _h = h; }

int Node::GetF() { return _g + _h; }

// Link definitions.
Link::Link(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2) : _node1(node1), _node2(node2)
{
}

std::shared_ptr<Node> Link::GetNode1() { return _node1; }

std::shared_ptr<Node> Link::GetNode2() { return _node2; }

// Graph definitions.
void Graph::AddNode(std::shared_ptr<Node> node) { _nodes.push_back(node); }

void Graph::AddLink(Link link) { _links.push_back(std::make_shared<Link>(link)); }

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