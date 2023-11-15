/**
 * @file physics_facade.hpp
 * @author Daan Groot (d.groot3@student.avans.nl)
 * @brief This file contains the PhysicsFacade class definition.
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

    /**
     * Creates a shape on a body through a fixture
     * @param body the body that the fixture is placed on
     * @param shape the shape you want to add to the body
     * @param rigidBody the rigidbody of the gameobject/body this fixture will belong to
     * @param area the area of the shape
     */
    void SetFixture(b2Body* body, b2Shape* shape, const std::shared_ptr<RigidBody>& rigidBody, double area);
public:

    PhysicsFacade();

    ~PhysicsFacade();

    /**
    * @brief Create a body from a gameobject
    */
    void MakeBody(std::shared_ptr<GameObject> gameObject);

    /**
    * @brief Destroy a body from a gameobject
    */
    void DestroyBody(std::shared_ptr<GameObject> gameObject);

    /**
    * @brief Populate the b2World through a list of gameobjects
    */
    void PopulateWorld(std::vector<std::shared_ptr<GameObject>> gameObjects);

    /**
    * @brief Add a force to an object
    * can be used for jumping or boosts in speed
    */
    void AddForce(std::shared_ptr<GameObject> gameObject, float vx, float vy);

    /**
    * @brief Add a force to an object
    * can be used for jumping or boosts in speed
    */
    void AddRotation(std::shared_ptr<GameObject> gameObject, float amount);

    /**
    * @brief Execute the step function on the b2World
    */
    void Step();

    /**
    * @brief Simulate all bodies in the b2World in a window
    */
    void ShowDebug();

    /**
    * @brief Create a ground object for testing purposes
    */
    void CreateGround();
};


#endif //AVANS_SPCPRJ13_PHYSICS_FACADE_HPP
