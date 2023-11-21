/**
 * @file contact_listener.hpp
 * @author Daan Groot (d.groot3@student.avans.nl)
 * @brief This file contains the defenition of the class ContactListener
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_CONTACTLISTENER_HPP
#define DEFUNBOBENGINE_CONTACTLISTENER_HPP


#include <memory>
#include <vector>
#include <map>
#include "box2d/b2_world_callbacks.h"
#include "box2d/b2_contact.h"
#include "game_object.hpp"

class ContactListener : public b2ContactListener {
private:
    std::map<std::shared_ptr<GameObject>, b2Body *>
            gameObjects;
public:
    ContactListener(std::map<std::shared_ptr<GameObject>, b2Body *>
                    gameObjects);

    ~ContactListener() = default;

    void BeginContact(b2Contact *contact);

    void EndContact(b2Contact *contact);
};


#endif //DEFUNBOBENGINE_CONTACTLISTENER_HPP
