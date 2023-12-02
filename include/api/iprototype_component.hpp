/**
* @file iprototype_component.hpp
* @author Maxuuuu
* @brief This file contains the IPrototypeComponent interface definition.
* @version 0.1
* @date 30-11-2023
*
* @copyright Copyright (c) 2023
*
*/

#ifndef DEFUNBOBENGINE_IPROTOTYPE_COMPONENT_HPP
#define DEFUNBOBENGINE_IPROTOTYPE_COMPONENT_HPP

#include "component.hpp"
#include "game_object.hpp"
#include <memory>

class Component;
class GameObject;

/**
 * @class IPrototypeComponent
 * @brief The IPrototypeComponent interface defines that a class needs to be cloneable.
 */
class IPrototypeComponent {
  public:
    /**
     * @brief Returns a clone of the current object.
     * @param parent The parent of object that is to be copied.
     * @return A copy of the object in a shared pointer.
     */
    virtual std::shared_ptr<Component> Clone(std::weak_ptr<GameObject> parent) = 0;
};

#endif // DEFUNBOBENGINE_IPROTOTYPE_COMPONENT_HPP
