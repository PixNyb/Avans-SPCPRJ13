/**
 * @file pathfindable.hpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the Pathfindable class definition.
 * @version 0.1
 * @date 2023-12-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AVANS_SPCPRJ13_PATHFINDABLE_H
#define AVANS_SPCPRJ13_PATHFINDABLE_H

#include "component.hpp"
#include "game_object.hpp"
#include "pathfinding/graph.hpp"
#include <memory>
#include <vector>

/**
 * @class Pathfindable
 * @brief The Pathfindable class represents a pathfindable object.
 *
 * The Pathfindable class is a component that can be attached to a GameObject to create nodes for
 * pathfinding. These nodes are picked up by the PathfindingManager and used to create a graph.
 */
class Pathfindable : public Component
{
  public:
    /**
     * @brief Clone the Pathfindable object
     *
     * @param parent
     * @return A shared pointer to the cloned Pathfindable object.
     */
    std::shared_ptr<Component> Clone(std::weak_ptr<GameObject> parent) override;

    /**
     * @brief Construct a new Pathfindable object
     *
     * @param parent The parent GameObject of this component.
     */
    Pathfindable(std::weak_ptr<GameObject> parent);

    /**
     * @brief Construct a new Pathfindable object
     *
     * @param other The Pathfindable object to copy.
     */
    Pathfindable(const Pathfindable &other);

    /**
     * @brief Destroy the Pathfindable object
     */
    ~Pathfindable();

    /**
     * @brief Generate the nodes for this Pathfindable object.
     *
     * Using the CoreConstants::Pathfinding constants, this method generates nodes for this
     * Pathfindable object. The nodes are stored in the _nodes vector and retrieved by the
     * PathfindingManager to create a graph of the scene.
     */
    void Generate();

    /**
     * @brief Whether or not the nodes for this Pathfindable object have been generated.
     *
     * @return true If the nodes have been generated.
     * @return false If the nodes have not been generated.
     */
    bool IsGenerated() const;

    /**
     * @brief Get the Nodes object
     *
     * @return The nodes for this Pathfindable object.
     */
    std::vector<std::shared_ptr<Node>> GetNodes() const;

  protected:
    std::vector<std::shared_ptr<Node>> _nodes; ///< The nodes for this Pathfindable object.
    std::shared_ptr<GameObject> _parent;       ///< The parent GameObject of this component.
    bool _generated = false;                   ///< Whether or not the nodes have been generated.
};

#endif // AVANS_SPCPRJ13_PATHFINDABLE_H