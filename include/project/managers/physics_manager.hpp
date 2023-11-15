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
    PhysicsManager();
    ~PhysicsManager() = default;

    void CreateWorld(std::vector<std::shared_ptr<GameObject>> gameObjects);

    void RemoveBody(std::shared_ptr<GameObject> gameObject);

    void CreateBody(std::shared_ptr<GameObject> gameObject);

    void AddForce(std::shared_ptr<GameObject> gameObject, float vx, float vy);

    void AddRotation(std::shared_ptr<GameObject> gameObject, float amount);

    void Step();
};


#endif //DEFUNBOBENGINE_PHYSICS_MANAGER_HPP
