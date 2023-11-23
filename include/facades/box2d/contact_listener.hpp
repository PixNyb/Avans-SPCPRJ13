/**
 * @file contact_listener.hpp
 * @author Daan Groot (d.groot3@student.avans.nl)
 * @brief This file contains the defenition of the class ContactListener
 * This class should only be used inside the physicsfacade
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_CONTACTLISTENER_HPP
#define DEFUNBOBENGINE_CONTACTLISTENER_HPP

#include "box2d/b2_contact.h"
#include "box2d/b2_world_callbacks.h"
#include "game_object.hpp"
#include <map>
#include <memory>
#include <vector>

class ContactListener : public b2ContactListener
{
  private:
    std::map<std::shared_ptr<GameObject>, b2Body *>
        gameObjects; ///< The gameobjects that are in the b2world
  public:
    /**
     * Constructs a contactlistener
     * @param gameObjects
     */
    ContactListener(std::map<std::shared_ptr<GameObject>, b2Body *> gameObjects);

    /**
     * Destructs a contactlistener
     */
    ~ContactListener() = default;

    /**
     * executes the defined actions in the gameobjects that corresponds with bodies in the incoming
     * contact object
     * @param contact is the object that contains the 2 bodies that have come in contact
     */
    void BeginContact(b2Contact *contact) override;

    /**
     * executes the defined actions in the gameobjects that corresponds with bodies in the incoming
     * contact object
     * @param contact is the object that contains the 2 bodies that have exited their contact
     */
    void EndContact(b2Contact *contact) override;
};

#endif // DEFUNBOBENGINE_CONTACTLISTENER_HPP
