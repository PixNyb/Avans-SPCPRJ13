#include "graph.hpp"
#include <gtest/gtest.h>

// Test case for adding a node to the graph
TEST(GraphTest, AddNodeTest)
{
    Graph graph;
    std::shared_ptr<Node> node = std::make_shared<Node>(0, 0);
    graph.AddNode(node);
    EXPECT_EQ(graph.GetNodeCount(), 1);
    EXPECT_EQ(graph.GetNode(0), node);
}

// Test case for checking if two nodes are linked
TEST(GraphTest, AreNodesLinkedTest)
{
    Graph graph;
    std::shared_ptr<Node> node1 = std::make_shared<Node>(0, 0);
    std::shared_ptr<Node> node2 = std::make_shared<Node>(1, 0);
    graph.AddNode(node1);
    graph.AddNode(node2);
    EXPECT_FALSE(graph.AreNodesLinked(node1, node2));

    Link link(node1, node2);
    graph.AddLink(link);
    EXPECT_TRUE(graph.AreNodesLinked(node1, node2));
}

// Test case for getting a node at a given index
TEST(GraphTest, GetNodeTest)
{
    Graph graph;
    std::shared_ptr<Node> node1 = std::make_shared<Node>(0, 0);
    graph.AddNode(node1);
    EXPECT_EQ(graph.GetNode(0), node1);

    std::shared_ptr<Node> node2 = std::make_shared<Node>(1, 0);
    graph.AddNode(node2);
    EXPECT_EQ(graph.GetNode(1), node2);
}

// Test case for getting the node count in the graph
TEST(GraphTest, GetNodeCountTest)
{
    Graph graph;
    std::shared_ptr<Node> node1 = std::make_shared<Node>(0, 0);
    std::shared_ptr<Node> node2 = std::make_shared<Node>(1, 0);
    graph.AddNode(node1);
    graph.AddNode(node2);
    EXPECT_EQ(graph.GetNodeCount(), 2);

    std::shared_ptr<Node> node3 = std::make_shared<Node>(2, 0);
    graph.AddNode(node3);
    EXPECT_EQ(graph.GetNodeCount(), 3);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}