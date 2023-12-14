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

class Pathfinding : public BehaviourScript
{
  public:
    std::shared_ptr<Component> Clone(std::weak_ptr<GameObject> parent) override;
    Pathfinding(std::shared_ptr<GameObject> parent, std::shared_ptr<GameObject> target);
    Pathfinding(const Pathfinding &other);
    virtual void OnStart() override;
    virtual void OnUpdate() override;

  private:
    std::shared_ptr<GameObject> _parent;
    std::shared_ptr<GameObject> _target;
    std::vector<std::shared_ptr<Node>> _path;
};