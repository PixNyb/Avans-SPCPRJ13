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

#include "game_object.hpp"
#include <box2d/b2_contact.h>
#include <box2d/b2_world_callbacks.h>
#include <map>
#include <memory>

/**
 * @class ContactListener
 * @brief This class handles the contacts that occur in the b2World. When a contact comes through
 * here the behaviour scripts of both bodies are called.
 */
class ContactListener : public b2ContactListener
{
  private:
    std::map<std::shared_ptr<GameObject>, b2Body *>
        gameObjects; ///< The gameobjects that are in the b2world
  public:
    /**
     * @brief Constructs a contactlistener
     * @param gameObjects
     */
    ContactListener(std::map<std::shared_ptr<GameObject>, b2Body *> gameObjects);

    /**
     * @brief Destructs a contactlistener
     */
    ~ContactListener() override;

    /**
     * @brief executes the defined actions in the gameobjects that corresponds with bodies in the
     * incoming contact object
     * @param contact is the object that contains the 2 bodies that have come in contact
     */
    void BeginContact(b2Contact *contact) override;

    /**
     * @brief executes the defined actions in the gameobjects that corresponds with bodies in the
     * incoming contact object
     * @param contact is the object that contains the 2 bodies that have exited their contact
     */
    void EndContact(b2Contact *contact) override;

    /**
     * @brief Updates the list of bodies in the contact listener.
     * @param gameObjects the new list of objects
     */
    void UpdateBodies(std::map<std::shared_ptr<GameObject>, b2Body *> gameObjects);

    /**
     * @brief Finds the gameobject with a b2body
     */
    std::shared_ptr<GameObject> FindGameObject(b2Body *body);

    void CleanUp();
};

#endif // DEFUNBOBENGINE_CONTACTLISTENER_HPP
