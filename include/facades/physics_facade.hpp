/**
 * @file physics_facade.hpp
 * @author Daan Groot (d.groot3@student.avans.nl)
 * @brief This file contains the Collider class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AVANS_SPCPRJ13_PHYSICS_FACADE_HPP
#define AVANS_SPCPRJ13_PHYSICS_FACADE_HPP

#include <box2d/box2d.h>
#include <vector>
#include <memory>
#include <map>
#include "game_object.hpp"


class PhysicsFacade {
private:
    std::vector<std::shared_ptr<GameObject>> game_objects; ////< the list of gameobjects in the engine
    std::map<std::shared_ptr<GameObject>, std::unique_ptr<b2Body>> bodies; ///< The map with bodies in the physicsfacade.
    std::unique_ptr<b2World> world; ////< The world in which the bodies can move.

public:
    PhysicsFacade(std::vector<std::shared_ptr<GameObject>> &game_objects);

    ~PhysicsFacade();

    void PopulateWorld();

    void Step();
};


#endif //AVANS_SPCPRJ13_PHYSICS_FACADE_HPP
