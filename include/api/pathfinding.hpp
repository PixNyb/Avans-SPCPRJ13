/**
 * @file pathfinding.hpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the Pathfinding class definition.
 * @version 0.1
 * @date 2023-12-13
 *
 * @copyright Copyright (c) 2023
 */

#include "behaviour_script.hpp"
#include "game_object.hpp"
#include "graph.hpp"
#include <memory>
#include <vector>

/**
 * @class Pathfinding
 * @brief The Pathfinding class represents a pathfinding behaviour script.
 *
 * The Pathfinding class is a behaviour that can be attached to a GameObject to make it move
 * towards a target GameObject.
 */
class Pathfinding : public BehaviourScript
{
  public:
    /**
     * @brief Clone the Pathfinding object
     *
     * @param parent
     * @return A shared pointer to the cloned Pathfinding object.
     */
    std::shared_ptr<Component> Clone(std::weak_ptr<GameObject> parent) override;

    /**
     * @brief Construct a new Pathfinding object
     *
     * @param parent The parent GameObject of this component.
     * @param targetId The id of the target GameObject. This will be used to find the target during
     * runtime.
     */
    Pathfinding(std::weak_ptr<GameObject> parent, std::string targetId);

    /**
     * @brief Construct a new Pathfinding object
     *
     * @param other The Pathfinding object to copy.
     */
    Pathfinding(const Pathfinding &other);

    virtual void OnStart() override;
    virtual void OnUpdate() override;

  private:
    std::weak_ptr<GameObject> _parent;        // The parent GameObject of this component.
    std::weak_ptr<GameObject> _target;        // The target GameObject.
    std::string _targetId;                    // The id of the target GameObject.
    std::vector<std::shared_ptr<Node>> _path; // The path to the target.
    std::shared_ptr<Node> _targetNode;        // The target node.
};