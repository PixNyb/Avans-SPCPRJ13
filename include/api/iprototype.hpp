/**
* @file iprototype.hpp
* @author Maxuuuu
* @brief This file contains the IPrototype interface definition.
* @version 0.1
* @date 02-12-2023
*
* @copyright Copyright (c) 2023
*
*/

#ifndef DEFUNBOBENGINE_IPROTOTYPE_HPP
#define DEFUNBOBENGINE_IPROTOTYPE_HPP

#include <memory>

/**
 * @class IPrototype
 * @brief The IPrototype interface defines that a class needs to be cloneable.
 * @tparam T The type of the class which needs to be cloneable.
 */
template <typename T> class IPrototype
{
  public:
    /**
     * @brief Returns a clone of the object.
     * @return The cloned object in a shared pointer.
     */
    virtual std::shared_ptr<T> Clone() = 0;
};

#endif // DEFUNBOBENGINE_IPROTOTYPE_HPP
