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
#include "rigidbody.hpp"
#include "collider.hpp"


class PhysicsFacade {
private:
    std::map<std::shared_ptr<GameObject>, b2Body*> bodies; ///< The map with bodies in the physicsfacade.
    std::unique_ptr<b2World> world; ////< The world in which the bodies can move.
    void SetFixture(b2Body* body, b2Shape* shape, const std::shared_ptr<RigidBody>& rigidBody, double area);
public:
    PhysicsFacade();

    ~PhysicsFacade();

    void MakeBody(std::shared_ptr<GameObject> game_object);

    void PopulateWorld(std::vector<std::shared_ptr<GameObject>> game_objects);

    void Step();

    void ShowDebug();

    void CreateGround();
};


#endif //AVANS_SPCPRJ13_PHYSICS_FACADE_HPP
