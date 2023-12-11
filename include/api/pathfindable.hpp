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
#include <SDL_render.h>
#include <memory>
#include <vector>

/**
 * @class Pathfindable
 * @brief The Pathfindable class represents a pathfindable object.
 *
 * Upon initialisation, the Pathfindable component registers itself with the
 * PathfindingManager and creates multiple pathfinding nodes around itself.
 * These nodes are used by the PathfindingManager to calculate a graph of
 * pathfinding nodes in the level.
 */
class Pathfindable : public Component
{
  public:
    Pathfindable(std::shared_ptr<GameObject> parent);
    ~Pathfindable();

    std::vector<std::shared_ptr<Node>> GetNodes() const;
    void RenderNodes() const;

  protected:
    void CreateAndStoreNodes();
    std::vector<std::shared_ptr<Node>> _nodes;
    std::shared_ptr<GameObject> _parent;
};

#endif // AVANS_SPCPRJ13_PATHFINDABLE_H