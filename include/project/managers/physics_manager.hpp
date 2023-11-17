/**
* @file physics_manager.hpp
* @author Daan Groot (d.groot3@student.avans.nl)
* @brief This file contains the PhysicsManager class definition.
* @version 0.1
* @date 2023-11-15
*
* @copyright Copyright (c) 2023
*
*/

#ifndef DEFUNBOBENGINE_PHYSICS_MANAGER_HPP
#define DEFUNBOBENGINE_PHYSICS_MANAGER_HPP

#include "vector"
#include "memory"
#include "game_object.hpp"
#include "physics_facade.hpp"

class PhysicsManager {
private:
    PhysicsFacade physicsFacade;
public:
    PhysicsManager() = default;
    ~PhysicsManager() = default;

    /**
     * Creates the world the gameobjects will be simulated in
     * @param gameObjects are the gameobjects that contain a rigicbody or colliders
     */
    void CreateWorld(std::vector<std::shared_ptr<GameObject>> gameObjects);

    /**
     * Removes the gameobject from the simulated world
     * @param gameObject is the object to be removed
     */
    void RemoveBody(const std::shared_ptr<GameObject>& gameObject);

    /**
     * Creates a body in the world simulation
     * @param gameObject the object for which a body will be created
     */
    void CreateBody(std::shared_ptr<GameObject> gameObject);

    /**
     * Adds a force to a gameobject (will allways create a force on the center of the body)
     * @param gameObject is the object the force will be added to
     * @param vx horizontal velocity
     * @param vy vertical velocity
     */
    void AddForce(const std::shared_ptr<GameObject>& gameObject, float vx, float vy);

    /**
     * Adds a rotation to a gameobject (will also apply the rotation on the center an is clockwise when amount is positive)
     * @param gameObject is the object the rotation will be added to
     * @param amount the speed at which the object should spin
     */
    void AddRotation(const std::shared_ptr<GameObject>& gameObject, float amount);

    /**
     * Simulates the world for 1 step
     */
    void Step();

    void Sleep(const std::shared_ptr<GameObject>& gameObject);
};


#endif //DEFUNBOBENGINE_PHYSICS_MANAGER_HPP