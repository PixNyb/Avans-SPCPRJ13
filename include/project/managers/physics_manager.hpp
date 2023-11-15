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
    void CreateWorld(std::vector<std::shared_ptr<GameObject>>);
    void RemoveBody(std::shared_ptr<GameObject>);
    void CreateBody(std::shared_ptr<GameObject>);
    void Step();
};


#endif //DEFUNBOBENGINE_PHYSICS_MANAGER_HPP
