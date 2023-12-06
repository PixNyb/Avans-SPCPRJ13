/**
 * @file graph_utility.hpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the GraphUtility class.
 * @version 0.1
 * @date 2023-12-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_GRAPH_UTILITY_HPP
#define DEFUNBOBENGINE_GRAPH_UTILITY_HPP

#include "graph.hpp"
#include <memory>
#include <vector>

class GraphUtility
{
  public:
    /**
     * @brief Get the Nodes for a specified level.
     *
     * This information can be used to generate a graph for the level for a specified game object.
     * @return std::vector<std::shared_ptr<Node>> The nodes for the level.
     */
    static std::vector<std::shared_ptr<Node>> GetNodesForLevel();

    /**
     * @brief Get the Graph for a specified level.
     *
     * @return std::shared_ptr<Graph> The graph for the level.
     */
    static std::shared_ptr<Graph> GetGraphForLevel();
};

#endif // DEFUNBOBENGINE_GRAPH_UTILITY_HPP